// Copyright 2017 Buldakov Vladislav

#include "include/weight_converter.h"
#include <map>
#include <string>

const std::map<Weights, double> WeightsMap::kWeights_ratio =
    WeightsMap::CreateMap();

WeightConverter::WeightConverter(double weight, Weights type) {
    SetWeight(weight, type);
}

void WeightConverter::SetWeight(double weight, Weights type) {
    weight_ = weight * WeightsMap::kWeights_ratio.at(type);
}

double WeightConverter::GetWeight() {
    return weight_;
}

double WeightConverter::Convert(Weights to) {
    return weight_ / WeightsMap::kWeights_ratio.at(to);
}

double WeightConverter::Convert(double weight, Weights from, Weights to) {
    return WeightsMap::kWeights_ratio.at(from) /
        WeightsMap::kWeights_ratio.at(to) * weight;
}
