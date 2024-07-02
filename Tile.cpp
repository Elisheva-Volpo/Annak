#include "Tile.h"
#include "Game.h"

Tile::Tile(int type) : type(type)
{
	string typeName = Game::tiles[type];
	switch (type)
	{
	case 1:
		resources = { 10,0,0,0,0,0 };
		break;
	case 2:
		resources = { 0,10,0,0,0,0 };
		break;
	case 3:
		resources = { 0,0,100,0,0,0 };
		break;
	case 4:
		resources = { 0,0,0,100,0,0 };
		break;
	case 5:
		resources = { 0,0,0,0,10,0 };
		break;
	case 6:
		resources = { 0,0,0,0,0,5 };
	default:
		break;
	}
}
