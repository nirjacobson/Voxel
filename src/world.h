/**
 * @file world.h
 * @author Nir Jacobson
 * @date 2026-04-23
 */

#ifndef WORLD_H
#define WORLD_H

/// @public
/// @memberof World
#define WORLD_CHUNK_LENGTH    16

#include <stdlib.h>

#include "box.h"
#include "camera.h"
#include "chunk.h"
#include "chunk_dao.h"
#include "linked_list.h"
#include "ground.h"

/**
 * @class WorldChunk
 * @brief A Chunk that serves as a division of the World.
 */
typedef struct {
    /// @private
    /// @brief (x, y, z) world location.
    ChunkID id;
    
    /// @private
    /// @brief The Chunk itself.
    Chunk* chunk;
} WorldChunk;

/**
 * @class World
 * @brief The world has a Ground and is divided into \ref WorldChunk "WorldChunks".
 */
typedef struct {
    /// @private
    /// @brief Global Vulkan object or NULL if using OpenGL.
    Vulkan* vulkan;

    /// @private
    /// @brief ChunkDAO singleton object.
    ChunkDAO chunkDAO;

    /// @private
    /// @brief \ref Chunk "Chunks" in memory.
    LinkedList chunks;

    /// @private
    /// @brief The Ground.
    Ground ground;
} World;

/** 
 * @public
 * @memberof World
 * @brief Initializes the World.
 * @param [in] world  World to initialize. Can be NULL to allocate a new World.
 * @param [in] vulkan Global Vulkan object. Set NULL when using OpenGL.
 * @param [in] name   Name of the save file sans file extension.
 * @param [out] new   Whether the World save file was created due to this function call or it already existed.
 * @return **world** or a new World if **world** was NULL.
 */
World* world_init(World* world, Vulkan* vulkan, const char* name, bool* new);

/** 
 * @public
 * @memberof World
 * @brief Destroys the World.
 * @param [in] world World to destroy.
 */
void world_destroy(World* world);

/** 
 * @public
 * @memberof World
 * @brief Gets the Block at an (x, y, z) location.
 * @param [in] world    Voxel World.
 * @param [in] location (x, y, z) Block location.
 * @returns Block found or NULL if not found.
 */
Block* world_get_block(World* world, int* location);

/** 
 *  @brief Set the visibility of a Block at a given location.
 *  @param [in] world    Voxel World.
 *  @param [in] location (x, y, z) Block location.
 *  @param [in] active   Active (1) or inactive (0).
 */
void world_block_set_active(World* world, int* location, char active);

/** 
 *  @brief Set the color of a Block at a given location.
 *  @param [in] world    Voxel World.
 *  @param [in] location (x, y, z) Block location.
 *  @param [in] color    9-bit color.
 */
void world_block_set_color(World* world, int* location, uint16_t color);

/** 
 *  @brief Copies a volume of \ref Block Blocks into a new Chunk.
 *  @param [in] world Voxel World.
 *  @param [in] box   Defines the volume of \ref Block Blocks.
 *  @return New Chunk containing the same \ref Block Blocks as in **box**.
 */
Chunk* world_copy_chunk(World* world, Box* box);

/** 
 *  @brief Copies a volume of \ref Block Blocks into a new Chunk, \
 *         and then removes the original ref Block Blocks from the World.
 *  @param [in] world Voxel World.
 *  @param [in] box   Defines the volume of \ref Block Blocks.
 *  @return New Chunk containing the same \ref Block Blocks as in **box**.
 */
Chunk* world_cut_chunk(World* world, Box* box);

/** 
 *  @brief Places a Chunk in the World at a given location, over any \ref Block Blocks that are already there.
 *  @param [in] world    Voxel World.
 *  @param [in] chunk    Chunk to place.
 *  @param [in] location (x, y, z) location of placement.
 *  @param [in] rotation Rotation to perform on **chunk** before placement. See implementation for details.
 */
void world_set_chunk(World* world, Chunk* chunk, int* location, int rotation);

/** 
 *  @brief Clears (deactivates) a volume of \ref Block Blocks in the world.
 *  @param [in] world Voxel World.
 *  @param [in] box   Defines the volume of \ref Block Blocks.
 */
void world_clear_region(World* world, Box* region);

/** 
 *  @brief Updates the list of \ref WorldChunk WorldChunks based on what is visible as determined by \
 *         the properties of the Camera.
 *  @param [in] world  Voxel World.
 *  @param [in] camera Active Voxel Camera.
 */
void world_update(World* world, Camera* camera);

#endif // WORLD_H
