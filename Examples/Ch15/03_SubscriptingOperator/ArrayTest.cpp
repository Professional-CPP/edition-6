import array;
import std;

using namespace std;

void printArray(const Array<int>& arr)
{
	for (size_t i{ 0 }; i < arr.getSize(); ++i) {
		print("{} ", arr[i]); // Calls the const operator[] because arr is a const object.
	}
	println("");
}

int main()
{
	{
		Array<int> myArray;
		for (size_t i{ 0 }; i < 20; i += 2) {
			myArray.setElementAt(i, 100);
		}
		for (size_t i{ 0 }; i < 20; ++i) {
			print("{} ", myArray.getElementAt(i));
		}
		println("");
	}


	{
		Array<int> myArray;
		for (size_t i{ 0 }; i < 20; i += 2) {
			myArray[i] = 100;	// Calls the non-const operator[] because myArray is a non-const object.
		}
		for (size_t i{ 0 }; i < 20; ++i) {
			print("{} ", myArray[i]);
		}

		println("");

		printArray(myArray);
	}
}
