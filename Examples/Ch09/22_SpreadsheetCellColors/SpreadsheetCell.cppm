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

	enum class Color { Red = 1, Green, Blue, Yellow };
	void setColor(Color color);
	Color getColor() const;

private:
	static std::string doubleToString(double value);
	static double stringToDouble(std::string_view value);

	double m_value{ 0 };
	Color m_color{ Color::Red };
};
