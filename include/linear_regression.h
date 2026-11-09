#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H

#include <vector>
using namespace std;

struct LinearRegression
{
    vector<double> weight;
    double bias;
};

double predict(
    const LinearRegression& model,
    const vector<double>& features
);

void trainModel(
    LinearRegression& model,
    const vector<vector<double>> & X,
    const vector<double>& y,
    int epochs,
    double learningRate
);

#endif
