#ifndef SCENE_H
#define SCENE_H

#include "camera.h"

typedef struct Scene
{
    // NOTE: Place for model structures and texture ids.
} Scene;

/**
 * Initialize the scene.
 */
void init_scene(Scene* scene);

/**
 * Draw the scene objects.
 */
void draw_scene(const Scene* scene);

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

/**
 * Draws a triangle.
 */
void draw_triangle();

/**
 * Draws a cylinder (with quad strips).
 */
void draw_cylinder();

/**
 * Draws a cylinder (with triangle strips).
 */
void draw_cylinder_tstrips()

/**
 * Draws a cone.
 */
void draw_cone();

/**
 * Draws a sphere.
 */
void draw_sphere();

/**
 * Draws a square.
 */
void draw_square(float x1, float y1, int bow);

/**
 * Drwas a chessboard.
 */
void draw_chessboard();

#endif /* SCENE_H */

