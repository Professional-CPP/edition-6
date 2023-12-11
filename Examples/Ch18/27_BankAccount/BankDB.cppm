export module bank_db;

import std;

export class BankAccount final
{
public:
	explicit BankAccount(int accountNumber, std::string name)
		: m_accountNumber{ accountNumber }, m_clientName{ std::move(name) } {}

	void setAccountNumber(int accountNumber) { m_accountNumber = accountNumber; }
	int getAccountNumber() const { return m_accountNumber; }

	void setClientName(std::string name) { m_clientName = std::move(name); }
	const std::string& getClientName() const { return m_clientName; }

private:
	int m_accountNumber;
	std::string m_clientName;
};

export class BankDB final
{
public:
	// Adds account to the bank database. If an account exists already
	// with that account number, the new account is not added. Returns true
	// if the account is added, false if it's not.
	bool addAccount(const BankAccount& account);

	// Removes the account with accountNumber from the database.
	void deleteAccount(int accountNumber);

	// Returns a reference to the account represented
	// by its account number or the client name.
	// Throws out_of_range if the account is not found.
	BankAccount& findAccount(int accountNumber);
	BankAccount& findAccount(std::string_view name);

	// Adds all the accounts from db to this database.
	// Deletes all the accounts from db.
	void mergeDatabase(BankDB& db);

private:
	std::map<int, BankAccount> m_accounts;
};

