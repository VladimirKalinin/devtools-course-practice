// Copyright 2017 Tarasov Oleg

/* 
Использование:
Length length(LENGTH_LYPE in_type, double value);
double converted_val = length.ConverTo(LENGTH_LYPE out_type);

LENGTH_LYPE in_type - входная единица измерения
double val - входное значение
out_type - выходная единица измерения
*/


#ifndef MODULES_LENGTH_CONVERTER_INCLUDE_LENGTH_CONVERTER_H_
#define MODULES_LENGTH_CONVERTER_INCLUDE_LENGTH_CONVERTER_H_

enum LengthType {
    /* Метрические единицы измерения */
    MICROMETRE,     // микрометр = 0.000001 метра
    MILLIMETRE,     // миллиметр = 0.001 метра
    CENTIMETRE,     // сантиметр = 0.01 метра
    DECIMETRE,      // дециметр = 0.1 метра
    METRE,          // метр
    KILOMETRE,      // километр = 1000 метров

    /* Английская система мер */
    INCH,           // дюйм = 2.54 см
    HAND,           // хэнд = 10.16 см
    LINK,           // линк = 20.1168 см
    FOOT,           // фут = 30.48 см
    YARD,           // ярд = 91.44 см
    ROD,            // род/перч = 5.0292 м
    CHAIN,          // чейн = 20.1168 м
    FURHLONG,       // фурлонг = 201.16 м
    MILE,           // миля = 1,609344 км
    LEAGUE,         // лига = 4,828032 км
    _LENGTH_END_    // фиктивный член - конец enum'а
};


class Length {
 public:
    Length(LengthType type, double value);
    void SetValue(LengthType type, double value);
    double ConvertTo(LengthType type) const;

 private:
    double length_cm_;  // Длина в сантиметрах
    double GetConvertCoef(LengthType type) const;

    static const double convert_coef_[_LENGTH_END_];

    /*static const double micrometre_to_cm_;
    static const double millimetre_to_cm_;
    static const double centimetre_to_cm_;
    static const double decimetre_to_cm_;
    static const double metre_to_cm_;
    static const double kilometre_to_cm_;
    static const double inch_to_cm_;
    static const double hand_to_cm_;
    static const double link_to_cm_;
    static const double foot_to_cm_;
    static const double yard_to_cm_;
    static const double rod_to_cm_;
    static const double chain_to_cm_;
    static const double furhlong_to_cm_;
    static const double mile_to_cm_;
    static const double league_to_cm_;*/
};

#endif  // MODULES_LENGTH_CONVERTER_INCLUDE_LENGTH_CONVERTER_H_
