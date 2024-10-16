#include <print>
#include <span>
#include <spanstream>
#include <string>

using namespace std;

int main()
{
	char fixedBuffer[]{ "11 2.222 Hello" };

	ispanstream stream{ span{ fixedBuffer } };

	int i;
	double d;
	string str;
	stream >> i >> d >> str;

	println("Parsed data: int: {}, double: {}, string: {}", i, d, str);
}