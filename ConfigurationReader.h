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
        /*nlohmann::json_abi_v3_11_3::json  sizes= jsonObject["Sizes"];*/
        return jsonObject;
    }

    inline nlohmann::json_abi_v3_11_3::json getData(string s) {
        return jsonObject[s];
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

