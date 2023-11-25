module weather_prediction;

import std;

using namespace std;

WeatherPrediction::~WeatherPrediction()
{
}

void WeatherPrediction::setCurrentTempFahrenheit(int temp)
{
	m_currentTempFahrenheit = temp;
}

void WeatherPrediction::setPositionOfJupiter(int distanceFromMars)
{
	m_distanceFromMars = distanceFromMars;
}

int WeatherPrediction::getTomorrowTempFahrenheit() const
{
	// Obviously, this is nonsense
	return (m_distanceFromMars / 1000) + m_currentTempFahrenheit;
}

double WeatherPrediction::getChanceOfRain() const
{
	// Obviously, this is nonsense too
	return 0.5;
}

void WeatherPrediction::showResult() const
{
	println("Result: {} chance.  Temp. {}",
		getChanceOfRain() * 100, getTomorrowTempFahrenheit());
}

std::string WeatherPrediction::getTemperature() const
{
	return to_string(m_currentTempFahrenheit);
}
