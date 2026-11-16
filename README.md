SMART ELECTRICITY CONSUMPTION PREDICTION

C++ MACHINE LEARNING PROJECT

Team Members:

- AJAGEKAR SHRAYASH MACHINDRA
- MANSURI HAREEMBANU MOHAMMED HUSSAIN

================================================

FILES

data_loader.h / data_loader.cpp

Dataset structure and electricity dataset loading.

Structure:

- "Dataset"

Function:

- "loadDataset()" – Loads the dataset, checks missing values and stores valid records.

preprocessing.h / preprocessing.cpp

Data preprocessing, feature selection, train-test splitting and standardization.

Structures:

- "PreparedData" – Stores input features (X) and target values (y).
- "SplitData" – Stores training and testing datasets.
- "Standardizer" – Stores mean and standard deviation.

Functions:

- "selectFeatures()" – Selects six input features and one target variable.
- "trainTestSplit()" – Splits data into training and testing sets.
- "fitStandardizer()" – Calculates mean and standard deviation from training features.
- "transformFeatures()" – Standardizes input features.

linear_regression.h / linear_regression.cpp

Linear Regression model implementation using Gradient Descent.

Structure:

- "LinearRegression" – Stores model weights and bias.

Functions:

- "trainModel()" – Trains the model by updating weights and bias.
- "predict()" – Estimates Global Active Power using trained model parameters.

main.cpp

Main function and complete execution workflow.

- Dataset loading
- Feature selection
- Train-test splitting
- Feature standardization
- Model training
- Model testing
- Prediction
- MAE calculation

================================================

DATASET FEATURES


INPUT FEATURES (X):

1. Global Reactive Power
2. Voltage
3. Global Intensity
4. Sub Metering 1
5. Sub Metering 2
6. Sub Metering 3

TARGET VARIABLE (Y):

- Global Active Power (kW)

Date and Time are not used as model input features.

================================================

MACHINE LEARNING WORKFLOW

Dataset Loading
|
v
Data Preprocessing
|
v
Feature Selection
|
v
Train-Test Split (80:20)
|
v
Feature Standardization
|
v
Linear Regression
|
v
Gradient Descent
|
v
Model Training
|
v
Model Testing
|
v
Prediction
|
v
MAE Evaluation

================================================

REQUIREMENTS

- Windows
- GCC 
- Visual Studio Code

================================================

COMPILE

Run from the project root directory.

Create the bin directory if it does not exist:

mkdir bin

Compile:

g++ src/main.cpp src/data_loader.cpp src/preprocessing.cpp src/linear_regression.cpp -o bin/main.exe

================================================

RUN

bin\main.exe

================================================

NOTES

- The dataset uses semicolon-separated values.
- Records containing missing numerical values ("?") are skipped.
- The current implementation processes up to 10,000 valid records.
- Linear Regression learns weights and bias using Gradient Descent.
- Feature standardization uses training data statistics.
- The model estimates Global Active Power from supplied electrical measurements.
- The current implementation does not perform future time-based forecasting.
- Model evaluation using MAE is currently performed inside "main.cpp".

================================================