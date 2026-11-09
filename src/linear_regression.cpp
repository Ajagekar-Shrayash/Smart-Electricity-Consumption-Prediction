#include <iostream>
#include <vector>
#include "../include/linear_regression.h"
#include <cmath>

using namespace std;

double predict(
    const LinearRegression& model,
    const vector<double>& features)
{
    double prediction = model.bias;

    for(int i = 0; i < model.weight.size(); i++)
    {
        prediction += model.weight[i] * features[i];
    }
    
    return prediction;
}

void trainModel(
    LinearRegression& model,
    const vector<vector<double>>& X,
    const vector<double>& y,
    int epochs,
    double learningRate)
{
    int samples = X.size();
    int features = X[0].size();

    model.weight.resize(features, 0.0);
    model.bias = 0.0;

    for(int epoch = 0; epoch < epochs; epoch++)
    {
        vector<double> dw(features, 0.0);
        double db = 0.0;

        for(int i = 0; i < samples; i++)
        {
            double prediction = predict(model, X[i]);

            double error = prediction - y[i];

            for(int j = 0; j < features; j++)
            {
                dw[j] += error*X[i][j];
            }

            db += error;
        }

        for(int j = 0; j < features; j++)
        {
            dw[j] = (2.0 / samples)*dw[j];
        }

        db = (2.0 / samples)* db;

        for(int j = 0; j < features; j++)
        {
            model.weight[j] -= learningRate*dw[j];
        }
        model.bias -= learningRate*db;

        if (!isfinite(model.bias))
        {
            cout << "Bias became invalid at epoch: "
                << epoch << endl;
            return;
        }

        for (int j = 0; j < features; j++)
        {
            if (!isfinite(model.weight[j]))
            {
                cout << "Weight became invalid at epoch: "
                     << epoch << endl;
                return;
            }   
        }
    }
    cout << " model training Completed!" << endl;
}