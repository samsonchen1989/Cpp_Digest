#include <iostream>
#include "WeatherPrediction.h"

void WeatherPrediction::setCurrentTempFahrenheit(int inTemp)
{
    mCurrentFahrenheit = inTemp;
}

void WeatherPrediction::setPositionOfJupiter(int inDistanceFromMars)
{
    mDistanceFromMars = inDistanceFromMars;
}

int WeatherPrediction::getTomorrowTempFahrenheit()
{
    return mCurrentFahrenheit;
}

double WeatherPrediction::getChanceOfRain()
{
    return 0;
}

void WeatherPrediction::showResult()
{
    std::cout << "Tommorrow Fahrenheit:" << getTomorrowTempFahrenheit() << std::endl;
}

