export module airline_ticket;

import std;

export class AirlineTicket
{
public:
	double calculatePriceInDollars() const;
	
	std::string getPassengerName() const;
	void setPassengerName(std::string name);

	int getNumberOfMiles() const;
	void setNumberOfMiles(int miles);
	
	bool hasEliteSuperRewardsStatus() const;
	void setHasEliteSuperRewardsStatus(bool status);

private:
	std::string m_passengerName{ "Unknown Passenger" };
	int m_numberOfMiles{ 0 };
	bool m_hasEliteSuperRewardsStatus{ false };
};
