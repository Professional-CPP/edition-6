import std;

using namespace std;

void g()
{
	throw invalid_argument{ "Some exception" };
}

void f()
{
	try {
		g();
	} catch (const invalid_argument& e) {
		println("caught in f(): {}", e.what());
		throw;  // rethrow
	}
}

int main()
{
	try {
		f();
	} catch (const invalid_argument& e) {
		println("caught in main(): {}", e.what());
	}
}