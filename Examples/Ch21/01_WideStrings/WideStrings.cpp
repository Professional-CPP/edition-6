import std;

using namespace std;

int main()
{
	wchar_t myWideCharacter{ L'm' };
	wcout << L"I am a wide-character string literal." << endl;
	wcout << format(L"myWideCharacter is {}", myWideCharacter) << endl;
}
