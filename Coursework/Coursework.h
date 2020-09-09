#include <iostream> 
#include <math.h> 
#include <string> 
#include <windows.h>
#include "glut.h"
#include <ctime>

void f_data_in(vector a, vector b);
void data_in(vector a, vector b);
void f_data_out_1(vector a, vector b, float res);
void f_data_out(vector a, vector b, vector c);
int enter_menu();
int  calc(vector a, vector b, vector c);
void reshape(int w, int h);
void displayText(float x, float y, int r, int g, int b, char string);
void display();
void ScreenShot(int W, int H);

float scl_multiple_vectors(vector a, vector b);
vector cnst_multiple_vecror(vector a, int x);
vector vct_multiple_vectors(vector a, vector b);
float mxt_multiple_vectors(vector a, vector b, vector c);
vector substract_vectors(vector a, vector b);
vector add_vectors(vector a, vector b);
float** direct_mult(vector a, vector b);
float* vct_a, * vct_b, * vct_c;

typedef struct {
	int dim; //dimension 
	float* coord; //coordinates 
} vector;

