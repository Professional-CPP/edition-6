import std;

using namespace std;

mutex mut1;
mutex mut2;

void process()
{
	unique_lock lock1{ mut1, defer_lock };
	unique_lock lock2{ mut2, defer_lock };
	lock(lock1, lock2);

	// Locks acquired.

} // Locks automatically released.

int main()
{
	process();
}
