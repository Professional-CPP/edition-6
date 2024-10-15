#pragma once

#include "SpreadsheetCell.h"
#include "DoubleSpreadsheetCell.h"
#include <optional>
#include <string>
#include <string_view>

class StringSpreadsheetCell : public SpreadsheetCell
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

StringSpreadsheetCell operator+(const StringSpreadsheetCell& lhs,
	const StringSpreadsheetCell& rhs);
