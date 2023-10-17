module airline_ticket;

using namespace std;

//AirlineTicket::AirlineTicket()
//	: m_passengerName{ "Unknown Passenger" }
//	, m_numberOfMiles{ 0 }
//	, m_hasEliteSuperRewardsStatus{ false }
//{
//}
//
//AirlineTicket::~AirlineTicket()
//{
//	// Nothing to do in terms of cleanup
//}

double AirlineTicket::calculatePriceInDollars()
{
	if (hasEliteSuperRewardsStatus()) {
		// Elite Super Rewards customers fly for free!
		return 0;
	}

	// The cost of the ticket is the number of miles times 0.1.
	// Real airlines probably have a more complicated formula!
	return getNumberOfMiles() * 0.1;
}

string AirlineTicket::getPassengerName()
{
	return m_passengerName;
}

void AirlineTicket::setPassengerName(string name)
{
	m_passengerName = name;
}

int AirlineTicket::getNumberOfMiles()
{
	return m_numberOfMiles;
}

void AirlineTicket::setNumberOfMiles(int miles)
{
	m_numberOfMiles = miles;
}

bool AirlineTicket::hasEliteSuperRewardsStatus()
{
	return m_hasEliteSuperRewardsStatus;
}

void AirlineTicket::setHasEliteSuperRewardsStatus(bool status)
{
	m_hasEliteSuperRewardsStatus = status;
}
