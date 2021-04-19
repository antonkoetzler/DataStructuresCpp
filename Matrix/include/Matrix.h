#pragma once

#include <iostream>
#include <vector>

class Matrix
{
public:
	Matrix() {}
	Matrix(int); // x by x
	Matrix(int, int); // x by y
	~Matrix();

	// Allocation
	void allocateMatrix(int, int);
	void replaceValue(int, int, int);
	void readMatrix();
	void resizeMatrix(int, int);

	// Printer
	void printMatrix() const;

private:
	std::vector<std::vector<int>> matrix;
};
