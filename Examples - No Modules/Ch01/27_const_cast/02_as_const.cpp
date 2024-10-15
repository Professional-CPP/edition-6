#include <string>
#include <utility>

using namespace std;

int main()
{
	string str{ "C++" };
	const string& constStr{ as_const(str) };
}
