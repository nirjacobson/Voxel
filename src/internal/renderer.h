/**
 * @file internal/renderer.h
 * @author Nir Jacobson
 * @date 2026-04-23
 */

#ifndef RENDERER_INTERNAL_H
#define RENDERER_INTERNAL_H

#include "../renderer.h"

#include "../ground.h"
#include "../chunk.h"
#include "../mesh.h"
#include "../panel.h"

/* OpenGL */

/// @private
/// @memberof Renderer
/// @name Private OpenGL functions
/// @{
/**
 *  @private
 *  @memberof Renderer
 *  @brief Updates the model matrix on the GPU.
 *  @param [in] renderer Voxel Renderer.
 *  @param [in] mat4     New model matrix.
 */
void renderer_3D_update_model(Renderer* renderer, float* mat4);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Updates the camera model-view matrix on the GPU.
 *  @param [in] renderer Voxel Renderer.
 *  @param [in] mat4     New model-view matrix.
 */
void renderer_3D_update_camera(Renderer* renderer, float* mat4);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Updates the projection matrix on the GPU.
 *  @param [in] renderer Voxel Renderer.
 *  @param [in] mat4     New projection matrix.
 */
void renderer_3D_update_projection(Renderer* renderer, float* mat4);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Updates the world location of a Block on the GPU.
 *  @param [in] renderer Voxel Renderer.
 *  @param [in] position (x, y, z) world location.
 */
void renderer_3D_update_world_position(Renderer* renderer, float* position);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Updates the Block color on the GPU.
 *  @param [in] renderer Voxel Renderer.
 *  @param [in] r        Red component of color. 0.0 - 255.0.
 *  @param [in] g        Green component of color. 0.0 - 255.0.
 *  @param [in] b        Blue component of color. 0.0 - 255.0.
 */
void renderer_3D_update_color(Renderer* renderer, float r, float g, float b);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Updates the degree of ambient light on the GPU.
 *  @param [in] renderer Voxel Renderer.
 *  @param [in] a        Ambient light degree.
 */
void renderer_3D_update_ambient(Renderer* renderer, float a);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Updates the world location of the sun on the GPU.
 *  @param [in] renderer Voxel Renderer.
 *  @param [in] position (x, y, z) world location.
 */
void renderer_3D_update_sun_position(Renderer* renderer, float* position);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Activates the 3D shader program.
 *  @param [in] renderer Voxel Renderer.
 */
void renderer_3D_use(Renderer* renderer);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Updates the projection matrix on the GPU.
 *  @param [in] renderer Voxel Renderer.
 *  @param [in] mat4     New projection matrix.
 */
void renderer_2D_update_projection(Renderer* renderer, float* mat4);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Updates the sampler number on the GPU.
 *  @param [in] renderer Voxel Renderer.
 *  @param [in] sampler  New sampler number.
 */
void renderer_2D_update_sampler(Renderer* renderer, GLint sampler);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Activates the 2D shader program.
 *  @param [in] renderer Voxel Renderer.
 */
void renderer_2D_use(Renderer* renderer);

/// @private
/// @memberof Renderer
/// @name Linked list processing callbacks
/// @{

/**
 *  @private
 *  @memberof Renderer
 *  @brief LinkedList processing callback for rendering \ref Mesh "Meshes" in a LinkedList (OpenGL).
 *  @param [in] ptr         Resolves to a Mesh.
 *  @param [in] rendererPtr Resolves to the Voxel Renderer.
 */
void render_mesh(void* ptr, void* rendererPtr);

/**
 *  @private
 *  @memberof Renderer
 *  @brief LinkedList processing callback for rendering \ref Chunk "Chunks" in a LinkedList (OpenGL).
 *  @param [in] worldChunkPtr Resolves to a Chunk.
 *  @param [in] rendererPtr   Resolves to the Voxel Renderer.
 */
void render_world_chunk(void* worldChunkPtr, void* rendererPtr);

/**
 *  @private
 *  @memberof Renderer
 *  @brief LinkedList processing callback for rendering \ref Panel "Panels" in a LinkedList (OpenGL).
 *  @param [in] panelPtr    Resolves to a Chunk.
 *  @param [in] rendererPtr Resolves to the Voxel Renderer.
 */
void render_panel(void* panelPtr, void* rendererPtr);

/** 
 * @private
 * @memberof Renderer
 * @brief LinkedList processing callback for recording a Mesh render to a %Vulkan command buffer.
 * @param [in] ptr         Resolves to a Mesh.
 * @param [in] rendererPtr Resolves to the Voxel Renderer.
 */
void record_mesh(void* ptr, void* rendererPtr);

