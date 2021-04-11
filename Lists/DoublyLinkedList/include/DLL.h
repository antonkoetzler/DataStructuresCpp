#pragma once

#include <iostream>

class DLL
{
public:
	DLL();

private:
	int data;

	DLL* prev;
	DLL* next = nullptr;
};
