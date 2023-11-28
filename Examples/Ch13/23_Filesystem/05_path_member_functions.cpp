import std;

using namespace std;
using namespace std::filesystem;

int main()
{
	path p{ R"(C:\Foo\Bar\file.txt)" };
	println("{}", p.root_name().string());
	println("{}", p.filename().string());
	println("{}", p.stem().string());
	println("{}", p.extension().string());
}