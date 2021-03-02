#ifndef MATRIX_H
#define MATRIX_H

/**
 * Initializes all elements of the matrix to zero.
 */
void init_zero_matrix(float matrix[3][3]);

/**
 * Initializes an identity matrix.
 */
void init_identity_matrix(float matrix[3][3]);

/**
 * Initializes all elements of the matrix to zero.
 */
void mult_scalar_matrix(float result[3][3], float scalar, const float matrix[3][3]);


/**
 * Print the elements of the matrix.
 */
void print_matrix(const float matrix[3][3]);


/**
 * Add matrices.
 */
void add_matrices(const float a[3][3], const float b[3][3], float c[3][3]);

/**
 * Multiply matrices.
 */
void multiply_matrices(const float a[3][3], const float b[3][3], float d[3][3]);

/**
 * Print point.
 */
void print_point(const float point[3]);

/**
 * Transform point.
 */
void transform_point(const float p[3], const float matrix[3][3], float p_t[3]);

/**
 * Transformations
 */
 void scale (const float matrix[3][3], float result[3][3]);
 void shift (const float matrix[3][3], float result[3][3]);
 void rotate (const float matrix[3][3], float result[3][3]);

#endif // MATRIX_H

