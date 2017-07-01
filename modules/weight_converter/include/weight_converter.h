// Copyright 2017 Buldakov Vladislav

#ifndef MODULES_WEIGHT_CONVERTER_INCLUDE_WEIGHT_CONVERTER_H_
#define MODULES_WEIGHT_CONVERTER_INCLUDE_WEIGHT_CONVERTER_H_

#include <map>

enum Weights {
    KG,    // kilogram
    MG,    // milligram
    G,     // gram
    GR,    // grain
    DR,    // dram
    OZ,    // ounce
    LB,    // pound
    CR,    // carat

    END
};

struct WeightsMap {
    static std::map<Weights, double> CreateMap() {
        std::map<Weights, double> m;
        m[KG] = 1.0;
        m[MG] = 0.000001;
        m[G] = 0.001;
        m[GR] = 0.00006479891;
        m[DR] = 0.00177185;
        m[OZ] = 0.0283495;
        m[LB] = 0.453592;
        m[CR] = 0.0002;
        return m;
    }
    static const std::map<Weights, double> kWeights_ratio;
};

class WeightConverter {
 public:
    explicit WeightConverter(double weight = 0.0, Weights type = KG);
    void SetWeight(double weight, Weights type);
    double GetWeight();

    double Convert(Weights to);
    double Convert(double weight, Weights from, Weights to);
 private:
    double weight_;    // kg
};

#endif  // MODULES_WEIGHT_CONVERTER_INCLUDE_WEIGHT_CONVERTER_H_
