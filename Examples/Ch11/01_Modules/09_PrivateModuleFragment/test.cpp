import std;
import adder;

using namespace std;

int main()
{
	Adder adder;
	println("Value: {}", adder.add(20, 22));
	auto impl{ adder.getImplementation() };
	//auto result{ impl->add(20, 22) }; // Error!
}
