import std;

using namespace std;

void g() { throw invalid_argument { "Some exception" }; }

void f()
{
	try {
		g();
	} catch (const exception& e) {
		println("caught in f(): {}", e.what());
		throw;  // rethrow
	}
}

int main()
{
	try {
		f();
	} catch (const invalid_argument& e) {
		println("invalid_argument caught in main(): {}", e.what());
	} catch (const exception& e) {
		println("exception caught in main(): {}", e.what());
	}
}
