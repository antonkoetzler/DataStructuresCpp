#include "Hash.h"

int main()
{
	cout << endl << "Hash Table Demo" << endl << endl << endl;

	Hash foo;

	pair<string, int> a("George", 5);
	pair<string, int> b("Anton", 19);
	pair<string, int> c("Lizzy", 40);
	pair<string, int> d("Elise", 60);
	pair<string, int> e("Roger", 80);
	pair<string, int> f("Jimmy", 10);
	pair<string, int> g("Tommy", 50);
	pair<string, int> h("Sabrina", 92);

	foo.add(a);
	foo.add(b);
	foo.add(c);
	foo.add(d);
	foo.add(e);
	foo.add(f);
	foo.add(g);
	foo.add(h);

	cout << "--- Printing out the information added to our hash table ---" << endl << endl;
	foo.print(); cout << endl << endl;

	cout << "--- Deleting Tommy name from our hash table ---" << endl << endl;
	foo.del(2, 1); foo.print();


	return 0;
}
