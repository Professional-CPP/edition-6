import std;

using namespace std;

mutex mut1;
mutex mut2;

void process()
{
	scoped_lock locks{ mut1, mut2 };
	//scoped_lock<mutex, mutex> locks{ mut1, mut2 };

	// Locks acquired.

} // Locks automatically released.

int main()
{
	process();
}
