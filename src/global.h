#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdlib.h>

/// @brief Allocates memory for **count** objects of type **type**.
#define NEW(type, count)     (type*)malloc((count) * sizeof(type));

extern float X[3];  ///< @brief Global X vector (1, 0, 0).
extern float Y[3];  ///< @brief Global Y vector (0, 1, 0).
extern float Z[3];  ///< @brief Global Z vector (0, 0, 1).

#endif // GLOBAL_H
