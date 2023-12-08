import std;
import airline_ticket;

using namespace std;

int main()
{
	AirlineTicket myTicket;  // Stack-based AirlineTicket
	myTicket.setPassengerName("Sherman T. Socketwrench");
	myTicket.setNumberOfMiles(700);
	myTicket.setFrequentFlyerNumber(123'456);
	const double cost{ myTicket.calculatePriceInDollars() };
	println("This ticket will cost ${}", cost);
	
	const auto frequentFlyerNumber{ myTicket.getFrequentFlyerNumber() };
	if (frequentFlyerNumber) {
		println("Frequent flyer number: {}", frequentFlyerNumber.value());
	} else {
		println("No frequent flyer number.");
	}
} 
