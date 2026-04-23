/**
 * @file panel.h
 * @author Nir Jacobson
 * @date 2026-04-23
 */

#ifndef PANEL_H
#define PANEL_H

#include <cairo/cairo.h>
#include <stdlib.h>

#include "global.h"
#include "linked_list.h"
#include "window.h"
#include "vulkan_util.h"
#include "renderer.h"

const extern int MAX_FRAMES_IN_FLIGHT;

struct Panel;
struct PanelManager;
struct ActionRegion;

/* ActionRegion */

/**
 * @class ActionRegionArgs
 * @brief Encapsulates the arguments passed to ActionRegion functions.
 */
typedef struct {
    /// @private
    /// @brief Parent panel.
    struct Panel* panel;

    /// @private
    /// @brief Parent ActionRegion.
    struct ActionRegion* actionRegion;

    /// @private
    /// @brief The ActionRegion-local x-coordinate of the event.
    unsigned int x;

    /// @private
    /// @brief The ActionRegion-local y-coordinate of the event.
    unsigned int y;
} ActionRegionArgs;

/**
 * @class ActionRegion
 * @brief A rectangular region on the screen with mouse press and release handlers.
 */
typedef struct ActionRegion {
    /// @private
    /// @brief (x, y) position of the ActionRegion.
    unsigned int position[2];

    /// @private
    /// @brief Width of the ActionRegion.
    unsigned int width;

    /// @private
    /// @brief Height of the ActionRegion.
    unsigned int height;

    /// @private
    /// @brief Mouse press handler.
    void (*action_press)(ActionRegionArgs*);

    /// @private
    /// @brief Mouse release handler.
    void (*action_release)(ActionRegionArgs*);
} ActionRegion;

/* Panel */

/**
 * @class PanelRenderStateOpenGL
 * @brief Panel render state (OpenGL).
 */
typedef struct {
    /// @private
    /// @brief Vertex buffer object (VBO).
    unsigned int vbo;

    /// @private
    /// @brief Texture object.
    unsigned int tex;
} PanelRenderStateOpenGL;

/**
 * @class PanelRenderStateVulkan
 * @brief Panel render state (%Vulkan).
 */
typedef struct {
    /// @private
    /// @brief Vertex buffer object (VBO).
    VkBuffer vbo;

    /// @private
    /// @brief VBO device memory.
    VkDeviceMemory vboDeviceMemory;

    /// @private
    /// @brief Texture image.
    VkImage texImage;

    /// @private
    /// @brief Texture image device memory.
    VkDeviceMemory texImageDeviceMemory;

    /// @private
    /// @brief Texture image view.
    VkImageView texImageView;

    /// @private
    /// @brief Texture view descriptor sets.
    VkDescriptorSet* descriptorSets;
} PanelRenderStateVulkan;

/**
 * @class Panel
 * @brief A drawable rectangular region on the screen with zero or more \ref ActionRegion "ActionRegions".
 */
typedef struct Panel {
    /// @private
    /// @brief Global Vulkan object or NULL if using OpenGL.
    Vulkan* vulkan;

    /// @private
    /// @brief Reference to the Voxel Renderer.
    Renderer* renderer;

    /// @private
    /// @brief Mesh render state.
    union {
        /// @private
        /// @brief OpenGL render state.
        PanelRenderStateOpenGL opengl;

        /// @private
        /// @brief Vulkan render state.
        PanelRenderStateVulkan vulkan;
    } renderState;

    /// @private
    /// @brief Cairo drawing surface.
    cairo_surface_t *surface;

    /// @private
    /// @brief Cairo handle
    cairo_t *cr;

    /// @private
    /// @brief Panel owner.
    void* owner;

    /// @private
    /// @brief Callback used to (re)draw the panel.
    void (*drawCallback)(void*);


    /// @private
    /// @brief Reference to the Voxel PanelManager.
    struct PanelManager* manager;

    /// @private
    /// @brief (x, y) position of the Panel.
    unsigned int position[2];

    /// @private
    /// @brief Width of the Panel.
    unsigned int width;

    /// @private
    /// @brief Height of the Panel.
    unsigned int height;

    /// @private
    /// @brief List of \ref ActionRegion "ActionRegions".
    LinkedList actionRegions;
} Panel;

