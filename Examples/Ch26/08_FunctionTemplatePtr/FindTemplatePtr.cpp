import std;
import spreadsheet_cell;

using namespace std;

template <typename T>
optional<size_t> Find(const T& value, const T* arr, size_t size)
{
	println("original");
	for (size_t i{ 0 }; i < size; ++i) {
		if (arr[i] == value) {
			return i; // found it; return the index.
		}
	}
	return {}; // failed to find it; return empty optional.
}


optional<size_t> Find(const char* value, const char** arr, size_t size)
{
	println("overload");
	for (size_t i{ 0 }; i < size; ++i) {
		if (strcmp(arr[i], value) == 0) {
			return i; // found it; return the index.
		}
	}
	return {}; // failed to find it; return empty optional.
}

template <typename T>
optional<size_t> Find(T* value, T* const* arr, size_t size)
{
	println("ptr overload");
	for (size_t i{ 0 }; i < size; ++i) {
		if (*arr[i] == *value) {
			return i; // found it; return the index.
		}
	}
	return {}; // failed to find it; return empty optional.
}
int main()
{
	optional<size_t> res;

	int myInt{ 3 }, intArray[]{ 1, 2, 3, 4 };
	size_t sizeArray{ size(intArray) };
	res = Find(myInt, intArray, sizeArray);      // calls Find<int> by deduction
	res = Find<int>(myInt, intArray, sizeArray); // calls Find<int> explicitly

	double myDouble{ 5.6 }, doubleArray[]{ 1.2, 3.4, 5.7, 7.5 };
	sizeArray = size(doubleArray);
	res = Find(myDouble, doubleArray, sizeArray);         // calls Find<double> by deduction
	res = Find<double>(myDouble, doubleArray, sizeArray); // calls Find<double> explicitly

	const char* word{ "two" };
	const char* words[]{ "one", "two", "three", "four" };
	sizeArray = size(words);
	res = Find<const char*>(word, words, sizeArray);  // calls Find<const char*> explicitly
	res = Find(word, words, sizeArray);		          // calls overloaded Find for const char*s

	int* intPointer{ &myInt }, *pointerArray[]{ &myInt, &myInt };
	sizeArray = size(pointerArray);
	res = Find(intPointer, pointerArray, sizeArray);    // calls the overloaded Find for pointers

	SpreadsheetCell cell1{ 10 };
	SpreadsheetCell cellArray[]{ SpreadsheetCell{ 4 }, SpreadsheetCell{ 10 } };
	sizeArray = size(cellArray);
	res = Find(cell1, cellArray, sizeArray);                  // calls Find<SpreadsheetCell> by deduction
	res = Find<SpreadsheetCell>(cell1, cellArray, sizeArray); // calls Find<SpreadsheetCell> explicitly

	SpreadsheetCell* cellPointer{ &cell1 };
	SpreadsheetCell *cellPointerArray[]{ &cell1, &cell1 };
	sizeArray = size(cellPointerArray);
	res = Find(cellPointer, cellPointerArray, sizeArray); // Calls the overloaded Find for pointers
}
