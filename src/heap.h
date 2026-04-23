/**
 * @file heap.h
 * @author Nir Jacobson
 * @date 2026-04-23
 */

 #ifndef HEAP_H
#define HEAP_H

#include <stdio.h>

#ifndef _WIN32
#include <unistd.h>
#endif

#include "chunk.h"

#ifndef F_OK
#define F_OK    0
#endif

/**
 * @class Heap
 * @brief The save file heap used for Chunk storage.
 */
typedef struct {
    /// @private
    /// @brief The save file handle.
    FILE* file;
} Heap;

/** 
 * @public
 * @memberof Heap
 * @brief Initializes a Heap.
 * @param [in]  h        Heap to initialize. Can be NULL to allocate a new Heap.
 * @param [in]  name     Name of the save file sans file extension.
 * @param [out] new      True if the save file did not exist at time of invokation.
 * @return **bt** or a new BPTree if **bt** was NULL.
 */
Heap* heap_init(Heap* h, const char* name, bool* new);

/** 
 * @public
 * @memberof Heap
 * @brief Destroys a Heap.
 * @param [in] chunkDAO Heap to destroy.
 */
void heap_destroy(Heap* heap);

/** 
 * @public
 * @memberof Heap
 * @brief Inserts a Chunk into the Heap.
 * @param [in] heap  Heap to insert into.
 * @param [in] chunk The Chunk to insert.
 * @returns The byte address of the Chunk in the save file.
 */
unsigned long heap_insert(Heap* heap, Chunk* chunk);

/** 
 * @public
 * @memberof Heap
 * @brief Writes a Chunk into the Heap.
 * @param [in] heap  Heap to insert into.
 * @param [in] address The byte address of the Chunk in the save file.
 * @param [in] chunk The Chunk to insert.
 */
void heap_write(Heap* heap, unsigned long address, Chunk* chunk);

/** 
 * @public
 * @memberof Heap
 * @brief Returns a Chunk from the Heap.
 * @param [in] heap  Heap to retrieve from.
 * @param [in] address The byte address of the Chunk in the save file.
 * @returns The Chunk in the Heap.
 */
Chunk* heap_get(Heap* heap, unsigned long address);

#endif // HEAP_H
