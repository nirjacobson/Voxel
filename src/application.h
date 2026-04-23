/**
 * @file application.h
 * @author Nir Jacobson
 * @date 2026-04-23
 */

#ifndef APPLICATION_H
#define APPLICATION_H

#include "global.h"

struct Application;
struct Window;

/**
 * @brief Function accepting an Application as argument.
 */
typedef void (*ApplicationFn)(struct Application*);

/**
 * @class Application
 * @brief The Voxel application.
 */
typedef struct Application {
    /// @private
    /// @brief Voxel Window.
    struct Window* window;

    /// @private
    /// @brief Application setup callback.
    ApplicationFn setup;

    /// @private
    /// @brief Application main loop callback.
    ApplicationFn main;

    /// @private
    /// @brief Application window resize callback.
    ApplicationFn resize;

    /// @private
    /// @brief Application teardown callback.
    ApplicationFn teardown;


    /// @private
    /// @brief Owning object of the Application.
    void* owner;
} Application;

/** 
 * @public
 * @memberof Application
 * @brief Initializes the Application.
 * @param [in] a        Application to initialize. Can be NULL to allocate a new Application.
 * @param [in] owner    Owner of the Application.
 * @param [in] setup    Setup procedure.
 * @param [in] main     Main loop.
 * @param [in] resize   Application window resize callback.
 * @param [in] teardown Teardown procedure.
 * @return **a** or a new Application if **a** was NULL.
 */
Application* application_init(Application* a, void* owner, ApplicationFn setup, ApplicationFn main, ApplicationFn resize, ApplicationFn teardown);


#endif // APPLICATION_H
