#pragma once
#include <vector>

using namespace std;

class Tile
{
	int type;
	vector<int> resources;

public:
	inline int getType() {
		return this->type;
	}
	inline vector<int>& getResources() {
		return this->resources;
	}
	Tile(int type);
};

