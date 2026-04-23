/**
 * @file internal/mesh.h
 * @author Nir Jacobson
 * @date 2026-04-23
 */

 #ifndef MESH_INTERNAL_H
#define MESH_INTERNAL_H

#include "../mesh.h"

/**
 * @private
 * @memberof Mesh
 * @brief Converts an orientation constant (see \ref DirectionalEnumerationConstants) to a 3D normal vector.
 * @param [in]  orientation Orientation constant.
 * @param [out] nvec        3D normal vector.
 */
void mesh_ortn_to_normal(char orientation, float* nvec);

#endif // MESH_INTERNAL_H
