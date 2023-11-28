import std;

using namespace std;

int main()
{
	char fixedBuffer[32]{};
	ospanstream stream{ span{ fixedBuffer } };
	stream << "Hello " << 2.222 << ' ' << 11;
	println("Buffer contents: \"{}\"", fixedBuffer);
}