export module packet_buffer;

import std;

export template <typename T>
class PacketBuffer final
{
public:
	// If maxSize is 0, the size is unlimited, because creating
	// a buffer of size 0 makes little sense. Otherwise only
	// maxSize packets are allowed in the buffer at any one time.
	explicit PacketBuffer(std::size_t maxSize = 0);

	// Stores a packet in the buffer.
	// Returns false if the packet has been discarded because
	// there is no more space in the buffer, true otherwise.
	bool bufferPacket(const T& packet);

	// Returns the next packet. Throws out_of_range
	// if the buffer is empty.
	[[nodiscard]] T getNextPacket();

private:
	std::queue<T> m_packets;
	std::size_t m_maxSize;
};

template <typename T>
PacketBuffer<T>::PacketBuffer(std::size_t maxSize/* = 0 */)
	: m_maxSize{ maxSize }
{
}

template <typename T>
bool PacketBuffer<T>::bufferPacket(const T& packet)
{
	if (m_maxSize > 0 && m_packets.size() == m_maxSize) {
		// No more space. Drop the packet.
		return false;
	}

	m_packets.push(packet);
	return true;
}

template <typename T>
T PacketBuffer<T>::getNextPacket()
{
	if (m_packets.empty()) {
		throw std::out_of_range{ "Buffer is empty" };
	}
	// Retrieve the head element
	T temp{ m_packets.front() };
	// Pop the head element
	m_packets.pop();
	// Return the head element
	return temp;
}
