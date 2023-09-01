import std;

using namespace std;

class Demo
{
public:
	int get() { return 5; }
};

int get() { return 10; }

namespace NS
{
	int get() { return 20; }
}

int main()
{
	Demo d;
    println("{}", d.get());      // prints 5
    println("{}", NS::get());    // prints 20
    println("{}", ::get());      // prints 10
    println("{}", get());        // prints 10
}
