/**
 * @file shader.h
 * @author Nir Jacobson
 * @date 2026-04-23
 */

#ifndef SHADER_H
#define SHADER_H

#include <stdio.h>

#include <gio/gio.h>

#include <GL/glew.h>

#include "global.h"

/// @defgroup Shader Shader
/// @{

/**
 * @class Shader
 * @brief General shader functions.
 */
typedef struct {

} Shader;

/* ShaderProgram3D */

/**
 * @class ShaderProgram3D
 * @brief Encapsulates the OpenGL state for the 3D shader program.
 */
typedef struct {
    /// @private
    /// @brief Handler to the vertex shader.
    GLuint shader_vert;

    /// @private
    /// @brief Handler to the fragment shader.
    GLuint shader_frag;

    /// @private
    /// @brief Handler to the shader program.
    GLuint shader_prog;

    /// @private
    /// @brief Handler to the position vertex attribute.
    GLint attrib_position;

    /// @private
    /// @brief Handler to the normal vertex attribute.
    GLint attrib_normal;

    /// @private
    /// @brief Handler to the world position uniform.
    GLint unifrm_world_position;

    /// @private
    /// @brief Handler to the model matrix uniform.
    GLint unifrm_model;

    /// @private
    /// @brief Handler to the camera model-view matrix uniform.
    GLint unifrm_camera;

    /// @private
    /// @brief Handler to the projection matrix uniform.
    GLint unifrm_projection;

    /// @private
    /// @brief Handler to the Block color uniform.
    GLint unifrm_color;

    /// @private
    /// @brief Handler to the ambient degree uniform.
    GLint unifrm_ambient;

    /// @private
    /// @brief Handler to the sun position uniform.
    GLint unifrm_sun_position;
} ShaderProgram3D;

/** 
 * @public
 * @memberof ShaderProgram3D
 * @brief Initializes the ShaderProgram3D.
 * @param [in] s      ShaderProgram3D to initialize. Can be NULL to allocate a new ShaderProgram3D.
 * @return **s** or a new ShaderProgram3D if **s** was NULL.
 */
ShaderProgram3D* shader_program_3D_init(ShaderProgram3D* s);

/** 
 * @public
 * @memberof ShaderProgram3D
 * @brief Destroys the ShaderProgram3D.
 * @param [in] shaderProgram3D Renderer ShaderProgram3D.
 */
void shader_program_3D_destroy(ShaderProgram3D* shaderProgram3D);

/** 
 * @public
 * @memberof ShaderProgram3D
 * @brief Updates the Block world location uniform.
 * @param [in] shaderProgram3D Renderer ShaderProgram3D.
 * @param [in] position (x, y, z) world location.
 */
void shader_program_3D_update_world_position(ShaderProgram3D* shaderProgram3D, float* position);

/** 
 * @public
 * @memberof ShaderProgram3D
 * @brief Updates the model matrix uniform.
 * @param [in] shaderProgram3D Renderer ShaderProgram3D.
 * @param [in] mat4            New model matrix.
 */
void shader_program_3D_update_model(ShaderProgram3D* shaderProgram3D, float* mat4);

/** 
 * @public
 * @memberof ShaderProgram3D
 * @brief Updates the Camera model-view matrix uniform.
 * @param [in] shaderProgram3D Renderer ShaderProgram3D.
 * @param [in] mat4            New model matrix.
 */
void shader_program_3D_update_camera(ShaderProgram3D* shaderProgram3D, float* mat4);

/** 
 * @public
 * @memberof ShaderProgram3D
 * @brief Updates the projection matrix uniform.
 * @param [in] shaderProgram3D Renderer ShaderProgram3D.
 * @param [in] mat4            New projection matrix.
 */
void shader_program_3D_update_projection(ShaderProgram3D* shaderProgram3D, float* mat4);

/** 
 * @public
 * @memberof ShaderProgram3D
 * @brief Updates the Block color uniform.
 * @param [in] shaderProgram3D Renderer ShaderProgram3D.
 * @param [in] r               Red component of color. 0.0 - 255.0.
 * @param [in] g               Green component of color. 0.0 - 255.0.
 * @param [in] b               Blue component of color. 0.0 - 255.0.
 */
void shader_program_3D_update_color(ShaderProgram3D* shaderProgram3D, float r, float g, float b);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Updates the ambient light degree uniform.
 *  @param [in] renderer Voxel Renderer.
 *  @param [in] a        Ambient light degree.
 */
void shader_program_3D_update_ambient(ShaderProgram3D* shaderProgram3D, float a);

/** 
 * @public
 * @memberof ShaderProgram3D
 * @brief Updates the sun world location uniform.
 * @param [in] shaderProgram3D Renderer ShaderProgram3D.
 * @param [in] position (x, y, z) world location.
 */
void shader_program_3D_update_sun_position(ShaderProgram3D* shaderProgram3D, float* position);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Activates the 3D shader program.
 *  @param [in] shaderProgram3D Renderer ShaderProgram3D.
 */
void shader_program_3D_use(ShaderProgram3D* shaderProgram3D);

/* ShaderProgram2D */

/**
 * @class ShaderProgram2D
 * @brief Encapsulates the OpenGL state for the 2D shader program.
 */
typedef struct {
    /// @private
    /// @brief Handler to the vertex shader.
    GLuint shader_vert;

    /// @private
    /// @brief Handler to the fragment shader.
    GLuint shader_frag;

    /// @private
    /// @brief Handler to the shader program.
    GLuint shader_prog;

    /// @private
    /// @brief Handler to the position vertex attribute.
    GLint attrib_position;

    /// @private
    /// @brief Handler to the texture coordinates vertex attribute.
    GLint attrib_texcoord;

    /// @private
    /// @brief Handler to the projection matrix uniform.
    GLint unifrm_projection;

    /// @private
    /// @brief Handler to the sampler uniform.
    GLint unifrm_sampler;
} ShaderProgram2D;

/** 
 * @public
 * @memberof ShaderProgram2D
 * @brief Initializes the ShaderProgram2D.
 * @param [in] s      ShaderProgram2D to initialize. Can be NULL to allocate a new ShaderProgram2D.
 * @return **s** or a new ShaderProgram2D if **s** was NULL.
 */
ShaderProgram2D* shader_program_2D_init(ShaderProgram2D* s);

/** 
 * @public
 * @memberof ShaderProgram2D
 * @brief Destroys the ShaderProgram2D.
 * @param [in] shaderProgram2D Renderer ShaderProgram2D.
 */
void shader_program_2D_destroy(ShaderProgram2D* shaderProgram2D);

/** 
 * @public
 * @memberof ShaderProgram2D
 * @brief Updates the projection matrix uniform.
 * @param [in] shaderProgram2D Renderer ShaderProgram2D.
 * @param [in] mat4            New projection matrix.
 */
void shader_program_2D_update_projection(ShaderProgram2D* shaderProgram2D, float* mat4);

/** 
 * @public
 * @memberof ShaderProgram2D
 * @brief Updates the sampler uniform.
 * @param [in] shaderProgram2D Renderer ShaderProgram2D.
 * @param [in] sampler         New sampler.
 */
void shader_program_2D_update_sampler(ShaderProgram2D* shaderProgram2D, GLint sampler);

/**
 *  @private
 *  @memberof Renderer
 *  @brief Activates the 2D shader program.
 * @param [in] shaderProgram2D Renderer ShaderProgram2D.
 */
void shader_program_2D_use(ShaderProgram2D* shaderProgram2D);

/// @}
#endif // SHADER_H
