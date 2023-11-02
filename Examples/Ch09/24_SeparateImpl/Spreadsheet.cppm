export module spreadsheet;

export import spreadsheet_cell;

import std;

export class Spreadsheet
{
public:
	explicit Spreadsheet(std::size_t width = MaxWidth, std::size_t height = MaxHeight);
	Spreadsheet(const Spreadsheet& src);
	Spreadsheet(Spreadsheet&&) noexcept;
	~Spreadsheet();

	Spreadsheet& operator=(const Spreadsheet& rhs);
	Spreadsheet& operator=(Spreadsheet&&) noexcept;
	
	void setCellAt(std::size_t x, std::size_t y, const SpreadsheetCell& cell);
	SpreadsheetCell& getCellAt(std::size_t x, std::size_t y);
	const SpreadsheetCell& getCellAt(std::size_t x, std::size_t y) const;
	
	std::size_t getId() const;

	static constexpr std::size_t MaxHeight{ 100 };
	static constexpr std::size_t MaxWidth{ 100 };

	void swap(Spreadsheet& other) noexcept;

private:
	class Impl;
	std::unique_ptr<Impl> m_impl;
};

export void swap(Spreadsheet& first, Spreadsheet& second) noexcept;
