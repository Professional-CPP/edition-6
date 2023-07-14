import std;

using namespace std;

function<int(void)> multiplyBy2Lambda(int x)
{
	return [x]{ return 2 * x; };
}

// Using function return type deduction
//auto multiplyBy2Lambda(int x)
//{
//	return [x]{ return 2 * x; };
//}

int main()
{
	//function<int(void)> fn{ multiplyBy2Lambda(5) };
	//println("{}", fn());

	auto fn{ multiplyBy2Lambda(5) };
	println("{}", fn());
}