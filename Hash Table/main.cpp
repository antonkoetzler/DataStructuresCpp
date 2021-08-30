#include "Hash.h"

int main()
{
	std::cout << std::endl << "Hash Table Demo" << std::endl << std::endl;

	Hash foo;

	pair<string, int> a("George", 5);
	pair<string, int> b("Anton", 19);
	pair<string, int> c("Lizzy", 40);
	pair<string, int> d("No", 60);
	pair<string, int> e("Roger", 80);

	foo.add(a);
	foo.add(b);
	foo.add(c);
	foo.add(d);
	foo.add(e);

	foo.print();

	return 0;
}
