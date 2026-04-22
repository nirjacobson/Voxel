#ifndef CHUNK_DAO_H
#define CHUNK_DAO_H

#include "bp_tree.h"
#include "heap.h"

/**
 * @class ChunkDAO
 * @brief Data Access Object for the save file.
 */
typedef struct {
    /// @private
    /// @brief The save file B+ tree index.
    BPTree bptree;

    /// @private
    /// @brief The chunk Heap.
    Heap heap;
} ChunkDAO;

/** 
 * @public
 * @memberof ChunkDAO
 * @brief Initializes the ChunkDAO.
 * @param [in] cd        ChunkDAO to initialize. Can be NULL to allocate a new ChunkDAO.
 * @param [in] worldName Name of the save file sans file extension.
 * @param [out] new      True if the save file did not exist at time of invokation.
 * @return **cd** or a new ChunkDAO if **cd** was NULL.
 */
ChunkDAO* chunk_dao_init(ChunkDAO* cd, const char* worldName, bool* new);

/** 
 * @public
 * @memberof ChunkDAO
 * @brief Destroys a ChunkDAO.
 * @param [in] chunkDAO ChunkDAO to destroy.
 */
void chunk_dao_destroy(ChunkDAO* chunkDAO);

/** 
 * @public
 * @memberof ChunkDAO
 * @brief Saves a Chunk at a location to the save file.
 * @param [in] chunkDAO ChunkDAO for the save file.
 * @param [in] chunkID  The world location of the Chunk.
 * @param [in] chunk    The Chunk to save.
 */
void chunk_dao_save(ChunkDAO* chunkDAO, ChunkID* chunkID, Chunk* chunk);

/** 
 * @public
 * @memberof ChunkDAO
 * @brief Loads a Chunk at a location from the save file.
 * @param [in] chunkDAO ChunkDAO for the save file.
 * @param [in] chunkID  The world location of the Chunk.
 * @returns The Chunk in the save file.
 */
Chunk* chunk_dao_load(ChunkDAO* chunkDAO, ChunkID* chunkID);

#endif // CHUNK_DAO_H
