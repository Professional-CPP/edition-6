export module spreadsheet;

export import spreadsheet_cell;

import std;

export class Spreadsheet
{
public:
	Spreadsheet(std::size_t width, std::size_t height);
	Spreadsheet(const Spreadsheet& src) = delete;
	~Spreadsheet();

	Spreadsheet& operator=(const Spreadsheet& rhs) = delete;

	void setCellAt(std::size_t x, std::size_t y, const SpreadsheetCell& cell);
	SpreadsheetCell& getCellAt(std::size_t x, std::size_t y);

	void swap(Spreadsheet& other) noexcept;

private:
	void verifyCoordinate(std::size_t x, std::size_t y) const;

	std::size_t m_width{ 0 };
	std::size_t m_height{ 0 };
	SpreadsheetCell** m_cells{ nullptr };
};

export void swap(Spreadsheet& first, Spreadsheet& second) noexcept;
