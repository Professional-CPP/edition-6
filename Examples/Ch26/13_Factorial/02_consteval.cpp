import std;

using namespace std;

consteval unsigned long long factorial(unsigned char f)
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
