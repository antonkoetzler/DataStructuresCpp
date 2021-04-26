/*
KD-Tree data structure with various operations:
- add
- remove
- search
- print

***Only meant to hold integers for the sake of simplicity***

Author: Anton Koetzler-Faust
Email: antonkoetzler-faust@hotmail.com
*/

#pragma once

#include <iostream>
#include <vector>

class KD
{
public:
	KD(); // Empty KD-Tree

private:
	std::vector<int> data;

	KD* left;
	KD* right;
};
