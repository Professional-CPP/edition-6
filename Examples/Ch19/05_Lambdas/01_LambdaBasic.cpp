import std;

using namespace std;

class Person
{
public:
	explicit Person(std::string name) : m_name{ std::move(name) } { }
	const std::string& getName() const { return m_name; }

private:
	std::string m_name;
};

int main()
{
	// Basic lambda
	auto basicLambda{ [] { println("Hello from Lambda"); } };
	basicLambda();

	// Lambda with parameters
	auto parametersLambda{ [](int value) { println("The value is {}", value); } };
	parametersLambda(42);

	// Lambda returning a value
	auto sumLambda{ [](int a, int b) -> int { return a + b; } };
	int sum{ sumLambda(11, 22) };
	println("The result is {}", sum);

	// Lambda returning a value, with return type omitted
	auto sumLambda2{ [](int a, int b) { return a + b; } };
	sum = sumLambda2(11, 22);
	println("The result is {}", sum);

	// Demonstrating stripping of reference and const qualifiers
	Person p{ "John Doe" };
	decltype(auto) name1{ [](const Person& person) { return person.getName(); }(p) };
	decltype(auto) name2{ [](const Person& person) -> decltype(auto) { return person.getName(); }(p) };

	// Lambda capturing a variable by value
	double data{ 1.23 };
	auto capturingVLambda{ [data] { println("Data = {}", data); } };
	capturingVLambda();

	// Lambda capturing a variable by value
	auto capturingVLambda2{ [data]() mutable { data *= 2; println("Data = {}", data); } };
	capturingVLambda2();

	// Lambda capturing a variable by reference
	auto capturingRLambda{ [&data] { data *= 2; } };
	capturingRLambda();
	println("Data = {}", data);
}
