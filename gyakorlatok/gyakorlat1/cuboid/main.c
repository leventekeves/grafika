#include "cuboid.h"

#include <stdio.h>

int main(int argc, char* argv[])
{
	Cuboid cuboid;
	double volume;
	double surface;
	int square;

	set_size(&cuboid, 2, 3, 3);
	volume = calc_volume(&cuboid);
	surface = calc_surface(&cuboid);
	square = has_square(&cuboid);

	printf("Volume: %lf \nSurface: %lf \n", volume, surface);

	if(square == 1){
        printf("Has square side");
	}
	else{
        printf("Doesn't have square side");
	}


	return 0;
}

