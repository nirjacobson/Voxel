/**
 * @file box.h
 * @author Nir Jacobson
 * @date 2026-04-23
 */

#ifndef BOX_H
#define BOX_H

#include <stdio.h>

#include "global.h"
#include "matrix.h"
#include "mesh.h"

/**
 * @class Box
 * @brief Conceptual box with location, size and orientation.
 */
typedef struct {
    /// @private
    /// @brief %Global Vulkan object or NULL if using OpenGL.
    Vulkan* vulkan;

    /// @private
    /// @brief Box position (x, y, z).
    float position[3];

    /// @private
    /// @brief Forward vector (x, y, z).
    float forward[3];

    /// @private
    /// @brief Up vector (x, y, z).
    float up[3];

    /// @private
    /// @brief Right vector (x, y, z).
    float right[3];

    /// @private
    /// @brief Box width in \ref Block "Blocks".
    float width;

    /// @private
    /// @brief Box height in \ref Block "Blocks".
    float height;

    /// @private
    /// @brief Box length in \ref Block "Blocks".
    float length;
} Box;

/** 
 * @public
 * @memberof Box
 * @brief Initializes a Box.
 * @param [in] b Box to initialize. Can be NULL to allocate a new Box.
 * @param [in] vulkan %Global Vulkan object. Set NULL when using OpenGL.
 * @return **b** or a new Box if **b** was NULL.
 */
Box* box_init(Box* b, Vulkan* vulkan);

/** 
 * @public
 * @memberof Box
 * @brief Returns the AABB (axis-aligned bounding box) of a Box.
 * @param [in] boxd Box to return. This box is aligned to the axes. Can be NULL to allocate a new Box.
 * @param [in] boxs Box to return the AABB of.
 * @return **boxd** or a new Box if **boxd** was NULL.
 */
Box* box_aabb(Box* boxd, Box* boxs);

/** 
 * @public
 * @memberof Box
 * @brief Returns a Mesh that can be rendered for a Box.
 * @param [in] mesh Mesh to return. Can be NULL to allocate a new Mesh.
 * @param [in] box Box to return a Mesh of.
 * @return **mesh** or a new Mesh if **mesh** was NULL.
 */
Mesh* box_mesh(Mesh* mesh, Box* box);

/** 
 * @public
 * @memberof Box
 * @brief Prints Box details to stdout.
 * @param [in] box Box to print.
 */
void box_print(Box* box);

#endif // BOX_H
