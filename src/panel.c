#include "panel.h"
#include "internal/panel.h"

/* Linked list processing callbacks */

char coords_over_action_region(void* coordsPtr, void* actionRegionPtr) {
    unsigned int* coords = (unsigned int*)coordsPtr;
    ActionRegion* actionRegion = (ActionRegion*)actionRegionPtr;

    return (coords[0] >= actionRegion->position[0]) && (coords[0] < (actionRegion->position[0] + actionRegion->width)) &&
           (coords[1] >= actionRegion->position[1]) && (coords[1] < (actionRegion->position[1] + actionRegion->height));
}

char coords_over_panel(void* coordsPtr, void* panelPtr) {
    unsigned int* coords = (unsigned int*)coordsPtr;
    Panel* panel = (Panel*)panelPtr;

    return (coords[0] >= panel->position[0]) && (coords[0] < (panel->position[0] + panel->width)) &&
           (coords[1] >= panel->position[1]) && (coords[1] < (panel->position[1] + panel->height));
}

/* Panel */

Panel* panel_init(Panel* d, Renderer* renderer, void* owner, void (*drawCallback)(void*), PanelManager* manager, unsigned int width, unsigned int height) {
    Panel* panel = d ? d : NEW(Panel, 1);

    panel->renderer = renderer;

    panel->position[0] = 16;
    panel->position[1] = 16;

    panel->width = width;
    panel->height = height;

    panel->surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, panel->width, panel->height);
    panel->cr = cairo_create (panel->surface);

    panel->owner = owner;
    panel->drawCallback = drawCallback;
    panel->manager = manager;

    linked_list_init(&panel->actionRegions);

    glGenBuffers(1, &panel->renderState.opengl.vbo);
    glGenTextures(1, &panel->renderState.opengl.tex);

    float vertex_data[] =  {
        panel->position[0], panel->position[1], -0.5, 0, 0,
        panel->position[0], panel->position[1] + panel->height, -0.5, 0, 1,
        panel->position[0] + panel->width, panel->position[1], -0.5, 1, 0,
        panel->position[0] + panel->width, panel->position[1] + panel->height, -0.5, 1, 1
    };
    glBindBuffer(GL_ARRAY_BUFFER, panel->renderState.opengl.vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_data), vertex_data, GL_STATIC_DRAW);

    panel_manager_add_panel(panel->manager, panel);

    return panel;
}

void panel_destroy(Panel* panel) {
    glDeleteTextures(1, &panel->renderState.opengl.tex);
    glDeleteBuffers(1, &panel->renderState.opengl.vbo);

    linked_list_destroy(&panel->actionRegions, free);

    cairo_destroy(panel->cr);
    cairo_surface_destroy(panel->surface);
}

void panel_hide(Panel* panel) {
    panel_manager_remove_panel(panel->manager, panel);
}

void panel_add_action_region(Panel* panel, ActionRegion* actionRegion) {
    linked_list_insert(&panel->actionRegions, actionRegion);
}

void panel_action(Panel* panel, char action, unsigned int x, unsigned int y) {
#ifdef _WIN32
    GLFWmonitor* primary = glfwGetPrimaryMonitor();
    float xscale, yscale;
    glfwGetMonitorContentScale(primary, &xscale, &yscale);

    x = x / xscale - panel->position[0];
    y = y / yscale - panel->position[1];
#else
    const char* sessionType = getenv("XDG_SESSION_TYPE");
    if (sessionType && strcmp(sessionType, "x11") == 0) {
        GLFWmonitor* primary = glfwGetPrimaryMonitor();
        float xscale, yscale;
        glfwGetMonitorContentScale(primary, &xscale, &yscale);

        x = x / xscale - panel->position[0];
        y = y / yscale - panel->position[1];
    } else {
        x -= panel->position[0];
        y -= panel->position[1];    }
#endif

    if (action == MOUSE_PRESS) {
        panel->manager->active_panel = panel;
    }

    unsigned int coords[2] = { x, y };
    LinkedListNode* node = linked_list_find(&panel->actionRegions, coords, coords_over_action_region);

    if (node) {
        ActionRegion* actionRegion = (ActionRegion*)node->data;
        ActionRegionArgs args = {
            panel,
            actionRegion,
            x - actionRegion->position[0],
            y - actionRegion->position[1]
        };

        switch (action) {
            case MOUSE_PRESS:
                if (actionRegion->action_press)
                    actionRegion->action_press(&args);
                break;
            case MOUSE_RELEASE:
                if (actionRegion->action_release)
                    actionRegion->action_release(&args);
                break;
        }
    }
}

