import person;
import std;

using namespace std;

int main()
{
	Person person{ "John", "Doe" };

	// Write person to standard output console.
	cout << person << endl;

	// Write person to a string stream.
	ostringstream output;
	output << person;
	// Verify the contents of the string stream.
	println("{}", output.str());

	// Read the person back from the string stream.
	istringstream input{ output.str() };
	Person person2;
	input >> person2;

	// Verify the read-back person.
	cout << person2 << endl;
}
