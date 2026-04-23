/**
 * @file internal/voxel.h
 * @author Nir Jacobson
 * @date 2026-04-23
 */

#ifndef VOXEL_INTERNAL_H
#define VOXEL_INTERNAL_H

#include "../voxel.h"

/** 
 * @private
 * @memberof Voxel
 * @brief Processes mouse and keyboard events since last invokation.
 * @param voxel Voxel.
 * @return 0 if Voxel should exit, 1 otherwise.
 */
char voxel_process_input(Voxel* voxel);

/** 
 * @private
 * @memberof Voxel
 * @brief Renders the next frame to the screen.
 * @param voxel Voxel.
 */
void voxel_draw(Voxel* voxel);

/** 
 * @private
 * @memberof Voxel
 * @brief Initializes %Vulkan.
 * @param voxel Voxel.
 */
void voxel_setup_vulkan(Voxel* voxel);

/** 
 * @private
 * @memberof Voxel
 * @brief Destroys %Vulkan.
 * @param voxel Voxel.
 */
void voxel_teardown_vulkan(Voxel* voxel);

/** 
 * @private
 * @memberof Voxel
 * @brief Voxel setup routine.
 * @param voxel Voxel.
 */
void voxel_setup(Application* application);

/** 
 * @private
 * @memberof Voxel
 * @brief Voxel main loop.
 * @param voxel Voxel.
 */
void voxel_main(Application* application);

/** 
 * @private
 * @memberof Voxel
 * @brief Voxel window resize handler.
 * @param voxel Voxel.
 */
void voxel_resize(Application* application);

/** 
 * @private
 * @memberof Voxel
 * @brief Voxel teardown routine.
 * @param voxel Voxel.
 */
void voxel_teardown(Application* application);

#endif // VOXEL_INTERNAL_H
