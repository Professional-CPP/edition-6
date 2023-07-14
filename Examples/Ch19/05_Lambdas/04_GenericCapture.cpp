import std;

using namespace std;

int main()
{
	{
		double pi{ 3.1415 };
		auto myLambda{ [myCapture = "Pi: ", pi] { println("{}{}", myCapture, pi); } };
		myLambda();
	}

	{
		auto myPtr{ make_unique<double>(3.1415) };
		auto myLambda{ [p = move(myPtr)] { println("{}", *p); } };
		myLambda();
	}

	{
		auto myPtr{ make_unique<double>(3.1415) };
		auto myLambda{ [myPtr = move(myPtr)] { println("{}", *myPtr); } };
		myLambda();
	}
}
