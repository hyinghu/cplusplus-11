#include <iostream>
#include <list>

std::ostream& operator<<(std::ostream& ostr, const std::list<int>& list)
{
	for (auto& i : list) {
		ostr << " " << i;
	}
	return ostr;
}

int main ()
{
	std::list<int> list1 = { 1, 2, 3, 4, 5 };
	std::list<int> list2 = { 10, 20, 30, 40, 50 };

	auto it = list1.begin();
	// Increments given iterator it by n elements.
	std::advance(it, 2);

	list1.splice(it, list2);

	std::cout << "list1: " << list1 << "\n";
	std::cout << "list2: " << list2 << "\n";

	list2.splice(list2.begin(), list1, it, list1.end());

	std::cout << "list1: " << list1 << "\n";
	std::cout << "list2: " << list2 << "\n";

	it = list2.begin();
	std::advance(it, 2);
	list2.splice(list2.begin(), list2, it);
	std::cout << "list2: " << list2 << "\n";
}


// output
// list1:  1 2 10 20 30 40 50 3 4 5
// list2:
// list1:  1 2 10 20 30 40 50
// list2:  3 4 5
// list2:  5 3 4

