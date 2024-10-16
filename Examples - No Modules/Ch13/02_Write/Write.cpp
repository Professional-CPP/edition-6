#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	const char* test{ "hello there" };
	cout.write(test, strlen(test));
}
