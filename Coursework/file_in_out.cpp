#ifndef FILE_IN_OUT_H
#define _CRT_SECURE_NO_WARNINGS 
#include "file_in_out.h"

void f_data_in(vector a, vector b) //ввод данных из файла
{
	ifstream input("in.txt");
	cout << "vector a: ";
	for (int i = 0; i < a.dim; i++)
	{
		input >> a.coord[i];
		cout << a.coord[i] << " ";
	}
	cout << endl << "vector b: ";
	for (int i = 0; i < b.dim; i++)
	{
		input >> b.coord[i];
		cout << b.coord[i] << " ";
	}
	cout << endl;
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
void f_data_in_vector_a(vector a)
{
	ifstream input("in.txt");
	cout << "vector a: ";
	for (int i = 0; i < a.dim; i++)
	{
		input >> a.coord[i];
		cout << a.coord[i] << " ";
	}
	cout << endl;
}
void f_data_out_res_vct(vector a, vector res_vct)
{
	FILE* out;
	out = fopen("out.txt", "w");
	if (out != NULL)
	{
		fprintf(out, "vector a: ");
		for (int i = 0; i < a.dim; i++)
			fprintf(out, "%f ", a.coord[i]);
		fprintf(out, "\n");
		fprintf(out, "result vector: ");
		for (int i = 0; i < res_vct.dim; i++)
			fprintf(out, "%f ", res_vct.coord[i]);
		fprintf(out, "\n");
	}
	fclose(out);
}
void f_data_in_vectors(vector a, vector b, vector c)
{
	ifstream input("in.txt");
	cout << "vector a: ";
	for (int i = 0; i < a.dim; i++)
	{
		input >> a.coord[i];
		cout << a.coord[i] << " ";
	}
	cout << endl << "vector b: ";
	for (int i = 0; i < b.dim; i++)
	{
		input >> b.coord[i];
		cout << b.coord[i] << " ";
	}
	cout << endl << "vector c: ";
	for (int i = 0; i < c.dim; i++)
	{
		input >> c.coord[i];
		cout << c.coord[i] << " ";
	}
	cout << endl;
}
void f_data_out_mxt_mul(vector a, vector b, vector c, float res)
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
		fprintf(out, "result: %f\n", res);
	}
	fclose(out);
}
void f_data_out_drct_mul(vector a, vector b, float** res)
{
	FILE* out;
	out = fopen("out.txt", "w");
	if (out != NULL)
	{
		fprintf(out, "vector a: ");
		for (int i = 0; i < a.dim; i++)
			fprintf(out, "%f ", a.coord[i]);
		fprintf(out, "\n");

		fprintf(out, "vector b: ");
		for (int i = 0; i < b.dim; i++)
			fprintf(out, "%f ", b.coord[i]);
		fprintf(out, "\n");

		fprintf(out, "result: \n");
		for (int i = 0; i < a.dim; i++)
		{
			for (int j = 0; j < a.dim; j++)
				fprintf(out, "%f ", res[i][j]);
			fprintf(out, "\n");
		}
	}
	fclose(out);
}
#endif // !FILE_IN_OUT_H