void panel_set_position(Panel* panel, int x, int y) {
    panel->position[0] = x;
    panel->position[1] = y;

    float z = -0.5;

    float vertex_data[] =  {
        panel->position[0], panel->position[1], z, 0, 0,
        panel->position[0], panel->position[1] + panel->height, z, 0, 1,
        panel->position[0] + panel->width, panel->position[1], z, 1, 0,
        panel->position[0] + panel->width, panel->position[1] + panel->height, z, 1, 1
    };

    glBindBuffer(GL_ARRAY_BUFFER, panel->renderState.opengl.vbo);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertex_data), vertex_data);
}

void panel_translate(Panel* panel, int x, int y) {
#ifdef _WIN32
    GLFWmonitor* primary = glfwGetPrimaryMonitor();
    float xscale, yscale;
    glfwGetMonitorContentScale(primary, &xscale, &yscale);

    x /= xscale;
    y /= yscale;
#else
    const char* sessionType = getenv("XDG_SESSION_TYPE");
    if (sessionType && strcmp(sessionType, "x11") == 0) {
        GLFWmonitor* primary = glfwGetPrimaryMonitor();
        float xscale, yscale;
        glfwGetMonitorContentScale(primary, &xscale, &yscale);

        x /= xscale;
        y /= yscale;
    }
#endif

    int tx = panel->position[0] + x;
    int ty = panel->position[1] + y;
    panel_set_position(panel, tx, ty);
}

void panel_texture(Panel* panel) {
    glBindTexture(GL_TEXTURE_2D, panel->renderState.opengl.tex);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    unsigned char* pixels = cairo_image_surface_get_data(panel->surface);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, panel->width, panel->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
}

/* PanelManager */

PanelManager* panel_manager_init(PanelManager* pm) {
    PanelManager* panelManager = pm ? pm : NEW(PanelManager, 1);

    linked_list_init(&panelManager->panels);

    panelManager->active_panel = NULL;
    panelManager->dragging = 0;

    return panelManager;
}

void panel_manager_destroy(PanelManager* panelManager) {
    linked_list_destroy(&panelManager->panels, NULL);
}

void panel_manager_add_panel(PanelManager* panelManager, Panel* panel) {
    linked_list_insert(&panelManager->panels, panel);
    panel->manager = panelManager;
}

char pointers_equal(void* a, void* b) {
    return a == b;
}

void panel_manager_remove_panel(PanelManager* panelManager, Panel* panel) {
    LinkedListNode* node = linked_list_find(&panelManager->panels, panel, pointers_equal);

    if (node) {
        linked_list_remove(&panelManager->panels, node, NULL);
    }
}

Panel* panel_manager_find_panel(PanelManager* panelManager, unsigned int x, unsigned int y) {
#ifdef _WIN32
    GLFWmonitor* primary = glfwGetPrimaryMonitor();
    float xscale, yscale;
    glfwGetMonitorContentScale(primary, &xscale, &yscale);

    x /= xscale;
    y /= yscale;
#else
    const char* sessionType = getenv("XDG_SESSION_TYPE");
    if (sessionType && strcmp(sessionType, "x11") == 0) {
        GLFWmonitor* primary = glfwGetPrimaryMonitor();
        float xscale, yscale;
        glfwGetMonitorContentScale(primary, &xscale, &yscale);

        x /= xscale;
        y /= yscale;
    }
#endif
    unsigned int coords[2] = { x, y };
    LinkedListNode* node = linked_list_find(&panelManager->panels, coords, coords_over_panel);

    return node ? node->data : NULL;
}

