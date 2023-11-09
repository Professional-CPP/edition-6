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

	// Obtains the given page from this host.
	std::string getPage(const std::string& page);
private:
	std::unique_ptr<ConnectionHandle, decltype(&closeConnection)> m_connection{ nullptr, closeConnection };
};

WebHost::WebHost(const std::string& host)
{
	HostRecord hostRecord{ host };
	if (hostRecord.get()) {
		m_connection = { connectToHost(hostRecord.get()), closeConnection };
	}
}

std::string WebHost::getPage(const std::string& page)
{
	std::string resultAsString;
	if (m_connection) {
		std::unique_ptr<char[], decltype(&freeWebPage)> result{
			retrieveWebPage(m_connection.get(), page.c_str()),
			freeWebPage };
		resultAsString = result.get();
	}
	return resultAsString;
}
