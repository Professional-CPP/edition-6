export module cable_company;

import std;

export class CableCompany
{
public:
	virtual ~CableCompany() = default;

	// Number of supported channels.
	static const std::size_t NumChannels{ 10 };

	// Adds package with the channels specified as a bitset to the database.
	void addPackage(std::string_view packageName,
		const std::bitset<NumChannels>& channels);

	// Adds package with the channels specified as a string to the database.
	void addPackage(std::string_view packageName, std::string_view channels);

	// Removes the specified package from the database.
	void removePackage(std::string_view packageName);

	// Retrieves the channels of a given package.
	// Throws out_of_range if the package name is invalid.
	const std::bitset<NumChannels>& getPackage(std::string_view packageName) const;

	// Adds customer to database with initial channels found in package.
	// Throws out_of_range if the package name is invalid.
	// Throws invalid_argument if the customer is already known.
	void newCustomer(std::string_view name, std::string_view package);

	// Adds customer to database with given initial channels.
	// Throws invalid_argument if the customer is already known.
	void newCustomer(std::string_view name, const std::bitset<NumChannels>& channels);

	// Adds the channel to the customer's profile.
	// Throws invalid_argument if the customer is unknown.
	void addChannel(std::string_view name, int channel);

	// Removes the channel from the customer's profile.
	// Throws invalid_argument if the customer is unknown.
	void removeChannel(std::string_view name, int channel);

	// Adds the specified package to the customer's profile.
	// Throws out_of_range if the package name is invalid.
	// Throws invalid_argument if the customer is unknown.
	void addPackageToCustomer(std::string_view name, std::string_view package);

	// Removes the specified customer from the database.
	void deleteCustomer(std::string_view name);

	// Retrieves the channels to which a customer subscribes.
	// Throws invalid_argument if the customer is unknown.
	const std::bitset<NumChannels>& getCustomerChannels(std::string_view name) const;

private:
	// Retrieves the channels for a customer. (non-const)
	// Throws invalid_argument if the customer is unknown.
	std::bitset<NumChannels>& getCustomerChannelsHelper(std::string_view name);

	using MapType = std::map<std::string, std::bitset<NumChannels>>;
	MapType m_packages, m_customers;
};
