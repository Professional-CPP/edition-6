import bank_db;
import std;

using namespace std;

int main()
{
	BankDB db;

	db.addAccount(BankAccount{ 100, "Nicholas Solter" });
	db.addAccount(BankAccount{ 200, "Scott Kleper" });

	try {
		auto& account{ db.findAccount(100) };
		println("Found account 100");
		account.setClientName("Nicholas A Solter");

		auto& account2{ db.findAccount("Scott Kleper") };
		println("Found account of Scott Kleper");

		auto& account3{ db.findAccount(1000) };
	} catch (const out_of_range& caughtException) {
		println("Unable to find account: {}", caughtException.what());
	}
}
