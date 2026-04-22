#ifndef HEAP_INTERNAL_H
#define HEAP_INTERNAL_H

#include "../heap.h"

/**
 * @class HeapHeader
 * @brief Heap header.
 * @details HeapHeader and BPTreeHeader are read from the same page in the save file.
 */
typedef struct {
    /// @private
    /// @brief The byte offset to free space in the save file.
    unsigned long freeSpacePtr;
} HeapHeader;

/**
 * @class HeapEntry
 * @brief One Heap entry header.
 */
typedef struct {
    /// @private
    /// @brief The width of the Chunk in the entry.
    int width;

    /// @private
    /// @brief The height of the Chunk in the entry.
    int height;

    /// @private
    /// @brief The length of the Chunk in the entry.
    int length;
} HeapEntryHeader;

/** 
 * @private
 * @memberof Heap
 * @brief Internal method to initialize a new Heap if the save file does not exist yet.
 * @param [in] heap Heap to create.
 */
void heap_init_heap(Heap* heap);

/** 
 * @private
 * @memberof Heap
 * @brief Returns a HeapHeader reflecting the header of the save file.
 * @param [in] heap Heap to retrieve the header of.
 * @returns Save file header as a HeapHeader.
 */
HeapHeader heap_get_header(Heap* heap);

/** 
 * @private
 * @memberof Heap
 * @brief Sets a HeapHeader onto the header of the save file.
 * @param heap Heap to set the header of.
 * @param [in] header Heap header.
 */
void heap_set_header(Heap* heap, HeapHeader* header);

#endif // HEAP_INTERNAL_H
