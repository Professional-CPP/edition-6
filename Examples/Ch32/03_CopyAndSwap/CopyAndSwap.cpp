module copy_and_swap;

import std;

CopyAndSwap::~CopyAndSwap() { /* Implementation of destructor. */ }

CopyAndSwap::CopyAndSwap(const CopyAndSwap& src)
{
	// This copy constructor can first delegate to a non-copy constructor
	// if any resource allocations have to be done. See the Spreadsheet
	// implementation in Chapter 9 for an example.

	// Make a copy of all data members...
}

void swap(CopyAndSwap& first, CopyAndSwap& second) noexcept
{
	first.swap(second);
}

void CopyAndSwap::swap(CopyAndSwap& other) noexcept
{
	using std::swap;

	// Swap each data member, for example:
	// swap(m_data, other.m_data);
}

CopyAndSwap& CopyAndSwap::operator=(const CopyAndSwap& rhs)
{
	// Copy-and-swap idiom.
	auto copy{ rhs };  // Do all the work in a temporary instance.
	swap(copy);        // Commit the work with only non-throwing operations.
	return *this;
}
