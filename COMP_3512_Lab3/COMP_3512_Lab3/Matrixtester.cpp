#include <iostream>
#include "Matrix.hpp"

using namespace std;

int main()
{
	Matrix a;
	cout << a << endl;
	Matrix b(3);
	cout << b << endl;

	int wrong_size[] = { 1, 2, 3 };
	Matrix c(wrong_size, 3);

	b.set_value(0, 0, -1);
	b.set_value(0,0, 13);
	b.clear();

	Matrix identity = a.identity();

	Matrix d;
	Matrix e;

	if (d == e) { cout << "equal" << endl; }
	if (d >= e) { cout << "c is greater than d" << endl; }

	Matrix f = d + e;
	cout << f;

	//Matrix d += a;

	system("pause");
	return 0;
}
