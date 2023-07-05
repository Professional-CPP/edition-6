import memory_demo;

using namespace std;

int main()
{
	MemoryDemo* mem{ new MemoryDemo{} };
	delete mem;

	mem = new MemoryDemo[10];
	delete [] mem;

	mem = new (nothrow) MemoryDemo{};
	delete mem;

	mem = new (nothrow) MemoryDemo[10];
	delete [] mem;

	MemoryDemo* memp{ new(5) MemoryDemo{} };
	delete memp;
}
