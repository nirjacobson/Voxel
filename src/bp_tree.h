/**
 * @file bp_tree.h
 * @author Nir Jacobson
 * @date 2026-04-23
 */

 #ifndef BP_TREE_H
#define BP_TREE_H

#include <stdio.h>
#include <string.h>

#ifndef _WIN32
#include <unistd.h>
#endif

#include "chunk.h"

#ifndef F_OK
#define F_OK    0
#endif

/**
 * @class BPTree
 * @brief B+ tree index for the save file.
 */
typedef struct {
    /// @private
    /// @brief The save file handle.
    FILE* file;
} BPTree;

/** 
 * @public
 * @memberof BPTree
 * @brief Initializes a BPTree.
 * @param [in] bt       BPTree to initialize. Can be NULL to allocate a new BPTree.
 * @param [in] name     Name of the save file sans file extension.
 * @return **bt** or a new BPTree if **bt** was NULL.
 */
BPTree* bp_tree_init(BPTree* bt, const char* name);

/** 
 * @public
 * @memberof BPTree
 * @brief   Destroys a BPTree.
 * @param [in] bt BPTree to destroy.
 */
void bp_tree_destroy(BPTree* bpTree);

/** 
 * @public
 * @memberof BPTree
 * @brief Inserts a block address value given a ChunkID key into the index.
 * @param [in] bpTree   BPTree to insert into.
 * @param [in] chunkID  The ChunkID (Cartesian location).
 * @param [in] value    The byte offset into the save file at which the Chunk referenced by **chunkID** is stored.
 */
void bp_tree_insert(BPTree* bpTree, ChunkID* key, unsigned long value);

/** 
 * @public
 * @memberof BPTree
 * @brief Retrieves a block address value given a ChunkID key from the index.
 * @param [in] bpTree       BPTree to retrieve from.
 * @param [in] chunkID      The ChunkID (Cartesian location).
 * @param [out] valuePtr    The byte offset into the save file at which the Chunk referenced by **chunkID** is stored.
 */
char bp_tree_find(BPTree* bpTree, ChunkID* key, unsigned long* valuePtr);

/** 
 * @public
 * @memberof BPTree
 * @brief Prints BPTree contents in JSON format to stdout.
 * @param [in] bpTree BPTree to print.
 */
void bp_tree_print(BPTree* bpTree);

#endif // BP_TREE_H
