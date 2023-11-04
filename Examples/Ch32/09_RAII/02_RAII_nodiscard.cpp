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

	// Allow move construction.
	File(File&& src) noexcept : m_file{ std::exchange(src.m_file, nullptr) }
	{
	}

	// Allow move assignment.
	File& operator=(File&& rhs) noexcept
	{
		if (this != &rhs) {
			reset();
			m_file = std::exchange(rhs.m_file, nullptr);
		}
		return *this;
	}

	// get(), release(), and reset()
	std::FILE* get() const noexcept { return m_file; }

	[[nodiscard]] std::FILE* release() noexcept
	{
		return std::exchange(m_file, nullptr);
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
