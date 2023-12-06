#include "HostHandle.h"
#include "ConnectionHandle.h"

// Gets the host record for a particular Internet host given
// its hostname (i.e. www.host.com).
HostHandle* lookupHostByName(const char* hostName);
// Frees the given HostHandle.
void freeHostHandle(HostHandle* host);

// Connects to the given host.
ConnectionHandle* connectToHost(HostHandle* host);
// Closes the given connection.
void closeConnection(ConnectionHandle* connection);

// Retrieves a web page from an already-opened connection.
char* retrieveWebPage(ConnectionHandle* connection, const char* page);
// Frees the memory pointed to by page.
void freeWebPage(char* page);
