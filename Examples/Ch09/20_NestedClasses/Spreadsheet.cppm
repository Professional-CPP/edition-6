export module spreadsheet;

import std;

export class SpreadsheetApplication { };

export class Spreadsheet
{
public:

	class Cell
	{
	public:
		Cell() = default;
		Cell(double initialValue);
		Cell(std::string_view initialValue);

		void set(double value);
		void set(std::string_view value);

		double getValue() const;
		std::string getString() const;

	private:
		std::string doubleToString(double value) const;
		double stringToDouble(std::string_view value) const;

		double m_value{ 0 };
	};

	Spreadsheet(std::size_t width, std::size_t height,
		const SpreadsheetApplication& theApp);
	Spreadsheet(const Spreadsheet& src);
	~Spreadsheet();
	Spreadsheet& operator=(const Spreadsheet& rhs);

	void setCellAt(std::size_t x, std::size_t y, const Cell& cell);
	Cell& getCellAt(std::size_t x, std::size_t y);
	const Cell& getCellAt(std::size_t x, std::size_t y) const;

	std::size_t getId() const;

	void swap(Spreadsheet& other) noexcept;

	static constexpr std::size_t MaxHeight{ 100 };
	static constexpr std::size_t MaxWidth{ 100 };

private:
	void verifyCoordinate(std::size_t x, std::size_t y) const;

	std::size_t m_id{ 0 };
	std::size_t m_width{ 0 };
	std::size_t m_height{ 0 };
	Cell** m_cells{ nullptr };

	const SpreadsheetApplication& m_theApp;

	static inline std::size_t ms_counter{ 0 };
};

export void swap(Spreadsheet& first, Spreadsheet& second) noexcept;
