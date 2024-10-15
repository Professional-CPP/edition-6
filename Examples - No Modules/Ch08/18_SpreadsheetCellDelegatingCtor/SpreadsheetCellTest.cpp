#include "SpreadsheetCell.h"
#include <print>

using namespace std;

int main()
{
	SpreadsheetCell myCell{ "6.2" };
	println("cell 1: {}", myCell.getValue());
}
