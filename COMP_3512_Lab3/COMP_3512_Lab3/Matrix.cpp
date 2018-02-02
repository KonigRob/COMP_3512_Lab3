#include "Matrix.hpp"
// COMP_3512_Lab3.cpp : Defines the entry point for the console application.
//

Matrix::Matrix() : dimensions{ 1 }, arr(new int[1]) 
{
	arr[0] = {0};
}

Matrix::Matrix(int n) : dimensions{ n }, arr{new int[dimensions*dimensions] }
{
	clear();
}

Matrix::Matrix(int n[], int size_of_array) : dimensions{ (int)sqrt(size_of_array) }
{
	if (pow(dimensions, 2) != size_of_array) {
		cerr << "Error, wrong size" << endl;
	}
	arr = new int[size_of_array];
	for (int i = 0; i < size_of_array; ++i) {
		arr[i] = n[i];
	}
}

Matrix::~Matrix()
{
	delete[] arr;
}

void Matrix::set_value(int row, int col, int new_value)
{
	arr[(row * dimensions) +  col] = new_value;
}

int Matrix::get_value(int row, int col) const
{
	return (row * dimensions) + col;
}

void Matrix::clear()
{
	for (int i = 0; i < dimensions * dimensions; ++i) {
		arr[i] = 0;
	}
}

Matrix Matrix::identity()
{
	Matrix mirror(dimensions);
	for (int i = 0; i < dimensions; ++i) {
		for (int j = 0; j < dimensions; ++j) {
			if (i == j) {
				arr[i * dimensions + j] == 1;
			}
			else {
				arr[i * dimensions + j] == 0;
			}
		}
	}
	return mirror;
}

ostream & operator<<(ostream & output, const Matrix & matrix)
{
	for (int i = 0; i < matrix.dimensions; ++i) {
		for (int j = 0; j < matrix.dimensions; ++j) {
			output << matrix.arr[i * matrix.dimensions + j];
		}
		output << "\n";
	}
	return output;
}

bool operator==(const Matrix & lefthand, const Matrix & righthand)
{
	if (lefthand.dimensions != righthand.dimensions) {
		return false;
	}
	for (int i = 0; i < lefthand.dimensions; ++i) {
		for (int j = 0; j < righthand.dimensions; ++j) {
			if (lefthand.get_value(i, j) != righthand.get_value(i, j)) {
				return false;
			}
		}
	}
	return true;
}

bool operator!=(const Matrix & lefthand, const Matrix & righthand)
{
	return !operator==(lefthand, righthand);
}

bool operator<(const Matrix & lefthand, const Matrix & righthand)
{
	return lefthand.dimensions < righthand.dimensions;
}

bool operator>(const Matrix & lefthand, const Matrix & righthand)
{
	return operator< (righthand, lefthand);
}

bool operator<=(const Matrix & lefthand, const Matrix & righthand)
{
	return !operator> (lefthand, righthand);
}

bool operator>=(const Matrix & lefthand, const Matrix & righthand)
{
	return !operator< (lefthand, righthand);
}

Matrix operator+(Matrix lefthand, const Matrix& righthand)
{
	lefthand += righthand;
	return lefthand;
}

Matrix operator-(Matrix lefthand, const Matrix& righthand)
{
	lefthand -= righthand;
	return lefthand;
}

Matrix & Matrix::operator++()
{
	for (int i = 0; i < dimensions; ++i) {
		for (int j = 0; j < dimensions; ++j) {
			int tmp = i * dimensions + j;
			arr[tmp] = 1 + arr[tmp];
		}
	}
	return *this;
}

Matrix Matrix::operator++(int)
{
	Matrix tmp(*this);
	operator++();
	return tmp;
}

Matrix & Matrix::operator--()
{
	for (int i = 0; i < dimensions; ++i) {
		for (int j = 0; j < dimensions; ++j) {
			int tmp = i * dimensions + j;
			arr[tmp] = arr[tmp] - 1;
		}
	}
	return *this;
}

Matrix Matrix::operator--(int)
{
	Matrix tmp(*this);
	operator--();
	return tmp;
}

void Matrix::swap(Matrix& lefthand, Matrix& righthand)
{
	using std::swap;
	swap(lefthand.dimensions, righthand.dimensions);
	swap(lefthand.arr, righthand.arr);
}

Matrix & Matrix::operator=(Matrix righthand)
{
	swap(*this, righthand);
	return *this;
}

Matrix & Matrix::operator+=(const Matrix& righthand)
{
	for (int i = 0; i < dimensions; ++i) {
		for (int j = 0; j < dimensions; ++j) {
			int tmp = i * dimensions + j;
			arr[tmp] += righthand.arr[tmp];
		}
	}
	return *this;
}

Matrix & Matrix::operator-=(const Matrix& righthand)
{
	for (int i = 0; i < dimensions; ++i) {
		for (int j = 0; j < dimensions; ++j) {
			int tmp = i * dimensions + j;
			arr[tmp] -= righthand.arr[tmp];
		}
	}
	return *this;
}
