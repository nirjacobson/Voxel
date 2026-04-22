#ifndef CAMERA_H
#define CAMERA_H

#include <stdlib.h>
#include <math.h>

#include "global.h"
#include "matrix.h"
#include "box.h"

/**
 * @class Camera
 * @brief The Voxel Camera.
 */
typedef struct {
    /// @private
    /// @brief Global Vulkan object or NULL if using OpenGL.
    Vulkan* vulkan;

    /// @private
    /// @brief The vertical field of view in degrees.
    float fov;

    /// @private
    /// @brief The width-to-height aspect ratio.
    float aspect;

    /// @private
    /// @brief The distance of the near plane.
    float _near;

    /// @private
    /// @brief The distance of the far plane.
    float _far;

    /// @private
    /// @brief Cartesian location.
    float position[3];

    /// @private
    /// @brief Forward vector (x, y, z).
    float forward[3];
    
    /// @private
    /// @brief Up vector (x, y, z).
    float up[3];

    /// @private
    /// @brief Right vector (x, y, z).
    float right[3];

    /// @private
    /// @brief Model matrix.
    /// @details Captures the orientation (3D rotation) of the Camera.
    float mat_model[16];

    /// @private
    /// @brief View matrix.
    /// @details Captures the position (global 3D location & rotation) of the Camera.
    float mat_view[16];

    /// @private
    /// @brief Projection matrix.
    /// @details Maps eye space to device space.
    float mat_proj[16];

    /// @private
    /// @brief Inverse projection matrix.
    float mat_proj_inv[16];
} Camera;

/** 
 * @public
 * @memberof Camera
 * @brief Initializes a Camera.
 * @param [in] c Camera to initialize. Can be NULL to allocate a new Camera.
 * @param [in] vulkan Global Vulkan object. Set NULL when using OpenGL.
 * @return **c** or a new Camera if **c** was NULL.
 */
Camera* camera_init(Camera* c, Vulkan* vulkan);

/** 
 * @public
 * @memberof Camera
 * @brief Rotates a Camera.
 * @param [in] camera Camera to rotate.
 * @param [in] axis The vector from the Camera origin around which to rotate.
 * @param [in] radians The extent of rotation.
 */
void camera_rotate(Camera* camera, float* axis, float radians);

/** 
 * @public
 * @memberof Camera
 * @brief Moves a Camera.
 * @param [in] camera Camera to move.
 * @param [in] direction This vector from the Camera origin determines the direction of motion.
 * @param [in] amount The distance to move.
 */
void camera_move(Camera* camera, float* direction, float amount);

/** 
 * @public
 * @memberof Camera
 * @brief Sets the Camera aspect ratio.
 * @param [in] camera Camera to modify.
 * @param [in] aspect The new width-to-height aspect ratio of the camera.
 */
void camera_set_aspect(Camera* camera, float aspect);

/** 
 * @public
 * @memberof Camera
 * @brief Updates a \ref Camera "Camera's" projection matrix based on its other properties.
 * @param [in] camera Camera to update.
 */
void camera_update_projection(Camera* camera);

/** 
 * @public
 * @memberof Camera
 * @brief Returns an AABB (axis-aligned bounding box) around the view frustum of the Camera.
 * @param [out] box Destination box. Can be NULL to allocate a new Box.
 * @param [in] camera Camera to capture.
 * @returns **box** or a new Box if **box** was NULL.
 */
Box* camera_aabb(Box* box, Camera* camera);

#endif // CAMERA_H
