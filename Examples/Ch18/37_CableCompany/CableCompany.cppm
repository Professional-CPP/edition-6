export module cable_company;

import std;

export class CableCompany final
{
public:
	// Number of supported channels.
	static constexpr std::size_t NumChannels{ 10 };

	// Adds package with the channels specified as a bitset to the database.
	void addPackage(const std::string& packageName,
		const std::bitset<NumChannels>& channels);

	// Adds package with the channels specified as a string to the database.
	void addPackage(const std::string& packageName, const std::string& channels);

	// Removes the specified package from the database.
	void removePackage(const std::string& packageName);

	// Retrieves the channels of a given package.
	// Throws out_of_range if the package name is invalid.
	const std::bitset<NumChannels>& getPackage(const std::string& packageName) const;

	// Adds customer to database with initial channels found in package.
	// Throws out_of_range if the package name is invalid.
	// Throws invalid_argument if the customer is already known.
	void newCustomer(const std::string& name, const std::string& package);

	// Adds customer to database with given initial channels.
	// Throws invalid_argument if the customer is already known.
	void newCustomer(const std::string& name, const std::bitset<NumChannels>& channels);

	// Adds the channel to the customer's profile.
	// Throws invalid_argument if the customer is unknown.
	void addChannel(const std::string& name, int channel);

	// Removes the channel from the customer's profile.
	// Throws invalid_argument if the customer is unknown.
	void removeChannel(const std::string& name, int channel);

	// Adds the specified package to the customer's profile.
	// Throws out_of_range if the package name is invalid.
	// Throws invalid_argument if the customer is unknown.
	void addPackageToCustomer(const std::string& name, const std::string& package);

	// Removes the specified customer from the database.
	void deleteCustomer(const std::string& name);

	// Retrieves the channels to which a customer subscribes.
	// Throws invalid_argument if the customer is unknown.
	const std::bitset<NumChannels>& getCustomerChannels(const std::string& name) const;

private:
	// Retrieves the channels for a customer. (non-const)
	// Throws invalid_argument if the customer is unknown.
	std::bitset<NumChannels>& getCustomerChannelsHelper(const std::string& name);

	using MapType = std::map<std::string, std::bitset<NumChannels>>;
	MapType m_packages, m_customers;
};
