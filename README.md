## PROJECT TITLE

# [![Typing SVG](https://readme-typing-svg.demolab.com?font=Fira+Code&size=28&duration=3000&pause=1000&width=700&lines=Smart+Electricity+Consumption+Prediction)](https://git.io/typing-svg)

### PROJECT DESCRIPTION

This project aims to develop a C++ based Machine Learning that analyzes historical electricity consumption data
and predicts future consumption using Linear Regression.

The system will process historical readings, learn the relationship between relevant input variables and electricity
usage, and generate predictions for new inputs. It will also evaluate prediction accuracy by comparing predicted values
with actual readings.

The project will implement the core prediction algorithm in C++ without relying on Python. It will demonstrate fundamental
Machine Learning concepts, including data processing, model training, prediction and evaluation.

### PROJECT DELIVERABLES

1. **C++ Application:** A working program for electricity consumption prediction.
3. **Dataset:** A sample dataset containing historical electricity consumption readings.
5. **Data Processing Module:** Functionality to load and process the dataset.
7. **Machine Learning Model:** A Linear Regression algorithm implemented in C++.
9. **Prediction Module:** Functionality to estimate electricity consumption for new inputs.
11. **Evaluation Module:** Calculation of prediction errors using appropriate evaluation metrics such as MAE.
13. **Testing and Results:** Test cases and results demonstrating the model's performance.
15. **Project Documentation:** A report explaining the problem, methodology, algorithm, implementation, results and limitations.
16. **Generate predictions and evaluate model performance.**

### 🛠️ Technologies Used

**Programming Language:** C++

**Compiler:** GCC (g++)

**Machine Learning:** Linear Regression

**Optimization:** Gradient Descent

**Data Structures:** C++ Vectors

**Evaluation Metric:** Mean Absolute Error (MAE)

### 📂 Project Structure

**Smart-Electricity-Consumption-Prediction/**
│
├── **dataset/**
│   └── *household_power_consumption.txt*
│
├── **include/**
│   ├── *data_loader.h*
│   ├── *preprocessing.h*
│   └── *linear_regression.h*
│
├── **src/**
│   ├── *main.cpp*
│   ├── *data_loader.cpp*
│   ├── *preprocessing.cpp*
│   └── *linear_regression.cpp*
│
├── **bin/**
│   └── *main.exe*
│
├── **.gitignore**
└── **README.md**

### 📊 Dataset Information

**Dataset:** Individual Household Electric Power Consumption

**Source:** `UCI Machine Learning Repository`

The dataset contains household electrical measurements recorded at one-minute intervals.

### Features Used

| Feature | Description |
|:---|:---|
| `Global_reactive_power` | Reactive power measurement |
| `Voltage` | Household electrical voltage |
| `Global_intensity` | Overall current intensity |
| `Sub_metering_1` | Energy used by kitchen appliances |
| `Sub_metering_2` | Energy used by laundry appliances |
| `Sub_metering_3` | Energy used by other appliances |

**Target Variable:** `Global_active_power` (kW)

The program processes up to 10,000 valid records and skips records containing missing numerical values.

### Dataset Setup

- Download the Individual Household Electric Power Consumption dataset from the UCI Machine Learning Repository.

- Extract the downloaded archive.

- Create a folder named dataset in the project root.

- Place household_power_consumption.txt inside that folder.

## ⚙️ Machine Learning Workflow

- **Dataset Loading**
  - `↓`
- **Data Preprocessing**
  - `↓`
- **Feature Selection**
  - `↓`
- **Train-Test Split (80:20)**
  - `↓`
- **Feature Standardization**
  - `↓`
- **Linear Regression**
  - `↓`
- **Gradient Descent**
  - `↓`
- **Model Training**
  - `↓`
- **Model Testing**
  - `↓`
- **Prediction**
  - `↓`
- **MAE Evaluation**
