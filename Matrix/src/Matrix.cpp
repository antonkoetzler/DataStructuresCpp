#include "Matrix.h"

Matrix::Matrix(int dimension)
{
	xDimension = dimension;
	yDimension = dimension;

	matrix = new int[xDimension];
}
