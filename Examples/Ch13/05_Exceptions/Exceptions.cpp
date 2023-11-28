import std;

using namespace std;

int main()
{
	cout.exceptions(ios::failbit | ios::badbit | ios::eofbit);
	try {
		cout << "Hello World." << endl;
	} catch (const ios_base::failure& ex) {
		cerr << "Caught exception: " << ex.what()
			<< ", error code = " << ex.code() << endl;
	}
}
