export module my_weather_prediction;

import weather_prediction;
import std;

export class MyWeatherPrediction : public WeatherPrediction
{
public:
	virtual void setCurrentTempCelsius(int temp);

	virtual int getTomorrowTempCelsius() const;

	void showResult() const override;

	std::string getTemperature() const override;

private:
	static int convertCelsiusToFahrenheit(int celsius);
	static int convertFahrenheitToCelsius(int fahrenheit);
};
