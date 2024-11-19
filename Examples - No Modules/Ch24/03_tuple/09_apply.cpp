#include <print>
#include <tuple>
#include <functional>

using namespace std;

int add(int a, int b)
{
	return a + b;
}

int main()
{
	println("{}", apply(add, tuple{ 39, 3 }));
}