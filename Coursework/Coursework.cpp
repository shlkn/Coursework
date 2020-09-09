#define _CRT_SECURE_NO_WARNINGS 
#include <iostream> 
#include <math.h> 
#include <string> 
#include <windows.h>
#include "glut.h"
#include <ctime>
#include "file_in_out.cpp"
typedef struct {
	int dim; //dimension 
	float* coord; //coordinates 
} vector;

using namespace std;
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
int main(int argc, char* argv[])
{
	int N, x, i, flg = 0;
	double start, graph = 0;
	cout << "enter count of coordinates\n";
	cin >> N;
	start = clock();

	vector vector_a;
	vector vector_b;
	vector vector_c;
	float res_val = 0;
	vector res_vct;
	vector_a.coord = (float*)malloc(sizeof(float) * N);
	vector_a.dim = N;
	vector_b.coord = (float*)malloc(sizeof(float) * N);
	vector_b.dim = N;
	vector_c.coord = (float*)malloc(sizeof(float) * N);
	vector_c.dim = N;
	int chs = 0, chs_1 = 0;
	float** arr;
	while (true)
	{
		cout << "what do you want multiply(1) ora add(2) vectors?\n";
		cin >> chs;
		if (chs == 1)
		{
			cout << "how to multiply a vector?\n 1-scalar\n 2-on const number\n 3-vector\n 4-mixed\n 5-direct multiplication\n";
			cin >> chs;
			switch (chs)
			{
			case 1:
			{
				chs = enter_menu();
				if (chs == 1)
					f_data_in(vector_a, vector_b);
				if (chs == 2)
					data_in(vector_a, vector_b);
				res_val = scl_multiple_vectors(vector_a, vector_b);
				cout << "result of scalar multiplication of vectors - " << res_val << endl;
				f_data_out_1(vector_a, vector_b, res_val);
				break;
			}
			case 2:
			{
				chs = enter_menu();
				if (chs == 1)
				{
					ifstream input("in.txt");
					cout << "vector a: ";
					for (int i = 0; i < N; i++)
					{
						input >> vector_a.coord[i];
						cout << vector_a.coord[i] << " ";
					}
					cout << endl;
				}
				if (chs == 2)
				{
					cout << "Enter the coordinates of the vector as(x1, y1, z1...)." << endl;
					for (i = 0; i < N; i++)
						cin >> vector_a.coord[i];
					cout << "------------------------" << endl;
					for (i = 0; i < N; i++)
						cout << vector_a.coord[i] << " ";
					cout << endl;
				}
				cout << "please enter const value\n";
				cin >> x;
				res_vct = cnst_multiple_vecror(vector_a, x);
				cout << "result of multiply of vector on const value:\n";
				cout << "(";
				for (i = 0; i < N; i++)
				{
					cout << res_vct.coord[i];
					if (i != N - 1)
						cout << ", ";
				}
				cout << ")" << endl;

				int i;
				FILE* out;
				out = fopen("out.txt", "w");
				if (out != NULL)
				{
					fprintf(out, "vector a: ");
					for (i = 0; i < N; i++)
						fprintf(out, "%f ", vector_a.coord[i]);
					fprintf(out, "\n");

					fprintf(out, "result vector: ");
					for (i = 0; i < N; i++)
						fprintf(out, "%f ", res_vct.coord[i]);
					fprintf(out, "\n");
				}
				fclose(out);

				if (N == 3)
				{
					vector_b.coord[0] = 0;
					vector_b.coord[1] = 0;
					vector_b.coord[2] = 0;
					flg = calc(vector_a, vector_b, res_vct);
				}
				break;
			}
			case 3:
			{
				if (N > 3)
				{
					cout << "the dimension of vectors more than 3, this operation will be calculate by dimension 3" << endl;
					N = 3;
				}
				chs = enter_menu();
				if (chs == 1)
					f_data_in(vector_a, vector_b);
				if (chs == 2)
					data_in(vector_a, vector_b);
				res_vct = vct_multiple_vectors(vector_a, vector_b);
				cout << "result of vector multiplication of vectors - ";
				cout << "(";
				for (i = 0; i < 3; i++)
				{
					cout << res_vct.coord[i];
					if (i != 2)
						cout << ", ";
				}
				cout << ")" << endl;
				f_data_out(vector_a, vector_b, res_vct);
				flg = calc(vector_a, vector_b, res_vct);
				break;
			}
			case 4:
			{
				if (N > 3)
				{
					cout << "the dimension of vectors more than 3, this operation will be calculate by dimension 3" << endl;
					N = 3;
				}
				chs = enter_menu();
				if (chs == 1)
				{
					ifstream input("in.txt");
					cout << "vector a: ";
					for (int i = 0; i < N; i++)
					{
						input >> vector_a.coord[i];
						cout << vector_a.coord[i] << " ";
					}
					cout << endl << "vector b: ";
					for (int i = 0; i < N; i++)
					{
						input >> vector_b.coord[i];
						cout << vector_b.coord[i] << " ";
					}
					cout << endl << "vector c: ";
					for (int i = 0; i < N; i++)
					{
						input >> vector_c.coord[i];
						cout << vector_c.coord[i] << " ";
					}
					cout << endl;
				}
				if (chs == 2)
				{
					cout << "Enter the coordinates of the 2 vectors as(x1, y1, z1... x2, y2, z2...)." << endl;
					int j;
					for (j = 0; j < N; j++)
						cin >> vector_a.coord[j];
					for (j = 0; j < N; j++)
						cin >> vector_b.coord[j];
					for (j = 0; j < N; j++)
						cin >> vector_c.coord[j];
					cout << "------------------------" << endl;
					for (j = 0; j < N; j++)
						cout << vector_a.coord[j] << " ";
					cout << endl;
					for (j = 0; j < N; j++)
						cout << vector_b.coord[j] << " ";
					cout << endl;
					for (j = 0; j < N; j++)
						cout << vector_c.coord[j] << " ";
					cout << endl;
				}
				res_val = mxt_multiple_vectors(vector_a, vector_b, vector_c);
				cout << "result of mixed multiplication of vectors - " << res_val << endl;
				f_data_out_1(vector_a, vector_b, res_val);
				break;
			}
			case 5:
			{
				chs = enter_menu();
				if (chs == 1)
					f_data_in(vector_a, vector_b);
				if (chs == 2)
					data_in(vector_a, vector_b);
				arr = direct_mult(vector_a, vector_b);
				for (int i = 0; i < N; i++)
				{
					for (int j = 0; j < N; j++)
						cout << arr[i][j] << " ";
					cout << endl;
				}
				cout << endl;
				FILE* out;
				out = fopen("out.txt", "w");
				if (out != NULL)
				{
					fprintf(out, "vector a: ");
					for (i = 0; i < N; i++)
						fprintf(out, "%f ", vector_a.coord[i]);
					fprintf(out, "\n");

					fprintf(out, "vector b: ");
					for (i = 0; i < N; i++)
						fprintf(out, "%f ", vector_b.coord[i]);
					fprintf(out, "\n");

					fprintf(out, "result: \n");
					for (int i = 0; i < N; i++)
					{
						for (int j = 0; j < N; j++)
							fprintf(out, "%f ", arr[i][j]);
						fprintf(out, "\n");
					}
				}
				fclose(out);
				break;
			}
			}
			break;
		}
		if (chs == 2)
		{
			cout << "1-subtract\n2-add\n";
			cin >> chs;
			switch (chs)
			{
			case 1:
			{
				chs = enter_menu();
				if (chs == 1)
					f_data_in(vector_a, vector_b);
				if (chs == 2)
					data_in(vector_a, vector_b);
				res_vct = substract_vectors(vector_a, vector_b);
				cout << "result of substract of vectors:\n";
				cout << "(";
				for (i = 0; i < N; i++)
				{
					cout << res_vct.coord[i];
					if (i != N - 1)
						cout << ", ";
				}
				cout << ")";
				f_data_out(vector_a, vector_b, res_vct);
				if (N == 3)
					flg = calc(vector_a, vector_b, res_vct);
				break;
			}
			case 2:
			{
				chs = enter_menu();
				if (chs == 1)
					f_data_in(vector_a, vector_b);
				if (chs == 2)
					data_in(vector_a, vector_b);
				res_vct = add_vectors(vector_a, vector_b);
				cout << "result of substract of vectors:\n";
				cout << "(";
				for (i = 0; i < N; i++)
				{
					cout << res_vct.coord[i];
					if (i != N - 1)
						cout << ", ";
				}
				cout << ")";
				f_data_out(vector_a, vector_b, res_vct);
				if (N == 3)
					flg = calc(vector_a, vector_b, res_vct);
				break;
			}
			}
			break;
		}
		cout << "please try again\n";
	}
	if (flg != 0 && N == 3)
	{
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

		glutInitWindowSize(1500, 1000);
		glutCreateWindow("your vectors");
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

		glutReshapeFunc(reshape);
		glutDisplayFunc(display);
		glutMainLoop();
	}
}
int enter_menu()
{
	while (true)
	{
		int chs;
		cout << "How do you want to enter data: 1-file, 2-manual" << endl;
		cin >> chs;
		if (chs == 2)
			return chs;
		if (chs == 1)
			return chs;
	}
}
void data_in(vector a, vector b) //ввод данных через консоль
{

	cout << "Enter the coordinates of the 2 vectors as(x1, y1, z1... x2, y2, z2...)." << endl;
	int j;
	for (j = 0; j < a.dim; j++)
		cin >> a.coord[j];
	for (j = 0; j < a.dim; j++)
		cin >> a.coord[j];
	cout << "------------------------" << endl;
	for (j = 0; j < b.dim; j++)
		cout << b.coord[j] << " ";
	cout << endl;
	for (j = 0; j < b.dim; j++)
		cout << b.coord[j] << " ";
	cout << endl;
}

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
	int i;
	for (i = 0; i < a.dim; i++)
		res.coord[i] = a.coord[i] * x;
	return res;
}
vector vct_multiple_vectors(vector a, vector b)
{
	vector res;
	res.coord = (float*)malloc(sizeof(float) * 3);
	int i;
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
	int i;
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
	int i;
	for (i = 0; i < a.dim; i++)
		res.coord[i] = a.coord[i] - b.coord[i];
	return res;
}
vector add_vectors(vector a, vector b)
{
	vector res;
	res.coord = (float*)malloc(sizeof(float) * a.dim);
	int i;
	for (i = 0; i < a.dim; i++)
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
	{
		for (int j = 0; j < n; j++)
		{
			A[i][j] = 0;
			if (j == 0)
				A[i][j] = a.coord[i];
		}
	}

	B = new float* [n];
	for (int i = 0; i < n; i++)
		B[i] = new float[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			B[i][j] = 0;
			if (i == 0)
				B[i][j] = b.coord[j];
		}
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
void f_data_out_1(vector a, vector b, float res)
{
	int i;
	FILE* out;
	out = fopen("out.txt", "w");
	if (out != NULL)
	{
		fprintf(out, "vector a: ");
		for (i = 0; i < a.dim; i++)
			fprintf(out, "%f ", a.coord[i]);
		fprintf(out, "\n");

		fprintf(out, "vector b: ");
		for (i = 0; i < b.dim; i++)
			fprintf(out, "%f ", b.coord[i]);
		fprintf(out, "\n");
		fprintf(out, "result: %f\n", res);
	}
	fclose(out);
}
void f_data_out(vector a, vector b, vector c)
{
	int i;
	FILE* out;
	out = fopen("out.txt", "w");
	if (out != NULL)
	{
		fprintf(out, "vector a: ");
		for (i = 0; i < a.dim; i++)
			fprintf(out, "%f ", a.coord[i]);
		fprintf(out, "\n");

		fprintf(out, "vector b: ");
		for (i = 0; i < b.dim; i++)
			fprintf(out, "%f ", b.coord[i]);
		fprintf(out, "\n");

		fprintf(out, "result vector: ");
		for (i = 0; i < c.dim; i++)
			fprintf(out, "%f ", c.coord[i]);
		fprintf(out, "\n");
	}
	fclose(out);
}
void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void displayText(float x, float y, int r, int g, int b, char string) {
	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(5);

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(750, 500);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(750, 950);
	glEnd();
	displayText(780, 820, 0, 0, 0, 'Z');

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(750, 500);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(100, 50);
	glEnd();
	displayText(70, 70, 0, 0, 0, 'X');

	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(750, 500);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2i(1400, 50);
	glEnd();
	displayText(1420, 70, 0, 0, 0, 'Y');

	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 1.0);
	glVertex2i(750, 500);
	glColor3f(1.0, 0.0, 1.0);
	glVertex2i(vct_c[0], vct_c[1]);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(750, 500);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(vct_a[0], vct_a[1]);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(750, 500);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(vct_b[0], vct_b[1]);
	glEnd();
	ScreenShot(1500, 840);
	glutSwapBuffers();

}
void ScreenShot(int W, int H)
{
	const int imSize = W * H * 3;
	unsigned char* image = new unsigned char[imSize];
	memset(image, 0, imSize);
	glReadPixels(0, 0, W, H, GL_RGB, GL_UNSIGNED_BYTE, image);
	BITMAPINFO bmi;
	memset(&bmi, 0, sizeof(BITMAPINFOHEADER));
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biHeight = H;
	bmi.bmiHeader.biWidth = W;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 24;
	bmi.bmiHeader.biCompression = BI_RGB;
	bmi.bmiHeader.biSizeImage = imSize;
	FILE* F = fopen("screen.bmp", "w");
	int nBitsOffset = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
	LONG lImageSize = imSize;
	LONG lFileSize = nBitsOffset + lImageSize;
	BITMAPFILEHEADER bmfh;
	bmfh.bfType = 'B' + ('M' << 8);
	bmfh.bfOffBits = nBitsOffset;
	bmfh.bfSize = lFileSize;
	bmfh.bfReserved1 = bmfh.bfReserved2 = 0;

	UINT nWrittenFileHeaderSize = fwrite(&bmfh, 1, sizeof(BITMAPFILEHEADER), F);
	UINT nWrittenInfoHeaderSize = fwrite(&bmi, 1, sizeof(BITMAPINFOHEADER), F);
	UINT nWrittenDIBDataSize = fwrite(image, 1, imSize, F);
	UINT total = nWrittenDIBDataSize + nWrittenInfoHeaderSize + nWrittenFileHeaderSize;
	delete[]image;
	fclose(F);
}
int  calc(vector a, vector b, vector c)
{
	vct_a = (float*)malloc(sizeof(float) * 2);
	vct_b = (float*)malloc(sizeof(float) * 2);
	vct_c = (float*)malloc(sizeof(float) * 2);
	int flg;

	a.coord[0] *= 0.82;
	a.coord[1] *= 0.82;
	a.coord[2] *= 0.82;
	float temp_1, temp_2;
	temp_1 = 750 - (16 * a.coord[0]);
	temp_2 = 500 - (9 * a.coord[0]);
	vct_a[0] = temp_1 + (16 * a.coord[1]);
	vct_a[1] = temp_2 - (9 * a.coord[1]);
	vct_a[1] += (25 * a.coord[2]);

	b.coord[0] *= 0.82;
	b.coord[1] *= 0.82;
	b.coord[2] *= 0.82;
	temp_1 = 750 - (16 * b.coord[0]);
	temp_2 = 500 - (9 * b.coord[0]);
	vct_b[0] = temp_1 + (16 * b.coord[1]);
	vct_b[1] = temp_2 - (9 * b.coord[1]);
	vct_b[1] += (25 * b.coord[2]);

	c.coord[0] *= 0.82;
	c.coord[1] *= 0.82;
	c.coord[2] *= 0.82;
	temp_1 = 750 - (16 * c.coord[0]);
	temp_2 = 500 - (9 * c.coord[0]);
	vct_c[0] = temp_1 + (16 * c.coord[1]);
	vct_c[1] = temp_2 - (9 * c.coord[1]);
	vct_c[1] += (25 * c.coord[2]);

	return flg = 1;
}

