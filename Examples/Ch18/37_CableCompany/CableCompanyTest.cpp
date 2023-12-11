import cable_company;
import std;

using namespace std;

int main()
{
	CableCompany myCC;
	myCC.addPackage("basic",   "1111000000");
	myCC.addPackage("premium", "1111111111");
	myCC.addPackage("sports",  "0000100111");

	myCC.newCustomer("Marc G.", "basic");
	myCC.addPackageToCustomer("Marc G.", "sports");
	println("{}", myCC.getCustomerChannels("Marc G.").to_string());

	try {
		println("{}", myCC.getCustomerChannels("John").to_string());
	} catch (const exception& e) {
		println("Error: {}", e.what());
	}
}
