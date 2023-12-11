import std;

using namespace std;

void func(const map<int, int>& m)
{
	//println("{}", m[1]);  // Error
}

int main()
{
	map<int, int> m;
	m[1] = 11;
	m[2] = 22;
	m[3] = 33;
	func(m);
}
