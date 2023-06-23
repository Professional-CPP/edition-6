import std;
import spreadsheet_cell;

using namespace std;

template <typename T>
optional<size_t> Find(const T& value, const T* arr, size_t size)
{
	for (size_t i{ 0 }; i < size; ++i) {
		if (arr[i] == value) {
			return i; // Found it; return the index.
		}
	}
	return {}; // Failed to find it; return empty optional.
}

template <typename T, size_t N>
optional<size_t> Find(const T& value, const T(&arr)[N])
{
	return Find(value, arr, N);
}

int main()
{
	int myInt{ 3 }, intArray[]{ 1, 2, 3, 4 };
	const size_t sizeIntArray{ size(intArray) };

	optional<size_t> res;
	res = Find(myInt, intArray, sizeIntArray);        // calls Find<int> by deduction.
	res = Find<int>(myInt, intArray, sizeIntArray);   // calls Find<int> explicitly.
	if (res) { println("{}", *res); }
	else { println("Not found"); }

	double myDouble{ 5.6 }, doubleArray[]{ 1.2, 3.4, 5.7, 7.5 };
	const size_t sizeDoubleArray{ size(doubleArray) };

	res = Find(myDouble, doubleArray, sizeDoubleArray);         // calls Find<double> by deduction.
	res = Find<double>(myDouble, doubleArray, sizeDoubleArray); // calls Find<double> explicitly.
	if (res) { println("{}", *res); }
	else { println("Not found"); }

	//res = Find(myInt, doubleArray, sizeDoubleArray);        // DOES NOT COMPILE! Arguments are different types.
	res = Find<double>(myInt, doubleArray, sizeDoubleArray);  // calls Find<double> explicitly, even with myInt.

	SpreadsheetCell cell1{ 10 };
	SpreadsheetCell cellArray[]{ SpreadsheetCell{ 4 }, SpreadsheetCell{ 10 } };
	const size_t sizeCellArray{ size(cellArray) };

	res = Find(cell1, cellArray, sizeCellArray);                  // calls Find<SpreadsheetCell> by deduction.
	res = Find<SpreadsheetCell>(cell1, cellArray, sizeCellArray); // calls Find<SpreadsheetCell> explicitly.

	res = Find(myInt, intArray);
}
