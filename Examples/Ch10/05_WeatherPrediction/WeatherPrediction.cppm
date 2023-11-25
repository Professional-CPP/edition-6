export module weather_prediction;

import std;

// Predicts the weather using proven new-age techniques given the current
// temperature and the distance from Jupiter to Mars. If these values are
// not provided, a guess is still given but it's only 99% accurate.
export class WeatherPrediction
{
public:
	// Virtual destructor
	virtual ~WeatherPrediction();

	// Sets the current temperature in Fahrenheit
	virtual void setCurrentTempFahrenheit(int temp);

	// Sets the current distance between Jupiter and Mars
	virtual void setPositionOfJupiter(int distanceFromMars);
	
	// Gets the prediction for tomorrow's temperature
	virtual int getTomorrowTempFahrenheit() const;
	
	// Gets the probability of rain tomorrow. 1 means
	// definite rain. 0 means no chance of rain.
	virtual double getChanceOfRain() const;
	
	// Displays the result to the user in this format:
	// Result: x.xx chance. Temp. xx
	virtual void showResult() const;
	
	// Returns a string representation of the temperature
	virtual std::string getTemperature() const;

private:
	int m_currentTempFahrenheit{ 0 };
	int m_distanceFromMars{ 0 };
};
