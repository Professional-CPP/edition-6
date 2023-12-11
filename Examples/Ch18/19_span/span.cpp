import std;

using namespace std;

//void print(const vector<int>& values)
//{
//	for (const auto& value : values) {
//		print("{} ", value);
//	}
//	println("");
//}
//
//void print(const int values[], size_t count)
//{
//	for (size_t i{ 0 }; i < count; ++i) {
//		print("{} ", values[i]);
//	}
//	println("");
//}

void print(span<const int> values)
{
	for (const auto& value : values) {
		print("{} ", value);
	}
	println("");
}

int main()
{
	vector v{ 11, 22, 33, 44, 55, 66 };

	// Pass the whole vector, implicitly converted to a span.
	print(v);

	// Pass an explicitly created span.
	span mySpan{ v };
	print(mySpan);

	// Create a subview and pass that.
	span subspan{ mySpan.subspan(2, 3) };
	print(subspan);

	// Pass a subview created in-line.
	print({ v.data() + 2, 3 });

	// Pass an std::array.
	array<int, 5> arr{ 5, 4, 3, 2, 1 };
	print(arr);
	print({ arr.data() + 2, 3 });

	// Pass a C-style array.
	int carr[]{ 9, 8, 7, 6, 5 };
	print(carr);            // The entire C-style array.
	print({ carr + 2, 3 }); // A subview of the C-style array.
}
