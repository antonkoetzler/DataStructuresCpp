// Program: Basic Matrix Arithmetic
// Author: Anton Koetzler-Faust
//
// Operations: +, -, *

#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <utility>
using namespace std;

class Matrix
{
public:
	// x by x matrix with all 0s
	Matrix(int size) { alloc(size, size); }
	// x by y matrix with all 0s
	Matrix(int x, int y) { alloc(x, y); }


	~Matrix() {}

	// Allocates a matrix WITH ALL 0s
	void alloc(int x, int y)
	{
		// Creating a "row vector" to add to our empty columns within our matrix
		vector<float> row;
		for (int i = 0; i < y; i++) row.push_back(0);

		data.clear(); // Just in case, we'll clear the matrix data

		// Adding to matrix
		for (int i = 0; i < x; i++) data.push_back(row);
	}

	void readMatrix()
	{
		for (int i = 0; i < data.size(); i++)
		{
			for (int o = 0; o < data[i].size(); o++)
			{
				cout << "Enter data for ("<<i<<", "<<o<<"): ";
				cin >> data[i][o]; // Directly adding the data to our matrix
			}
		}
	}

	// Print
	void print()
	{
		for (size_t i = 0; i < data.size(); i++)
		{
			for (size_t o = 0; o < data[i].size(); o++)
			{
				// Allows for neater printing
				cout << fixed << setprecision(2) << data[i][o];
				if (o != (data[i].size() - 1)) cout << "   ";
			} cout << endl;
		}
	}

	pair<int, int> getDimensions() const
	{
		pair<int, int> returnData;

		returnData.first = data.size();

		// Checking if this matrix isn't empty
		if (data.size() > 0)
			returnData.second = data[0].size();
		else
			returnData.second = 0;

		return returnData;
	}

	// Operations (+, -, *, and /)
	Matrix operator + (const Matrix &m)
	{
		// For addition, matrices must have the same dimensions
		if (this->getDimensions() != m.getDimensions())
		{
			cout << "Invalid dimensions for addition operation" << endl;
			exit(1);
		}
		else
		{
			Matrix returnMatrix(this->getDimensions().first, this->getDimensions().second);

			// Where the adding takes place
			for (int i = 0; i < this->getDimensions().first; i++)
				for (int o = 0; o < this->getDimensions().second; o++)
					returnMatrix.data[i][o] = this->data[i][o] + m.data[i][o];

			return returnMatrix;
		}
	}
	Matrix operator - (const Matrix &m)
	{
		// For subtraction, matrices must have the same dimensions
		if (this->getDimensions() != m.getDimensions())
		{
			cout << "Invalid dimensions for subtraction operation" << endl;
			exit(1);
		}
		else
		{
			Matrix returnMatrix(this->getDimensions().first, this->getDimensions().second);

			// Where the subtracting takes place
			for (int i = 0; i < this->getDimensions().first; i++)
				for (int o = 0; o < this->getDimensions().second; o++)
					returnMatrix.data[i][o] = this->data[i][o] - m.data[i][o];

			return returnMatrix;
		}
	}
	Matrix operator * (const Matrix &m)
	{
		// For multiplication, the second dimension of this must equal the first dimension of m
		if (this->getDimensions().second != m.getDimensions().first)
		{
			cout << "Invalid dimensions for multiplication operation" << endl;
			exit(1);
		}
		else
		{
			// Dimensions of the resulting matrix are always the first dimension
			// of the first matrix and the second dimension of the second matrix
			Matrix returnMatrix(this->getDimensions().first, m.getDimensions().second);

			// --- Where the cross products take place ---
			// This loop indicates this's rows
			for (int i = 0; i < this->getDimensions().first; i++)
			{
				// The cross product is one number in our resulting matrix
				int crossProduct = 0;

				// Grabbing 'this' row, to not index this->data deep in our loop for simplicity
				vector<float> row = data[i];

				// This loop indicates m's columns, which each need to be 
				// calculated with this's rows for the multiplication process
				for (int o = 0; o < m.getDimensions().second; o++)
				{
					// This loop traverses an 'm' row amount.
					// The actual loop vertically traverses down a column of 'm'
					// however, to then get the cross product with a 'this' row.
					for (int p = 0; p < m.getDimensions().first; p++)
					{
						crossProduct += (m.data[p][o] * row[p]);

						// Adding our cross product of one number to our result
						if (p == (m.getDimensions().first - 1))
							returnMatrix.data[i][o] = crossProduct;
					} crossProduct = 0; // Reset cross product every 'm' column
				} 
			} 

			return returnMatrix;
		}
	}
	vector<float> operator[] (int index)
	{
		// Error handling
		if (index >= this->getDimensions().first)
		{
			cout << "Index out of range of matrix scope" << endl;
			exit(1);
		}

		return data[index];
	}
	// Replaces [][]
	float operator() (int x, int y)
	{
		// Error handling
		if (x >= this->getDimensions().first || y >= this->getDimensions().second)
		{
			cout << "One or both indexes out of matrix scope" << endl;
			exit(1);
		}
		
		return data[x][y];
	}

private:
	// Our matrix
	vector<vector<float>> data;
};
