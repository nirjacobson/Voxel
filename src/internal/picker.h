/**
 * @file internal/picker.h
 * @author Nir Jacobson
 * @date 2026-04-23
 */

#ifndef PICKER_INTERNAL_H
#define PICKER_INTERNAL_H

#include "../picker.h"

/// @private
/// @memberof Picker
/// @brief Enacts the current tool
/// @param picker    Voxel Picker.
/// @param modifier1 Presence of the 1st of two modifiers to alter the action.
/// @param modifier2 Presence of the 2nd of two modifiers to alter the action.
void picker_act(Picker* picker, char modifier1, char modifier2);

/// @private
/// @memberof Picker
/// @brief Generates a Box of smallest volume that encloses two \ref Box "Boxes".
/// @details Used to expand the current Selection to include the current location of the Picker.
/// @param boxA 1st Box. 
/// @param boxB 2nd Box.
/// @returns Box of smallest volume that encloses **boxA** and **boxB**.
Box picker_merge_selections(Box* boxA, Box* boxB);

#endif // PICKER_INTERNAL_H
