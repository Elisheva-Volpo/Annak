#include "World.h"
#include "Game.h"
using namespace std;

World::World(vector<vector<int>>& initialBoard)
{
    initTilesBoard(initialBoard);
    initCellsBoard(initialBoard);
    //printBoard();
}

void World::printBoard() const
{
    /*for (const auto& row : cellBoard) {
        for (Cell cell : row) {
            cout <<  << " ";
        }
        cout << endl;
    }*/
}

int World::getType(int x, int y)
{
	if (cellsBoard.size() <= x || x < 0 || cellsBoard[x].size() <= y || y < 0) {
		cout << "This location doesn't exist ";
		return -1;
	}
	cout << cellsBoard[x][y].getTile()->getType();
	return  cellsBoard[x][y].getTile()->getType();
}

vector<int>& World::getResourcesByCell(int x, int y)
{
    if (cellsBoard.size() <= x || x < 0 || cellsBoard[x].size() <= y || y < 0) {
        throw "This location doesn't exist ";
    }
    return cellsBoard[x][y].getTile()->getResources();
}



void World::initTilesBoard(vector<vector<int>>& initialBoard)
{
    int rows = initialBoard.size();
    int cols = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < initialBoard[i].size(); ++j) {
            tilesBoard[i][j] = Tile(initialBoard[i][j]);
        }
    }
}

void World::initCellsBoard(vector<vector<int>>& initialBoard)
{

    sizeOfTile = Game::reader.getData("Sizes")["Tile"];
    int rows = initialBoard.size();
    int cols = 0;
    for (const auto& row : initialBoard) {
        if (row.size() > cols) {
            cols = row.size();
        }
    }

    cellsBoard.resize(rows * sizeOfTile[0], vector<Cell>(cols * sizeOfTile[1], NULL));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < initialBoard[i].size(); ++j) {
            for (int k = 0; k < 5; ++k) {
                for (int l = 0; l < 5; ++l) {
                    cellsBoard[i * 5 + k][j * 5 + l] = Cell(&tilesBoard[i][j]);
                }
            }
        }
    }


}


void World::addResources(int amount, string resource, int x, int y)
{   
    cellsBoard[x - 1][y - 1].getTile()->setResources(amount,resource);

}
