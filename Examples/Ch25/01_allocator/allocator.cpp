import std;

class MyClass {};

int main()
{
	// Create an allocator to use.
	std::allocator<MyClass> alloc;

	// Allocate an uninitialized memory block for 1 instance of MyClass.
	auto* memory{ alloc.allocate(1) };

	// Use placement new operator to construct a MyClass in place.
	::new(memory) MyClass{};

	// Destroy MyClass instance.
	std::destroy_at(memory);

	// Deallocate memory block.
	alloc.deallocate(memory, 1);
	memory = nullptr;
}
