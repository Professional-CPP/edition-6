import std;

using namespace std;

int main()
{
	size_t n{ 5 };
	wstring filename{ L"file1.txt" };
	wcout << n << L" bytes read from " << filename << endl;
	wcout << n << L" Bytes aus " << filename << L" gelezen" << endl;
}