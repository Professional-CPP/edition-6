#include "networklib.h"

/////////////////////////////////////////////////////////////////////
//                                                                 //
// For this example, these functions are kept to the bare minimum. //
//                                                                 //
/////////////////////////////////////////////////////////////////////

HostHandle* lookupHostByName(const char* hostName)
{
	return new HostHandle{};
}

void freeHostHandle(HostHandle* host)
{
	delete host;
}

ConnectionHandle* connectToHost(HostHandle* host)
{
	return new ConnectionHandle{};
}

void closeConnection(ConnectionHandle* connection)
{
	delete connection;
}

char* retrieveWebPage(ConnectionHandle* connection, const char* page)
{
	return new char[] { "Hello Webpage!" };
}

void freeWebPage(char* page)
{
	delete[] page;
}
