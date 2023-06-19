import std;

using namespace std;

int main()
{
	//println("Hello "World"!");    // Error!
	println("Hello \"World\"!");
	println(R"(Hello "World"!)");

	println("Line 1\nLine 2");
	println(R"(Line 1
Line 2)");

	println(R"(Is the following a tab character? \t)");

	//println(R"(Embedded )" characters)");    // Error!
	println(R"-(Embedded )" characters)-");
}
