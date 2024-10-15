#pragma once

#include <string>
#include <string_view>

class SpreadsheetCell
{
public:
	void setValue(double value);
	double getValue() const;

	void setString(std::string_view value);
	std::string getString() const;

private:
	std::string doubleToString(double value) const;
	double stringToDouble(std::string_view value) const;

	double value{ 0 };
};
