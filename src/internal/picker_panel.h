#ifndef PICKER_PANEL_INTERNAL_H
#define PICKER_PANEL_INTERNAL_H

#include "../global.h"
#include "../block.h"

#include "../picker_panel.h"

/// @memberof PickerPanel
/// @name PickerPanel dimensions
/// @{
#define PICKER_PANEL_WIDTH          320
#define PICKER_PANEL_HEIGHT         176
/// @}

/// @memberof PickerPanel
/// @name PickerPanel element locations
/// @{
#define PENCIL_BUTTON_X                    8
#define PENCIL_BUTTON_Y                   24
#define ERASER_BUTTON_X                   46
#define ERASER_BUTTON_Y                   24
#define COLOR_DROPPER_BUTTON_X             8
#define COLOR_DROPPER_BUTTON_Y            62
#define SELECT_BUTTON_X                    8
#define SELECT_BUTTON_Y                  135
#define STAMP_BUTTON_X                    46
#define STAMP_BUTTON_Y                   135
#define MOVE_BUTTON_X                     84
#define MOVE_BUTTON_Y                    135
#define BUTTON_WIDTH                      34
#define BUTTON_HEIGHT                     34
#define BLUE_BAR_X                       191
#define BLUE_BAR_Y                        24
#define PALETTE_X                        191
#define PALETTE_Y                         48
/// @}

/* Action region callbacks */

/// @private
/// @memberof PickerPanel
/// @brief Handler for a mouse press on the title bar.
/// @param args Arguments passed to the ActionRegion action handler.
void picker_panel_titlebar_press(ActionRegionArgs* args);

/// @private
/// @memberof PickerPanel
/// @brief Handler for a mouse release on the title bar.
/// @param args Arguments passed to the ActionRegion action handler.
void picker_panel_titlebar_release(ActionRegionArgs* args);

/// @private
/// @memberof PickerPanel
/// @brief Handler for a mouse press on the blue bar.
/// @param args Arguments passed to the ActionRegion action handler.
void picker_panel_bluebar_press(ActionRegionArgs* args);

/// @private
/// @memberof PickerPanel
/// @brief Handler for a mouse press on the palette.
/// @param args Arguments passed to the ActionRegion action handler.
void picker_panel_palette_press(ActionRegionArgs* args);

/// @private
/// @memberof PickerPanel
/// @brief Handler for a mouse press on the pencil button.
/// @param args Arguments passed to the ActionRegion action handler.
void picker_panel_pencil_button_press(ActionRegionArgs* args);

/// @private
/// @memberof PickerPanel
/// @brief Handler for a mouse press on the eraser button.
/// @param args Arguments passed to the ActionRegion action handler.
void picker_panel_eraser_button_press(ActionRegionArgs* args);

/// @private
/// @memberof PickerPanel
/// @brief Handler for a mouse press on the dropper button.
/// @param args Arguments passed to the ActionRegion action handler.
void picker_panel_dropper_button_press(ActionRegionArgs* args);

/// @private
/// @memberof PickerPanel
/// @brief Handler for a mouse press on the select button.
/// @param args Arguments passed to the ActionRegion action handler.
void picker_panel_select_button_press(ActionRegionArgs* args);

/// @private
/// @memberof PickerPanel
/// @brief Handler for a mouse press on the stamp button.
/// @param args Arguments passed to the ActionRegion action handler.
void picker_panel_stamp_button_press(ActionRegionArgs* args);

/// @private
/// @memberof PickerPanel
/// @brief Handler for a mouse press on the move button.
/// @param args Arguments passed to the ActionRegion action handler.
void picker_panel_move_button_press(ActionRegionArgs* args);

/// @private
/// @memberof PickerPanel
/// @brief Handler for a mouse press on the question button.
/// @param args Arguments passed to the ActionRegion action handler.
void picker_panel_question_button_press(ActionRegionArgs* args);

/// @private
/// @memberof PickerPanel
/// @brief Handler for a mouse release on the question button.
/// @param args Arguments passed to the ActionRegion action handler.
void picker_panel_question_button_release(ActionRegionArgs* args);

/* PickerPanel */

/// @private
/// @memberof PickerPanel
/// @brief Draws the background.
/// @param pickerPanel PickerPanel to draw on.
void picker_panel_draw_background(PickerPanel* pickerPanel);

/// @private
/// @memberof PickerPanel
/// @brief Draws the title bar.
/// @param pickerPanel PickerPanel to draw on.
void picker_panel_draw_titlebar(PickerPanel* pickerPanel);

/// @private
/// @memberof PickerPanel
/// @brief Draws the blue bar.
/// @param pickerPanel PickerPanel to draw on.
void picker_panel_draw_bluebar(PickerPanel* pickerPanel);

