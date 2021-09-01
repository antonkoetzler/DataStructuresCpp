#include "Matrix.h"

int main()
{
	cout << endl << "Basic Matrix Arithmetic Program Demo" << endl << endl;
	cout << "You will have two matrices which you will fill with numbers,then every\noperation (+, -, *) will be performed with that information." << endl << endl;

	Matrix foo1(2); Matrix foo2(2);

	foo1.readMatrix(); cout << endl << endl; foo2.readMatrix(); cout << endl << endl;

	Matrix foo3 = foo1 + foo2;
	foo3.print(); cout << endl << endl;

	Matrix foo4 = foo1 - foo2;
	foo4.print(); cout << endl << endl;

	Matrix foo5 = foo1 * foo2;
	foo5.print(); cout << endl << endl;

	cout << "Getting index [1][1] of foo3, to show that double indexing is possible: " << foo3(1, 1) << endl << endl << endl;

	cout << "Getting the second row of foo3, to show that indexing [] is possible" << endl;
	vector<float> row = foo3[1];
	cout << "foo3[1]: ";
	for (size_t i = 0; i < row.size(); i++)
	{
		cout << row[i];

		if (i != (row.size() - 1)) cout << ", ";
	} cout << endl << endl;

	return 0;
}
