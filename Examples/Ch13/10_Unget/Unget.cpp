import std;

using namespace std;

void getReservationData()
{
	print("Name and number of guests: ");
	string guestName;
	int partySize{ 0 };
	// Read characters until we find a digit
	char ch;
	cin >> noskipws;
	while (cin >> ch) {
		if (isdigit(ch)) {
			cin.unget();
			if (cin.fail()) { println(cerr, "unget() failed."); }
			break;
		}
		guestName += ch;
	}
	// Read partySize, if the stream is not in error state
	if (cin) { cin >> partySize; }
	if (!cin) {
		println(cerr, "Error getting party size.");
		return;
	}

	println("Thank you '{}', party of {}.", guestName, partySize);
	if (partySize > 10) {
		println("An extra gratuity will apply.");
	}
}

int main()
{
	getReservationData();
}
