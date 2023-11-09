module;
#include "networklib.h"

export module webhost;

import std;
import hostrecord;

// A class wrapping a ConnectionHandle from the networklib library.
export class WebHost final
{
public:
	// Connects to the given host.
	explicit WebHost(const std::string& host);

	// Closes the connection to the host.
	~WebHost();

	// Prevent copy construction and copy assignment.
	WebHost(const WebHost&) = delete;
	WebHost& operator=(const WebHost&) = delete;

	// Prevent move construction and move assignment.
	WebHost(WebHost&&) = delete;
	WebHost& operator=(WebHost&&) = delete;

	// Obtains the given page from this host.
	std::string getPage(const std::string& page);
private:
	ConnectionHandle* m_connection{ nullptr };
};

WebHost::WebHost(const std::string& host)
{
	HostRecord hostRecord{ host };
	if (hostRecord.get()) {
		m_connection = connectToHost(hostRecord.get());
	}
}

WebHost::~WebHost()
{
	if (m_connection) {
		closeConnection(m_connection);
	}
}

std::string WebHost::getPage(const std::string& page)
{
	std::string resultAsString;
	if (m_connection) {
		std::unique_ptr<char[], decltype(&freeWebPage)> result{
			retrieveWebPage(m_connection, page.c_str()),
			freeWebPage };
		resultAsString = result.get();
	}
	return resultAsString;
}
