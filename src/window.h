/**
 * @file window.h
 * @author Nir Jacobson
 * @date 2026-04-23
 */

#ifndef WINDOW_H
#define WINDOW_H

/// @public
/// @memberof Window
/// @name Window default dimensions
/// @{
#define WINDOW_DEFAULT_WIDTH  1440
#define WINDOW_DEFAULT_HEIGHT 900
/// @}

/// @public
/// @memberof Window
/// @name Mouse button bitmasks
/// @{
#define MOUSE_BUTTON_LEFT  0b10
#define MOUSE_BUTTON_RIGHT 0b01
/// @}

/// @public
/// @memberof Window
/// @name Mouse actions
/// @{
#define MOUSE_PRESS        1
#define MOUSE_RELEASE      0
/// @}

#define GLFW_INCLUDE_VULKAN

#include <assert.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cairo/cairo.h>

#include "global.h"
#include "application.h"

struct Window;
struct Voxel;

/**
 * @class Window
 * @brief The Voxel Window.
 */
struct Window {
    /// @private
    /// @brief GLFW window handle.
    GLFWwindow* glfwWindow;

    /// @private
    /// @brief Window width.
    int width;

    /// @private
    /// @brief Window height.
    int height;

    /// @private
    /// @brief Voxel Application.
    Application* application;

    /// @private
    /// @brief Vulkan surface.
    VkSurfaceKHR surface;
};

typedef struct Window Window;

/** 
 * @public
 * @memberof Window
 * @brief Initializes the Window.
 * @param [in] w      Window to initialize. Can be NULL to allocate a new Window.
 * @return **w** or a new Window if **w** was NULL.
 */
Window* window_init(Window* w, Application* application);


/** 
 * @public
 * @memberof Window
 * @brief Opens the Window.
 * @param [in] window Window to open.
 */
void window_open(Window* window);

/** 
 * @public
 * @memberof Window
 * @brief Destroys the Window.
 * @param [in] window Window to destroy.
 */
void window_destroy(Window* window);

/** 
 * @public
 * @memberof Window
 * @brief Toggles fullscreen.
 * @param [in] window Window to destroy.
 */
void window_toggle_fullscreen(Window* window);

/** 
 * @public
 * @memberof Window
 * @brief Returns whether a key is pressed.
 * @param [in] window Window to ask.
 * @param [in] key Key to check the state of. See "Function keys" in glfw3.h.
 * @returns 1 if pressed, 0 otherwise.
 */
char window_key_is_pressed(Window* window, int key);

/** 
 * @public
 * @memberof Window
 * @brief Returns the mouse state.
 * @param [in]  window Window to ask.
 * @param [out] x X-coordinate of the mouse.
 * @param [out] y Y-coordinate of the mouse.
 * @returns Mouse buttons state. Compare with MOUSE_BUTTON_LEFT or MOUSE_BUTTON_RIGHT.
 */
char window_mouse_state(Window* window, int* x, int* y);

#endif // WINDOW_H
