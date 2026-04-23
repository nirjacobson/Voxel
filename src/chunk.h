#ifndef CHUNK_H
#define CHUNK_H

#include "block.h"
#include "mesh.h"
#include "linked_list.h"

/**
 * @class ChunkID
 * @brief The Cartesian location of a Chunk in the World.
 */
typedef struct {
    /// @private
    /// @brief The location along the x-axis.
    int x;

    /// @private
    /// @brief The location along the y-axis.
    int y;

    /// @private
    /// @brief The location along the z-axis.
    int z;
} ChunkID;

/**
 * @class Chunk
 * @brief One rectangular prism of mixed \ref Block "Blocks".
 */
typedef struct {
    /// @private
    /// @brief Global Vulkan object or NULL if using OpenGL.
    Vulkan* vulkan;

    /// @private
    /// @brief The \ref Block "Blocks".
    Block*** blocks;

    /// @private
    /// @brief Per-color \ref Mesh "Meshes".
    LinkedList meshes;

    /// @private
    /// @brief The width of the Chunk.
    int width;
    
    /// @private
    /// @brief The height of the Chunk.
    int height;
    
    /// @private
    /// @brief The length of the Chunk.
    int length;
    
    /// @private
    /// @brief Whether the Chunk has been modified in memory since being loaded from the save file.
    /// @details 1 if the Chunk has been modified, 0 otherwise.
    char dirty;
} Chunk;

/* Chunk */

/** 
 * @public
 * @memberof Chunk
 * @brief Initializes a Chunk.
 * @param [in] c        Chunk to initialize. Can be NULL to allocate a new Chunk.
 * @param [in] vulkan   Global Vulkan object. Set NULL when using OpenGL.
 * @param [in] width    The width of the Chunk in \ref Block "Blocks".
 * @param [in] height   The height of the Chunk in \ref Block "Blocks".
 * @param [in] length   The length of the Chunk in \ref Block "Blocks".
 * @return **c** or a new Chunk if **c** was NULL.
 */
Chunk* chunk_init(Chunk* c, Vulkan* vulkan, int width, int height, int length);

/** 
 * @public
 * @memberof Chunk
 * @brief Destroys a Chunk.
 * @param [in] chunk Chunk to destroy.
 */
void chunk_destroy(Chunk* chunk);


/** 
 * @public
 * @memberof Chunk
 * @brief (Re)generates the \ref Mesh "Meshes" for the Chunk.
 * @param [in] chunk Chunk to generate \ref Mesh "Meshes" for.
 */
void chunk_mesh(Chunk* chunk);

#endif // CHUNK_H
