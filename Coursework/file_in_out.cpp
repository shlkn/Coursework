#include <fstream>
#include "Coursework.cpp"
using namespace std;
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