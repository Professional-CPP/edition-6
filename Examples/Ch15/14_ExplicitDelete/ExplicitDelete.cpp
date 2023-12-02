import std;

class MyClass
{
public:
	void* operator new(std::size_t) = delete;
	void* operator new[](std::size_t) = delete;
	void* operator new(std::size_t, const std::nothrow_t&) noexcept = delete;
	void* operator new[](std::size_t, const std::nothrow_t&) noexcept = delete;
};

int main()
{
	// It is possible to create instances of MyClass on the stack.
	MyClass classOnStack;

	// It is not possible to create them on the free store.
	// The following two lines do not compile.
	//MyClass* p1{ new MyClass };
	//MyClass* p2{ new MyClass[2] };
	//MyClass* p3{ new(std::nothrow) MyClass };
}
