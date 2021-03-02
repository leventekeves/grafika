#ifndef CUBOID_H
#define CUBOID_H

typedef struct Cuboid
{
	double x;
	double y;
	double z;
} Cuboid;

double set_size(Cuboid* cuboid, double x, double y, double z);
double calc_volume(const Cuboid* cuboid);
double calc_surface(const Cuboid* cuboid);
double has_square(const Cuboid* cuboid);

#endif // CUBOID_H
