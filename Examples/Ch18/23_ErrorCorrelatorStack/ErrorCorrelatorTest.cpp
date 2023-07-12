import error_correlator;
import std;

using namespace std;

int main()
{
	ErrorCorrelator ec;

	ec.addError(Error{ 3, "Unable to read file" });
	ec.addError(Error{ 1, "Incorrect entry from user" });
	ec.addError(Error{ 10, "Unable to allocate memory!" });

	while (true) {
		try {
			Error e{ ec.getError() };
			cout << e << endl;
		} catch (const out_of_range&) {
			println("Finished processing errors");
			break;
		}
	}
}
