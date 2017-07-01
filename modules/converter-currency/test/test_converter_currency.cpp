// Copyright 2017 Dmitrichev Nikita

#include <gtest/gtest.h>
#include "include/ConverterCurrency.h"

TEST(ConverterCurrenciesTest, can_not_convert_if_money_size_less_then_zero) {
    EXPECT_ANY_THROW(ConverterCurrency::Convert(-1, RUR, EUR));
}

TEST(ConverterCurrenciesTest, can_convert_if_money_size_equal_to_zero) {
    EXPECT_NO_THROW(ConverterCurrency::Convert(0, RUR, EUR));
}

TEST(ConverterCurrenciesTest, if_zero_money_size_was_converted_its_zero) {
    double expected = 0.0;
    EXPECT_EQ(expected, ConverterCurrency::Convert(0, RUR, EUR));
}

TEST(ConverterCurrenciesTest, can_convert_if_target_equal_to_old) {
    double exp = 111.1;
    EXPECT_NEAR(exp, ConverterCurrency::Convert(exp, EUR, EUR), 0.01);
}

TEST(ConverterCurrenciesTest, converter_works_right) {
    double expected = 2647.32;  // 100 usd to uah
    EXPECT_NEAR(expected, ConverterCurrency::Convert(100.0, USD, UAH), 0.5);
}

TEST(ConverterCurrenciesTest,
    cant_do_set_if_second_parameter_less_than_0) {
    EXPECT_ANY_THROW(ConverterCurrency::SetExchangeRateToRUR(USD, -1));
}

TEST(ConverterCurrenciesTest,
    cant_do_set_if_second_parameter_equal_to_0) {
    EXPECT_ANY_THROW(ConverterCurrency::SetExchangeRateToRUR(USD, 0));
}

TEST(ConverterCurrenciesTest, there_is_no_throw_if_currency_is_RUR) {
    EXPECT_NO_THROW(ConverterCurrency::SetExchangeRateToRUR(RUR, 4));
}

TEST(ConverterCurrenciesTest, exchange_rate_rur_to_rur_does_not_change) {
    double new_rur_to_rur = 5.0;

    ConverterCurrency::SetExchangeRateToRUR(RUR, new_rur_to_rur);

    double expected = 100.0;
    EXPECT_EQ(expected, ConverterCurrency::Convert(expected, RUR, RUR));
}

TEST(ConverterCurrenciesTest, set_exchange_rate_to_rur_works_right) {
    double new_usd_to_rur = 30.0;
    double old_money_size = 100.0;  // 100 usd

    ConverterCurrency::SetExchangeRateToRUR(USD, new_usd_to_rur);

    double expected = old_money_size*new_usd_to_rur;  // 100 usd to rur
    EXPECT_EQ(expected, ConverterCurrency::Convert(old_money_size, USD, RUR));
}
