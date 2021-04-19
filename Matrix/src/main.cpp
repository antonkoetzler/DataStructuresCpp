#include "Matrix.h"

int main()
{
	Matrix* myMatrix = new Matrix(2, 3);

	myMatrix->printMatrix();
	myMatrix->replaceValue(0, 0, 5);
	myMatrix->printMatrix();

	delete myMatrix; return 0;
}