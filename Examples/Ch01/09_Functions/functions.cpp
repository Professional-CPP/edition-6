import std;

using namespace std;

void myFunction(int i, char c);

void myFunction(int i, char c)
{
	println("The value of i is {}.", i);
	println("The value of c is {}.", c);
}

int addNumbers(int number1, int number2)
{
	println("Entering function {}", __func__);
	return number1 + number2;
}

// With function return type deduction
//auto addNumbers(int number1, int number2)
//{
//	println("Entering function {}", __func__);
//	return number1 + number2;
//}

double addNumbers(double a, double b)
{
	return a + b;
}

int main()
{
	int someInt{ 6 };
	char someChar{ 'c' };
	myFunction(8, 'a');
	myFunction(someInt, 'b');
	myFunction(5, someChar);

	int sum{ addNumbers(5, 3) };

	println("{}", addNumbers(1, 2));        // Calls the integer version
	println("{}", addNumbers(1.11, 2.22));  // Calls the double version
}
