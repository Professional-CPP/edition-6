import std;

using namespace std;

mutex m1;
mutex m2;

void process()
{
	scoped_lock locks{ m1, m2 }; // Uses class template argument deduction, CTAD.
	//scoped_lock<mutex, mutex> locks{ m1, m2 };

	// Locks acquired.

} // Locks automatically released.

int main()
{
	process();
}
