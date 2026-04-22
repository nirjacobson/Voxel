#ifndef CHUNK_INTERNAL_H
#define CHUNK_INTERNAL_H

#include "../chunk.h"

/* Linked list processing callbacks */


/** 
 * @private
 * @memberof Chunk
 * @brief Linked list processing callback to destroy one Mesh in the list of \ref Mesh "Meshes".
 * @param [in] ptr Resolves to a Mesh in the list of \ref Mesh "Meshes".
 */
void destroy_mesh(void* ptr);

/** 
 * @private
 * @memberof Chunk
 * @brief LinkedList processing callback to determine whether two Meshes have the same color.
 * @param [in] ptrA Resolves to a Mesh in the list of \ref Mesh "Meshes".
 * @param [in] ptrB Resolves to a Mesh in the list of \ref Mesh "Meshes".
 */
char meshes_are_equal(void* ptrA, void* ptrB);

/** 
 * @private
 * @memberof Chunk
 * @brief LinkedList processing callback to prepare one Mesh in the list of \ref Mesh "Meshes" for rendering.
 * @param [in] node Resolves to a Mesh in the list of \ref Mesh "Meshes".
 * @param [in] userData Unused but required by the LinkedList processor.
 */
void prepare_mesh(void* node, void* userData);

#endif // CHUNK_INTERNAL_H
