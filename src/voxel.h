#ifndef VOXEL_H
#define VOXEL_H

#ifdef _WIN32
#include <winsock.h>
#endif

#ifndef _WIN32
#include <sys/time.h>
#endif

#include <gio/gio.h>

#include "global.h"
#include "vulkan_util.h"
#include "application.h"
#include "window.h"
#include "renderer.h"
#include "camera.h"
#include "world.h"
#include "picker.h"
#include "panel.h"
#include "fps_panel.h"
#include "picker_panel.h"
#include "instructions_panel.h"
#include "undo_stack.h"

/**
 * @class Voxel
 * @brief The Voxel application.
 */
typedef struct Voxel {
    /// @private
    /// @brief Application singleton object.
    Application application;

    /// @private
    /// @brief Window singleton object.
    Window window;

    /// @private
    /// @brief Vulkan singleton object or NULL if using OpenGL. 
    Vulkan* vulkan;

    /// @brief Renderer singleton object.
    Renderer renderer;

    /// @private
    /// @brief World singleton object.
    World world;

    /// @private
    /// @brief Camera singleton object.
    Camera camera;

    /// @private
    /// @brief Picker singleton object.
    Picker picker;

    /// @private
    /// @brief PanelManager singleton object.
    PanelManager panelManager;

    /// @private
    /// @brief FPSPanel singleton object.
    FPSPanel fpsPanel;

    /// @private
    /// @brief PickerPanel singleton object.
    PickerPanel pickerPanel;

    /// @private
    /// @brief InstructionsPanel singleton object.
    InstructionsPanel instrPanel;

    /// @private
    /// @brief UndoStack singleton object.
    UndoStack undoStack;

    /// @private
    /// @brief Time marker used to calculate frames per second (FPS).
    struct timeval frameTime;
} Voxel;

/** 
 * @public
 * @memberof Voxel
 * @brief Initializes Voxel.
 * @param [in] v            Voxel.
 * @return **v** or a new Voxel if **v** was NULL.
 */
Voxel* voxel_init(Voxel* v);

/** 
 * @public
 * @memberof Voxel
 * @brief Destroys Voxel.
 * @param [in] voxel        Voxel.
 */
void voxel_destroy(Voxel* voxel);

/** 
 * @public
 * @memberof Voxel
 * @brief Shows the InstructionsPanel.
 * @param [in] voxel        Voxel.
 */
void voxel_show_instructions_panel(Voxel* voxel);

/** 
 * @public
 * @memberof Voxel
 * @brief Runs Voxel.
 * @param [in] voxel        Voxel.
 */
void voxel_run(Voxel* voxel);

#endif // VOXEL_H
