#include "BST.h"

int main()
{
	std::cout << "Binary Search Tree Demo" << std::endl << std::endl;

	BST foo;
	foo.add(5);
	foo.add(5);
	foo.add(3);
	foo.add(6);

	std::cout << "Is 3 within the tree?: " << (foo.search(3) ? "Yes" : "No") << std::endl << std::endl;

	std::cout << "Simplistic preorder traversal" << std::endl;
	foo.print();

	return 0;
}
