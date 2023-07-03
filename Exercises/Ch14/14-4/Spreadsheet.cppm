export module spreadsheet;

export import spreadsheet_cell;

import std;

export class Spreadsheet
{
public:
	Spreadsheet(std::size_t width, std::size_t height);
	Spreadsheet(const Spreadsheet& src);
	Spreadsheet(Spreadsheet&& src) noexcept; // Move constructor
	~Spreadsheet();

	Spreadsheet& operator=(const Spreadsheet& rhs);
	Spreadsheet& operator=(Spreadsheet&& rhs) noexcept;  // Move assignment

	void setCellAt(std::size_t x, std::size_t y, const SpreadsheetCell& cell);
	SpreadsheetCell& getCellAt(std::size_t x, std::size_t y);

	void swap(Spreadsheet& other) noexcept;;
	
	static const std::size_t MaxHeight{ 100 };
	static const std::size_t MaxWidth{ 100 };

private:
	void cleanup() noexcept;
	void verifyCoordinate(std::size_t x, std::size_t y) const;

	std::size_t m_width{ 0 };
	std::size_t m_height{ 0 };
	SpreadsheetCell** m_cells{ nullptr };
};

export void swap(Spreadsheet& first, Spreadsheet& second) noexcept;
