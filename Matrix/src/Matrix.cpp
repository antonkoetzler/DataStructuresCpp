#include "Matrix.h"

Matrix::Matrix(int dimension)
{
	allocateMatrix(dimension, dimension);
}

Matrix::Matrix(int x, int y) // Dimension args
{
	allocateMatrix(x, y);
}

Matrix::~Matrix()
{
	matrix.clear();
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
	for (int i = 0; i < (int)matrix.size(); i++)
	{
		for (int o = 0; o < (int)matrix[i].size(); o++)
		{
			if (i == x && o == y)
				matrix[i][o] = value;
		}
	}
}

void Matrix::readMatrix()
{
	int value;

	for (int i = 0; i < (int)matrix.size(); i++)
	{
		for (int o = 0; o < (int)matrix[i].size(); o++)
		{
			std::cout << "Enter value for (" << i << ", " << o << "): ";
			std::cin >> value;

			matrix[i][o] = value;
		}
	}
}

void Matrix::resizeMatrix(int x, int y) // New dimensions
{
	std::vector<int> row;
	std::vector<std::vector<int>> newMatrix;

	for (int i = 0; i < x; i++)
	{
		for (int o = 0; o < y; o++)
		{
			if (i > (int)matrix.size() - 1)
				row.push_back(0);
			else if (o > (int)matrix[i].size() - 1)
				row.push_back(0);
			else
				row.push_back(matrix[i][o]);
		}

		newMatrix.push_back(row);
		row.clear();
	}

	matrix.clear(); matrix = newMatrix;
	row.clear(); newMatrix.clear();
}

void Matrix::printMatrix() const
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

	std::cout << std::endl << std::endl;
}
