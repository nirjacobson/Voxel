/**
 * @file internal/panel.h
 * @author Nir Jacobson
 * @date 2026-04-23
 */

#ifndef PANEL_INTERNAL_H
#define PANEL_INTERNAL_H

#include "../panel.h"

/* Linked list processing callbacks */

/** 
 * @private
 * @memberof Panel
 * @brief LinkedList processing callback for finding an ActionRegion under a Panel-local location.
 * @param [in] coordsPtr Two-element array containing a Panel-local location.
 * @param [in] actionRegionPtr The ActionRegion being considered.
 * @returns 1 if the ActionRegion is under the given coordinates, 0 otherwise.
 */
char coords_over_action_region(void* coordsPtr, void* actionRegionPtr);

/** 
 * @private
 * @memberof PanelManager
 * @brief LinkedList processing callback for finding a Panel under a global screen location.
 * @param [in] coordsPtr Two-element array containing a global screen location.
 * @param [in] panelPtr The Panel being considered.
 * @returns 1 if the Panel is under the given coordinates, 0 otherwise.
 */
char coords_over_panel(void* coordsPtr, void* panelPtr);

/** 
 * @private
 * @memberof Panel
 * @brief Generates the Vulkan resources for rendering a Panel.
 * @param [in] panel Panel to generate resources for.
 */
void panel_create_vulkan_resources(Panel* panel);

#endif // PANEL_INTERNAL_H
