import packet_buffer;
import std;

using namespace std;

class IPPacket final
{
public:
	explicit IPPacket(int id) : m_id{ id } {}
	int getID() const { return m_id; }

private:
	int m_id;
};

int main()
{
	PacketBuffer<IPPacket> ipPackets{ 3 };

	// Add 4 packets
	for (int i{ 1 }; i <= 4; ++i) {
		if (!ipPackets.bufferPacket(IPPacket{ i })) {
			println("Packet {} dropped (queue is full).", i);
		}
	}

	while (true) {
		try {
			IPPacket packet{ ipPackets.getNextPacket() };
			println("Processing packet {}", packet.getID());
		} catch (const out_of_range&) {
			println("Queue is empty.");
			break;
		}
	}
}
