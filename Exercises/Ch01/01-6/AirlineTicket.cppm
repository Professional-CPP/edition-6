export module airline_ticket;

import std;

export class AirlineTicket
{
public:
	double calculatePriceInDollars() const;          //// const member function
	
	const std::string& getPassengerName() const;     //// const member function + return a const reference
	void setPassengerName(const std::string& name);  //// Accept a const reference

	int getNumberOfMiles() const;                    //// const member function
	void setNumberOfMiles(int miles);
	
	bool hasEliteSuperRewardsStatus() const;         //// const member function
	void setHasEliteSuperRewardsStatus(bool status);

private:
	std::string m_passengerName{ "Unknown Passenger" };
	int m_numberOfMiles{ 0 };
	bool m_hasEliteSuperRewardsStatus{ false };
};
