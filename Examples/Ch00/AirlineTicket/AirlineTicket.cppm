export module airline_ticket;

import <string>;

export class AirlineTicket
{
public:
	//AirlineTicket();
	//~AirlineTicket();

	double calculatePriceInDollars();
	
	std::string getPassengerName();
	void setPassengerName(std::string name);

	int getNumberOfMiles();
	void setNumberOfMiles(int miles);
	
	bool hasEliteSuperRewardsStatus();
	void setHasEliteSuperRewardsStatus(bool status);

private:
	//std::string m_passengerName;
	//int m_numberOfMiles;
	//bool m_hasEliteSuperRewardsStatus;
	std::string m_passengerName{ "Unknown Passenger" };
	int m_numberOfMiles{ 0 };
	bool m_hasEliteSuperRewardsStatus{ false };
};
