/**
 * @file internal/instructions_panel.h
 * @author Nir Jacobson
 * @date 2026-04-23
 */

#ifndef INSTRUCTIONS_PANEL_INTERNAL_H
#define INSTRUCTIONS_PANEL_INTERNAL_H

#include "../instructions_panel.h"

#define PENCIL_BUTTON_X                    8
#define PENCIL_BUTTON_Y                   24
#define COLOR_DROPPER_BUTTON_X             8
#define COLOR_DROPPER_BUTTON_Y            82
#define ERASER_BUTTON_X                    8
#define ERASER_BUTTON_Y                  136
#define SELECT_BUTTON_X                  185
#define SELECT_BUTTON_Y                   24
#define STAMP_BUTTON_X                   185
#define STAMP_BUTTON_Y                    82
#define MOVE_BUTTON_X                    185
#define MOVE_BUTTON_Y                    136

/* Action region callbacks */

/// @private
/// @memberof InstructionsPanel
/// @brief Handler for a mouse press on the title bar.
/// @param args Arguments passed to the ActionRegion action handler.
void instructions_panel_titlebar_press(ActionRegionArgs* args);

/// @private
/// @memberof InstructionsPanel
/// @brief Handler for a mouse release on the title bar.
/// @param args Arguments passed to the ActionRegion action handler.
void instructions_panel_titlebar_release(ActionRegionArgs* args);

/// @private
/// @memberof InstructionsPanel
/// @brief Handler for a mouse release on the close button.
/// @param args Arguments passed to the ActionRegion action handler.
void instructions_panel_close_button_release(ActionRegionArgs* args);

/// @private
/// @memberof InstructionsPanel
/// @brief Handler for a mouse press on the ok button.
/// @param args Arguments passed to the ActionRegion action handler.
void instructions_panel_ok_button_press(ActionRegionArgs* args);

/// @private
/// @memberof InstructionsPanel
/// @brief Handler for a mouse release on the ok button.
/// @param args Arguments passed to the ActionRegion action handler.
void instructions_panel_ok_button_release(ActionRegionArgs* args);

/* InstructionsPanel */

/// @private
/// @memberof InstructionsPanel
/// @brief Draws the background.
/// @param instrPanel InstructionsPanel to draw on.
void instructions_panel_draw_background(InstructionsPanel* instrPanel);

/// @private
/// @memberof InstructionsPanel
/// @brief Draws the title bar.
/// @param instrPanel InstructionsPanel to draw on.
void instructions_panel_draw_titlebar(InstructionsPanel* instrPanel);

/// @private
/// @memberof InstructionsPanel
/// @brief Draws the title bar buttons.
/// @param instrPanel InstructionsPanel to draw on.
void instructions_panel_draw_title_buttons(InstructionsPanel* instrPanel);

/// @private
/// @memberof InstructionsPanel
/// @brief Draws the background image.
/// @param instrPanel InstructionsPanel to draw on.
void instructions_panel_draw_image(InstructionsPanel* instrPanel);

/// @private
/// @memberof InstructionsPanel
/// @brief Draws the dialog buttons.
/// @param instrPanel InstructionsPanel to draw on.
void instructions_panel_draw_dialog_buttons(InstructionsPanel* instrPanel);

/// @private
/// @memberof InstructionsPanel
/// @brief Draws the pencil button.
/// @param instrPanel InstructionsPanel to draw on.
void instructions_panel_draw_pencil_button(InstructionsPanel* pickerPanel);

/// @private
/// @memberof InstructionsPanel
/// @brief Draws the eraser button.
/// @param instrPanel InstructionsPanel to draw on.
void instructions_panel_draw_eraser_button(InstructionsPanel* pickerPanel);

/// @private
/// @memberof InstructionsPanel
/// @brief Draws the dropper button.
/// @param instrPanel InstructionsPanel to draw on.
void instructions_panel_draw_dropper_button(InstructionsPanel* pickerPanel);

/// @private
/// @memberof InstructionsPanel
/// @brief Draws the select button.
/// @param instrPanel InstructionsPanel to draw on.
void instructions_panel_draw_select_button(InstructionsPanel* pickerPanel);

/// @private
/// @memberof InstructionsPanel
/// @brief Draws the stamp button button.
/// @param instrPanel InstructionsPanel to draw on.
void instructions_panel_draw_stamp_button(InstructionsPanel* pickerPanel);

/// @private
/// @memberof InstructionsPanel
/// @brief Draws the move button.
/// @param instrPanel InstructionsPanel to draw on.
void instructions_panel_draw_move_button(InstructionsPanel* pickerPanel);

/// @private
/// @memberof InstructionsPanel
/// @brief Draws the tool buttons.
/// @param instrPanel InstructionsPanel to draw on.
void instructions_panel_draw_buttons(InstructionsPanel* pickerPanel);

/// @private
/// @memberof InstructionsPanel
/// @brief Draws the entire InstructionsPanel.
/// @param instrPanel InstructionsPanel to draw.
void instructions_panel_draw(void* instrPanelPtr);

/// @private
/// @memberof InstructionsPanel
/// @brief Adds the title bar ActionRegion to the InstructionsPanel.
/// @param instrPanel InstructionsPanel to add to.
void instructions_panel_add_titlebar_action_region(InstructionsPanel* instrPanel);

/// @private
/// @memberof InstructionsPanel
/// @brief Adds the close button ActionRegion to the InstructionsPanel.
/// @param instrPanel InstructionsPanel to add to.
void instructions_panel_add_close_button_action_region(InstructionsPanel* instrPanel);

/// @private
/// @memberof InstructionsPanel
/// @brief Adds the ok button ActionRegion to the InstructionsPanel.
/// @param instrPanel InstructionsPanel to add to.
void instructions_panel_add_ok_button_action_region(InstructionsPanel* instrPanel);

#endif