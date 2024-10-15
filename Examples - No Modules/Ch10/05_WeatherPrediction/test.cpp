#include "MyWeatherPrediction.h"
#include <print>

using namespace std;

int main()
{
	MyWeatherPrediction p;
	p.setCurrentTempCelsius(33);
	p.setPositionOfJupiter(80);
	p.showResult();
	println("{}", p.getTemperature());
}
