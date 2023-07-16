import std;

using namespace std;

int main()
{
	vector values{ 11, 22, 33, 44, 55 };
	println("{:n}", values);

	// Shift elements to the left by 2 positions.
	auto newEnd{ shift_left(begin(values), end(values), 2) };
	// Resize the vector to its proper size.
	values.erase(newEnd, end(values));
	println("{:n}", values);

	// Shift elements to the right by 2 positions.
	auto newBegin{ shift_right(begin(values), end(values), 2) };
	// Resize the vector to its proper size.
	values.erase(begin(values), newBegin);
	println("{:n}", values);
}
