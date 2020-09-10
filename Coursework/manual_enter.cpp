#include "manual_enter.h"
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
void data_in_vector_a(vector a)
{
	cout << "Enter the coordinates of the vector as(x1, y1, z1...)." << endl;
	for (int i = 0; i < a.dim; i++)
		cin >> a.coord[i];
	cout << "------------------------" << endl;
	for (int i = 0; i < a.dim; i++)
		cout << a.coord[i] << " ";
	cout << endl;
}
void data_in_vectors(vector a, vector b, vector c)
{
	cout << "Enter the coordinates of the 2 vectors as(x1, y1, z1... x2, y2, z2...)." << endl;
	int j;
	for (j = 0; j < a.dim; j++)
		cin >> a.coord[j];
	for (j = 0; j < b.dim; j++)
		cin >> b.coord[j];
	for (j = 0; j < c.dim; j++)
		cin >> c.coord[j];
	cout << "------------------------" << endl;
	for (j = 0; j < a.dim; j++)
		cout << a.coord[j] << " ";
	cout << endl;
	for (j = 0; j < b.dim; j++)
		cout << b.coord[j] << " ";
	cout << endl;
	for (j = 0; j < c.dim; j++)
		cout << c.coord[j] << " ";
	cout << endl;
}