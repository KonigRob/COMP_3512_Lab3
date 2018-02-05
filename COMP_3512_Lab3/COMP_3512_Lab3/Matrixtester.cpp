#include <iostream>
#include "Matrix.hpp"

using namespace std;

int main()
{
	cout << "Matrix a(4);" << endl;
	Matrix a(4);
	cout << a << endl;
	cout << "Matrix b(3);" << endl;
	Matrix b(3);
	cout << b << endl;
	cout << "Matrix b, row 0, col 0 set to 13" << endl;
	b.set_value(0, 0, 13);
	cout << b << endl;
	cout << "Matrix b++" << endl;
	b++;
	cout << b << endl;
	

	int wrong_size[] = { 1, 2, 3 };
	Matrix c(wrong_size, 3);

	b.set_value(0, 0, -1);
	b.set_value(0,0, 13);
	b.clear();

	Matrix identity = a.identity();
	cout << identity << endl;

	Matrix d(2);
	Matrix e(2);

	if (d == e) { cout << "equal" << endl; }
	if (d >= e) { cout << "c is greater than d" << endl; }

	Matrix f = d + e;
	cout << "F: \n" << f << endl; //error

	d += a;

	cout << "D: \n" << d << endl; //error

	system("pause");
	return 0;
}
