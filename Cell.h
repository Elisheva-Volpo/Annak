#pragma once
#include "Tile.h"
class Cell
{

	Tile* tile;

public:
	Cell(Tile* tilePtr);
	inline Tile* getTile() {
		return this->tile;
	}
};

