#pragma once

#include <iostream>
#include <vector>

class Matrix
{
public:
	Matrix() {}
	Matrix(int); // x by x
	Matrix(int, int); // x by y

	// Allocation
	void allocateMatrix(int, int);
	void replaceValue(int, int, int);

	// Printer
	void printMatrix();

private:
	std::vector<std::vector<int>> matrix;
};
