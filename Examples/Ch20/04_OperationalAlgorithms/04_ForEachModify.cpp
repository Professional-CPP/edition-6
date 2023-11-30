import std;

using namespace std;

int main()
{
	vector values{ 11, 22, 33, 44 };
	
	// Double each element in the values vector.
	for_each(begin(values), end(values), [](auto& value) { value *= 2; });
	println("{:n}", values);
}
