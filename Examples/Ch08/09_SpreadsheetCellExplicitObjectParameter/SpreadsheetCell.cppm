export module spreadsheet_cell;

import std;

class SpreadsheetCell
{
public:
	void setValue(this SpreadsheetCell& self, double value);
	double getValue() const;

	void setString(std::string_view value);
	std::string getString() const;

private:
	std::string doubleToString(double value) const;
	double stringToDouble(std::string_view value) const;

	double m_value{ 0 };
};
