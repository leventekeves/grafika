#ifndef CUBOID_H
#define CUBOID_H

/**
 * Data of a circle object in Descartes coordinate system
 */
typedef struct Cuboid
{
	double x;
	double y;
	double z;
} Cuboid;

/**
 * Set the data of the circle
 */
double set_size(Cuboid* cuboid, double x, double y, double z);

/**
 * Calculate the area of the circle.
 */
double calc_volume(const Cuboid* cuboid);
double calc_surface(const Cuboid* cuboid);

//négyzet lapja van-e?
double has_square(const Cuboid* cuboid);

#endif // CUBOID_H
