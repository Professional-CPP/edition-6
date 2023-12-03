export module copy_and_swap;

// A simple class that illustrates the copy-and-swap idiom.
export class CopyAndSwap final
{
public:
	CopyAndSwap() = default;
	~CopyAndSwap();                                 // Destructor

	CopyAndSwap(const CopyAndSwap& src);            // Copy constructor
	CopyAndSwap& operator=(const CopyAndSwap& rhs); // Copy assignment operator

	void swap(CopyAndSwap& other) noexcept;         // noexcept swap() member function

private:
	// Private data members...
};

// Standalone noexcept swap() function
export void swap(CopyAndSwap& first, CopyAndSwap& second) noexcept;
