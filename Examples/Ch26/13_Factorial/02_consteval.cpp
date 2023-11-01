import std;

using namespace std;

consteval unsigned long long factorial(int f)
{
	if (f == 0) {
		return 1;
	} else {
		return f * factorial(f - 1);
	}
}

int main()
{
	println("{}", factorial(6));
}
