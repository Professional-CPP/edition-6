import std;

using namespace std;

int main()
{
	locale locUSEng{ "en-US" };       // For Windows
	//locale locUSEng{ "en_US" };     // For Linux
	locale locBritEng{ "en-GB" };     // For Windows
	//locale locBritEng{ "en_GB" };   // For Linux

	wstring dollars{ use_facet<moneypunct<wchar_t>>(locUSEng).curr_symbol() };
	wstring pounds{ use_facet<moneypunct<wchar_t>>(locBritEng).curr_symbol() };

	wcout << L"In the US, the currency symbol is " << dollars << endl;
	wcout << L"In Great Britain, the currency symbol is " << pounds << endl;
}
