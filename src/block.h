/**
 * @file block.h
 * @author Nir Jacobson
 * @date 2026-04-23
 */

#ifndef BLOCK_H
#define BLOCK_H

/// @public
/// @memberof Block
/// @brief Bitmask to extract red component of color value.
#define BLOCK_COLOR_MASK_RED        (((1 << 3) - 1) << 0)

/// @public
/// @memberof Block
/// @brief Bitmask to extract green component of color value.
#define BLOCK_COLOR_MASK_GREEN      (((1 << 3) - 1) << 3)

/// @public
/// @memberof Block
/// @brief Bitmask to extract blue component of color value.
#define BLOCK_COLOR_MASK_BLUE       (((1 << 3) - 1) << 6)

/// @public
/// @memberof Block
/// @brief Extracts red component of color value as a new color.
#define BLOCK_COLOR_RED(x)          ((x & BLOCK_COLOR_MASK_RED) >> 0)

/// @public
/// @memberof Block
/// @brief Sets the red component of a color value.
#define BLOCK_COLOR_SET_RED(x, y)     x = ((x & ~BLOCK_COLOR_MASK_RED) | ((y) << 0))

/// @public
/// @memberof Block
/// @brief Extracts green component of color value as a new color.
#define BLOCK_COLOR_GREEN(x)        ((x & BLOCK_COLOR_MASK_GREEN) >> 3)

/// @public
/// @memberof Block
/// @brief Sets the green component of a color value.
#define BLOCK_COLOR_SET_GREEN(x, y)   x = ((x & ~BLOCK_COLOR_MASK_GREEN) | ((y) << 3))

/// @public
/// @memberof Block
/// @brief Extracts the blue component of color value as a new color.
#define BLOCK_COLOR_BLUE(x)         ((x & BLOCK_COLOR_MASK_BLUE) >> 6)

/// @public
/// @memberof Block
/// @brief Sets the blue component of a color value.
#define BLOCK_COLOR_SET_BLUE(x, y)    x = ((x & ~BLOCK_COLOR_MASK_BLUE) | ((y) << 6))

#include <stdint.h>

#include "global.h"

/**
 * @class Block
 * @brief One Voxel block.
 */
typedef struct {
    /// @private
    /// @brief Color value and visibility.
    uint16_t data;
} Block;

/** 
 * @public
 * @memberof Block
 * @brief Whether the block is active (visible) or inactive (invisible).
 * @param [in] block Block to inspect.
 */
char block_is_active(Block* block);

/** 
 * @public
 * @memberof Block
 * @brief Gets the color value of a Block.
 * @param [in] block Block to inspect.
 */
uint16_t block_color(Block* block);

/** 
 * @public
 * @memberof Block
 * @brief Gets the components of a color value.
 * @param [in] color Block color value.
 * @param [out] components Three components (R, G, B) set to values between 0.0 and 255.0.
 */
void block_color_rgb(uint16_t color, float* components);

/** 
 * @public
 * @memberof Block
 * @brief Sets whether the block is active (visible) or inactive (invisible).
 * @param [in] block Block to modify.
 * @param [in] active 0 (false) or 1 (true).
 */
void block_set_active(Block* block, char active);

/** 
 * @public
 * @memberof Block
 * @brief Sets the color value of a Block.
 * @param [in] block Block to modify.
 * @param [in] color Color to set.
 */
void block_set_color(Block* block, uint16_t color);

#endif // BLOCK_H
