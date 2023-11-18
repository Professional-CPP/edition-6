import std;

using namespace std;

int main()
{
	map<int, int> src{ { 1, 11 },{ 2, 22 } };
	map<int, int> dst{ { 2, 22 },{ 3, 33 },{ 4, 44 },{ 5, 55 } };
	dst.merge(src);
	println("src = {}", src);
	println("dst = {}", dst);
}
