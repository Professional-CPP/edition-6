import <iostream>;
import airline_ticket;

using namespace std;

int main()
{
	AirlineTicket myTicket;  // Stack-based AirlineTicket
	myTicket.setPassengerName("Sherman T. Socketwrench");
	myTicket.setNumberOfMiles(700);
	double cost{ myTicket.calculatePriceInDollars() };
	cout << "This ticket will cost $" << cost << endl;
} 
