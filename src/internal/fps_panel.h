/**
 * @file internal/fps_panel.h
 * @author Nir Jacobson
 * @date 2026-04-23
 */

#ifndef FPS_PANEL_INTERNAL_H
#define FPS_PANEL_INTERNAL_H

#define FPS_PANEL_WIDTH     128
#define FPS_PANEL_HEIGHT     16

#include "../fps_panel.h"

/** 
 * @private
 * @memberof FPSPanel
 * @brief Callback used to (re)draw the FPSPanel.
 * @param [in] fpsPanelPtr The FPS panel being drawn.
 */
void fps_panel_draw(void* fpsPanelPtr);

#endif // FPS_PANEL_INTERNAL_H
