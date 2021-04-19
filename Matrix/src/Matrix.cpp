#include "Matrix.h"

Matrix::Matrix(int dimension)
{
	allocateMatrix(dimension, dimension);
}

Matrix::Matrix(int x, int y) // Dimension args
{
	allocateMatrix(x, y);
}

void Matrix::allocateMatrix(int x, int y) // Dimension args
{
	std::vector<int> row;

	for (int i = 0; i < y; i++)
		row.push_back(0);

	for (int i = 0; i < x; i++)
		matrix.push_back(row);

	row.clear();
}

void Matrix::replaceValue(int x, int y, int value)
{
	
}

void Matrix::printMatrix()
{
	for (int i = 0; i < (int)matrix.size(); i++)
	{
		for (int o = 0; o < (int)matrix[i].size(); o++)
		{
			std::cout << matrix[i][o];

			if (o != (int)matrix[i].size() - 1)
				std::cout << "   ";
			else
				std::cout << std::endl << std::endl;
		}
	}
}