/** 
 * @public
 * @memberof Panel
 * @brief Initializes a Mesh.
 * @param [in] p            Panel to initialize. Can be NULL to allocate a new Panel.
 * @param [in] renderer     Voxel Renderer.
 * @param [in] owner        Panel owner.
 * @param [in] drawCallback Callback used to (re)draw the panel.
 * @param [in] panelManager Voxel PanelManager.
 * @param [in] width        Width of the panel.
 * @param [in] height       Height of the panel.
 * @return **p** or a new Panel if **p** was NULL.
 */
Panel* panel_init(Panel* p, Renderer* renderer, void* owner, void (*drawCallback)(void*), struct PanelManager* manager, unsigned int width, unsigned int height);

/** 
 * @public
 * @memberof Panel
 * @brief Destroys a Panel.
 * @param [in] panel Panel to destroy.
 */
void panel_destroy(Panel* panel);

/** 
 * @public
 * @memberof Panel
 * @brief Adds an ActionRegion to a Panel.
 * @param [in] panel        Panel to add to.
 * @param [in] actionRegion ActionRegion to add.
 */
void panel_add_action_region(Panel* panel, ActionRegion* actionRegion);

/** 
 * @public
 * @memberof Panel
 * @brief Enacts a mouse press or release at a panel-local location.
 * @param [in] panel  Panel to add to.
 * @param [in] action Event to enact.
 * @param [in] x      The Panel-local x-coordinate of the event.
 * @param [in] y      The Panel-local y-coordinate of the event.
 */
void panel_action(Panel* panel, char action, unsigned int x, unsigned int y);

/** 
 * @public
 * @memberof Panel
 * @brief Sets the panel location on the screen.
 * @param [in] panel  Panel to position.
 * @param [in] x      The global x-coordinate of the Panel.
 * @param [in] y      The global y-coordinate of the Panel.
 */
void panel_set_position(Panel* panel, int x, int y);

/** 
 * @public
 * @memberof Panel
 * @brief Moves the panel by a given amount in each direction.
 * @param [in] panel  Panel to move.
 * @param [in] x      The x increment.
 * @param [in] y      The y increment.
 */
void panel_translate(Panel* panel, int x, int y);

/** 
 * @public
 * @memberof Panel
 * @brief Re(generates) the texture of the Panel from its drawing surface.
 * @param [in] panel  Panel to (re)texture.
 */
void panel_texture(Panel* panel);

/** 
 * @public
 * @memberof Panel
 * @brief Hides a Panel.
 * @param [in] panel Panel to hide.
 */
void panel_hide(Panel* panel);

/* PanelManager */

/**
 * @class PanelManager
 * @brief Container for adding, removing and finding \ref Panel "Panels" on-screen.
 */
typedef struct PanelManager {
    /// @private
    /// @brief \ref Panel "Panels" on the screen
    LinkedList panels;

    /// @private
    /// @brief The Panel with focus.
    Panel* active_panel;

    /// @private
    /// @brief Whether **active_panel** is being dragged.
    char dragging;
} PanelManager;

/** 
 * @public
 * @memberof PanelManager
 * @brief Initializes the PanelManager.
 * @param [in] pm PanelManager to initialize. Can be NULL to allocate a new PanelManager.
 */
PanelManager* panel_manager_init(PanelManager* pm);

/** 
 * @public
 * @memberof PanelManager
 * @brief Destroys the PanelManager.
 * @param [in] panelManager PanelManager to destroy.
 */
void panel_manager_destroy(PanelManager* panelManager);

/** 
 * @public
 * @memberof PanelManager
 * @brief Adds a Panel to the PanelManager.
 * @param [in] panelManager PanelManager to add to.
 * @param [in] panel        Panel to add.
 */
void panel_manager_add_panel(PanelManager* panelManager, Panel* panel);

/** 
 * @public
 * @memberof PanelManager
 * @brief Removes a Panel from the PanelManager.
 * @param [in] panelManager PanelManager to remove from.
 * @param [in] panel        Panel to remove.
 */
void panel_manager_remove_panel(PanelManager* panelManager, Panel* panel);

/** 
 * @public
 * @memberof PanelManager
 * @brief Finds the first Panel under the given (x, y) location.
 * @param [in] x The global x-coordinate of the location.
 * @param [in] y The global y-coordinate of the location.
 * @returns Panel found, or NULL if not found.
 */
Panel* panel_manager_find_panel(PanelManager* panelManager, unsigned int x, unsigned int y);

#endif // PANEL_H
