export module spreadsheet;

export import spreadsheet_cell;

import std;

export class SpreadsheetApplication { };

export class Spreadsheet
{
public:
	Spreadsheet(std::size_t width, std::size_t height,
		const SpreadsheetApplication& theApp);
	Spreadsheet(const Spreadsheet& src);
	~Spreadsheet();
	Spreadsheet& operator=(const Spreadsheet& rhs);

	void setCellAt(std::size_t x, std::size_t y, const SpreadsheetCell& cell);
	SpreadsheetCell& getCellAt(std::size_t x, std::size_t y);
	const SpreadsheetCell& getCellAt(std::size_t x, std::size_t y) const;

	std::size_t getId() const;

	void swap(Spreadsheet& other) noexcept;

	static constexpr std::size_t MaxHeight{ 100 };
	static constexpr std::size_t MaxWidth{ 100 };

private:
	void verifyCoordinate(std::size_t x, std::size_t y) const;

	const std::size_t m_id{ 0 };
	std::size_t m_width{ 0 };
	std::size_t m_height{ 0 };
	SpreadsheetCell** m_cells{ nullptr };

	const SpreadsheetApplication& m_theApp;

	//static std::size_t ms_counter; // Pre C++17
	static inline std::size_t ms_counter{ 0 }; // Since C++17
};

export void swap(Spreadsheet& first, Spreadsheet& second) noexcept;
