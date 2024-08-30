#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

#include <iostream>
#include <vector>
#include <string>
#include <math.h> 

using namespace std;

class Matrix
{
private:
	std::vector<int> A; //matrix stored column-wise
	unsigned int m; //number of rows
	unsigned int n; //number of columns

public:
	Matrix();
	Matrix(const std::vector<int>& A, unsigned int n);
	Matrix(const std::vector<int>& A, unsigned int m, unsigned int n);
	int get(unsigned int i, unsigned int j) const;
	bool set(unsigned int i, unsigned int j, int aij);
	unsigned int size(unsigned int dim) const;
	const Matrix add(const Matrix& rhs) const;
	const Matrix sub(const Matrix& rhs) const;
	const Matrix mult(const Matrix& rhs) const;
	const Matrix mult(int c) const;
	const Matrix power(unsigned int n) const;
	void trans(const Matrix& B) const;
	int determinant(const Matrix& rhs, int n);
	Matrix inverse(const Matrix& rhs);
	void output() const;
};
#endif