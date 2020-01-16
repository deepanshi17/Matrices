// matrix-multiplication <Project2.cpp>
// EE 312 Project 2 submission by
// <Deepanshi Sharma>
// <ds52384>
// Slip days used: <0>
// Fall 2019


/* Project2.cpp
 * Deepanshi Sharma
 * EE312, Fall 2019
 * Project 2, Matrix Multiplication
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "MatrixMultiply.h"

void multiplyMatrices(
        double a[],
        const uint32_t a_rows,
        const uint32_t a_cols,
        double b[],
        const uint32_t b_cols,
        double c[])
        {
    // https://en.wikipedia.org/wiki/Row-_and_column-major_order
    int c_index = 0;
    double sum = 0;
    int temp_i = 0;
    int temp_j = 0;
    for(int i=0; i<a_rows; i++){
        for(int j=0; j<b_cols; j++){
            temp_j = j;
            for(int n=0; n<a_cols; n++) {
                sum += (a[n+temp_i] * b[temp_j]);
                temp_j += b_cols;
            }
            c[c_index] = sum;
            c_index ++;
            sum=0;
        }
        temp_i += a_cols;
    }
}

double** multiplyMatricesPtr(
        double** a,
        const uint32_t a_rows,
        const uint32_t a_cols,
        double** b,
        const uint32_t b_cols) {
    int size = a_rows * b_cols;
    double** c = (double **)malloc(sizeof(double *) * size);
    for (int i = 0; i < a_rows; i++) {
        *(c + i) = (double *)malloc(sizeof(double) * b_cols);
    }
    double sum = 0;
    int temp_i = 0;
    int temp_j = 0;
    for(int i=0; i<a_rows; i++){
        for(int j=0; j<b_cols; j++){
            temp_j = 0;
            temp_i = j;
            for(int n=0; n<a_cols; n++) {
                sum += ((a[i][n]) * (b[temp_j][temp_i]));
                temp_j ++;
            }
            c[i][j] = sum;
            sum=0;
        }
    }
    return(c);
}

// https://en.wikipedia.org/wiki/Transpose
double** transposeMatrix(
         double** a,
         const uint32_t a_rows,
         const uint32_t a_cols) {
    int size = a_rows * a_cols;
    double** c = (double **)malloc(sizeof(double *) * size);
    for (int i = 0; i < a_cols; i++) {
        *(c + i) = (double *)malloc(sizeof(double) * a_rows);
    }
    for(int i=0; i<a_rows; i++)
        for(int j=0; j<a_cols; j++) {
            c[j][i] = a[i][j];
        }
    return (c);
}
