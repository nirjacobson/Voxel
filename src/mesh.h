#ifndef MESH_H
#define MESH_H

#include <stdlib.h>
#include <stdint.h>

#include "global.h"
#include "linked_list.h"
#include "vulkan_util.h"

/// @memberof Quad
/// @defgroup DirectionalEnumerationConstants Directional enumeration constants
/// @{
#define NORTH           0
#define SOUTH           1
#define WEST            2
#define EAST            3
#define TOP             4
#define BOTTOM          5
/// @}

/// @memberof Mesh
/// @defgroup MeshFillModes Mesh fill modes
/// @{
#define MESH_FILL       1
#define MESH_LINE       2
/// @}

/**
 * @class Vertex
 * @brief A vertex has a Cartesian location and a 3D orientation.
 */
typedef struct {
    /// @private
    /// @brief Cartesian location
    float position[3];

    /// @private
    /// @brief 3D orientation.
    float normal_v[3];
} Vertex;

/**
 * @class Quad
 * @brief A quad has four vertices and a direction.
 */
typedef struct {
    /// @private
    /// @brief Four vertices.
    Vertex vertices[4];

    /// @private
    /// @brief The direction. See \ref DirectionalEnumerationConstants.
    char orientation;
} Quad;

/**
 * @class MeshRenderStateOpenGL
 * @brief Mesh render state (OpenGL).
 */
typedef struct {
    /// @private
    /// @brief Vertex buffer object (VBO).
    GLuint vbo;

    /// @private
    /// @brief Element buffer object (EBO).
    GLuint ebo;
} MeshRenderStateOpenGL;

/**
 * @class MeshRenderStateVulkan
 * @brief Mesh render state (Vulkan).
 */
typedef struct {
    /// @private
    /// @brief Vertex buffer object (VBO).
    VkBuffer vbo;

    /// @private
    /// @brief VBO device memory.
    VkDeviceMemory vboDeviceMemory;

    /// @private
    /// @brief Element buffer object (EBO).
    VkBuffer ebo;

    /// @private
    /// @brief EBO device memory.
    VkDeviceMemory eboDeviceMemory;

    /// @private
    /// @brief Whether the VBO and EBO have been acquired.
    bool haveBuffers;
} MeshRenderStateVulkan;

/**
 * @class Mesh
 * @brief The render object for a set of Quads that share a color.
 * @details Contains the Quads and render state necessary to render them.
 */
typedef struct {
    /// @private
    /// @brief Global Vulkan object or NULL if using OpenGL.
    Vulkan* vulkan;

    /// @private
    /// @brief 9-bit color.
    uint16_t color;

    /// @brief Mesh Quads.
    LinkedList quads;

    /// @private
    /// @brief Mesh render state.
    union {
        /// @private
        /// @brief OpenGL render state.
        MeshRenderStateOpenGL opengl;

        /// @private
        /// @brief Vulkan render state.
        MeshRenderStateVulkan vulkan;
    } renderState;
} Mesh;

/** 
 * @public
 * @memberof Mesh
 * @brief Initializes a Mesh.
 * @param [in] m      Mesh to initialize. Can be NULL to allocate a new Mesh.
 * @param [in] vulkan Global Vulkan object. Set NULL when using OpenGL.
 * @return **m** or a new Mesh if **m** was NULL.
 */
Mesh* mesh_init(Mesh* m, Vulkan* vulkan);

/** 
 * @public
 * @memberof Mesh
 * @brief Destroys a Mesh.
 * @param [in] mesh Mesh to destroy.
 */
void mesh_destroy(Mesh* mesh);

/** 
 * @public
 * @memberof Mesh
 * @brief Adds a Quad to a Mesh.
 * @param [in] mesh Mesh to add to.
 * @param [in] mesh Quad to add.
 */
void mesh_add_quad(Mesh* mesh, Quad* quad);


/** 
 * @public
 * @memberof Mesh
 * @brief (Re)calculates the normals of each Vertex of each Quad.
 * @param [in] mesh Mesh to calculate the normals of.
 */
void mesh_calc_normals(Mesh* mesh);

/** 
 * @public
 * @memberof Mesh
 * @brief Generates vertex buffers on the GPU and fills them.
 * @param [in] mesh Mesh to calculate the normals of.
 * @param [in] mode Whether the mesh is rendered solid or wireframe. See \ref MeshFillModes.
 */
void mesh_buffer(Mesh* mesh, char mode);

#endif // MESH_H
