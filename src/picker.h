/**
 * @file picker.h
 * @author Nir Jacobson
 * @date 2026-04-23
 */

#ifndef PICKER_H
#define PICKER_H

#include <glib.h>

#include "global.h"
#include "box.h"
#include "camera.h"
#include "world.h"
#include "undo_stack.h"
#include "commands/world_set_region_command.h"
#include "commands/world_clear_region_command.h"
#include "commands/world_copy_chunk_command.h"
#include "commands/world_cut_chunk_command.h"

/// @memberof Picker
/// @name Picker selection modes
/// @{
#define PICKER_ONTO        1
#define PICKER_ADJACENT    2
/// @}

/// @memberof Picker
/// @defgroup PickerTools Picker tools
/// @{
#define PICKER_CLEAR       3
#define PICKER_SET         4
#define PICKER_EYEDROPPER  5
#define PICKER_SELECT      6
#define PICKER_STAMP       7
#define PICKER_MOVE        8
/// @}

/**
 * @class Selection
 * @brief Encapsulates Picker selection state.
 */
typedef struct {
    /// @private
    /// @brief Box defining the volume of the Selection
    Box box;

    /// @private
    /// @brief Mesh rendered to display the Selection.
    Mesh mesh;
    
    /// @private
    /// @brief Chunk representing a copy of a selected volume.
    Chunk* model;

    /// @private
    /// @brief Rotation of **model**.
    char rotation;

    /// @private
    /// @brief Whether there is an active selection.
    char present;
} Selection;

/**
 * @class Picker
 * @brief Cursor for manipulating \ref Block "Blocks" in the World.
 */
typedef struct {
    /// @private
    /// @brief Voxel World.
    World* world;

    /// @private
    /// @brief Voxel UndoStack.
    UndoStack* undoStack;

    /// @private
    /// @brief Starting block position of an active operation.
    int positionStart[3];

    /// @private
    /// @brief Ending block position of an active operation.
    int positionEnd[3];

    /// @private
    /// @brief Box defining the volume of the Picker.
    Box box;

    /// @private
    /// @brief Mesh rendered to display the Picker.
    Mesh mesh;

    /// @private
    /// @brief Picker Selection.
    Selection selection;

    /// @private
    /// @brief Whether the Picker is currently being dragged.
    char dragging;

    /// @private
    /// @brief Current selection mode.
    char mode;

    /// @private
    /// @brief Current tool.
    char action;

    /// @private
    /// @brief Current color.
    uint16_t color;
} Picker;

/** 
 * @public
 * @memberof Picker
 * @brief Initializes the Picker.
 * @param [in] p            Picker to initialize. Can be NULL to allocate a new Panel.
 * @param [in] world        Voxel World.
 * @param [in] undoStack    Voxel UndoStack.
 */
void picker_init(Picker* p, World* world, UndoStack* undoStack);

/** 
 * @public
 * @memberof Picker
 * @brief Destroys the Picker.
 * @param [in] picker Picker to destroy.
 */
void picker_destroy(Picker* picker);

/** 
 * @public
 * @memberof Picker
 * @brief Updates the \ref Picker "Picker's" start and end positions in the World based on global mouse coordinates.
 * @param [in] picker Picker to destroy.
 * @param [in] camera A Voxel Camera. The inverse of its projection matrix is used to calculate the world position \
 *                    of the Picker based on the coordinates of the mouse.
 * @param [in] mouseX x-coordinate of the global mouse position.
 * @param [in] mouseY y-coordinate of the global mouse position.
 */
void picker_update(Picker* picker, Camera* camera, float mouseX, float mouseY);

/** 
 * @public
 * @memberof Picker
 * @brief Enacts a mouse press.
 * @param [in] picker Voxel Picker.
 * @param [in] modifier1 Presence of the 1st of two modifiers to alter the action.
 * @param [in] modifier2 Presence of the 2nd of two modifiers to alter the action.
 */
void picker_press(Picker* picker, char modifier1, char modifier2);

/** 
 * @public
 * @memberof Picker
 * @brief Enacts a mouse release.
 * @param [in] picker Voxel Picker.
 * @param [in] modifier1 Presence of the 1st of two modifiers to alter the action.
 * @param [in] modifier2 Presence of the 2nd of two modifiers to alter the action.
 */
void picker_release(Picker* picker, char modifier1, char modifier2);

/** 
 * @public
 * @memberof Picker
 * @brief Sets the Picker tool.
 * @param [in] picker Voxel Picker.
 * @param [in] action Picker tool. See \ref PickerTools.
 */
void picker_set_action(Picker* picker, char action);

#endif // PICKER_H
