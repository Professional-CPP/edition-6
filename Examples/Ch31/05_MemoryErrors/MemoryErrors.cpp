import std;

using namespace std;

void memoryLeak()
{
	int* p{ new int[1000] };
	return; // Not freeing p!
}

void mismatchedFree()
{
	int* p1{ (int*)malloc(sizeof(int)) };
	int* p2{ new int };
	int* p3{ new int[1000] };
	delete p1;    // Should use free()!
	delete [] p2; // Should use delete!
	free(p3);     // Should use delete []!
}

void doubleFree()
{
	int* p1{ new int[1000] };
	delete [] p1;
	int* p2{ new int[1000] };
	delete [] p1; // Freeing p1 twice!
} // Leaking memory of p2!

void freeUnallocated()
{
	int* p{ reinterpret_cast<int*>(10) };
	delete p; // p is not a valid pointer!
}

void freeStack()
{
	int x;
	int* p{ &x };
	delete p; // Freeing stack memory!
}



void accessInvalid()
{
	int* p{ reinterpret_cast<int*>(10) };
	*p = 5;    // p is not a valid pointer!
}

void accessFreed()
{
	int* p1{ new int };
	delete p1;
	*p1 = 5; // The memory pointed to by p1 has been freed!
}

void accessElsewhere()
{
	int x, y[10], z;
	x = 0;
	z = 0;
	for (int i{ 0 }; i <= 10; ++i) {
		y[i] = 5; // BUG for i==10! element 10 is past end of array
	}
}

void readUninitialized()
{
	int* p;
	print("{}", *p); // p is uninitialized!
}

int main()
{
	println("Memory leak");
	memoryLeak();

	println("Mismatched Free");
	mismatchedFree();
	
	println("Double Free");
	doubleFree();
	
	println("Free Unallocated");
	freeUnallocated();
	
	println("Free Stack");
	freeStack();
	
	println("Access Invalid");
	accessInvalid();
	
	println("Access Freed");
	accessFreed();
	
	println("Access Elsewhere");
	accessElsewhere();
	
	println("Read Uninitialized");
	readUninitialized();
}
