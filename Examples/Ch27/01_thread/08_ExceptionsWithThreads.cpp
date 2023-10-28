import std;

using namespace std;

void doSomeWork()
{
	for (int i{ 0 }; i < 5; ++i) {
		println("{}", i);
	}
	println("Thread throwing a runtime_error exception...");
	throw runtime_error{ "Exception from thread" };
}

void threadFunc(exception_ptr& err)
{
	try {
		doSomeWork();
	} catch (...) {
		println("Thread caught exception, returning exception...");
		err = current_exception();
	}
}

void doWorkInThread()
{
	exception_ptr error;
	// Launch thread.
	jthread t{ threadFunc, ref(error) };
	// Wait for thread to finish.
	t.join();
	// See if thread has thrown any exception.
	if (error) {
		println("Main thread received exception, rethrowing it...");
		rethrow_exception(error);
	} else {
		println("Main thread did not receive any exception.");
	}
}

int main()
{
	try {
		doWorkInThread();
	} catch (const exception& e) {
		println("Main function caught: '{}'", e.what());
	}
}
