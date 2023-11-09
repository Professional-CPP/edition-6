//#include "networklib.h"
import std;
import hostrecord;
import webhost;

using namespace std;

int main()
{
	{ // C Style
		//HostHandle* myHost{ lookupHostByName("www.wrox.com") };
		//ConnectionHandle* myConnection{ connectToHost(myHost) };
		//char* result{ retrieveWebPage(myConnection, "/index.html") };

		//println("The result is:\n{}", result);

		//freeWebPage(result); result = nullptr;
		//closeConnection(myConnection); myConnection = nullptr;
		//freeHostHandle(myHost); myHost = nullptr;
	}

	{ // C++ Style
		WebHost myHost{ "www.wrox.com" };
		string result{ myHost.getPage("/index.html") };
		println("The result is:\n{}", result);
	}
}
