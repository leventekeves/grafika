#include "matrix.h"

#include <stdio.h>
#include <math.h>


int main(int argc, char* argv[])
{
	float a[3][3] = {
        { 1.0f, -2.0f,  3.0f},
        { 5.0f, -3.0f,  0.0f},
        {-2.0f,  1.0f, -4.0f}
    };
	float b[3][3];
	float c[3][3];
	float d[3][3];

    float transformation_matrix[3][3] = {
        { 1.0f,  0.0f,  3.0f},
        { 0.0f,  1.0f,  4.0f},
        { 0.0f,  0.0f,  1.0f}
    };

    float transformation_matrix_scale[3][3];
    float transformation_matrix_shift[3][3];
    float transformation_matrix_rotate[3][3];

	float p[3] = {0.0f, 0.0f, 1.0f};
	float p_t[3] = {0.0f, 0.0f, 0.0f};

    init_zero_matrix(b);
    b[1][1] =  8.0f;
    b[2][0] = -3.0f;
    b[2][2] =  5.0f;

    printf("a:\n");
    print_matrix(a);
    printf("b:\n");
    print_matrix(b);

    add_matrices(a, b, c);
    printf("Add matrices:\n");
    print_matrix(c);

    init_zero_matrix(d);
	multiply_matrices(a, b, d);
	printf("Multiply matrices:\n");
	print_matrix(d);

	init_identity_matrix(a);
	printf("Identiry matrix:\n");
	print_matrix(a);

	mult_scalar_matrix(b, 1000, a);
	printf("Multiple by scalar:\n");
	print_matrix(b);

    printf("Point:\n");
    print_point(p);

    printf("Transformation matrix:\n");
    print_matrix(transformation_matrix);

    transform_point(p, transformation_matrix, p_t);

    printf("Transformed point::\n");
    print_point(p_t);

    init_zero_matrix(transformation_matrix_scale);
    init_zero_matrix(transformation_matrix_shift);
    init_zero_matrix(transformation_matrix_rotate);

    scale(transformation_matrix, transformation_matrix_scale);
    printf("Scale:\n");
    print_matrix(transformation_matrix_scale);


    shift(transformation_matrix, transformation_matrix_shift);
    printf("Shift:\n");
    print_matrix(transformation_matrix_shift);


    rotate(transformation_matrix, transformation_matrix_rotate);
    printf("Rotate:\n");
    print_matrix(transformation_matrix_rotate);



	return 0;
}

