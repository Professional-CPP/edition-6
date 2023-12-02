export module serial;

export class Serial
{
public:
	// A new object gets a next serial number.
	Serial() : m_serialNumber{ ms_nextSerial++ } {}
	unsigned getSerialNumber() const { return m_serialNumber; }

private:
	static inline unsigned ms_nextSerial{ 0 }; // The first serial number is 0.
	unsigned m_serialNumber{ 0 };
};

