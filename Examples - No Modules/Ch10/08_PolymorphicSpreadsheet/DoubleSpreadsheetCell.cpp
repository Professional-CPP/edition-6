#pragma	once

#include "DoubleSpreadsheetCell.h"

DoubleSpreadsheetCell operator+(const DoubleSpreadsheetCell& lhs,
	const DoubleSpreadsheetCell& rhs)
{
	DoubleSpreadsheetCell newCell;
	newCell.set(lhs.getValue() + rhs.getValue());
	return newCell;
}
