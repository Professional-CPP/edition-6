module bank_db;

import std;

using namespace std;

bool BankDB::addAccount(const BankAccount& account)
{
	// Do the actual insert, using the account number as the key.
	auto res{ m_accounts.emplace(account.getAccountNumber(), account) };
	// or: auto res{ m_accounts.insert(pair{ account.getAccountNumber(), account }) };

	// Without 'auto', you need the following:
	// Declare a variable to store the return from insert()
	//pair<map<int, BankAccount>::iterator, bool> res;
	// do the actual insert, using the account number as the key
	//res = m_accounts.insert(make_pair(account.getAccountNumber(), account));

	// Return the bool field of the pair specifying success or failure.
	return res.second;
}

void BankDB::deleteAccount(int accountNumber)
{
	m_accounts.erase(accountNumber);
}

BankAccount& BankDB::findAccount(int accountNumber)
{
	// Finding an element via its key can be done with find().
	auto it{ m_accounts.find(accountNumber) };
	// Without 'auto', you need:
	//map<int, BankAccount>::iterator it{ m_accounts.find(accountNumber) };

	if (it == end(m_accounts)) {
		throw out_of_range{ format("No account with number {}.", accountNumber) };
	}

	// Remember that iterators into maps refer to pairs of key/value.
	return it->second;
}

BankAccount& BankDB::findAccount(string_view name)
{
	// Finding an element by a non-key attribute requires a linear
	// search through the elements. The following uses structured bindings.
	for (auto& [accountNumber, account] : m_accounts) {
		if (account.getClientName() == name) {
			return account;  // found it!
		}
	}

	// Without structured bindings:
	//for (auto& p : m_accounts) {
	//	if (p.second.getClientName() == name) {
	//		return p.second;  // found it!
	//	}
	//}

	// Without range-based for loop:
	//for (map<int, BankAccount>::iterator it{ m_accounts.begin() };
	//	it != m_accounts.end(); ++it) {
	//	if (it->second.getClientName() == name) {
	//		return it->second;  // found it!
	//	}
	//}
	throw out_of_range{ format("No account with name '{}'.", name) };
}

void BankDB::mergeDatabase(BankDB& db)
{
	// Use merge().
	m_accounts.merge(db.m_accounts);
	// Or: m_accounts.insert(begin(db.m_accounts), end(db.m_accounts));

	// Now clear the source database.
	db.m_accounts.clear();
}
