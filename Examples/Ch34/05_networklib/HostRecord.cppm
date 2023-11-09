module;
#include "networklib.h"

export module hostrecord;

import std;

// A class wrapping a HostHandle from the networklib library.
export class HostRecord final
{
public:
	// Looks up the host record for the given host.
	explicit HostRecord(const std::string& host)
		: m_hostHandle{ lookupHostByName(host.c_str()) }
	{ }

	// Frees the host record.
	~HostRecord() { if (m_hostHandle) freeHostHandle(m_hostHandle); }

	// Prevent copy construction and copy assignment.
	HostRecord(const HostRecord&) = delete;
	HostRecord& operator=(const HostRecord&) = delete;

	// Prevent move construction and move assignment.
	HostRecord(HostRecord&&) = delete;
	HostRecord& operator=(HostRecord&&) = delete;

	// Returns the underlying handle.
	HostHandle* get() const noexcept { return m_hostHandle; }

private:
	HostHandle* m_hostHandle{ nullptr };
};
