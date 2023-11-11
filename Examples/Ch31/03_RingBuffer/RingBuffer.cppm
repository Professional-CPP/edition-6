export module ring_buffer;

import std;

// Provides a simple ring buffer for messages. The client specifies the number
// of entries in the constructor, and adds messages with the addEntry()
// member function. Once the number of entries exceeds the number allowed, new
// entries overwrite the oldest entries in the buffer.
//
// The buffer also provides the option to output entries to a stream as
// they are added to the buffer. The client can specify an output stream
// in the constructor, and can reset it with the setOutput() member function.
// 
// Finally, the operator<< streams the entire buffer to an output stream.
export class RingBuffer final
{
public:
	// Constructs a ring buffer with space for numEntries.
	// Entries are written to *outStream as they are queued (optional).
	explicit RingBuffer(std::size_t numEntries = DefaultNumEntries,
		std::ostream* outStream = nullptr);

	// Adds the string to the ring buffer, possibly overwriting the
	// oldest string in the buffer (if the buffer is full).
	template<typename... Args>
	void addEntry(const Args&... args)
	{
		std::ostringstream oss;
		std::print(oss, "{:L} UTC: ", std::chrono::system_clock::now());
		// Use a fold-expression; see Chapter 26.
		(oss << ... << args);
		addStringEntry(std::move(oss).str());
	}

	// Streams the buffer entries, separated by newlines, to outStream.
	friend std::ostream& operator<<(std::ostream& outStream, RingBuffer& rb);

	// Streams entries as they are added to the given stream.
	// Specify nullptr to disable this feature.
	// Returns the old output stream.
	std::ostream* setOutput(std::ostream* newOutStream);

private:
	std::vector<std::string> m_entries;
	std::vector<std::string>::iterator m_next;

	std::ostream* m_outStream{ nullptr };
	bool m_wrapped{ false };

	static constexpr std::size_t DefaultNumEntries{ 500 };

	void addStringEntry(std::string entry);
};
