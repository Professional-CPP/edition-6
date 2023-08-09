import std;

class Bar { };

class Foo
{
public:
	explicit Foo(const Bar& b) {}   //// Pass by reference-to-const.
};

Foo getFoo(bool condition, const Bar& b1, const Bar& b2)  //// 2x pass by reference-to-const.
{
	try {
		if (condition) { return Foo{ b1 }; }
		else { return Foo{ b2 }; }
	} catch (const std::exception& caughtException) { //// Catch exceptions by reference-to-const.
		/* ... */
	}
}

int main()
{
	Bar b1, b2;
	auto foo{ getFoo(true, b1, b2) };
}