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

typedef struct {
    Window* window;
    union {
        struct {
            ShaderProgram3D shaderProgram3D;
            ShaderProgram2D shaderProgram2D;
        } opengl;
    } renderState;
    
} Renderer;

Renderer* renderer_init(Renderer* r, Window* window);
void renderer_destroy(Renderer* renderer);

/* OpenGL */
void renderer_clear(Renderer* renderer);
void renderer_resize(Renderer* renderer, int width, int height, Camera* camera);
void renderer_apply_camera(Renderer* renderer, Camera* camera);
void renderer_render_world(Renderer* renderer, World* world, Camera* camera);
void renderer_render_picker(Renderer* renderer, Picker* picker);
void renderer_render_panels(Renderer* renderer, LinkedList* panels);

#endif // RENDERER_H
