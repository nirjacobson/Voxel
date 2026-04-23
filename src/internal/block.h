/**
 * @file internal/block.h
 * @author Nir Jacobson
 * @date 2026-04-23
 */

 #ifndef BLOCK_INTERNAL_H
#define BLOCK_INTERNAL_H

#include "../block.h"

/// @name Block value macros
/// @{

/// @private
/// @memberof Block
/// @brief Bitmask to extract red component of color value.
#define BLOCK_COLOR_MASK_RED        (((1 << 3) - 1) << 0)

/// @private
/// @memberof Block
/// @brief Bitmask to extract green component of color value.
#define BLOCK_COLOR_MASK_GREEN      (((1 << 3) - 1) << 3)

/// @private
/// @memberof Block
/// @brief Bitmask to extract blue component of color value.
#define BLOCK_COLOR_MASK_BLUE       (((1 << 3) - 1) << 6)

/// @private
/// @memberof Block
/// @brief Extracts red component of color value as a new color.
#define BLOCK_COLOR_RED(x)          ((x & BLOCK_COLOR_MASK_RED) >> 0)

/// @private
/// @memberof Block
/// @brief Sets the red component of a color value.
#define BLOCK_COLOR_SET_RED(x, y)     x = ((x & ~BLOCK_COLOR_MASK_RED) | ((y) << 0))

/// @private
/// @memberof Block
/// @brief Extracts green component of color value as a new color.
#define BLOCK_COLOR_GREEN(x)        ((x & BLOCK_COLOR_MASK_GREEN) >> 3)

/// @private
/// @memberof Block
/// @brief Sets the green component of a color value.
#define BLOCK_COLOR_SET_GREEN(x, y)   x = ((x & ~BLOCK_COLOR_MASK_GREEN) | ((y) << 3))

/// @private
/// @memberof Block
/// @brief Extracts the blue component of color value as a new color.
#define BLOCK_COLOR_BLUE(x)         ((x & BLOCK_COLOR_MASK_BLUE) >> 6)

/// @private
/// @memberof Block
/// @brief Sets the blue component of a color value.
#define BLOCK_COLOR_SET_BLUE(x, y)    x = ((x & ~BLOCK_COLOR_MASK_BLUE) | ((y) << 6))

/// @private
/// @memberof Block
/// @brief Bitmask to extract the color from a \ref Block "Block's" 16-bit value.
#define BLOCK_COLOR_MASK        ((1 << BLOCK_ACTIVE_BIT) - 1)

/// @private
/// @memberof Block
/// @brief Bitmask to extract the activity from a \ref Block "Block's" 16-bit value.
#define BLOCK_ACTIVE_MASK       (1 << BLOCK_ACTIVE_BIT)

/// @private
/// @memberof Block
/// @brief Returns the activity of a Block (active if positive, zero otherwise).
#define BLOCK_ACTIVE(x)         (x & BLOCK_ACTIVE_MASK)

/// @private
/// @memberof Block
/// @brief Returns the 9-bit color of a Block.
#define BLOCK_COLOR(x)          (x & BLOCK_COLOR_MASK)

/// @}

/// @private
/// @memberof Block
/// @brief Bit number of the active flag in a \ref Block "Block's" 16-bit value.
#define BLOCK_ACTIVE_BIT        9

#endif // BLOCK_INTERNAL_H
