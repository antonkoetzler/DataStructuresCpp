#include "BST.h"
#include <string>

BST::BST()
{
	dataInit = nullptr;

	prev = left = right = nullptr;
}

BST::BST(int newData, BST* prevNode)
{
	dataInit = new Node(newData);

	prev = prevNode;

	left = right = nullptr;
}

void BST::add(int newData)
{
	// Root node case
	if (!prev && !dataInit)
		dataInit = new Node(newData);

	else
	{
		// Left child case
		if (newData < dataInit->data)
		{
			if (left == nullptr)
				left = new BST(newData, this);
			else
				left->add(newData);
		}

		// Right child case
		else
		{
			if (right == nullptr)
				right = new BST(newData, this);
			else
				right->add(newData);
		}
	}
}

void BST::print()
{
	int length = getLength(); // For spacing

	// Empty case
	if (length == 0)
	{
		std::cout << "Empty Tree" << std::endl << std::endl;
		return;
	}
	else
	{
		std::vector<int> values; getData(values);

		std::vector<std::vector<Node*>> BFS = BFSOrder(values);

		for (int i = 0; i < (int)BFS.size(); i++)
		{
			for (int i = 0; i < length; i++)
				std::cout << "  ";

			for (int o = 0; o < (int)BFS[i].size(); o++)
			{
				if (o != 0)
					for (int i = 0; i < length; i++)
						std::cout << "  ";

				if (BFS[i][o])
					std::cout << BFS[i][o]->data;
				else
					std::cout << " ";
			} std::cout << std::endl << std::endl;

			length--;
		}

		std::cout << std::endl << std::endl;

		BFS.clear();
	}
}

std::vector<std::vector<Node*>> BST::BFSOrder(std::vector<int>& values)
{
	std::vector<std::vector<Node*>> BFS;

	// Variables needed for this operations
	std::vector<Node*> transfer;
	Node* parent = nullptr;
	Node* current = nullptr;
	int height = getLength();
	int parentIndex;

	// Empty case
	if (height == 0)
		return BFS;

	for (int i = 0; i < height; i++)
	{
		// Root node case
		if (BFS.empty())
		{
			transfer.push_back(new Node(values[0]));
			BFS.push_back(transfer);
			transfer.clear();
			values.erase(values.begin());
		}

		// Root node children case
		else if ((int)BFS.size() == 1)
		{
			// Find left child
			for (int i = 0; i < (int)values.size(); i++)
			{
				if (values[i] < BFS[0][0]->data)
				{
					transfer.push_back(new Node(values[i]));
					values.erase(values.begin() + i);

					break;
				}

				else if (i == (int)values.size() - 1)
					transfer.push_back(nullptr);
			}
			
			// Find right child
			for (int i = 0; i < (int)values.size(); i++)
			{
				if (values[i] >= BFS[0][0]->data)
				{
					transfer.push_back(new Node(values[i]));
					values.erase(values.begin() + i);

					break;
				}

				else if (i == (int)values.size() - 1)
					transfer.push_back(nullptr);
			}

			BFS.push_back(transfer); transfer.clear();
		}

		// General node case
		else
		{
			// Starts at finding the left/right subtree's children
			// then their children until the whole tree is explored
			for (int i = 0; i < (int)BFS[BFS.size() - 1].size(); i++)
			{
				parentIndex = i * 0.5;
				parent = new Node(BFS[BFS.size() - 2][parentIndex]->data);

				current = new Node(BFS[BFS.size() - 1][i]->data);

				// Find left child
				for (int i = 0; i < (int)values.size(); i++)
				{
					if (values[i] < current->data)
					{
						if (current->data < parent->data)
						{
							transfer.push_back(new Node(values[i]));
							values.erase(values.begin() + i);

							break;
						}
						else if (current->data >= parent->data && values[i] >= parent->data)
						{
							transfer.push_back(new Node(values[i]));
							values.erase(values.begin() + i);

							break;
						}
					}

					else if (i == (int)values.size() - 1)
						transfer.push_back(nullptr);
				}

				// Find right child
				for (int i = 0; i < (int)values.size(); i++)
				{
					if (values[i] >= current->data)
					{
						if (current->data < parent->data && values[i] < parent->data)
						{
							transfer.push_back(new Node(values[i]));
							values.erase(values.begin() + i);

							break;
						}
						else if (current->data > parent->data)
						{
							transfer.push_back(new Node(values[i]));
							values.erase(values.begin() + i);

							break;
						}
					}

					else if (i == (int)values.size() - 1)
						transfer.push_back(nullptr);
				}
			}

			BFS.push_back(transfer); transfer.clear();
		}
	}

	values.clear(); return BFS;
}

bool BST::search(int searchData)
{
	if (!prev && !dataInit)
		return false;

	else
	{
		if (searchData == dataInit->data)
			return true;
		else
		{
			if (searchData < dataInit->data)
			{
				if (left)
					return left->search(searchData);
				else
					return false;
			}

			else
			{
				if (right)
					return right->search(searchData);
				else
					return false;
			}
		}
	}
}

bool BST::del(int delData)
{
	if (!prev && !dataInit)
		return false;

	else
	{
		if (delData == dataInit->data)
		{
			fillGaps();
			return true;
		}

		else
		{
			if (delData < dataInit->data)
			{
				if (left)
					return left->del(delData);
				else
					return false;
			}

			else
			{
				if (right)
					return right->del(delData);
				else
					return false;
			}
		}
	}
}

void BST::fillGaps()
{
	delete dataInit; dataInit = nullptr;

	if (left)
	{
		dataInit = new Node(left->getData());

		if (!left->left && !left->right)
		{
			delete left; left = nullptr;

			return;
		}

		left->fillGaps();
	}

	else if (right)
	{
		dataInit = new Node(right->getData());

		if (!right->left && !right->right)
		{
			delete right; right = nullptr;

			return;
		}

		right->fillGaps();
	}
}

int BST::getLength()
{
	int leftHeight = 0;
	int rightHeight = 0;

	// Empty case
	if (!prev && !dataInit)
		return 0;

	else
  {
    	if (left)
			  leftHeight = left->getLength();
    	if (right)
    		rightHeight = right->getLength();

    	if (leftHeight >= rightHeight)
    		return leftHeight + 1;
    	else
    		return rightHeight + 1;
    }
}

void BST::getData(std::vector<int>& values)
{
	if (dataInit)
		values.push_back(dataInit->data);

	if (left) left->getData(values);
	if (right) right->getData(values);
}
