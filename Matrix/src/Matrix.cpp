#include "Matrix.h"

Matrix::Matrix()
{
	x = 0; y = 0;
	matrix = nullptr;
}

Matrix::Matrix(int dimension)
{
	x = dimension; y = dimension;
	matrix = nullptr; allocateMatrix();
}

Matrix::Matrix(int xDimension, int yDimension)
{
	x = xDimension; y = yDimension;
	matrix = nullptr; allocateMatrix();
}

Matrix::~Matrix()
{
	for (int i = 0; i < x; i++)
		delete[] matrix[i];
	delete[] matrix;
}

void Matrix::allocateMatrix()
{
	matrix = new int*[x];

	for (int i = 0; i < x; i++)
	{
		matrix[i] = new int[y];

		for (int o = 0; o < y; o++)
			matrix[i][o] = 0;
	}
}

void Matrix::printMatrix()
{
	for (int i = 0; i < x; i++)
	{
		for (int o = 0; o < y; o++)
			std::cout << matrix[i][o] << "  ";
		std::cout << std::endl << std::endl;
	}
}

void Matrix::printDimensions()
{
	std::cout << "x Dimension: " << x << std::endl;
	std::cout << "y Dimension: " << y << std::endl;
	std::cout << std::endl << std::endl;
}