/** 
 * @private
 * @memberof Renderer
 * @brief LinkedList processing callback for recording a WorldChunk render to a %Vulkan command buffer.
 * @param [in] ptr         Resolves to a WorldChunk.
 * @param [in] rendererPtr Resolves to the Voxel Renderer.
 */
void record_world_chunk(void* worldChunkPtr, void* rendererPtr);

/** 
 * @private
 * @memberof Renderer
 * @brief LinkedList processing callback for recording a Panel render to a %Vulkan command buffer.
 * @param [in] ptr         Resolves to a Panel.
 * @param [in] rendererPtr Resolves to the Voxel Renderer.
 */
void record_panel(void* panelPtr, void* rendererPtr);

/// @}

/**
 *  @private
 *  @memberof Renderer
 *  @brief Renders the Ground.
 *  @param [in] renderer Voxel Renderer.
 *  @param [in] ground   Voxel Ground.
 *  @param [in] camera   Voxel Camera.
 */
void renderer_render_ground(Renderer* renderer, Ground* ground, Camera* camera);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Renders a Mesh.
 *  @param [in] renderer Voxel Renderer.
 *  @param [in] mesh     Mesh to render.
 *  @param [in] mode     Fill mode. See \ref MeshFillModes.
 */
void renderer_render_mesh(Renderer* renderer, Mesh* mesh, char mode);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Renders a Chunk.
 *  @param [in] renderer Voxel Renderer.
 *  @param [in] chunk    Chunk to render.
 *  @param [in] position (x, y, z) world location of **chunk**.
 */
void renderer_render_chunk(Renderer* renderer, Chunk* chunk, float* position);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Renders a Panel.
 *  @param [in] renderer Voxel Renderer.
 *  @param [in] panel    Panel to render.
 */
void renderer_render_panel(Renderer* renderer, Panel* panel);
/// @}

/* Vulkan */

/**
 * @private
 * @memberof Renderer
 * @brief Pipeline3D camera/projection UBO structure.
 */
typedef struct {
    _Alignas(16) float camera[16];
    _Alignas(16) float projection[16];
} UniformBufferObject3D;

/**
 * @private
 * @memberof Renderer
 * @brief Pipeline3D push constants structure.
 */
typedef struct {
    _Alignas(16) float model[16];
    _Alignas(16) float worldPosition[3];
    _Alignas(16) float color[3];
    _Alignas(16) float sunPosition[3];
    _Alignas(16) float ambient;
} PushConstants3D;

/**
 * @private
 * @memberof Renderer
 * @brief Pipeline2D push constants structure.
 */
typedef struct {
    _Alignas(16) float projection[16];
} PushConstants2D;

/// @private
/// @memberof Renderer
/// @name Private Vulkan functions
/// @{

/**
 *  @private
 *  @memberof Renderer
 *  @brief Creates the descriptor set layout.
 *  @param [in]  renderer Voxel Renderer.
 *  @param [out] dsLayout Descriptor set layout.
 */
void renderer_3D_create_descriptor_set_layout(Renderer* renderer, VkDescriptorSetLayout* dsLayout);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Initializes the vertex input binding description.
 *  @param [out] description V%ertex input binding description.
 */
void renderer_3D_get_binding_description(VkVertexInputBindingDescription* description);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Initializes the vertex input attribute descriptions.
 *  @param [in]  renderer    Voxel Renderer.
 *  @param [out] description %Vertex input attribute descriptions.
 *  @param [out] count       The number of descriptions created.
 */
void renderer_3D_get_attribute_descriptions(VkVertexInputAttributeDescription** descriptions, int* count);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Creates the 3D pipeline.
 *  @param [in]  renderer    Voxel Renderer.
 */
void renderer_3D_create_pipeline(Renderer* renderer);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Creates the descriptor set layout.
 *  @param [in]  renderer Voxel Renderer.
 *  @param [out] dsLayout Descriptor set layout.
 */
void renderer_2D_create_descriptor_set_layout(Renderer* renderer, VkDescriptorSetLayout* dsLayout);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Initializes the vertex input binding description.
 *  @param [out] description Vertex input binding description.
 */
void renderer_2D_get_binding_description(VkVertexInputBindingDescription* description);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Initializes the vertex input attribute descriptions.
 *  @param [in]  renderer    Voxel Renderer.
 *  @param [out] description Vertex input attribute descriptions.
 *  @param [out] count       The number of descriptions created.
 */
void renderer_2D_get_attribute_descriptions(VkVertexInputAttributeDescription** descriptions, int* count);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Creates the 2D pipeline.
 *  @param [in]  renderer    Voxel Renderer.
 */
void renderer_2D_create_pipeline(Renderer* renderer);

/** 
 * @private
 * @memberof Renderer
 * @brief Sets up resources for the depth buffer.
 * @param [in]  renderer  Voxel Renderer.
 */
