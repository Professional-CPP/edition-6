#include <print>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
	vector<int> values(10);
	iota(begin(values), end(values), 5);
	println("{:n}", values);
}