/// @private
/// @memberof PickerPanel
/// @brief Draws the palette.
/// @param pickerPanel PickerPanel to draw on.
void picker_panel_draw_palette(PickerPanel* pickerPanel);

/// @private
/// @memberof PickerPanel
/// @brief Draws the pencil button.
/// @param pickerPanel PickerPanel to draw on.
void picker_panel_draw_pencil_button(PickerPanel* pickerPanel);

/// @private
/// @memberof PickerPanel
/// @brief Draws the eraser button.
/// @param pickerPanel PickerPanel to draw on.
void picker_panel_draw_eraser_button(PickerPanel* pickerPanel);

/// @private
/// @memberof PickerPanel
/// @brief Draws the dropper button.
/// @param pickerPanel PickerPanel to draw on.
void picker_panel_draw_dropper_button(PickerPanel* pickerPanel);

/// @private
/// @memberof PickerPanel
/// @brief Draws the select button.
/// @param pickerPanel PickerPanel to draw on.
void picker_panel_draw_select_button(PickerPanel* pickerPanel);

/// @private
/// @memberof PickerPanel
/// @brief Draws the stamp button.
/// @param pickerPanel PickerPanel to draw on.
void picker_panel_draw_stamp_button(PickerPanel* pickerPanel);

/// @private
/// @memberof PickerPanel
/// @brief Draws the move button.
/// @param pickerPanel PickerPanel to draw on.
void picker_panel_draw_move_button(PickerPanel* pickerPanel);

/// @private
/// @memberof PickerPanel
/// @brief Draws the tool buttons.
/// @param pickerPanel PickerPanel to draw on.
void picker_panel_draw_buttons(PickerPanel* pickerPanel);

/// @private
/// @memberof PickerPanel
/// @brief Draws the question button.
/// @param pickerPanel PickerPanel to draw on.
void picker_panel_draw_question_button(PickerPanel* pickerPanel);

/// @private
/// @memberof PickerPanel
/// @brief Draws the PickerPanel.
/// @param pickerPanel PickerPanel to draw.
void picker_panel_draw(void* pickerPanelPtr);

/// @private
/// @memberof PickerPanel
/// @brief Adds the title bar ActionRegion to the PickerPanel.
/// @param pickerPanel PickerPanel to add to.
void picker_panel_add_titlebar_action_region(PickerPanel* pickerPanel);

/// @private
/// @memberof PickerPanel
/// @brief Adds the blue bar ActionRegion to the PickerPanel.
/// @param pickerPanel PickerPanel to add to.
void picker_panel_add_bluebar_action_region(PickerPanel* pickerPanel);

/// @private
/// @memberof PickerPanel
/// @brief Adds the palette ActionRegion to the PickerPanel.
/// @param pickerPanel PickerPanel to add to.
void picker_panel_add_palette_action_region(PickerPanel* pickerPanel);

/// @private
/// @memberof PickerPanel
/// @brief Adds the pencil button ActionRegion to the PickerPanel.
/// @param pickerPanel PickerPanel to add to.
void picker_panel_add_pencil_button_action_region(PickerPanel* pickerPanel);

/// @private
/// @memberof PickerPanel
/// @brief Adds the eraser button ActionRegion to the PickerPanel.
/// @param pickerPanel PickerPanel to add to.
void picker_panel_add_eraser_button_action_region(PickerPanel* pickerPanel);

/// @private
/// @memberof PickerPanel
/// @brief Adds the dropper button ActionRegion to the PickerPanel.
/// @param pickerPanel PickerPanel to add to.
void picker_panel_add_dropper_button_action_region(PickerPanel* pickerPanel);

/// @private
/// @memberof PickerPanel
/// @brief Adds the select button ActionRegion to the PickerPanel.
/// @param pickerPanel PickerPanel to add to.
void picker_panel_add_select_button_action_region(PickerPanel* pickerPanel);

/// @private
/// @memberof PickerPanel
/// @brief Adds the stamp button ActionRegion to the PickerPanel.
/// @param pickerPanel PickerPanel to add to.
void picker_panel_add_stamp_button_action_region(PickerPanel* pickerPanel);

/// @private
/// @memberof PickerPanel
/// @brief Adds the move button ActionRegion to the PickerPanel.
/// @param pickerPanel PickerPanel to add to.
void picker_panel_add_move_button_action_region(PickerPanel* pickerPanel);

/// @private
/// @memberof PickerPanel
/// @brief Adds the question button ActionRegion to the PickerPanel.
/// @param pickerPanel PickerPanel to add to.
void picker_panel_add_question_button_action_region(PickerPanel* pickerPanel);

#endif // PICKER_PANEL_INTERNAL_H
