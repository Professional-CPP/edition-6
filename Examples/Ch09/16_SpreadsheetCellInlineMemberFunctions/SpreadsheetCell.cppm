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

	/*
	double getValue() const;
	std::string getString() const;
	*/

	inline double getValue() const
	{
		++m_numAccesses;
		return m_value;
	}

	inline std::string getString() const
	{
		++m_numAccesses;
		return doubleToString(m_value);
	}

private:
	static std::string doubleToString(double value);
	static double stringToDouble(std::string_view value);

	double m_value{ 0 };
	mutable unsigned m_numAccesses{ 0 };
};
/*
inline double SpreadsheetCell::getValue() const
{
	++m_numAccesses;
	return m_value;
}

inline std::string SpreadsheetCell::getString() const
{
	++m_numAccesses;
	return doubleToString(m_value);
}
*/