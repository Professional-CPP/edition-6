import std;

using namespace std;

int main()
{
	if (is_integral<int>::value) {
		println("int is integral");
	} else {
		println("int is not integral");
	}

	if (is_class<string>::value) {
		println("string is a class");
	} else {
		println("string is not a class");
	}

	// Using _v helpers.
	if (is_integral_v<int>) {
		println("int is integral");
	} else {
		println("int is not integral");
	}

	if (is_class_v<string>) {
		println("string is a class");
	} else {
		println("string is not a class");
	}
}
