#include "Calculations.h"
extern float* vct_a, * vct_b, * vct_c;
float scl_multiple_vectors(vector a, vector b)
{
	float res = 0;
	int i = 0;
	for (i = 0; i < a.dim; i++)
		res = res + a.coord[i] * b.coord[i];
	return res;
}
vector cnst_multiple_vecror(vector a, int x)
{
	vector res;
	res.coord = (float*)malloc(sizeof(float) * a.dim);
	res.dim = a.dim;
	for (int i = 0; i < a.dim; i++)
		res.coord[i] = a.coord[i] * x;
	return res;
}
vector vct_multiple_vectors(vector a, vector b)
{
	vector res;
	res.coord = (float*)malloc(sizeof(float) * 3);
	res.coord[0] = a.coord[1] * b.coord[2] - a.coord[2] * b.coord[1];
	res.coord[1] = a.coord[0] * b.coord[2] - a.coord[2] * b.coord[0];
	res.coord[2] = a.coord[0] * b.coord[1] - a.coord[1] * b.coord[0];
	res.coord[1] = res.coord[1] * -1;
	return res;
}
float mxt_multiple_vectors(vector a, vector b, vector c)
{
	float res_val = 0;
	float* res;
	res = (float*)malloc(sizeof(float) * 3);
	res[0] = a.coord[1] * b.coord[2] - a.coord[2] * b.coord[1];
	res[1] = a.coord[0] * b.coord[2] - a.coord[2] * b.coord[0];
	res[2] = a.coord[0] * b.coord[1] - a.coord[1] * b.coord[0];
	res[1] = res[1] * -1;
	res_val = (res[0] * c.coord[0]) + (res[1] * c.coord[1]) + (res[2] * c.coord[2]);
	return res_val;
}
vector substract_vectors(vector a, vector b)
{
	vector res;
	res.coord = (float*)malloc(sizeof(float) * a.dim);
	for (int i = 0; i < a.dim; i++)
		res.coord[i] = a.coord[i] - b.coord[i];
	return res;
}
vector add_vectors(vector a, vector b)
{
	vector res;
	res.coord = (float*)malloc(sizeof(float) * a.dim);
	for (int i = 0; i < a.dim; i++)
		res.coord[i] = a.coord[i] + b.coord[i];
	return res;
}
float** direct_mult(vector a, vector b)
{
	int n, k;
	n = a.dim;
	float** arr, ** A, ** B;
	arr = new float* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new float[n];
	int i, j;

	A = new float* [n];
	for (int i = 0; i < n; i++)
		A[i] = new float[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			A[i][j] = 0;
			if (j == 0)
				A[i][j] = a.coord[i];
		}

	B = new float* [n];
	for (int i = 0; i < n; i++)
		B[i] = new float[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			B[i][j] = 0;
			if (i == 0)
				B[i][j] = b.coord[j];
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = 0;
			for (int k = 0; k < n; k++)
				arr[i][j] += A[i][k] * B[k][j];
		}
	return arr;
}
int  calc(vector a, vector b, vector c)
{
	vct_a = (float*)malloc(sizeof(float) * 2);
	vct_b = (float*)malloc(sizeof(float) * 2);
	vct_c = (float*)malloc(sizeof(float) * 2);

	a.coord[0] *= ASPECT_RATIO;
	a.coord[1] *= ASPECT_RATIO;
	a.coord[2] *= ASPECT_RATIO;
	float temp_1, temp_2;
	temp_1 = COORDINATES_START_X - (16 * a.coord[0]);
	temp_2 = COORDINATES_START_Y - (9 * a.coord[0]);
	vct_a[0] = temp_1 + (16 * a.coord[1]);
	vct_a[1] = temp_2 - (9 * a.coord[1]);
	vct_a[1] += (25 * a.coord[2]);

	b.coord[0] *= ASPECT_RATIO;
	b.coord[1] *= ASPECT_RATIO;
	b.coord[2] *= ASPECT_RATIO;
	temp_1 = COORDINATES_START_X - (16 * b.coord[0]);
	temp_2 = COORDINATES_START_Y - (9 * b.coord[0]);
	vct_b[0] = temp_1 + (16 * b.coord[1]);
	vct_b[1] = temp_2 - (9 * b.coord[1]);
	vct_b[1] += (25 * b.coord[2]);

	c.coord[0] *= ASPECT_RATIO;
	c.coord[1] *= ASPECT_RATIO;
	c.coord[2] *= ASPECT_RATIO;
	temp_1 = COORDINATES_START_X - (16 * c.coord[0]);
	temp_2 = COORDINATES_START_Y - (9 * c.coord[0]);
	vct_c[0] = temp_1 + (16 * c.coord[1]);
	vct_c[1] = temp_2 - (9 * c.coord[1]);
	vct_c[1] += (25 * c.coord[2]);

	return 1;
}