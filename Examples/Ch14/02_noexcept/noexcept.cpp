import std;

using namespace std;

void f1() noexcept {}
void f2() noexcept(false) {}
void f3() noexcept(noexcept(f1())) {}
void f4() noexcept(noexcept(f2())) {}

int main()
{
	println("{} {} {} {}", noexcept(f1()),
		noexcept(f2()),
		noexcept(f3()),
		noexcept(f4()));
}
