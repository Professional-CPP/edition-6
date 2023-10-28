static thread_local int x1; // OK, internal linkage
thread_local int x2;        // OK, external linkage

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
