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
	int get_value(int, int) const;
	void clear();
	Matrix identity();
	friend ostream& operator<<(ostream&, const Matrix&);
	friend bool operator==(const Matrix&, const Matrix&);
	friend bool operator!=(const Matrix&, const Matrix&);
	friend bool operator<(const Matrix&, const Matrix&);
	friend bool operator>(const Matrix&, const Matrix&);
	friend bool operator<=(const Matrix&, const Matrix&);
	friend bool operator>=(const Matrix&, const Matrix&);
	Matrix& operator++();
	Matrix operator++(int);
	Matrix& operator--();
	Matrix operator--(int);
	friend Matrix operator+(Matrix, const Matrix&);
	friend Matrix operator-(Matrix, const Matrix&);
	void swap(Matrix&, Matrix&);
	Matrix& operator=(Matrix);
	Matrix& operator+=(const Matrix&);
	Matrix& operator-=(const Matrix&);
};

