/**
 * @file internal/world.h
 * @author Nir Jacobson
 * @date 2026-04-23
 */

#ifndef WORLD_INTERNAL_H
#define WORLD_INTERNAL_H

#include "../world.h"

/* Linked list processing callbacks */

/// @private
/// @memberof World
/// @name LinkedList processing callbacks
/// @{

/**
 * @private
 * @memberof World
 * @brief Loads a WorldChunk with the given ChunkID into the World.
 * @param [in] chunkIDPtr Resolves to a ChunkID.
 * @param [in] worldPtr   Resolves to the World.
 */
void load_world_chunk(void* chunkIDPtr, void* worldPtr);

/**
 * @private
 * @memberof World
 * @brief Unloads a WorldChunk from the World, saving it back to the file if necessary.
 * @param [in] worldChunkPtr Resolves to a WorldChunk.
 * @param [in] worldPtr      Resolves to the World.
 */
void unload_world_chunk(void* worldChunkPtr, void* worldPtr);

/**
 * @private
 * @memberof World
 * @brief Determines whether a ChunkID matches a WorldChunk.
 * @param [in] chunkIDPtr    Resolves to a ChunkID.
 * @param [in] worldChunkPtr Resolves to a WorldChunk.
 * @returns 1 if it matches, 0 otherwise.
 */
char chunk_id_equals_world_chunk(void* chunkIDPtr, void* worldChunkPtr);

/**
 * @private
 * @memberof World
 * @brief Destroys a WorldChunk.
 * @param [in] worldChunkPtr Resolves to a WorldChunk.
 */
void destroy_world_chunk(void* worldChunkPtr);

/**
 * @private
 * @memberof World
 * @brief Compares two \ref ChunkID ChunkIDs.
 * @param [in] chunkIDA 1st ChunkID.
 * @param [in] chunkIDB 2nd ChunkID.
 * @returns the sign of chunkIDA - chunkIDB.
 */
int compare_chunk_ids(ChunkID* chunkIDA, ChunkID* chunkIDB);

/**
 * @private
 * @memberof World
 * @brief Compares two \ref WorldChunk WorldChunks.
 * @param [in] worldChunkAPtr Resolves to 1st WorldChunk.
 * @param [in] worldChunkBPtr Resolves 2nd WorldChunk.
 * @returns the sign of worldChunkA - worldChunkB.
 */
int compare_world_chunks(void* worldChunkAPtr, void* worldChunkBPtr);
/// @}

/* World */

Chunk* world_load_world_chunk(World* world, ChunkID* chunkID);
void world_unload_world_chunk(World* world, WorldChunk* worldChunk);

LinkedList* world_draw_list(LinkedList* list, Camera* camera);

#endif // WORLD_INTERNAL_H
