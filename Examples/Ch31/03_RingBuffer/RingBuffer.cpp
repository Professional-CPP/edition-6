module ring_buffer;

import std;

using namespace std;

// Initialize the vector to hold exactly numEntries. The vector size
// does not need to change during the lifetime of the object.
// Initialize the other members.
RingBuffer::RingBuffer(size_t numEntries, ostream* outStream)
	: m_entries{ numEntries }
	, m_outStream{ outStream }
	, m_wrapped{ false }
{
	if (numEntries == 0) {
		throw invalid_argument{ "Number of entries must be > 0." };
	}
	m_next = begin(m_entries);
}

// The addStringEntry algorithm is pretty simple: add the entry to the next
// free spot, then reset m_next to indicate the free spot after
// that. If m_next reaches the end of the vector, it starts over at 0.
//
// The buffer needs to know if the buffer has wrapped or not so
// that it knows whether to print the entries past m_next in operator<<.
void RingBuffer::addStringEntry(string entry)
{
	// If there is a valid m_outStream, write this entry to it.
	if (m_outStream) { *m_outStream << entry << endl; }

	// Move the entry to the next free spot and increment
	// m_next to point to the free spot after that.
	*m_next = move(entry);
	++m_next;

	// Check if we've reached the end of the buffer. If so, we need to wrap.
	if (m_next == end(m_entries)) {
		m_next = begin(m_entries);
		m_wrapped = true;
	}
}

// Set the output stream.
ostream* RingBuffer::setOutput(ostream* newOutStream)
{
	return exchange(m_outStream, newOutStream);
}

// operator<< uses an ostream_iterator to "copy" entries directly
// from the vector to the output stream.
//
// operator<< must print the entries in order. If the buffer has wrapped,
// the earliest entry is one past the most recent entry, which is the entry
// indicated by m_next. So, first print from entry m_next to the end.
//
// Then (even if the buffer hasn't wrapped) print from beginning to m_next-1.
ostream& operator<<(ostream& outStream, RingBuffer& rb)
{
	if (rb.m_wrapped) {
		// If the buffer has wrapped, print the elements from
		// the earliest entry to the end.
		copy(rb.m_next, end(rb.m_entries), ostream_iterator<string>{ outStream, "\n" });
	}

	// Now, print up to the most recent entry.
	// Go up to m_next because the range is not inclusive on the right side.
	copy(begin(rb.m_entries), rb.m_next, ostream_iterator<string>{ outStream, "\n" });

	return outStream;
}
