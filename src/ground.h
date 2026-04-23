/**
 * @file ground.h
 * @author Nir Jacobson
 * @date 2026-04-23
 */

#ifndef GROUND_H
#define GROUND_H

#include <string.h>

#include "global.h"
#include "mesh.h"

/**
 * @class Ground
 * @brief The Voxel Ground.
 */
typedef struct {
    /// @private
    /// @brief The Ground Mesh.
    Mesh mesh;
} Ground;

/** 
 * @public
 * @memberof Ground
 * @brief Initializes the Ground.
 * @param [in] g        Ground to initialize. Can be NULL to allocate a new Ground.
 * @param [in] vulkan   %Global Vulkan object or NULL if using OpenGL.
 * @param [in] length   The size of the Ground in width and length.
 * @return **g** or a new Ground if **g** was NULL.
 */
Ground* ground_init(Ground* g, Vulkan* vulkan, int length);

/** 
 * @public
 * @memberof Ground
 * @brief    Destroys the Ground.
 * @param [in] ground Ground to destroy.
 */
void ground_destroy(Ground* ground);

#endif // GROUND_H
