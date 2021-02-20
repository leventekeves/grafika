#include "cuboid.h"

#include <math.h>

double set_size(Cuboid* cuboid, double x, double y, double z)
{
    cuboid->x = x;
    cuboid->y = y;
    cuboid->z = z;

    if (x > 0.0) {
		cuboid->x = x;
	} else {
		cuboid->x = NAN;
	}

	if (y > 0.0) {
		cuboid->y = y;
	} else {
		cuboid->y = NAN;
	}

	if (z > 0.0) {
		cuboid->z = z;
	} else {
		cuboid->z = NAN;
	}


}

double calc_volume(const Cuboid* cuboid)
{
    double volume = cuboid->x * cuboid->y * cuboid->z;
    return volume;
}


double calc_surface(const Cuboid* cuboid)
{
    double surface = (cuboid->x * cuboid->y + cuboid->y * cuboid->z + cuboid->x * cuboid->z) * 2;
    return surface;
}

double has_square(const Cuboid* cuboid)
{
    if(cuboid->x == cuboid->y || cuboid->y == cuboid->z || cuboid->x == cuboid->z){
        return 1;
    }
    else {
        return 0;
    }

}


















