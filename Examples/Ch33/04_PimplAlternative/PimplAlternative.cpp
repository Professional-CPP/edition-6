import std;

using namespace std;

// Public interface (to be included in the rest of the program,
// shared from a library, ...)
class Foo
{
public:
	virtual ~Foo() = default;  // Always a virtual destructor!
	Foo(const Foo&) = default;
	Foo& operator=(const Foo&) = default;
	Foo(Foo&&) = default;
	Foo& operator=(Foo&&) = default;

	static unique_ptr<Foo> create();  // Factory function.
	// Public functionality...
	virtual void bar() = 0;
protected:
	Foo() = default; // Protected default constructor.
};

// Implementation
class FooImpl : public Foo
{
public:
	void bar() override { /* ... */ }
};

unique_ptr<Foo> Foo::create()
{
	return make_unique<FooImpl>();
}

int main()
{
	auto fooInstance{ Foo::create() };
	fooInstance->bar();
}