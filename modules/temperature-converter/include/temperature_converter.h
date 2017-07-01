// Copyright 2017 Zhorin Sergey

#ifndef MODULES_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CONVERTER_H_
#define MODULES_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CONVERTER_H_

class TemperatureConverter {
 public:
    static double CelsiusToFahrenheit(const double t);
    static double CelsiusToNewton(const double t);
    static double CelsiusToKelvin(const double t);
    static double FahrenheitToCelsius(const double t);
    static double FahrenheitToNewton(const double t);
    static double FahrenheitToKelvin(const double t);
    static double NewtonToFahrenheit(const double t);
    static double NewtonToCelsius(const double t);
    static double NewtonToKelvin(const double t);
    static double KelvinToFahrenheit(const double t);
    static double KelvinToNewton(const double t);
    static double KelvinToCelsius(const double t);
};

#endif  // MODULES_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CONVERTER_H_
