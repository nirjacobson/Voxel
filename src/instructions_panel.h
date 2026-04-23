#ifndef INSTRUCTIONS_PANEL_H
#define INSTRUCTIONS_PANEL_H

#include <gio/gio.h>

#include "panel.h"

/**
 * @class InstructionsPanel
 * @brief Panel displaying the Voxel usage instructions.
 */
typedef struct {
    /// @private
    /// @brief InstructionsPanel Panel.
    Panel panel;

    /// @private
    /// @brief Cairo surface for the background image.
    cairo_surface_t* image_surface;

    /// @private
    /// @brief Cairo surface for the pencil button image.
    cairo_surface_t* pencil_button_surface;

    /// @private
    /// @brief Cairo surface for the eraser button image.
    cairo_surface_t* eraser_button_surface;

    /// @private
    /// @brief Cairo surface for the dropper button image.
    cairo_surface_t* dropper_button_surface;

    /// @private
    /// @brief Cairo surface for the select button image.
    cairo_surface_t* select_button_surface;

    /// @private
    /// @brief Cairo surface for the stamp button image.
    cairo_surface_t* stamp_button_surface;

    /// @private
    /// @brief Cairo surface for the move button image.
    cairo_surface_t* move_button_surface;

    /// @private
    /// @brief Whether the mouse is hovered over the OK button at the time of a mouse press or release.
    bool ok_highlighted;

    /// @private
    /// @brief Width of the InstructionsPanel.
    int width;

    /// @private
    /// @brief Height of the InstructionsPanel.
    int height;
} InstructionsPanel;

/** 
 * @public
 * @memberof InstructionsPanel
 * @brief Initializes the InstructionsPanel.
 * @param [in] ip           InstructionsPanel to initialize. Can be NULL to allocate a new InstructionsPanel.
 * @param [in] renderer     The Voxel Renderer.
 * @param [in] panelManager The Voxel PanelManager.
 */
InstructionsPanel* instructions_panel_init(InstructionsPanel* ip, Renderer* renderer, PanelManager* panelManager);

/** 
 * @public
 * @memberof InstructionsPanel
 * @brief Destroys the InstructionsPanel.
 * @param [in] panel InstructionsPanel to destroy.
 */
void instructions_panel_destroy(InstructionsPanel* instrPanel);

/** 
 * @public
 * @memberof InstructionsPanel
 * @brief Sets the panel location on the screen.
 * @param [in] instrPanel InstructionsPanel to position.
 * @param [in] x          The global x-coordinate of the InstructionsPanel.
 * @param [in] y          The global y-coordinate of the InstructionsPanel.
 */
void instructions_panel_set_position(InstructionsPanel* instrPanel, unsigned int x, unsigned int y);

#endif // INSTRUCTIONS_PANEL_H