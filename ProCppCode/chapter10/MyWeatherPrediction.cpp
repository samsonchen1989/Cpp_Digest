#include <iostream>
#include "MyWeatherPrediction.h"

void MyWeatherPrediction::setCurrentTempCelsius(int inTemp)
{
    setCurrentTempFahrenheit(convertCelsiusToFahrenheit(inTemp));
}

int MyWeatherPrediction::getTomorrowTemCelsius()
{
    return convertFahrenheitToCelsius(getTomorrowTempFahrenheit());
}

int MyWeatherPrediction::convertCelsiusToFahrenheit(int inCelsius)
{
    return (1.8 * inCelsius + 32);
}

int MyWeatherPrediction::convertFahrenheitToCelsius(int inFahrenheit)
{
    return (inFahrenheit - 32) * 5 / 9;
}

void MyWeatherPrediction::showResult()
{
    WeatherPrediction::showResult();
    std::cout << "Tomorrow Celsius:" << getTomorrowTemCelsius() << std::endl;
}