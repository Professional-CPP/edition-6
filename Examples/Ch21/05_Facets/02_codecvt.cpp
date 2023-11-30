import std;

using namespace std;

int main()
{
	auto& facet{ use_facet<codecvt<wchar_t, char, mbstate_t>>(locale{ }) };
	string narrowString{ "Hello" };
	mbstate_t mb{};
	wstring wideString(narrowString.size(), '\0');
	const char* fromNext{ nullptr };
	wchar_t* toNext{ nullptr };
	facet.in(mb, narrowString.data(), narrowString.data() + narrowString.size(), fromNext,
		wideString.data(), wideString.data() + wideString.size(), toNext);
	wideString.resize(toNext - wideString.data());
	wcout << wideString << endl;
}
