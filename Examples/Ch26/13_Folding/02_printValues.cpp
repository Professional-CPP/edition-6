import std;

using namespace std;

template<typename... Values>
void printValues(const Values&... values)
{
	(println("{}", values), ...);
}

int main()
{
	printValues(1, "test", 2.34);
}