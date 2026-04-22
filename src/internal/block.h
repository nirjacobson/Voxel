#ifndef BLOCK_INTERNAL_H
#define BLOCK_INTERNAL_H

#include "../block.h"

/// @private
/// @memberof Block
/// @brief Bit number of the active flag in a \ref Block "Block's" 16-bit value.
#define BLOCK_ACTIVE_BIT        9

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

#endif // BLOCK_INTERNAL_H
