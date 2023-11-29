import std;

using namespace std;

class Foo { public: Foo() = delete; Foo(int) {} };
class Bar { public: Bar() = delete; Bar(int) {} };

class MyVisitor
{
public:
	static void operator()(int i) { println("int: {}", i); }
	static void operator()(const string& s) { println("string: {}", s); }
	static void operator()(float f) { println("float: {}", f); }
};

int main()
{
	variant<monostate, Foo, Bar> v0;

	variant<int, string, float> v;
	v = 12;
	v = 12.5f;
	v = "An std::string"s;

	println("Type index: {}", v.index());
	println("Contains an int: {}", holds_alternative<int>(v));

	println("{}", get<string>(v));
	try {
		println("{}", get<0>(v));
	} catch (const bad_variant_access& ex) {
		println("Exception: {}", ex.what());
	}

	string* theString{ get_if<string>(&v) };
	int* theInt{ get_if<int>(&v) };
	println("Retrieved string: {}", (theString ? *theString : "n/a"));
	println("Retrieved int: {}", (theInt ? to_string(*theInt) : "n/a"));

	visit([](auto&& value) { println("Value = {}", value); }, v);

	visit(MyVisitor{}, v);
}
