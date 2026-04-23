#ifndef WINDOW_INTERNAL_H
#define WINDOW_INTERNAL_H

#include "../window.h"

/// @defgroup GLFW GLFW
/// @{
// Static callback
/// @brief 
/// @param Callback supplied to glfwSetWindowSizeCallback().
void resize(GLFWwindow* glfwWindow, int width, int height);
/// @}

// Invoked by static callback
/**
 *  @private
 *  @memberof Window
 *  @brief Resize handler called by resize().
 *  @param [in] window  Voxel Window.
 *  @param [in] width   New window width.
 *  @param [in] height  New window height.
*/
void window_resize(Window* window, int width, int height);

/**
 *  @private
 *  @memberof Window
 *  @brief Sets the window icon.
 *  @param [in] window  Voxel Window.
*/
void window_set_icon(Window* window);

#endif // WINDOW_INTERNAL_H
