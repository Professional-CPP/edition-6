import std;

#if defined(_MSC_VER)
	// Disable the following Microsoft Visual C++ warning for this example:
	// C4996: 'fopen': This function or variable may be unsafe. Consider using fopen_s instead.
	#pragma warning( disable : 4996)
#endif

class File final
{
public:
	[[nodiscard]] explicit File(std::FILE* file) : m_file{ file } { }
	~File() { reset(); }

	// Prevent copy construction and copy assignment.
	File(const File& src) = delete;
	File& operator=(const File& rhs) = delete;

	// Allow move construction and move assignment.
	File(File&& src) noexcept = default;
	File& operator=(File&& rhs) noexcept = default;

	// get(), release(), and reset()
	std::FILE* get() const noexcept { return m_file; }

	[[nodiscard]] std::FILE* release() noexcept
	{
		std::FILE* file{ m_file };
		m_file = nullptr;
		return file;
	}
	
	void reset(std::FILE* file = nullptr) noexcept
	{
		if (m_file) { std::fclose(m_file); }
		m_file = file;
	}

private:
	std::FILE* m_file{ nullptr };
};

int main()
{
	File myFile{ std::fopen("input.txt", "r") };
}
