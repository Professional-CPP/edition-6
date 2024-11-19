#include <print>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<string> stringVector(10, "hello");
	println("Vector elements: {}", stringVector);
}
