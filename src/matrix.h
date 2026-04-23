/**
 * @file matrix.h
 * @author Nir Jacobson
 * @date 2026-04-23
 */

#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include <string.h>

#include "global.h"

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

#ifndef _WIN32
#include <math.h>
#endif

/// @defgroup Matrix Matrix
/// @{

/// @public
/// @brief Returns the determinate of a 2x2 matrix.
/// @param [in] mat2s 2x2 matrix. 
/// @return 2x2 matrix determinate.
float mat2_determinate(float* mat2s);

/// @public
/// @brief Returns the 2x2 matrix that results from deleting one element's column and row in a 3x3 matrix.
/// @param [out] mat2d Destination 2x2 matrix. Can be NULL to allocate a new 2x2 matrix.
/// @param [in]  mat3s Source 3x3 matrix.
/// @param [in]  i     The index of the element in **mat3s** that anchors the deletion.
/// @return **mat2d** or a new matrix if **mat2d** was NULL.
float* mat3_sub(float* mat2d, float* mat3s, unsigned int i);

/// @public
/// @brief Transposes a 3x3 matrix.
/// @param mat3d Destination 3x3 matrix. Can be NULL to allocate a new 3x3 matrix.
/// @param mat3s Source 3x3 matrix.
/// @return **mat3d** or a new matrix if **mat3d** was NULL.
float* mat3_transpose(float* mat3d, float* mat3s);

/// @public
/// @brief Inverts a 3x3 matrix.
/// @param mat3d Destination 3x3 matrix. Can be NULL to allocate a new 3x3 matrix.
/// @param mat3s Source 3x3 matrix.
/// @return **mat3d** or a new matrix if **mat3d** was NULL.
float* mat3_inverse(float* mat3d, float* mat3s);

/// @public
/// @brief Returns the determinate of a 3x3 matrix.
/// @param [in] mat3s 3x3 matrix. 
/// @return 3x3 matrix determinate.
float mat3_determinate(float* mat3s);

/// @public
/// @brief Returns the 3x3 matrix that results from deleting one element's column and row in a 4x4 matrix.
/// @param [out] mat3d Destination 3x3 matrix. Can be NULL to allocate a new 3x3 matrix.
/// @param [in]  mat4s Source 4x4 matrix.
/// @param [in]  i     The index of the element in **mat4s** that anchors the deletion.
/// @return **mat3d** or a new matrix if **mat3d** was NULL.
float* mat4_sub(float* mat3d, float* mat4s, unsigned int i);

/// @public
/// @brief Transposes a 4x4 matrix.
/// @param [out] mat3d Destination 4x4 matrix. Can be NULL to allocate a new 4x4 matrix.
/// @param [in]  mat3s Source 4x4 matrix.
/// @return **mat4d** or a new matrix if **mat4d** was NULL.
float* mat4_transpose(float* mat4d, float* mat4s);

/// @public
/// @brief Inverts a 4x4 matrix.
/// @param [out] mat4d Destination 4x4 matrix. Can be NULL to allocate a new 4x4 matrix.
/// @param [in]  mat4s Source 4x4 matrix.
/// @return **mat4d** or a new matrix if **mat4d** was NULL.
float* mat4_inverse(float* mat4d, float* mat4s);

/// @public
/// @brief Returns the determinate of a 4x4 matrix.
/// @param [in] mat4s 4x4 matrix. 
/// @return 4x4 matrix determinate.
float mat4_determinate(float* mat4s);

/// @public
/// @brief Returns the 4x4 Identity matrix.
/// @param [out] mat4d Destination 4x4 matrix. Can be NULL to allocate a new 4x4 matrix.
/// @return **mat4d** or a new matrix if **mat4d** was NULL.
float* mat4_identity(float* mat4d);

/// @public
/// @brief Adds to the translational component of a 4x4 matrix.
/// @param [out] mat4d Destination 4x4 matrix. Can be NULL to allocate a new 4x4 matrix.
/// @param [in]  mat4s Source 4x4 matrix.
/// @param [in]  vec3  The vector to add to the translational component.
/// @return **mat4d** or a new matrix if **mat4d** was NULL.
float* mat4_translate(float* mat4d, float* mat4s, float* vec3);

