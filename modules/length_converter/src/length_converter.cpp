// Copyright 2017 Tarasov Oleg

#include "include/length_converter.h"

/* Коэффициенты перевода единицы измерения в см */


const double Length::convert_coef_[] = {
    0.0001,         // Микрометры в сантиметры
    0.1,            // Миллиметры в сантиметры
    1.0,            // Сантиметры в сантиметры
    10.0,           // Дециметры в сантиметры
    100.0,          // Метры в сантиметры
    100000.0,       // Километры в сантиметры
    2.54,           // Дюймы в сантиметры
    10.16,          // Хэнды в сантиметры
    20.1168,        // Линки в сантиметры
    30.48,          // Футы в сантиметры
    91.44,          // Ярды в сантиметры
    502.92,         // Роды в сантиметры
    2011.68,        // Чейны в сантиметры
    20116.8,        // Фурлонги в сантиметры
    160934.4,       // Мили в сантиметры
    482803.2        // Лиги в сантиметры
};

Length::Length(LengthType type, double value) {
    SetValue(type, value);
}

void Length::SetValue(LengthType type, double value) {
    length_cm_ = value * GetConvertCoef(type);
}

double Length::GetConvertCoef(LengthType type) const {
    return convert_coef_[type];
}

double Length::ConvertTo(LengthType type) const {
    return length_cm_ / GetConvertCoef(type);
}
