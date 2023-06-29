import std;

using namespace std;

void getReservationData()
{
	print("Name and number of guests: ");
	string guestName;
	int partySize{ 0 };
	// Read characters until we find a digit.
	cin >> noskipws;
	while (true) {
		// 'peek' at next character.
		char ch{ static_cast<char>(cin.peek()) };
		if (!cin) { break; }
		if (isdigit(ch)) {
			// Next character will be a digit, so stop the loop.
			break;
		}
		// Next character will be a non-digit, so read it.
		cin >> ch;
		if (!cin) { break; }
		guestName += ch;
	}
	// Read partySize, if the stream is not in error state.
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
