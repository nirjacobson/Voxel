/**
 * @file fps_panel.h
 * @author Nir Jacobson
 * @date 2026-04-23
 */

#ifndef FPS_PANEL_H
#define FPS_PANEL_H

#include <stdio.h>

#include "panel.h"
#include "renderer.h"

/**
 * @class FPSPanel
 * @brief Panel displaying the \ref Renderer "Renderer's" current rate of frames per second.
 */
typedef struct {
    /// @private
    /// @brief FPSPanel Panel.
    Panel panel;

    /// @brief
    /// @brief Most recently recorded FPS.
    float fps;
} FPSPanel;

/** 
 * @public
 * @memberof FPSPanel
 * @brief Initializes the FPSPanel.
 * @param [in] p FPSPanel to initialize. Can be NULL to allocate a new FPSPanel.
 * @param [in] renderer Reference to the Voxel Renderer.
 * @param [in] panelManager Reference to the Voxel PanelManager.
 */
FPSPanel* fps_panel_init(FPSPanel* p, Renderer* renderer, PanelManager* panelManager);

/** 
 * @public
 * @memberof FPSPanel
 * @brief Destroys the FPSPanel.
 * @param [in] panel FPSPanel to destroy.
 */
void fps_panel_destroy(FPSPanel* fpsPanel);

/** 
 * @public
 * @memberof FPSPanel
 * @brief Sets the FPS value on the FPSPanel.
 * @param [in] fpsPanel FPSPanel to update.
 * @param [in] fps FPS value.
 */
void fps_panel_set_fps(FPSPanel* fpsPanel, float fps);


/** 
 * @public
 * @memberof FPSPanel
 * @brief Sets the panel location on the screen.
 * @param [in] fpsPanel FPSPanel to position.
 * @param [in] x        The global x-coordinate of the FPSPanel.
 * @param [in] y        The global y-coordinate of the FPSPanel.
 */
void fps_panel_set_position(FPSPanel* fpsPanel, unsigned int x, unsigned int y);

#endif // FPS_PANEL_H
