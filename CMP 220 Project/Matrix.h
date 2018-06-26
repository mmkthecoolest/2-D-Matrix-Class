#include <iostream>
using namespace std;
#ifndef Matrix_h
#define Matrix_h
class Matrix { //class declaration
			   //declaraing friend functions
	friend ostream & operator<<(ostream & out, const Matrix &a);
	friend istream & operator >> (istream & in, const Matrix &a);
public:
	Matrix(int r = 2, int c = 3); //default constructor
	Matrix(const Matrix&); //copy constructor
	~Matrix(); //destructor
			   //get functions
	int get(int r, int c) const;
	int getRow() const;
	int getColumn() const;
	void set(int r, int c, int value); //set function
	Matrix operator-(); //Matrix negation
	Matrix & operator++(); //Matrix pre-increment
	Matrix & operator--(); //Matrix pre-decrement
	Matrix &operator=(const Matrix &a); //Matrix assignment
	//Matrix addition
	Matrix operator+(const int &a);
	Matrix operator+(const Matrix &a);
	//Matrix subtraction
	Matrix operator-(const int &a);
	Matrix operator-(const Matrix &a);
	//Matrix multiplication
	Matrix operator*(const int &a);
	Matrix operator*(const Matrix &a);
	//Matrix "+=" operation
	Matrix &operator+=(const int &a);
	Matrix &operator+=(const Matrix &a);
	//Matrix "-=" operation
	Matrix &operator-=(const int &a);
	Matrix &operator-=(const Matrix &a);
	//Matrix "*=" operation
	Matrix &operator*=(const int &a);
	Matrix &operator*=(const Matrix &a);
	bool operator==(const Matrix &a); //Matrix equality
	bool operator!=(const Matrix &a); //Matrix inequality
	int & operator()(int r, int c); //double scripting operator (left hand side)
	const int & operator()(int r, int c) const; //double scripting operator (right hand side)
private:
	int row; //number of rows
	int col; //number of cols
	int **arr;
};
double SumMatrixElements(const Matrix &a);//returns the sum of the elements within a Matrix
double stdev(const Matrix &a);//returns the standard deviation of the Matrix
#endif
