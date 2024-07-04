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
	inline void setResources(int amount, string resource) {
		vector<string> resourceTypes = Game::reader.getData("ResourceTypes");
		int i = 0;
		for (; i < resourceTypes.size(); i++) {
			if (resourceTypes[i] == resource) {
				break;
			}
		}
		resources[i] += amount;

	}

	Tile(int type);
};

