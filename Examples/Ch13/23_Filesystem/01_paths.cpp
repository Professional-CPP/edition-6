import std;

using namespace std;
using namespace std::filesystem;

int main()
{
	path p1{ R"(D:\Foo\Bar)" };
	path p2{ "D:/Foo/Bar" };
	path p3{ "D:/Foo/Bar/MyFile.txt" };
	path p4{ R"(..\SomeFolder)" };
	path p5{ "/usr/lib/X11" };

	println("{}", p1.string());
	println("{}", p2.string());
	println("{}", p3.string());
	println("{}", p4.string());
	println("{}", p5.string());
}
