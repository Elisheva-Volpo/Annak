#pragma once
#include<iostream>
#include <vector>
#include "ConfigurationReader.h"
using namespace std;
class Game
{
public:
	static ConfigurationReader reader;
	static vector<string> tiles;

	static void initTiles() {
		nlohmann::json_abi_v3_11_3::json t = reader.getData("Tiles");
		for (auto& element : t.items()) {
			string key = element.key();
			int index = element.value().get<int>();
			tiles[index] = key;
		}
	}
};



