#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "../include/data_loader.h"

using namespace std;

Dataset loadDataset(const string& filename, int limit)
{
    Dataset data;

    ifstream file(filename);

    if (!file)
    {
        cout << "Error opening dataset!" << endl;
        return data;
    }

    string line;
    getline(file, line); // Skip header

    int count = 0;

    while (getline(file, line) && count < limit)
    {
        stringstream ss(line);
        string field;
        vector<string> columns;

        while (getline(ss, field, ';'))
        {
            columns.push_back(field);
        }

        if (columns.size() != 9)
            continue;

        bool missing = false;

        for (int i = 2; i < 9; i++)
        {
            if (columns[i] == "?")
            {
                missing = true;
                break;
            }
        }

        if (missing)
            continue;

        data.activePower.push_back(stod(columns[2]));
        data.reactivePower.push_back(stod(columns[3]));
        data.voltage.push_back(stod(columns[4]));
        data.intensity.push_back(stod(columns[5]));

        data.subMetering1.push_back(stod(columns[6]));
        data.subMetering2.push_back(stod(columns[7]));
        data.subMetering3.push_back(stod(columns[8]));

        count++;
    }

    file.close();

    cout << "Dataset loaded successfully!" << endl;
    cout << "Valid records: " << count << endl;

    return data;
}