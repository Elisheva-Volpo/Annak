#include "ConfigurationReader.h"
#include <iostream>
#include <fstream>
using namespace std;

ConfigurationReader::ConfigurationReader()
{
    // Open the JSON file
    ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        cerr << "Could not open the file!" << endl;
    }

    // Parse the JSON file
    inputFile >> jsonObject;

    // Close the file
    inputFile.close();
}

void ConfigurationReader::printAll()
{
    cout << jsonObject.dump(4) << endl;
}