void renderer_setup_depth_resources(Renderer* renderer);

/** 
 * @private
 * @memberof Renderer
 * @brief Sets up the framebuffers.
 * @param [in]  renderer  Voxel Renderer.
 */
void renderer_setup_framebuffers(Renderer* renderer);

/** 
 * @private
 * @memberof Renderer
 * @brief Sets up the camera & projection uniform block resources.
 * @param [in]  renderer  Voxel Renderer.
 */
void renderer_3D_create_uniform_buffers(Renderer* renderer);

/** 
 *  @private
 *  @memberof Renderer
 *  @brief Initializes the descriptor pools.
 *  @param [in]  renderer    Voxel Renderer.
 */
void renderer_create_descriptor_pool(Renderer* renderer);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Initializes the 3D descriptor sets.
 *  @param [in]  renderer    Voxel Renderer.
 */
void renderer_3D_create_descriptor_sets(Renderer* renderer);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Initializes the 2D descriptor sets.
 *  @param [in]  renderer    Voxel Renderer.
 */
void renderer_2D_create_descriptor_sets(Renderer* renderer);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Initializes the command buffers.
 *  @param [in]  renderer    Voxel Renderer.
 */
void renderer_create_command_buffers(Renderer* renderer);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Creates semaphores necessary for thread synchronization.
 *  @param [in]  renderer    Voxel Renderer.
 */
void renderer_create_sync_objects(Renderer* renderer);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Recreates the swap chain. Useful after a window resize.
 *  @param [in]  renderer    Voxel Renderer.
 */
void renderer_recreate_swap_chain(Renderer* renderer);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Destroys the swap chain.
 *  @param [in]  renderer    Voxel Renderer.
 */
void renderer_cleanup_swap_chain(Renderer* renderer);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Updates the camera & projection uniform block.
 *  @param [in]  renderer    Voxel Renderer.
 *  @param [in]  camera      Voxel Camera.
 */
void renderer_3D_update_uniforms(Renderer* renderer, Camera* camera);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Records the command buffer used to render objects.
 *  @param [in]  renderer      Voxel Renderer.
 *  @param [in]  commandBuffer Vulkan command buffer.
 *  @param [in]  imageIndex    Swap chain image index.
 *  @param [in]  world         Voxel World.
 *  @param [in]  camera        Active Camera.
 *  @param [in]  picker        Voxel Picker.
 *  @param [in]  panels        PanelManager \ref Panel "Panels".
 */
void renderer_record_command_buffer(Renderer* renderer, VkCommandBuffer commandBuffer, uint32_t imageIndex, World* world, Camera* camera, Picker* picker, LinkedList* panels);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Records a Mesh render to the current command buffer.
 *  @param [in]  renderer      Voxel Renderer.
 *  @param [in]  mesh          Mesh to render.
 *  @param [in]  mode          Fill mode. See \ref MeshFillModes.
 */
void renderer_3D_record_mesh(Renderer* renderer, Mesh* mesh, char mode);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Records a Chunk render to the current command buffer.
 *  @param [in]  renderer      Voxel Renderer.
 *  @param [in]  position      %World location of **chunk**.
 */
void renderer_3D_record_chunk(Renderer* renderer, Chunk* chunk, float* position);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Records the Picker render to the current command buffer.
 *  @param [in]  renderer      Voxel Renderer.
 *  @param [in]  picker        Voxel Picker.
 */
void renderer_3D_record_picker(Renderer* renderer, Picker* picker);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Records the Ground render to the current command buffer.
 *  @param [in]  renderer      Voxel Renderer.
 *  @param [in]  ground        Voxel Ground.
 *  @param [in]  camera        Voxel Ground.
 */
void renderer_3D_record_ground(Renderer* renderer, Ground* ground, Camera* camera);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Records the World and 3D interface render to the current command buffer.
 *  @param [in]  renderer      Voxel Renderer.
 *  @param [in]  world         Voxel World.
 *  @param [in]  camera        Voxel Ground.
 *  @param [in]  picker        Voxel Picker.
 */
void renderer_3D_record(Renderer* renderer, World* world, Camera* camera, Picker* picker);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Records a Panel render to the current command buffer.
 *  @param [in]  renderer      Voxel Renderer.
 *  @param [in]  panel         Panel to render.
 */
void renderer_2D_record_panel(Renderer* renderer, Panel* panel);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Records the 2D interface render to the current command buffer.
 *  @param [in]  renderer      Voxel Renderer.
 *  @param [in]  panels        PanelManager Panels.
 */
void renderer_2D_record(Renderer* renderer, LinkedList* panels);
/// @}

#endif // RENDERER_INTERNAL_H
