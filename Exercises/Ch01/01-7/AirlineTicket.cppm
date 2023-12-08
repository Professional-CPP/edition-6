export module airline_ticket;

import std;

export class AirlineTicket
{
public:
	double calculatePriceInDollars() const;
	
	const std::string& getPassengerName() const;
	void setPassengerName(const std::string& name);

	int getNumberOfMiles() const;
	void setNumberOfMiles(int miles);
	
	bool hasEliteSuperRewardsStatus() const;
	void setHasEliteSuperRewardsStatus(bool status);

	std::optional<int> getFrequentFlyerNumber() const;
	void setFrequentFlyerNumber(int number);

private:
	std::string m_passengerName{ "Unknown Passenger" };
	int m_numberOfMiles{ 0 };
	bool m_hasEliteSuperRewardsStatus{ false };
	std::optional<int> m_frequentFlyerNumber;
};
