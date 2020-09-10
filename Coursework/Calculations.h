#pragma once
#ifndef CALCULATIONS_H
#include "Coursework.h"
#define COORDINATES_START_X 750
#define COORDINATES_START_Y 500
#define ASPECT_RATIO 0.82

int  calc(vector a, vector b, vector c);
float scl_multiple_vectors(vector a, vector b);
vector cnst_multiple_vecror(vector a, int x);
vector vct_multiple_vectors(vector a, vector b);
float mxt_multiple_vectors(vector a, vector b, vector c);
vector substract_vectors(vector a, vector b);
vector add_vectors(vector a, vector b);
float** direct_mult(vector a, vector b);
#endif // !CALCULATIONS_H
