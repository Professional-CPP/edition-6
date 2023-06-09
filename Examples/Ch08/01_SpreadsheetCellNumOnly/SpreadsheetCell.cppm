export module spreadsheet_cell;

export class SpreadsheetCell
{
public:
	void setValue(double value);
	double getValue() const;

private:
	double m_value{ 0 };
};

//export class SpreadsheetCell
//{
//public:
//	void setValue(double value) { m_value = value; }
//	double getValue() const { return m_value; }
//private:
//	double m_value{ 0 };
//};
