#ifndef MESH_H
#define MESH_H

#include <stdlib.h>

#include "GLES2/gl2.h"

#include "linked_list.h"
#include "renderer.h"

#define NORTH           0
#define SOUTH           1
#define WEST            2
#define EAST            3
#define TOP             4
#define BOTTOM          5

#define MESH_FILL       1
#define MESH_LINE       2

typedef struct {
    float position[3];
    float normal_v[3];
} Vertex;

typedef struct {
    Vertex vertices[4];
    GLuint vt_order[4];
    char orientation;
} Quad;

typedef struct {
    LinkedList quads;

    GLuint vbo;
    GLuint ebo;
} Mesh;

Mesh* mesh_init(Mesh* m);
void mesh_destroy(Mesh* mesh);

void mesh_ortn_to_normal(char orientation, float* nvec);

void mesh_add_quad(Mesh* mesh, Quad* quad);
void mesh_calc_normals(Mesh* mesh);

void mesh_buffer(Mesh* mesh, char mode);
void mesh_draw(Mesh* mesh, Renderer* renderer, char mode);

#endif // MESH_H
