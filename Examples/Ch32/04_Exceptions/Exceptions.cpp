import std;

using namespace std;

void throwIf(bool throwIt)
{
	if (throwIt) {
		throw runtime_error{ "Here's my exception" };
	}
}

int main()
{
	try {
		throwIf(false); // Doesn't throw.
		throwIf(true);  // Throws.
	} catch (const runtime_error& e) {
		println(cerr, "Caught exception: {}", e.what());
		return 1;
	}
}
