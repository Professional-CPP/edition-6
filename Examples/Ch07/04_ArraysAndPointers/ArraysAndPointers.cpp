import std;

using namespace std;

void doubleInts(int* theArray, size_t size)
{
	for (size_t i{ 0 }; i < size; ++i) {
		theArray[i] *= 2;
	}
}

/*
void doubleInts(int theArray[], size_t size)
{
	for (size_t i{ 0 }; i < size; ++i) {
		theArray[i] *= 2;
	}
}
*/

/*
void doubleIntsStack(int (&theArray)[4])
{
	for (size_t i{ 0 }; i < 4; ++i) {
		theArray[i] *= 2;
	}
}
*/

template<size_t N>
void doubleIntsStack(int (&theArray)[N])
{
	for (size_t i{ 0 }; i < N; ++i) {
		theArray[i] *= 2;
	}
}

int main()
{
	int myIntArray[10]{};
	int* myIntPtr{ myIntArray };
	// Access the array through the pointer.
	myIntPtr[4] = 5;




	size_t arrSize{ 4 };
	int* freeStoreArray{ new int[arrSize] { 1, 5, 3, 4 } };
	doubleInts(freeStoreArray, arrSize);
	//doubleIntsStack(freeStoreArray);	// Does not work.
	delete[] freeStoreArray;
	freeStoreArray = nullptr;

	int stackArray[] { 5, 7, 9, 11 };
	arrSize = std::size(stackArray);	// Since C++17, requires <array>
	//arrSize = sizeof(stackArray) / sizeof(stackArray[0]); // Pre-C++17, see Ch1
	doubleInts(stackArray, arrSize);
	doubleInts(&stackArray[0], arrSize);

	doubleIntsStack(stackArray);
}
