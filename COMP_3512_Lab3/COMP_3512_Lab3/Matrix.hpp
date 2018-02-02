#pragma once

#include <math.h>
#include <ostream>
using namespace std;

class Matrix
{
	int dimensions;
	int * arr;

public:
	Matrix();
	Matrix(int);
	Matrix(int [], int);
	~Matrix();
	void set_value(int, int, int);
	int get_value(int, int);
	void clear();
	Matrix identity();
	friend ostream& operator<<(ostream&, const Matrix&);
	friend bool operator<=(const Matrix&, const Matrix&);
};

