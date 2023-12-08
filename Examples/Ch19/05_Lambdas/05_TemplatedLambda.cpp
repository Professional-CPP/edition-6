import std;

using namespace std;

int main()
{
	{
		auto lambda{ [](const auto& values) {
			using V = decay_t<decltype(values)>; // The real type of the vector.
			using T = typename V::value_type;    // The type of the elements of the vector.
			T someValue { };
		} };

		vector values{ 1, 2, 100, 5, 6 };
		lambda(values);
	}

	{
		auto lambda{ [] <typename T> (const vector<T>& values) {
			T someValue{ };
		} };

		vector values{ 1, 2, 100, 5, 6 };
		lambda(values);
	}
}
