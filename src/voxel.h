#ifndef VOXEL_H
#define VOXEL_H

#include <sys/time.h>

#include "global.h"
#include "keyboard.h"
#include "mouse.h"
#include "window.h"
#include "renderer.h"
#include "camera.h"
#include "world.h"
#include "cursor.h"
#include "picker.h"
#include "panel.h"
#include "picker_panel.h"
#include "fps_panel.h"

typedef struct {
    Keyboard keyboard;
    Mouse mouse;

    Window window;
    Cursor cursor;
    Renderer renderer;

    World world;
    Camera camera;
    Picker picker;

    PanelManager panelManager;
    PickerPanel pickerPanel;
    FPSPanel fpsPanel;

    struct timeval frameTime;
} Voxel;

Voxel* voxel_init(Voxel* v);
void voxel_destroy(Voxel* voxel);

char voxel_process_input(Voxel* voxel);

void voxel_draw(Voxel* voxel);

void voxel_run(Voxel* voxel);

#endif // VOXEL_H
