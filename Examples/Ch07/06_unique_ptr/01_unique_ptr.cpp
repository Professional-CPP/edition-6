import std;

using namespace std;

class Simple
{
public:
	Simple() { println("Simple constructor called!"); }
	~Simple() { println("Simple destructor called!"); }

	void go() {}
};


void leaky()
{
	Simple* mySimplePtr{ new Simple{} };  // BUG! Memory is never released!
	mySimplePtr->go();
}


void couldBeLeaky()
{
	Simple* mySimplePtr{ new Simple{} };
	mySimplePtr->go();
	delete mySimplePtr;
}


void notLeaky()
{
	auto mySimpleSmartPtr{ make_unique<Simple>() };
	mySimpleSmartPtr->go();
}


void processData(Simple* simple)
{
	/* Use the simple pointer ... */
	simple->go();
}

int main()
{
	leaky();
	couldBeLeaky();
	notLeaky();

	unique_ptr<Simple> mySimpleSmartPtr{ new Simple{} };
	
	processData(mySimpleSmartPtr.get());

	mySimpleSmartPtr.reset();             // Free resource and set to nullptr
	mySimpleSmartPtr.reset(new Simple{}); // Free resource and set to a new

	Simple* simple{ mySimpleSmartPtr.release() }; // Release ownership
	// Use the simple pointer...
	delete simple;
	simple = nullptr;
}