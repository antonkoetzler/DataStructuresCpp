/*
Singly linked list data structure.
Implemented
- add
- search
- delete
- print

Author: Anton Koetzler-Faust
Email: antonkoetzler-faust@hotmail.com
*/

#include "DLL.h"

int main()
{
	std::cout << "Singly Linked List" << std::endl;

	DLL arr;

	// Program loop stuff
	bool run = true;
	char userInput;
	int userData;

	while (run)
	{
		std::cout << "Enter a command listed below ";
		std::cout << "to modify your linked list" << std::endl;

		// Commands
		std::cout << "a - add" << std::endl;
		std::cout << "s - search" << std::endl;
		std::cout << "d - delete" << std::endl;
		std::cout << "r - reverse print" << std::endl;
		std::cout << std::endl;

		// Command recognition
		std::cout << "Command: ";
		std::cin >> userInput;
		userInput = tolower(userInput);
		
		// Command recognition
		switch (userInput)
		{
			case 'a':
				std::cout << "Enter integer to add: ";
				std::cin >> userData;
				arr.add(userData);
				break;
			case 's':
				std::cout << "Enter integer to search: ";
				std::cin >> userData;

				std::cout << std::endl << std::endl;
				if (arr.search(userData))
					std::cout <<  userData << " found" << std::endl;
				else
					std::cout << userData << " not found" << std::endl;
				break;
			case 'd':
				std::cout << "Enter integer to delete: ";
				std::cin >> userData;

				std::cout << std::endl << std::endl;
				if (arr.del(userData))
					std::cout << userData << " deleted" << std::endl;
				else
					std::cout << userData << " not found" << std::endl;
				break;
			case 'r':
				std::cout << "Your lists's contents in reverse: ";
				arr.reversePrint();
				break;
			default:
				std::cout << "Command not recognized" << std::endl;
		}

		std::cout << std::endl << std::endl << "Your list's contents: ";
		arr.print();

		// Continuing the loop
		std::cout << std::endl << "Continue? (Y/N): ";
		std::cin >> userInput;
		userInput = tolower(userInput);

		// Contining the loop
		switch (userInput)
		{
			case 'n':
				run = false;
				break;
			case 'y':
				run = true;
				break;
			default:
				std::cout << "Y or N not entered, looping either way." << std::endl;
				run = true;
				break;
		}

		// Spacing
		for (int i = 0; i < 10; i++)
			std::cout << std::endl;
	}

	return 0;
}
