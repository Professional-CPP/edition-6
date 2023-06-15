export module string_spreadsheet_cell;

export import spreadsheet_cell;
import double_spreadsheet_cell;
import std;

export class StringSpreadsheetCell : public SpreadsheetCell
{
public:
	StringSpreadsheetCell() = default;

	StringSpreadsheetCell(const DoubleSpreadsheetCell& cell)
		: m_value{ cell.getString() }
	{
	}

	void set(std::string_view value) override
	{
		m_value = value;
	}

	std::string getString() const override
	{
		return m_value.value_or("");
	}

private:
	std::optional<std::string> m_value;
};

export StringSpreadsheetCell operator+(const StringSpreadsheetCell& lhs,
	const StringSpreadsheetCell& rhs)
{
	StringSpreadsheetCell newCell;
	newCell.set(lhs.getString() + rhs.getString());
	return newCell;
}
