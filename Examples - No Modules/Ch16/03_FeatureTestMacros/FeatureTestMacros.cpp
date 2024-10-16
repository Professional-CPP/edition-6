#include <print>
#include <version>

using namespace std;

int main()
{
#ifdef __cpp_lib_constexpr_vector
	println("std::vector is constexpr!");
#else
	println("Bummer! std::vector is NOT constexpr!");
#endif
}
