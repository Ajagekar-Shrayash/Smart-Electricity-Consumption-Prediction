#ifndef DATA_LOADER_H
#define DATA_LOADER_H
#include <string>

#include <vector>
using namespace std;

struct Dataset
{
    vector<double> activePower;
    vector<double> reactivePower;
    vector<double> voltage;
    vector<double> intensity;
    vector<double> subMetering1;
    vector<double> subMetering2;
    vector<double> subMetering3;
};

Dataset loadDataset(const string& filename, int limit);

#endif