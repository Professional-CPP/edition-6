static thread_local int x1; // OK, internal linkage (See Chapter 11)
thread_local int x2;        // OK, external linkage (See Chapter 11)

class Foo
{
	static thread_local int x3; // OK
	//thread_local int x4;      // Error!
};


void f()
{
	static thread_local int x5; // OK
	thread_local int x6;        // OK, implicitly static!
}

int main()
{
}
