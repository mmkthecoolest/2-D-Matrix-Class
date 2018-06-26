#include "Matrix.h"
#include <iostream>
#include <cmath>
using namespace std;

ostream & operator<<(ostream & out, const Matrix &a) //overloading the stream insertion  <<  operator 
{
	for (int i = 0; i < a.row; i++)
	{
		out << "| ";
		for (int j = 0; j < a.col; j++)
		{
			out << a(i, j) << " ";
		}
		out << "|" << endl;
	}
	out << endl;
	return out;
}

istream &operator >> (istream &in, const Matrix &a) //overloading the stream extraction >>  operator 
{
	for (int i = 0; i < a.row; i++)
		for (int j = 0; j < a.col; j++)
		{
			cout << "Input value for (" << i << ", " << j << "): ";
			in >> a.arr[i][j];
		}
	return in;
}

Matrix::Matrix(int r, int c) //array initialized with 0 values and default size of 2 rows and 3 cols
{
	row = r;
	col = c;
	arr = new int *[row];
	for (int i = 0; i < row; i++)
	{
		arr[i] = new int[col];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			(*this)(i, j) = 0;
		}
	}
}

Matrix::Matrix(const Matrix& a) //copy constructor
{
	row = a.row;
	col = a.col;
	arr = new int *[row];
	for (int i = 0; i < row; i++)
	{
		arr[i] = new int[col];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			(*this)(i, j) = a(i, j);
		}
	}
}

Matrix::~Matrix() //destructor
{
	for (int i = 0; i < row; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

//get functions 
int Matrix::get(int r, int c) const
{
	if (r >= row || c >= col || c < 0 || r < 0)
	{
		cout << "Row/Col Size Error. Exiting!" << endl;
		exit(1);
	}
	else {
		return (*this)(r, c);
	}
}

int Matrix::getRow() const
{
	return row;
}

int Matrix::getColumn() const
{
	return col;
}

void Matrix::set(int r, int c, int value) //set function
{
	if (r >= row || c >= col || c < 0 || r < 0)
	{
		cout << "Row/Col Size Error. Exiting!" << endl;
		exit(1);
	}
	else {
		(*this)(r, c) = value;
	}
}

Matrix Matrix::operator-() //Matrix negation
{
	Matrix negate(*this);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			negate(i, j) *= -1;

	return negate;
}

Matrix & Matrix::operator++() //Matrix pre-increment
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			(*this)(i, j)++;

	return *this;
}


Matrix & Matrix::operator--() //Matrix pre-decrement
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			(*this)(i, j)--;

	return *this;
}

Matrix & Matrix::operator=(const Matrix &a) //Matrix assignment
{
	if (row != a.row || col != a.col)
	{
		for (int i = 0; i < row; i++)
		{
			delete[] arr[i];
		}
		delete[] arr;

		row = a.row;
		col = a.col;
		arr = new int *[row];
		for (int i = 0; i < row; i++)
		{
			arr[i] = new int[col];
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			(*this)(i, j) = a(i, j);
		}
	}

	return *this;
}

//Matrix addition

Matrix Matrix::operator+(const int &a)
{
	Matrix sum(*this);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			sum(i, j) += a;

	return sum;
}

Matrix Matrix::operator+(const Matrix &a)
{
	if (row != a.row || col != a.col)
	{
		cout << "Rows or columns not equal" << endl;
		exit(1);
	}

	Matrix sum(row, col);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			sum(i, j) = (*this)(i, j) + a(i, j);

	return sum;
}

//Matrix subtraction

Matrix Matrix::operator-(const int &a)
{
	Matrix difference(*this);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			difference(i, j) -= a;

	return difference;
}

Matrix Matrix::operator-(const Matrix &a)
{
	if (row != a.row || col != a.col)
	{
		cout << "Rows or columns not equal" << endl;
		exit(1);
	}

	Matrix difference(row, col);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			difference(i, j) = (*this)(i, j) - a(i, j);

	return difference;
}

//Matrix multiplication

Matrix Matrix::operator*(const int &a)
{
	Matrix product(*this);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			product(i, j) *= a;

	return product;
}

Matrix Matrix::operator*(const Matrix &a)
{
	if (col != a.row)
	{
		cout << "Multiplication not possible.\n";
		exit(1);
	}

	Matrix product(row, a.col);

	for (int i = 0; i < product.row; i++)
	{
		for (int j = 0; j < product.col; j++)
		{
			int sum = 0;
			for (int k = 0; k < col; k++)
				sum += (*this)(i, k) * a(k, j);

			product(i, j) = sum;
		}
	}

	return product;
}

//Matrix "+=" operation

Matrix &Matrix::operator+=(const int &a)
{
	*this = *this + a;

	return *this;
}

Matrix &Matrix::operator+=(const Matrix &a)
{
	*this = *this + a;

	return *this;
}

//Matrix "-=" operation

Matrix &Matrix::operator-=(const int &a)
{
	*this = *this - a;

	return *this;
}

Matrix &Matrix::operator-=(const Matrix &a)
{
	*this = *this - a;

	return *this;
}

//Matrix "*=" operation

Matrix &Matrix::operator*=(const int &a)
{
	*this = *this * a;

	return *this;
}

Matrix &Matrix::operator*=(const Matrix &a)
{
	*this = *this * a;

	return *this;
}

bool Matrix::operator==(const Matrix &a) //Matrix equality
{
	if (row != a.row || col != a.col)
		return 0;

	for (int i = 0; i < a.row; i++)
		for (int j = 0; j < a.col; j++)
			if ((*this)(i, j) != a(i, j))
				return 0;

	return 1;
}

bool Matrix::operator!=(const Matrix &a) //Matrix inequality 
{
	if (row != a.row || col != a.col)
		return 1;

	for (int i = 0; i < a.row; i++)
		for (int j = 0; j < a.col; j++)
			if ((*this)(i, j) != a(i, j))
				return 1;

	return 0;
}

int & Matrix::operator()(int r, int c) //double scripting operator (left hand side)
{
	if (r >= row || c >= col || c < 0 || r < 0)
	{
		cout << "Out of range Error" << endl;
		exit(1);
	}
	return arr[r][c];
}

const int & Matrix::operator()(int r, int c) const //double scripting operator (right hand side)
{
	if (r >= row || c >= col || c < 0 || r < 0)
	{
		cout << "Out of range Error" << endl;
		exit(1);
	}
	return arr[r][c];
}

double SumMatrixElements(const Matrix &a) //returns the sum of the elements within a Matrix
{
	double sum = 0;
	
	int r = a.getRow();
	int c = a.getColumn();
	
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			sum += a(i, j);

	return sum;
}

double stdev(const Matrix &a)//returns the standard deviation of the Matrix
{
	int r = a.getRow();
	int c = a.getColumn();
	double x_average = SumMatrixElements(a) / (r * c);
	double sum = 0;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			sum += pow((a(i, j) - x_average), 2);

	return sqrt(sum / (r*c - 1));
}