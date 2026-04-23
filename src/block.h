/**
 * @file block.h
 * @author Nir Jacobson
 * @date 2026-04-23
 */

#ifndef BLOCK_H
#define BLOCK_H

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
 * @brief Whether the Block is active (visible) or inactive (invisible).
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
 * @brief Sets whether the Block is active (visible) or inactive (invisible).
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
