// Copyright 2017 Zhorin Sergey

#include <gtest/gtest.h>

#include <string>

#include "include/temperature_converter.h"

TEST(TemperatureConverterTest, Can_Convert_Celsius_To_Fahrenheit) {
    // Arrange
    double Celsius = 26.0;

    // Act
    double Fahrenheit = TemperatureConverter::CelsiusToFahrenheit(Celsius);

    // Assert
    double expectedFahrenheit = 32.0 + 26*(9.0 / 5.0);
    EXPECT_EQ(Fahrenheit, expectedFahrenheit);
}

TEST(TemperatureConverterTest,
    Cant_Convert_Celsius_To_Newton_Temeprature_Less_Than_Absolute_Zero) {
    // Arrange
    double Celsius = -274.0;

    // Act & Assert
    EXPECT_THROW(TemperatureConverter::CelsiusToNewton(Celsius), std::string);
}

TEST(TemperatureConverterTest,
    Cant_Convert_Celsius_To_Fahrenheit_Temeprature_Less_Than_Absolute_Zero) {
    // Arrange
    double Celsius = -274.0;

    // Act & Assert
    EXPECT_THROW(TemperatureConverter::CelsiusToFahrenheit(Celsius),
        std::string);
}

TEST(TemperatureConverterTest,
    Cant_Convert_Celsius_To_Kelvin_Temeprature_Less_Than_Absolute_Zero) {
    // Arrange
    double Celsius = -274.0;

    // Act & Assert
    EXPECT_THROW(TemperatureConverter::CelsiusToKelvin(Celsius), std::string);
}

TEST(TemperatureConverterTest, Can_Convert_Celsius_To_Newton) {
    // Arrange
    double Celsius = 26.0;

    // Act
    double Newton = TemperatureConverter::CelsiusToNewton(Celsius);

    // Assert
    double expectedNewton = 26.0*(33.0 / 100.0);
    EXPECT_EQ(Newton, expectedNewton);
}

TEST(TemperatureConverterTest, Can_Convert_Celsius_To_Kelvin) {
    // Arrange
    double Celsius = 26.0;

    // Act
    double Kelvin = TemperatureConverter::CelsiusToKelvin(Celsius);

    // Assert
    double expectedKelvin = 273.15 + 26.0;
    EXPECT_EQ(Kelvin, expectedKelvin);
}

TEST(TemperatureConverterTest, Can_Convert_Kelvin_To_Newton) {
    // Arrange
    double Kelvin = 26.0;

    // Act
    double Newton = TemperatureConverter::KelvinToNewton(Kelvin);

    // Assert
    double expectedNewton = (26.0 - 273.15)*(33.0 / 100.0);
    EXPECT_EQ(Newton, expectedNewton);
}
TEST(TemperatureConverterTest, Can_Convert_Kelvin_To_Celsius) {
    // Arrange
    double Kelvin = 26.0;

    // Act
    double Celsius = TemperatureConverter::KelvinToCelsius(Kelvin);

    // Assert
    double expectedCelsius = 26.0 - 273.15;
    EXPECT_EQ(Celsius, expectedCelsius);
}
TEST(TemperatureConverterTest, Can_Convert_Kelvin_To_Fahrenheit) {
    // Arrange
    double Kelvin = 26.0;

    // Act
    double Fahrenheit = TemperatureConverter::KelvinToFahrenheit(Kelvin);

    // Assert
    double expectedFahrenheit = 32.0 + (26.0 - 273.15)*(9.0 / 5.0);
    EXPECT_EQ(Fahrenheit, expectedFahrenheit);
}
TEST(TemperatureConverterTest, Can_Convert_Newton_To_Kelvin) {
    // Arrange
    double Newton = 26.0;

    // Act
    double Kelvin = TemperatureConverter::NewtonToKelvin(Newton);

    // Assert
    double expectedKelvin = 26.0*(100.0 / 33.0) + 273.15;
    EXPECT_EQ(Kelvin, expectedKelvin);
}
TEST(TemperatureConverterTest, Can_Convert_Newton_To_Celsius) {
    // Arrange
    double Newton = 26.0;

    // Act
    double Celsius = TemperatureConverter::NewtonToCelsius(Newton);

    // Assert
    double expectedCelsius = 26.0*(100.0 / 33.0);
    EXPECT_EQ(Celsius, expectedCelsius);
}
TEST(TemperatureConverterTest, Can_Convert_Newton_To_Fahrenheit) {
    // Arrange
    double Newton = 26.0;

    // Act
    double Fahrenheit = TemperatureConverter::NewtonToFahrenheit(Newton);

    // Assert
    double expectedFahrenheit = 26.0*(100.0 / 33.0)*(9.0 / 5.0) + 32.0;
    EXPECT_EQ(Fahrenheit, expectedFahrenheit);
}
TEST(TemperatureConverterTest, Can_Convert_Fahrenheit_To_Kelvin) {
    // Arrange
    double Fahrenheit = 26.0;

    // Act
    double Kelvin = TemperatureConverter::FahrenheitToKelvin(Fahrenheit);

    // Assert
    double expectedKelvin = (5.0 / 9.0)*(26.0 - 32.0) + 273.15;
    EXPECT_EQ(Kelvin, expectedKelvin);
}
TEST(TemperatureConverterTest, Can_Convert_Fahrenheit_To_Newton) {
    // Arrange
    double Fahrenheit = 26.0;

    // Act
    double Newton = TemperatureConverter::FahrenheitToNewton(Fahrenheit);

    // Assert
    double expectedNewton = (5.0 / 9.0)*(26.0 - 32.0)*(33.0 / 100.0);
    EXPECT_EQ(Newton, expectedNewton);
}
TEST(TemperatureConverterTest, Can_Convert_Fahrenheit_To_Celsius) {
    // Arrange
    double Fahrenheit = 26.0;

    // Act
    double Celsius = TemperatureConverter::FahrenheitToCelsius(Fahrenheit);

    // Assert
    double expectedCelsius = (5.0 / 9.0)*(26.0 - 32.0);
    EXPECT_EQ(Celsius, expectedCelsius);
}

