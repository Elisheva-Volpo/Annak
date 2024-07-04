#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>
#include <string>
#include <sstream>
#include "ConfigurationReader.h"
#include "Cell.h"
using namespace std;
using json = nlohmann::json;

class World {
public:
    static World& getInstance(vector<vector<int>>& initialBoard) {
        static World instance(initialBoard);
        return instance;
    }

    World(const World&) = delete;
    World& operator=(const World&) = delete;

    void printBoard() const;

    int getType(int x,int y);
    vector<int>& getResourcesByCell(int x, int y);
    void addResources(int amount, string resource, int x, int y);
    

private:

    vector<vector<Cell>> cellsBoard;
    vector<vector<Tile>> tilesBoard;
    nlohmann::json_abi_v3_11_3::json sizeOfTile;
    World(vector<vector<int>>& initialBoard);
    void initTilesBoard(vector<vector<int>>& initialBoard);
    void initCellsBoard(vector<vector<int>>& initialBoard);
};
