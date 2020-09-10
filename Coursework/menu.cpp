#include "menu.h"
void menu(int argc, char* argv[])
{
	int N, x, i, flg = 0;
	cout << "enter count of coordinates\n";
	cin >> N;

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
			case 1: //scalar mul
			{
				chs = input_menu();
				if (chs == 1)
					f_data_in(vector_a, vector_b);
				if (chs == 2)
					data_in(vector_a, vector_b);
				res_val = scl_multiple_vectors(vector_a, vector_b);
				cout << "result of scalar multiplication of vectors - " << res_val << endl;
				f_data_out_1(vector_a, vector_b, res_val);
				break;
			}
			case 2: // const mul
			{
				chs = input_menu();
				if (chs == 1)
					f_data_in_vector_a(vector_a);
				if (chs == 2)
					data_in_vector_a(vector_a);
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
				f_data_out_res_vct(vector_a, res_vct);
				if (N == 3)
				{
					vector_b.coord[0] = 0;
					vector_b.coord[1] = 0;
					vector_b.coord[2] = 0;
					flg = calc(vector_a, vector_b, res_vct);
				}
				break;
			}
			case 3: //vector multiplication
			{
				if (N > 3)
				{
					cout << "the dimension of vectors more than 3, this operation will be calculate by dimension 3" << endl;
					N = 3;
				}
				chs = input_menu();
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
			case 4: //mixed multiplication
			{
				if (N > 3)
				{
					cout << "the dimension of vectors more than 3, this operation will be calculate by dimension 3" << endl;
					N = 3;
				}
				chs = input_menu();
				if (chs == 1)
					f_data_in_vectors(vector_a, vector_b, vector_c);
				if (chs == 2)
					data_in_vectors(vector_a, vector_b, vector_c);
				res_val = mxt_multiple_vectors(vector_a, vector_b, vector_c);
				cout << "result of mixed multiplication of vectors : " << res_val << endl;
				f_data_out_mxt_mul(vector_a, vector_b, vector_c, res_val);
				break;
			}
			case 5:
			{
				chs = input_menu();
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
				f_data_out_drct_mul(vector_a, vector_b, arr);
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
				chs = input_menu();
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
				chs = input_menu();
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
		graphic_init(argc, argv);
}
int input_menu()
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
