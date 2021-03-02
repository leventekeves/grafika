#include "matrix.h"

#include <stdio.h>
#include <math.h>

void init_zero_matrix(float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            matrix[i][j] = 0.0;
        }
    }
}

void init_identity_matrix(float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
			if (i==j){
				matrix[i][j] = 1;
			}
			else{
				matrix[i][j] = 0.0;
			}
        }
    }
}

void print_matrix(const float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            printf("%4.4f ", matrix[i][j]);
        }
        printf("\n");
    }
	printf("\n");
}

void mult_scalar_matrix(float result[3][3], float scalar, const float matrix[3][3])
{
	int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            result[i][j] = matrix[i][j] * scalar;
        }
    }
}


void add_matrices(const float a[3][3], const float b[3][3], float c[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiply_matrices(const float a[3][3], const float b[3][3], float d[3][3])
{
    int i, j, t;

    for (i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            for(t=0;t<3;t++)
            d[i][j]=d[i][j]+a[i][t]*b[t][j];
        }
    }
}

void print_point(const float point[3])
{
    int i;

    for (i = 0; i < 3; ++i) {
            printf("%4.4f \n", point[i]);
    }
	printf("\n");
}

void transform_point(const float p[3], const float matrix[3][3], float p_t[3])
{
    int i, t;

    for (i=0; i<3; i++) {
            for(t=0;t<3;t++)
            p_t[i]=p_t[i]+matrix[i][t]*p[t];
    }
}


 void scale (const float matrix[3][3], float result[3][3])
 {
    float matrix_scale[3][3] = {
        { 2.0f,  0.0f,  0.0f},
        { 0.0f,  3.0f,  0.0f},
        { 0.0f,  0.0f,  1.0f}
    };

    multiply_matrices(matrix, matrix_scale, result);

 }

 void shift (const float matrix[3][3], float result[3][3])
 {
    float matrix_shift[3][3] = {
        { 1.0f,  0.0f,  5.0f},
        { 0.0f,  1.0f,  6.0f},
        { 0.0f,  0.0f,  1.0f}
    };

    multiply_matrices(matrix, matrix_shift, result);

 }


 void rotate (const float matrix[3][3], float result[3][3])
{
    float matrix_rotate[3][3] = {
        { cos(30),  -sin(30),  0.0f},
        { -sin(30),  cos(30),  0.0f},
        { 0.0f,  0.0f,  1.0f}
    };

    multiply_matrices(matrix, matrix_rotate, result);

}











