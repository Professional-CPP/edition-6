#include <print>
#include <bit>

using namespace std;

int main()
{
	switch (endian::native)
	{
	case endian::little:
		println("Native ordering is little-endian.");
		break;
	case endian::big:
		println("Native ordering is big-endian.");
		break;
	}
}