// Copyright 2017 Kuchkov Ivan

#include <gtest/gtest.h>

#include <math.h>
#include <vector>
#include <limits>

#include "include/area_converter.h"

static const double kNeighbourhood =
std::numeric_limits<double>::epsilon() * 100000;

TEST(AreaConverterTest, can_create_converter_unit) {
    EXPECT_NO_THROW(AreaConverter(AreaConverter::kCentimeter,
        AreaConverter::kMeter));
}

TEST(AreaConverterTest,
    cant_create_converter_unit_with_wrong_format_to) {
    EXPECT_ANY_THROW(AreaConverter(AreaConverter::kCentimeter,
        0));
}

TEST(AreaConverterTest,
    cant_create_converter_unit_with_wrong_format_from) {
    EXPECT_ANY_THROW(AreaConverter(0,
        AreaConverter::kMeter));
}

TEST(AreaConverterTest, check_create_converter_unit) {
    AreaConverter c = AreaConverter(AreaConverter::kCentimeter,
        AreaConverter::kMeter);

    double r1 = c(123);
    double r2 = 0.0123;

    ASSERT_NEAR(r1, r2, kNeighbourhood);
}

TEST(AreaConverterTest, check_acr_to_yard_convertion) {
    double r1 = AreaConverter(AreaConverter::kAcr,
        AreaConverter::kYard)(10);
    double r2 = 4840. * 10;

    ASSERT_NEAR(r1, r2, kNeighbourhood);
}

TEST(AreaConverterTest, can_operate_with_zero_size_areas) {
    double r1 = AreaConverter(AreaConverter::kMeter,
        AreaConverter::kInch)(0.);
    double r2 = 0.;

    EXPECT_DOUBLE_EQ(r1, r2);
}

TEST(AreaConverterTest, is_negative_size_area_works_correct) {
    AreaConverter c = AreaConverter(AreaConverter::kMeter,
        AreaConverter::kInch);

    EXPECT_ANY_THROW(c(-2.1718));
}

TEST(AreaConverterTest,
    check_convert_multiple_times_with_different_arguments) {
    AreaConverter c = AreaConverter(AreaConverter::kCentimeter,
        AreaConverter::kAcr);
    int size = 10;
    double delta = 0.25;
    std::vector<double> r1(size);
    std::vector<double> r2(size);

    for (int i = 0; i < size; ++i) {
        r1.push_back(c(i * delta));
        r2.push_back(AreaConverter(AreaConverter::kCentimeter,
            AreaConverter::kAcr)(i * delta));
    }

    ASSERT_TRUE(r1 == r2);
}
