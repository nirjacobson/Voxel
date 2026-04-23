/**
 * @file picker_panel.h
 * @author Nir Jacobson
 * @date 2026in its04in its23
 */

#ifndef PICKER_PANEL_H
#define PICKER_PANEL_H

#include <gio/gio.h>

#include "panel.h"
#include "picker.h"

typedef struct Voxel Voxel;

/**
 * @class PickerPanel
 * @brief Picker tool and color selection panel.
 */
typedef struct {
    /// @private
    /// @brief PickerPanel Panel.
    Panel panel;

    /// @private
    /// @brief Cairo surface for pencil button in its natural state.
    cairo_surface_t* pencil_button_surface_natural;

    /// @private
    /// @brief Cairo surface for pencil button in its selected state.
    cairo_surface_t* pencil_button_surface_selected;

    /// @private
    /// @brief Cairo surface for eraser button in its natural state.
    cairo_surface_t* eraser_button_surface_natural;

    /// @private
    /// @brief Cairo surface for eraser button in its selected state.
    cairo_surface_t* eraser_button_surface_selected;

    /// @private
    /// @brief Cairo surface for dropper button in its natural state.
    cairo_surface_t* dropper_button_surface_natural;

    /// @private
    /// @brief Cairo surface for dropper button in its selected state.
    cairo_surface_t* dropper_button_surface_selected;

    /// @private
    /// @brief Cairo surface for select button in its natural state.
    cairo_surface_t* select_button_surface_natural;

    /// @private
    /// @brief Cairo surface for select button in its selected state.
    cairo_surface_t* select_button_surface_selected;

    /// @private
    /// @brief Cairo surface for stamp button in its natural state.
    cairo_surface_t* stamp_button_surface_natural;

    /// @private
    /// @brief Cairo surface for stamp button in its selected state.
    cairo_surface_t* stamp_button_surface_selected;

    /// @private
    /// @brief Cairo surface for move button in its natural state.
    cairo_surface_t* move_button_surface_natural;

    /// @private
    /// @brief Cairo surface for move button in its selected state.
    cairo_surface_t* move_button_surface_selected;

    /// @private
    /// @brief Whether the mouse is hovered over the question button at the time of a mouse press or release.
    bool question_highlighted;

    /// @private
    /// @brief Reference to Voxel
    Voxel* voxel;

    /// @private
    /// @brief Reference to the Voxel Picker
    Picker* picker;
} PickerPanel;

/** 
 * @public
 * @memberof PickerPanel
 * @brief Initializes the PickerPanel.
 * @param [in] pp           PickerPanel to initialize. Can be NULL to allocate a new PickerPanel.
 * @param [in] voxel        Reference to Voxel.
 * @param [in] renderer     The Voxel Renderer.
 * @param [in] panelManager The Voxel PanelManager.
 * @param [in] picker       The Voxel Picker.
 */
PickerPanel* picker_panel_init(PickerPanel* pp, Voxel* voxel, Renderer* renderer, PanelManager* panelManager, Picker* picker);

/** 
 * @public
 * @memberof PickerPanel
 * @brief Destroys the PickerPanel.
 * @param [in] panel PickerPanel to destroy.
 */
void picker_panel_destroy(PickerPanel* pickerPanel);

#endif // PICKER_PANEL_H
