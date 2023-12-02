module spreadsheet_cell;

import std;

using namespace std;

SpreadsheetCell::SpreadsheetCell(double initialValue)
	: m_value{ initialValue }
{
}

SpreadsheetCell::SpreadsheetCell(string_view initialValue)
	: m_value{ stringToDouble(initialValue) }
{
}

void SpreadsheetCell::set(double value)
{
	m_value = value;
}

void SpreadsheetCell::set(string_view value)
{
	m_value = stringToDouble(value);
}

string SpreadsheetCell::doubleToString(double value)
{
	return to_string(value);
}

double SpreadsheetCell::stringToDouble(string_view value)
{
	double number{ 0 };
	from_chars(value.data(), value.data() + value.size(), number);
	return number;
}

SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	auto result{ lhs };  // Local copy
	result += rhs;       // Forward to +=()
	return result;
}

SpreadsheetCell operator-(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	auto result{ lhs };  // Local copy
	result -= rhs;       // Forward to -=()
	return result;
}

SpreadsheetCell operator*(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	auto result{ lhs };  // Local copy
	result *= rhs;       // Forward to *=()
	return result;
}

SpreadsheetCell operator/(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	auto result{ lhs };  // Local copy
	result /= rhs;       // Forward to /=()
	return result;
}

SpreadsheetCell& SpreadsheetCell::operator+=(const SpreadsheetCell& rhs)
{
	set(getValue() + rhs.getValue());
	return *this;
}

SpreadsheetCell& SpreadsheetCell::operator-=(const SpreadsheetCell& rhs)
{
	set(getValue() - rhs.getValue());
	return *this;
}

SpreadsheetCell& SpreadsheetCell::operator*=(const SpreadsheetCell& rhs)
{
	set(getValue() * rhs.getValue());
	return *this;
}

SpreadsheetCell& SpreadsheetCell::operator/=(const SpreadsheetCell& rhs)
{
	if (rhs.getValue() == 0) {
		throw invalid_argument{ "Divide by zero." };
	}
	set(getValue() / rhs.getValue());
	return *this;
}

SpreadsheetCell SpreadsheetCell::operator-() const
{
	return SpreadsheetCell{ -getValue() };
}

SpreadsheetCell& SpreadsheetCell::operator++()
{
	set(getValue() + 1);
	return *this;
}

SpreadsheetCell SpreadsheetCell::operator++(int)
{
	auto oldCell{ *this }; // Save current value
	++(*this);           // Increment using prefix ++
	return oldCell;      // Return the old value
}

SpreadsheetCell& SpreadsheetCell::operator--()
{
	set(getValue() - 1);
	return *this;
}

SpreadsheetCell SpreadsheetCell::operator--(int)
{
	auto oldCell{ *this }; // Save current value
	--(*this);           // Decrement using prefix --
	return oldCell;      // Return the old value
}
