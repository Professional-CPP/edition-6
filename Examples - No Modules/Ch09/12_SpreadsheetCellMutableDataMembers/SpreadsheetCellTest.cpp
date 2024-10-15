#include "SpreadsheetCell.h"
#include <print>

using namespace std;

int main()
{
	SpreadsheetCell myCell{ 5 };
	println("{}", myCell.getValue());
}
