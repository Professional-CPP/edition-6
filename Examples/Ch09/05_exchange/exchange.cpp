import std;

using namespace std;

int main()
{
	int a{ 11 };
	int b{ 22 };

	println("Before exchange(): a = {}, b = {}", a, b);

	int returnedValue{ exchange(a, b) };

	println("After exchange():  a = {}, b = {}", a, b);
	println("exchange() returned: {}", returnedValue);
}