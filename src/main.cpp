#include <iostream>
#include "../include/data_loader.h"
#include "../include/preprocessing.h"
#include "../include/linear_regression.h"
#include <cmath>

using namespace std;

int main()
{
    Dataset data = loadDataset("dataset/household_power_consumption.txt", 10000);

    if (data.activePower.empty())
    {
        cout << "No valid dataset records found!" << endl;
        return 1;
    }

    PreparedData prepared = selectFeatures(data);

    cout << "\n--- Feature Selection ---\n";

    cout << "Total Samples: " << prepared.X.size() << endl;
    cout << "Features per Sample: " << prepared.X[0].size() << endl;
    cout << "Target Values: " << prepared.y.size() << endl;


    SplitData split = trainTestSplit(prepared, 0.8);

    cout << "\n--- Train-Test Split ---\n";

    cout << "Training Samples: " << split.X_train.size() << endl;
    cout << "Testing Samples: " << split.X_test.size() << endl;

    cout << "Training Targets: " << split.y_train.size() << endl;
    cout << "Testing Targets: " << split.y_test.size() << endl;

    Standardizer scaler = fitStandardizer(split.X_train);

    transformFeatures(split.X_train, scaler);

    transformFeatures(split.X_test, scaler);

    cout << "\n  Features Standardization  \n ";
    cout << "\n Standardization completed successfully!" << endl;

    LinearRegression model;

    cout << "\n  Model Training  \n";

    trainModel(
        model,
        split.X_train,
        split.y_train,
        1000,
        0.01
    );

    cout << "\n Model Parameters  \n";

    cout << "Bias:" << model.bias << endl;

    for(int i = 0; i < model.weight.size(); i++)
    {
        cout << "Weight" << i+1
            <<":" << model.weight[i] << endl;
    }

    cout << "\n model testing  \n";

    double totalError = 0.0;

    for(int i = 0; i < split.X_test.size(); i++)
    {
        double predicted = predict(model,split.X_test[i]);

        double actual = split.y_test[i];

        if(!isfinite(predicted))
        {
            cout << " Invalid prediction detected" << i << endl;
            return 1;
        }

        totalError += abs(predicted - actual);

        if(i<5)
        {
            cout << "Actual: " << actual
                <<"| Predicted: " << predicted << endl;
        }
    }

    double MAE = totalError / split.X_test.size();

    cout << "\n  Mean Absolute Error: " << MAE << "kW" << endl;

    return 0;
}