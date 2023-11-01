import std;

using namespace std;
using namespace std::filesystem;

int main()
{
	space_info s{ space("c:\\") };
	println("Capacity: {}", s.capacity);
	println("Free: {}", s.free);
}
