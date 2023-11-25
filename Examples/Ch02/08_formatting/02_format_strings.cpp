import std;

using namespace std;

int main()
{
	int n{ 42 };

	println("Read {} bytes from {}", n, "file1.txt");
	println("Read {0} bytes from {1}", n, "file1.txt");
	println("从{1}中读取{0}个字节。", n, "file1.txt");
}
