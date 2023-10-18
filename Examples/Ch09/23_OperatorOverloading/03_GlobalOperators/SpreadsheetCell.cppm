export module spreadsheet_cell;

import std;

export class SpreadsheetCell
{
public:
	SpreadsheetCell() = default;
	SpreadsheetCell(double initialValue);
	SpreadsheetCell(std::string_view initialValue);

	void set(double value);
	void set(std::string_view value);

	double getValue() const;
	std::string getString() const;

	SpreadsheetCell& operator+=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator-=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator*=(const SpreadsheetCell& rhs);
	SpreadsheetCell& operator/=(const SpreadsheetCell& rhs);

private:
	static std::string doubleToString(double value);
	static double stringToDouble(std::string_view value);

	double m_value{ 0 };
};

export SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
export SpreadsheetCell operator-(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
export SpreadsheetCell operator*(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
export SpreadsheetCell operator/(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
