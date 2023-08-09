import std;

using namespace std;

void handle0Or2() {}
void handle1() {}
void handle3() {}

void doSomething(int number_that_is_only_0_1_2_or_3)
{
	switch (number_that_is_only_0_1_2_or_3)
	{
	case 0:
	case 2:
		handle0Or2();
		break;
	case 1:
		handle1();
		break;
	case 3:
		handle3();
		break;
	default:
		unreachable();
	}
}

int main()
{
	doSomething(2);
}