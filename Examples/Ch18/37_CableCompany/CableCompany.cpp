module cable_company;

import std;

using namespace std;

void CableCompany::addPackage(string_view packageName,
	const bitset<NumChannels>& channels)
{
	m_packages.emplace(packageName, channels);
}

void CableCompany::addPackage(string_view packageName, string_view channels)
{
	addPackage(packageName, bitset<NumChannels> { channels.data() });
}

void CableCompany::removePackage(string_view packageName)
{
	m_packages.erase(packageName.data());
}

const bitset<CableCompany::NumChannels>& CableCompany::getPackage(
	string_view packageName) const
{
	// Get an iterator to the specified package.
	if (auto it{ m_packages.find(packageName.data()) }; it != end(m_packages)) {
		// Found package. Note that 'it' is an iterator to a name/bitset pair.
		// The bitset is the second field.
		return it->second;
	}
	throw out_of_range{ format("Invalid package '{}'.", packageName) };
}

void CableCompany::newCustomer(string_view name, string_view package)
{
	// Get the channels for the given package.
	auto& packageChannels{ getPackage(package) };
	// Create the account with the bitset representing that package.
	newCustomer(name, packageChannels);
}

void CableCompany::newCustomer(string_view name,
	const bitset<NumChannels>& channels)
{
	// Add customer to the customers map.
	if (auto [iter, success] { m_customers.emplace(name, channels) }; !success) {
		// Customer was already in the database. Nothing changed.
		throw invalid_argument{ format("Duplicate customer '{}'.", name) };
	}
}

void CableCompany::addChannel(string_view name, int channel)
{
	// Get the current channels for the customer.
	auto& customerChannels{ getCustomerChannelsHelper(name) };
	// We found the customer; set the channel.
	customerChannels.set(channel);
}

void CableCompany::removeChannel(string_view name, int channel)
{
	// Get the current channels for the customer.
	auto& customerChannels{ getCustomerChannelsHelper(name) };
	// We found this customer; remove the channel.
	customerChannels.reset(channel);
}

void CableCompany::addPackageToCustomer(string_view name, string_view package)
{
	// Get the channels for the given package.
	auto& packageChannels{ getPackage(package) };
	// Get the current channels for the customer.
	auto& customerChannels{ getCustomerChannelsHelper(name) };
	// Or-in the package to the customer's existing channels.
	customerChannels |= packageChannels;
}

void CableCompany::deleteCustomer(string_view name)
{
	m_customers.erase(name.data());
}

const bitset<CableCompany::NumChannels>& CableCompany::getCustomerChannels(
	string_view name) const
{
	// Find an iterator to the customer.
	if (auto it{ m_customers.find(name.data()) }; it != end(m_customers)) {
		// Found customer. Note that 'it' is an iterator to a name/bitset pair.
		// The bitset is the second field.
		return it->second;
	}
	throw invalid_argument{ format("Unknown customer '{}'.", name) };
}

bitset<CableCompany::NumChannels>& CableCompany::getCustomerChannelsHelper(
	string_view name)
{
	// Forward to const getCustomerChannels() to avoid code duplication.
	return const_cast<bitset<NumChannels>&>(
		as_const(*this).getCustomerChannels(name));
}
