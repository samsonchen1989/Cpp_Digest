#include "MyWeatherPrediction.h"

using namespace std;

int main(int args, char** argv)
{
    MyWeatherPrediction wp;

    wp.setCurrentTempCelsius(35);
    wp.showResult();

    return 0;
}