import std;

using namespace std;

int main()
{
	vector values { 1, 3, 6, 4, 6, 9 };
	int result1{ accumulate(cbegin(values), cend(values), 0) };
	int result2{ reduce(execution::par_unseq, cbegin(values), cend(values), 0) };
	println("result1 = {}", result1);
	println("result2 = {}", result2);
}
