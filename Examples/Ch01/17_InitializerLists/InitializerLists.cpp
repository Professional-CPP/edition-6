import std;

using namespace std;

int sum(initializer_list<int> values)
{
	int total{ 0 };
	for (int value : values) {
		total += value;
	}
	return total;
}

int main()
{
	int a{ sum({ 1, 2, 3 }) };
	int b{ sum({ 10, 20, 30, 40, 50, 60 }) };

	println("{}", a);
	println("{}", b);

	//int c{ sum({ 1, 2, 3.0 }) }; // Error
}
