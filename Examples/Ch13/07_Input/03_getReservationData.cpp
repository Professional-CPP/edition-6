import std;

using namespace std;

void getReservationData()
{
	string guestName;
	int partySize;
	print("Name and number of guests: ");
	cin >> guestName >> partySize;
	println("Thank you, {}.", guestName);
	if (partySize > 10) {
		println("An extra gratuity will apply.");
	}
}

int main()
{
	getReservationData();
}
