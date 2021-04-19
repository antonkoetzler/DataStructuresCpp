/*
Program that creates a mutable matrix

Author: Anton Koetzler-Faust
Email: antonkoetzler-faust@hotmail.com
*/

#include "Matrix.h"
#include <string>

int main ()
{
	Matrix* myMatrix = new Matrix();

	std::string commandInput;
	char continueInput;
	int x, y, value;
	bool run = true;

	std::cout << "Matrix Data Structure Program" << std::endl;
	std::cout << std::endl << "An empty matrix has been created." << std::endl;
	std::cout << std::endl << std::endl;

	while (run)
	{
		std::cout << "Commands" << std::endl;
		std::cout << "resize - Resize matrix dimensions" << std::endl;
		std::cout << "read - Read matrix (set values for each coordinate)" << std::endl;
		std::cout << "replace - Replaces a coordinate's value" << std::endl;

		std::cout << std::endl << std::endl << "Command: ";
		std::cin >> commandInput;

		if (commandInput == "resize")
		{
			std::cout << "New x dimension: ";
			std::cin >> x;

			std::cout << "New y dimension: ";
			std::cin >> y;

			myMatrix->resizeMatrix(x, y);

			std::cout << std::endl << std::endl;
		}
		else if (commandInput == "read")
		{
			myMatrix->readMatrix();

			std::cout << std::endl << std::endl;
		}
		else if (commandInput == "replace")
		{
			std::cout << "x coordinate: ";
			std::cin >> x;

			std::cout << "y coordinate: ";
			std::cin >> y;

			std::cout << "Value to replace with: ";
			std::cin >> value;

			myMatrix->replaceValue(x, y, value);

			std::cout << std::endl << std::endl;
		}
		else
		{
			std::cout << "Wrong/unknown command." << std::endl;
		}

		myMatrix->printMatrix(); std::cout << std::endl << std::endl;

		std::cout << "Continue? (Y/N): ";
		std::cin >> continueInput;

		continueInput = tolower(continueInput);

		if (continueInput == 'n')
			run = false;
		else
			std::cout << "Y or N not received, will continue running" << std::endl;
	}

	return 0;
}