/// @public
/// @brief Rotates a model-view matrix.
/// @param [out] mat4d    Destination 4x4 matrix. Can be NULL to allocate a new 4x4 matrix.
/// @param [in]  mat4s    Source 4x4 matrix.
/// @param [in]  radians  The extent of rotation.
/// @param [in]  vec3     The vector around which to rotate.
/// @return **mat4d** or a new matrix if **mat4d** was NULL.
float* mat4_rotate(float* mat4d, float* mat4s, float radians, float* vec3);

/// @public
/// @brief Multiplies two 4x4 matrices.
/// @param [out] mat4d    Destination 4x4 matrix. Can be NULL to allocate a new 4x4 matrix.
/// @param [in]  mat4a    Source 4x4 matrix.
/// @param [in]  mat4b    Source 4x4 matrix.
/// @return **mat4d** or a new matrix if **mat4d** was NULL.
float* mat4_multiply(float* mat4d, float* mat4a, float* mat4b);

/// @public
/// @brief Generates a perspective projection matrix.
/// @param [out] mat4d    Destination 4x4 matrix. Can be NULL to allocate a new 4x4 matrix.
/// @param [in]  fov      Vertical vield of view in degrees.
/// @param [in]  aspect   Width-to-height aspect ratio.
/// @param [in]  near     Near plane distance.
/// @param [in]  far      Far plane distance.
/// @return **mat4d** or a new matrix if **mat4d** was NULL.
float* mat4_perspective(float* mat4d, float fov, float aspect, float near, float far);

/// @public
/// @brief Generates an orthographic projection matrix.
/// @param [out] mat4d  Destination 4x4 matrix. Can be NULL to allocate a new 4x4 matrix.
/// @param [in]  left   Left plane x-coordinate.
/// @param [in]  right  Right plane x-coordinate.
/// @param [in]  top    Top plane y-coordinate.
/// @param [in]  bottom Bottom plane y-coordinate.
/// @return **mat4d** or a new matrix if **mat4d** was NULL.
float* mat4_orthographic(float* mat4d, float left, float right, float top, float bottom);

/// @public
/// @brief Adds two vec3's.
/// @param [out] vec3d Destination vec3. Can be NULL to allocate a new vec3.
/// @param [in]  vec3a 1st vec3.
/// @param [in]  vec3b 2nd vec3.
/// @return **vec3d** or a new vector if **vec3d** was NULL.
float* vec3_add(float* vec3d, float* vec3a, float* vec3b);

/// @public
/// @brief Scales a vec3.
/// @param [out] vec3d Destination vec3. Can be NULL to allocate a new vec3.
/// @param [in]  vec3s Source vec3.
/// @param [in]  m     Scalar.
/// @return **vec3d** or a new vector if **vec3d** was NULL.
float* vec3_scale(float* vec3d, float* vec3s, float m);

/// @public
/// @brief Left-multiplies a vec3 by a 4x4 matrix.
/// @param [out] vec3d Destination vec3. Can be NULL to allocate a new vec3.
/// @param [in]  mat4  4x4 matrix.
/// @param [in]  vec3s Vector to transform.
/// @return **vec3d** or a new vector if **vec3d** was NULL.
float* vec3_transform(float* vec3d, float* mat4, float* vec3s);

/// @public
/// @brief Normalizes a vec3 .
/// @param [out] vec3d  Destination vec3. Can be NULL to allocate a new vec3.
/// @param [in]  vec3s  Source vec3.
/// @return **vec3d** or a new vector if **vec3d** was NULL.
float* vec3_normalize(float* vec3d, float* vec3s);

/// @public
/// @brief Left-multiplies a vec4 by a 4x4 matrix.
/// @param [out] vec4d Destination vec4. Can be NULL to allocate a new vec4.
/// @param [in]  mat4  4x4 matrix.
/// @param [in]  vec4s Vector to transform.
/// @return **vec4d** or a new vector if **vec4d** was NULL.
float* vec4_transform(float* vec4d, float* mat4, float* vec4s);

/// @public
/// @brief Scales a vec4.
/// @param [out] vec4d Destination vec4. Can be NULL to allocate a new vec4.
/// @param [in]  vec4s Source vec4.
/// @param [in]  m     Scalar.
/// @return **vec4d** or a new vector if **vec4d** was NULL.
float* vec4_scale(float* vec4d, float* vec4s, float m);

/// @}
#endif // MATRIX_H
