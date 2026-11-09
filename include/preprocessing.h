#ifndef PREPROCESSING_H
#define PREPROCESSING_H

#include "data_loader.h"

struct PreparedData
{
    vector<vector<double>> X;
    vector<double> y;
};

struct SplitData
{
    vector<vector<double>> X_train;
    vector<vector<double>> X_test;

    vector<double> y_train;
    vector<double> y_test;
};

PreparedData selectFeatures(const Dataset& data);

SplitData trainTestSplit(const PreparedData& data, double trainRatio);

struct Standardizer
{
    vector<double> mean;
    vector<double> stdDev;
};

Standardizer fitStandardizer(
    const vector<vector<double>> & X_train
);

void transformFeatures(
    vector<vector<double>>& X,
    const Standardizer& scalar
);

#endif