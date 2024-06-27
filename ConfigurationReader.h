#pragma once
#include <fstream>
#include <string>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

class ConfigurationReader
{
    const string fileName= "Configurations.json";
    json jsonObject;

public:

    ConfigurationReader();
    void printAll();
    inline json getJsonObject() {
        return jsonObject;
    }

    //// Example of accessing specific values
    //auto size = jsonObject["Sizes"]["Tile"];
    ////auto age = jsonObject["age"];
    ////auto city = jsonObject["city"];
    ////auto skills = jsonObject["skills"];

    ////cout << "Name: " << name << endl;
    //cout << "size" << size << endl;
    ////cout << "City: " << city << endl;
    ////cout << "Skills: ";
    ////for (const auto& skill : skills) {
    ////    cout << skill << " ";
    ////}
    //cout << endl;

};

