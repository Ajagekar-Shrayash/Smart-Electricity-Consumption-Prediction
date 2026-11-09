#include <iostream>
#include "../include/preprocessing.h"
#include <cmath>

using namespace std;

PreparedData selectFeatures(const Dataset& data)
{
    PreparedData prepared;

    for (int i = 0; i < data.activePower.size(); i++)
    {
        vector<double> features;

        features.push_back(data.reactivePower[i]);
        features.push_back(data.voltage[i]);
        features.push_back(data.intensity[i]);

        features.push_back(data.subMetering1[i]);
        features.push_back(data.subMetering2[i]);
        features.push_back(data.subMetering3[i]);

        prepared.X.push_back(features);
        prepared.y.push_back(data.activePower[i]);
    }

    return prepared;
}

SplitData trainTestSplit(const PreparedData& data, double trainRatio)
{
    SplitData split;

    int splitIndex = data.X.size() * trainRatio;

    for (int i = 0; i < splitIndex; i++)
    {
        split.X_train.push_back(data.X[i]);
        split.y_train.push_back(data.y[i]);
    }

    for (int i = splitIndex; i < data.X.size(); i++)
    {
        split.X_test.push_back(data.X[i]);
        split.y_test.push_back(data.y[i]);
    }

    return split;

}

   Standardizer fitStandardizer(
    const vector<vector<double>>& X_train)
    {
        Standardizer scaler;

        int samples = X_train.size();
        int features = X_train[0].size();

        scaler.mean.resize(features, 0.0);
        scaler.stdDev.resize(features, 0.0);

        // Calculate Mean
        for (int j = 0; j < features; j++)
        {
            for (int i = 0; i < samples; i++)
            {
                scaler.mean[j] += X_train[i][j];
            }

            scaler.mean[j] /= samples;
        }

        // Calculate Standard Deviation
        for (int j = 0; j < features; j++)
        {
            for (int i = 0; i < samples; i++)
            {
                double difference =
                    X_train[i][j] - scaler.mean[j];

                scaler.stdDev[j] += difference * difference;
            }

            scaler.stdDev[j] =
            sqrt(scaler.stdDev[j] / samples);

            if (scaler.stdDev[j] == 0)
            {
                scaler.stdDev[j] = 1.0;
            }
    }

    return scaler;
}

    void transformFeatures(vector<vector<double>>& X,const Standardizer& scaler)
        {
            for(int i = 0; i < X.size(); i++)
            {
                for(int j = 0; j < X[i].size(); j++)
                {
                    X[i][j] = (X[i][j] - scaler.mean[j]) / scaler.stdDev[j];

                }
            }
        }