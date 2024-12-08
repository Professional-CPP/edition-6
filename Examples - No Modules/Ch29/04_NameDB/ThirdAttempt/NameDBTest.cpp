#include "NameDB.h"
#include <print>

using namespace std;

int main()
{
	NameDB boys{ "boys_long.txt" };

	println("{}", boys.getNameRank("Daniel"));
	println("{}", boys.getNameRank("Jacob"));
	println("{}", boys.getNameRank("William"));
}
