module spreadsheet;

import std;

using namespace std;

Spreadsheet::Spreadsheet(size_t width, size_t height,
	const SpreadsheetApplication& theApp)
	: m_id{ ms_counter++ }
	, m_width{ min(width, MaxWidth) }
	, m_height{ min(height, MaxHeight) }
	, m_theApp{ theApp }
{
	m_cells = new Cell*[m_width];
	for (size_t i{ 0 }; i < m_width; ++i) {
		m_cells[i] = new Cell[m_height];
	}
}

Spreadsheet::~Spreadsheet()
{
	for (size_t i{ 0 }; i < m_width; ++i) {
		delete[] m_cells[i];
	}
	delete[] m_cells;
	m_cells = nullptr;
}

Spreadsheet::Spreadsheet(const Spreadsheet& src)
	: Spreadsheet{ src.m_width, src.m_height, src.m_theApp }
{
	// The ctor-initializer of this constructor delegates first to the
	// non-copy constructor to allocate the proper amount of memory.

	// The next step is to copy the data.
	for (size_t i{ 0 }; i < m_width; ++i) {
		for (size_t j{ 0 }; j < m_height; ++j) {
			m_cells[i][j] = src.m_cells[i][j];
		}
	}
}

void Spreadsheet::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= m_width) {
		throw out_of_range { format("x ({}) must be less than width ({}).", x, m_width) };
	}
	if (y >= m_height) {
		throw out_of_range { format("y ({}) must be less than height ({}).", y, m_height) };
	}
}

void Spreadsheet::setCellAt(size_t x, size_t y, const Cell& cell)
{
	verifyCoordinate(x, y);
	m_cells[x][y] = cell;
}

const Spreadsheet::Cell& Spreadsheet::getCellAt(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return m_cells[x][y];
}

Spreadsheet::Cell& Spreadsheet::getCellAt(size_t x, size_t y)
{
	return const_cast<Spreadsheet::Cell&>(as_const(*this).getCellAt(x, y));
}

void Spreadsheet::swap(Spreadsheet& other) noexcept
{
	std::swap(m_width, other.m_width);
	std::swap(m_height, other.m_height);
	std::swap(m_cells, other.m_cells);
}

void swap(Spreadsheet& first, Spreadsheet& second) noexcept
{
	first.swap(second);
}

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs)
{
	// Copy-and-swap idiom
	Spreadsheet temp { rhs }; // Do all the work in a temporary instance
	swap(temp); // Commit the work with only non-throwing operations
	return *this;
}

size_t Spreadsheet::getId() const
{
	return m_id;
}




Spreadsheet::Cell::Cell(double initialValue)
	: m_value { initialValue }
{
}

Spreadsheet::Cell::Cell(string_view initialValue)
	: m_value { stringToDouble(initialValue) }
{
}

void Spreadsheet::Cell::set(double value)
{
	m_value = value;
}

double Spreadsheet::Cell::getValue() const
{
	return m_value;
}

void Spreadsheet::Cell::set(string_view value)
{
	m_value = stringToDouble(value);
}

string Spreadsheet::Cell::getString() const
{
	return doubleToString(m_value);
}

string Spreadsheet::Cell::doubleToString(double value) const
{
	return to_string(value);
}

double Spreadsheet::Cell::stringToDouble(string_view value) const
{
	double number{ 0 };
	from_chars(value.data(), value.data() + value.size(), number);
	return number;
}
