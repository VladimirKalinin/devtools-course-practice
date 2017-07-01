// Copyright 2017 Zhorin Sergey

#include "include/temperature_converter.h"

#include <string>

double TemperatureConverter::CelsiusToFahrenheit(const double t) {
    if (t < -273.15) {
        throw std::string("Temperature can't be less than absolute zero");
    }
    return 32.0 + t*(9.0 / 5.0);
}

double TemperatureConverter::CelsiusToKelvin(const double t) {
    if (t < -273.15) {
        throw std::string("Temperature can't be less than absolute zero");
    }
    return 273.15 + t;
}

double TemperatureConverter::CelsiusToNewton(const double t) {
    if (t < -273.15) {
        throw std::string("Temperature can't be less than absolute zero");
    }
    return t*(33.0 / 100.0);
}

double TemperatureConverter::FahrenheitToCelsius(const double t) {
    if (t < -459.67) {
        throw std::string("Temperature can't be less than absolute zero");
    }
    return (5.0 / 9.0)*(t - 32.0);
}

double TemperatureConverter::FahrenheitToNewton(const double t) {
    if (t < -459.67) {
        throw std::string("Temperature can't be less than absolute zero");
    }
    return (5.0 / 9.0)*(t - 32.0)*(33.0 / 100.0);
}

double TemperatureConverter::FahrenheitToKelvin(const double t) {
    if (t < -459.67) {
        throw std::string("Temperature can't be less than absolute zero");
    }
    return (5.0 / 9.0)*(t - 32.0) + 273.15;
}

double TemperatureConverter::NewtonToFahrenheit(const double t) {
    if (t < -90.14) {
        throw std::string("Temperature can't be less than absolute zero");
    }
    return t*(100.0 / 33.0)*(9.0 / 5.0) + 32.0;
}

double TemperatureConverter::NewtonToCelsius(const double t) {
    if (t < -90.14) {
        throw std::string("Temperature can't be less than absolute zero");
    }
    return t*(100.0 / 33.0);
}

double TemperatureConverter::NewtonToKelvin(const double t) {
    if (t < -90.14) {
        throw std::string("Temperature can't be less than absolute zero");
    }
    return t*(100.0 / 33.0) + 273.15;
}

double TemperatureConverter::KelvinToFahrenheit(const double t) {
    if (t < 0) {
        throw std::string("Temperature can't be less than absolute zero");
    }
    return 32.0 + (t - 273.15)*(9.0 / 5.0);
}

double TemperatureConverter::KelvinToNewton(const double t) {
    if (t < 0) {
        throw std::string("Temperature can't be less than absolute zero");
    }
    return (t - 273.15)*(33.0 / 100.0);
}

double TemperatureConverter::KelvinToCelsius(const double t) {
    if (t < 0) {
        throw std::string("Temperature can't be less than absolute zero");
    }
    return t - 273.15;
}
