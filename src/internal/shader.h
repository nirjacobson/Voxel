#ifndef SHADER_INTERNAL_H
#define SHADER_INTERNAL_H

#include <stdio.h>
#include <stdlib.h>

#include "../shader.h"

/**
 *  @private
 *  @memberof Shader
 *  @brief Creates a shader on the GPU from a GLSL source file.
 *  @param [in] path        Path to the shader GLSL source file.
 *  @param [in] shaderType  Can be GL_VERTEX_SHADER or GL_FRAGMENT_SHADER.
 *  @return Handle to the shader.
 */
GLuint shader_create(const char* path, GLenum shaderType);

/**
 *  @private
 *  @memberof Shader
 *  @brief Creates a shader program on the GPU from shader handles.
 *  @param [in] vertex_shader    Handle to the vertex shader.
 *  @param [in] fragment_shader  Handle to the fragment shader.
 *  @return Handle to the shader program.
 */
GLuint shader_create_program(GLuint vertex_shader, GLuint fragment_shader);

#endif // SHADER_INTERNAL_H
