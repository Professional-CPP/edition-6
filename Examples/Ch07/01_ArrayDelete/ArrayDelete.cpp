import std;

using namespace std;

class Simple
{
public:
	Simple() { println("Simple constructor called!"); }
	~Simple() { println("Simple destructor called!"); }
};

int main()
{
	Simple* mySimpleArray{ new Simple[4] };
	// Use mySimpleArray...
	delete[] mySimpleArray;
	mySimpleArray = nullptr;


	const size_t size{ 4 };
	Simple** mySimplePtrArray{ new Simple*[size] };

	// Allocate an object for each pointer.
	for (size_t i{ 0 }; i < size; ++i) { mySimplePtrArray[i] = new Simple{}; }

	// Use mySimplePtrArray ...

	// Delete each allocated object.
	for (size_t i{ 0 }; i < size; ++i) {
		delete mySimplePtrArray[i];
		mySimplePtrArray[i] = nullptr;
	}

	// Delete the array itself.
	delete[] mySimplePtrArray;
	mySimplePtrArray = nullptr;
}
