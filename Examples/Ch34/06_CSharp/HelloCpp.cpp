import std;

using namespace std;

extern "C"
{
	__declspec(dllexport) int functionInDLL(const wchar_t* p)
	{
		wcout << format(L"The following string was received by C++: '{}'", p) << endl;
		return 42;    // Return some value...
	}
}
