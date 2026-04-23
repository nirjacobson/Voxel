/**
 * @file renderer.h
 * @author Nir Jacobson
 * @date 2026-04-23
 */

#ifndef RENDERER_H
#define RENDERER_H

#include <math.h>
#include <gio/gio.h>
#include <GL/glew.h>

#include "shader.h"
#include "matrix.h"

#include "camera.h"
#include "world.h"
#include "picker.h"
#include "window.h"

#include "vulkan_util.h"

/**
 * @class Pipeline3D
 * @brief Encapsulates the state of the 3D %Vulkan pipeline.
 */
typedef struct {
    /// @private
    /// @brief Solid fill pipeline
    Pipeline pipeline;

    /// @private
    /// @brief Wireframe pipeline
    Pipeline pipelineLine;

    /// @name Camera & projection matrix uniform block
    /// @{

    /// @private
    /// @brief GPU-side buffers.
    VkBuffer* mcpBuffers;

    /// @private
    /// @brief GPU-side device memory
    VkDeviceMemory* mcpBuffersMemory;

    /// @private
    /// @brief Mapped buffers
    void** mcpBuffersMapped;
    /// @}

    /// @private
    /// @brief Descriptor sets.
    VkDescriptorSet* descriptorSets;
} Pipeline3D;

/**
 * @class Pipeline2D
 * @brief Encapsulates the state of the 2D %Vulkan pipeline.
 */
typedef struct {
    /// @private
    /// @brief Pipeline
    Pipeline pipeline;

    /// @private
    /// @brief Texture sampler.
    VkSampler sampler;
} Pipeline2D;

/**
 * @class RendererRenderStateOpenGL
 * @brief Renderer render state (OpenGL).
 */
typedef struct {
    /// @private
    /// @brief 3D shader program.
    ShaderProgram3D shaderProgram3D;

    /// @private
    /// @brief 2D shader program.
    ShaderProgram2D shaderProgram2D;
} RendererRenderStateOpenGL;

/**
 * @class RendererRenderStateVulkan
 * @brief Renderer render state (%Vulkan).
 */
typedef struct {
    /// @private
    /// @brief 3D pipeline.
    Pipeline3D pipeline3D;

    /// @private
    /// @brief 2D pipeline.
    Pipeline2D pipeline2D;

    /// @private
    /// @name General Vulkan state
    /// @{
    VkQueue graphicsQueue;
    VkQueue presentQueue;
    SwapChain swapChain;
    VkRenderPass renderPass;
    VkImage depthImage;
    VkDeviceMemory depthImageMemory;
    VkImageView depthImageView;
    VkDescriptorPool descriptorPool;
    VkCommandBuffer* commandBuffers;
    VkSemaphore* imageAvailableSemaphores;
    VkSemaphore* renderFinishedSemaphores;
    VkFence* inFlightFences;
    /// @}

    /// @private
    /// @brief The current frame out of \ref MAX_FRAMES_IN_FLIGHT.
    uint32_t currentFrame;

    /// @private
    /// @brief Whether the window has been resized.
    /// @details When the window is resized, the swap chain has to be recreated.
    bool framebufferResized;
} RendererRenderStateVulkan;

/**
 * @class Renderer
 * @brief Voxel Renderer.
 */
typedef struct {
    /// @private
    /// @brief Voxel Window.
    Window* window;

    /// @private
    /// @brief %Global Vulkan object or NULL if using OpenGL.
    Vulkan* vulkan;

    /// @private
    /// @brief Renderer render state.
    union {
        /// @private
        /// @brief OpenGL render state.
        RendererRenderStateOpenGL opengl;

        /// @private
        /// @brief %Vulkan render state.
        RendererRenderStateVulkan vulkan;
    } renderState;
    
} Renderer;

/** 
 * @public
 * @memberof Renderer
 * @brief Initializes the Renderer.
 * @param [in] r      Renderer to initialize. Can be NULL to allocate a new Renderer.
 * @param [in] window Voxel Window.
 * @param [in] vulkan %Global Vulkan object. Set NULL when using OpenGL.
 * @return **r** or a new Renderer if **r** was NULL.
 */
Renderer* renderer_init(Renderer* r, Window* window, Vulkan* vulkan);

/** 
 * @public
 * @memberof Renderer
 * @brief Destroys the Renderer.
 * @param [in] renderer Renderer to destroy.
 */
void renderer_destroy(Renderer* renderer);

/* OpenGL */

/// @public
/// @memberof Renderer
/// @name OpenGL functions
/// @{

/**
 * @public
 * @memberof Renderer
 * @brief Clears the screen.
 * @param [in] renderer Voxel Renderer.
 */
void renderer_clear(Renderer* renderer);

/**
 * @public
 * @memberof Renderer
 * @brief Handles window resize.
 * @param [in] renderer Voxel Renderer.
 * @param [in] width    The new window width.
 * @param [in] height   The new window height.
 * @param [in] camera   Active Voxel Camera.
 */
void renderer_resize(Renderer* renderer, int width, int height, Camera* camera);

/**
 * @public
 * @memberof Renderer
 * @brief Applies the Camera properties to the 3D render.
 * @param [in] renderer Voxel Renderer.
 * @param [in] camera   Active Voxel Camera.
 */
void renderer_apply_camera(Renderer* renderer, Camera* camera);

/**
 * @public
 * @memberof Renderer
 * @brief Renders everything in the World.
 * @param [in] renderer Voxel Renderer.
 * @param [in] world    Voxel World.
 * @param [in] camera   Active Voxel Camera.
 */
void renderer_render_world(Renderer* renderer, World* world, Camera* camera);

/**
 * @public
 * @memberof Renderer
 * @brief Renders the Picker.
 * @param [in] renderer Voxel Renderer.
 * @param [in] picker   Voxel Picker.
 */
void renderer_render_picker(Renderer* renderer, Picker* picker);

/**
 * @public
 * @memberof Renderer
 * @brief Renders the \ref Panel "Panels".
 * @param [in] renderer Voxel Renderer.
 * @param [in] panels   PanelManager \ref Panel "Panels".
 */
void renderer_render_panels(Renderer* renderer, LinkedList* panels);
/// @}

/* Vulkan */

/// @public
/// @memberof Renderer
/// @name Vulkan functions
/// @{
/**
 * @public
 * @memberof Renderer
 * @brief Handles window resize.
 * @param [in] renderer Voxel Renderer.
 */
void renderer_vulkan_resize(Renderer* renderer);

/**
 * @public
 * @memberof Renderer
 * @brief Renders everything.
 * @param [in] renderer Voxel Renderer.
 * @param [in] world    Voxel World.
 * @param [in] camera   Active Voxel Camera.
 * @param [in] picker   Voxel Picker.
 * @param [in] panels   PanelManager \ref Panel "Panels".
 */
void renderer_vulkan_render(Renderer* renderer, World* world, Camera* camera, Picker* picker, LinkedList* panels);

/**
 * @public
 * @memberof Renderer
 * @brief Creates required descriptor sets.
 * @param [in]  renderer       Voxel Renderer.
 * @param [in]  imageView      Image view to set on a descriptor set.
 * @param [out] descriptorSets The generated descriptor sets.
 */
void renderer_create_descriptor_sets(Renderer* renderer, VkImageView imageView, VkDescriptorSet** descriptorSets);
/// @}

#endif // RENDERER_H