TEST(TemperatureConverterTest,
    Cant_Convert_Fahrenheit_To_Newton_Temeprature_Less_Than_Absolute_Zero) {
    // Arrange
    double Fahrenheit = -460.0;

    // Act & Assert
    EXPECT_THROW(TemperatureConverter::FahrenheitToNewton(Fahrenheit),
        std::string);
}

TEST(TemperatureConverterTest,
    Cant_Convert_Fahrenheit_To_Celsius_Temeprature_Less_Than_Absolute_Zero) {
    // Arrange
    double Fahrenheit = -460.0;

    // Act & Assert
    EXPECT_THROW(TemperatureConverter::FahrenheitToCelsius(Fahrenheit),
        std::string);
}

TEST(TemperatureConverterTest,
    Cant_Convert_Fahrenheit_To_Kelvin_Temeprature_Less_Than_Absolute_Zero) {
    // Arrange
    double Fahrenheit = -460.0;

    // Act & Assert
    EXPECT_THROW(TemperatureConverter::FahrenheitToKelvin(Fahrenheit),
        std::string);
}

TEST(TemperatureConverterTest,
    Cant_Convert_Newton_To_Celsius_Temeprature_Less_Than_Absolute_Zero) {
    // Arrange
    double Newton = -91.0;

    // Act & Assert
    EXPECT_THROW(TemperatureConverter::NewtonToCelsius(Newton), std::string);
}

TEST(TemperatureConverterTest,
    Cant_Convert_Newton_To_Fahrenheit_Temeprature_Less_Than_Absolute_Zero) {
    // Arrange
    double Newton = -91.0;

    // Act & Assert
    EXPECT_THROW(TemperatureConverter::NewtonToFahrenheit(Newton), std::string);
}

TEST(TemperatureConverterTest,
    Cant_Convert_Newton_To_Kelvin_Temeprature_Less_Than_Absolute_Zero) {
    // Arrange
    double Newton = -91.0;

    // Act & Assert
    EXPECT_THROW(TemperatureConverter::NewtonToKelvin(Newton), std::string);
}

TEST(TemperatureConverterTest,
    Cant_Convert_Kelvin_To_Newton_Temeprature_Less_Than_Absolute_Zero) {
    // Arrange
    double Kelvin = -1.0;

    // Act & Assert
    EXPECT_THROW(TemperatureConverter::KelvinToNewton(Kelvin), std::string);
}

TEST(TemperatureConverterTest,
    Cant_Convert_Kelvin_To_Fahrenheit_Temeprature_Less_Than_Absolute_Zero) {
    // Arrange
    double Kelvin = -1.0;

    // Act & Assert
    EXPECT_THROW(TemperatureConverter::KelvinToFahrenheit(Kelvin), std::string);
}

TEST(TemperatureConverterTest,
    Cant_Convert_Kelvin_To_Celsius_Temeprature_Less_Than_Absolute_Zero) {
    // Arrange
    double Kelvin = -1.0;

    // Act & Assert
    EXPECT_THROW(TemperatureConverter::KelvinToCelsius(Kelvin), std::string);
}
