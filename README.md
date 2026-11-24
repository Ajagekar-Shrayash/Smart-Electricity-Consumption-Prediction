**SMART ELECTRICITY CONSUMPTION PREDICTION**
------------------------------------------------
c++   machine learning  project
------------------------------------------------
 
Team Members:

- AJAGEKAR SHRAYASH MACHINDRA  - 04
- MANSURI HAREEMBANU MOHAMMED HUSSAIN - 05

INTRO:
------------------------------------------------
This project uses Linear Regression with Gradient Descent in C++ to predict household electricity consumption (Global Active Power) based on six electrical features from historical data.

PROJECT STRUCTURE:
------------------------------------------------

```
bin /                    main.exe
dataset/                 household_power_consumption.txt
include/                 data_loader.h/preprocessing.h/linear_regression.h(Header files)
src/                     data_loader.cpp/preprocessing.cpp/linear_regression.cpp/main.cpp(Source files)
```
 
FILES:
------------------------------------------------

"data_loader.h/data_loader.cpp:" - Dataset structure and electricity dataset loading.    
  
"preprocessing.h/preprocessing.cpp:" - Data preprocessing, feature selection, train-test splitting and standardization.

"linear_regression.h/linear_regression.cpp:" - Linear Regression model implementation using Gradient Descent.

`Structure:`

- "Dataset"
- "PreparedData" –  Stores input features (X) and target values (y).
- "SplitData" –  Stores training and testing datasets.
- "Standardizer" –  Stores mean and standard deviation
- "LinearRegression" –  Stores model weights and bias.

`Function:`
 
- "loadDataset()" –  Loads the dataset, checks missing values and stores valid records.
- "selectFeatures()" –  Selects six input features and one target variable.
- "trainTestSplit()" –  Splits data into training and testing sets.
- "fitStandardizer()" –  Calculates mean and standard deviation from training features.
- "transformFeatures()" –  Standardizes input features.
- "trainModel()" –  Trains the model by updating weights and bias.
- "predict()" –  Estimates Global Active Power using trained model parameters.


main.cpp:
------------------------------------------------

    Main function and complete execution workflow.

    - Dataset loading
    - Feature selection
    - train_test_splitting
    - Feature standardization
    - Model training
    - Model testing
    - Prediction
    - MAE calculation

DATASET FEATURES:
------------------------------------------------

- INPUT FEATURES (X):

 1. Global Reactive Power
 2. Voltage
 3. Global Intensity
 4. Sub Metering 1
 5. Sub Metering 2
 6. Sub Metering 3

- TARGET VARIABLE (Y):

     Global Active Power (kW)

Date and Time are not used as model input features.


REQUIREMENTS:
------------------------------------------------
    
   - Windows
   - GCC 
   - Visual Studio Code

COMPILE:
------------------------------------------------

`g++ src/main.cpp src/data_loader.cpp src/preprocessing.cpp src/linear_regression.cpp -o bin/main.exe`
      

RUN:
------------------------------------------------

`bin\main.exe`


NOTES:
------------------------------------------------

- The dataset uses semicolon-separated values.
- Records containing missing numerical values ("?") are skipped.
- The current implementation processes up to 10,000 valid records.
- Linear Regression learns weights and bias using Gradient Descent.
- Feature standardization uses training data statistics.
- The model estimates Global Active Power from supplied electrical measurements.
- The current implementation does not perform future time-based forecasting.
- Model evaluation using MAE is currently performed inside "main.cpp".
