import std;

using namespace std;

int main()
{
	// Create 3 forward lists using an initializer_list
	// to initialize their elements (uniform initialization).
	forward_list<int> list1{ 5, 6 };
	forward_list list2{ 1, 2, 3, 4 };  // CTAD is supported.
	forward_list list3{ 7, 8, 9 };

	// Insert list2 at the front of list1 using splice.
	list1.splice_after(list1.before_begin(), list2);

	// Add number 0 at the beginning of the list1.
	list1.push_front(0);

	// Insert list3 at the end of list1.
	// For this, we first need an iterator to the last element.
	auto iter{ list1.before_begin() };
	auto iterTemp{ iter };
	while (++iterTemp != end(list1)) {
		++iter;
	}
	list1.insert_after(iter, cbegin(list3), cend(list3));

	// Output the contents of list1.
	println("{:n}", list1);
}
