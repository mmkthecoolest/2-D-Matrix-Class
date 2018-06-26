/*
Project 1 - Hassan - Muhammed - Amna
*/
#include "Matrix.h"
#include <iostream>
using namespace std;
int main() {	
	cout << "Please input rows and columns for Matrix A: ";
	int a, b;
	cin >> a >> b;
	
	cout << "Now creating Matrix A...\n";
	Matrix A(a, b);
	cin >> A;
	cout << "A=\n" << A << "Testing negate function...\n-A=\n" <<-A;

	cout << "Testing copy constructor on B with A...\n";
	Matrix B(A);
	cout << "B=\n" << B;
	
	cout << "Testing set function by setting the value of B(" << a - 1 << ", " << b - 1 << ") to 120...\n";
	B.set(a - 1, b - 1, 120);
	cout << "B=\n" << B;
	
	cout << "Testing boolean Matrix operators == and !=...\n";
	cout << "A == B : " << (A == B) << endl
		<< "A != B : " << (A != B) << endl;

	cout << "\nTesting pre-increment and pre-decrement operators on A...\n";
	cout << "A after ++A=\n" << ++A;
	cout << "A after --A=\n" << --A;

	cout << "Testing assignment operator by creating Matrix C and assigning it with values of B...\n";
	Matrix C = B;
	cout << "C = \n" << C;

	cout << "Testing +, -, and * operators with A and B...\n";
	cout << "A + B=\n" << A + B;
	cout << "A - B=\n" << A - B;
	cout << "A * B =\n" << A * B;

	const int int_const = 3;
	cout << "Testing +, -, and * operators with A and integer constant "<< int_const <<"...\n";
	cout << "A + "<< int_const<<" =\n" << A + int_const;
	cout << "A - " << int_const << " =\n" << A - int_const;
	cout << "A * " << int_const << " =\n" << A * int_const;
	
	cout << "Testing +=, -=, and *= operators with A and B...\n";
	A += B;
	cout << "A after += B =\n" << A;
	A -= B;
	cout << "A after -= B =\n" << A;
	A *= B;
	cout << "A after *= B =\n" << A;

	cout << "Testing +=, -=, and *= operators with A and integer constant " << int_const << "...\n";
	A += int_const;
	cout << "A after += " << int_const << " =\n" << A;
	A -= int_const;
	cout << "A after -= " << int_const << " =\n" << A;
	A *= int_const;
	cout << "A after *= " << int_const << " =\n" << A;

	cout << "Testing cascading operation A += C *= B - C + A * " << int_const << "...\n";
	A += C *= B - C + A * int_const;
	cout << "A =\n" << A;
	cout << "B =\n" << B;
	cout << "C =\n" << C;
	
	cout << "Testing default constructor for D...\n";
	Matrix D;

	cout << "D =\n" << D;

	cout << "sum of elements in A is " << SumMatrixElements(A) << endl;
	cout << "standard deviation of elements in A is " << stdev(A) << endl;
	return 0;
}