#pragma once

#include <iostream>

class Matrix
{
public:
	Matrix(); // Empty matrix
	Matrix(int); // x by x matrix
	Matrix(int, int); // x by y matrix
	~Matrix();

	// Allocation
	void allocateMatrix();

	// Printers
	void printMatrix();
	void printDimensions();

private:
	int x, y;
	int **matrix;
};
