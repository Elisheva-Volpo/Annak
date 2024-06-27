#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>
#include <string>
#include <sstream>
#include "ConfigurationReader.h"
using namespace std;
using json = nlohmann::json;

class World {
public:
    static World& getInstance(const vector<vector<int>>& initialBoard) {
        static World instance(initialBoard);
        return instance;
    }

    World(const World&) = delete;
    World& operator=(const World&) = delete;

    void printBoard() const {
        for (const auto& row : board) {
            for (int cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
    }

    int getType(int x,int y);

private:
    vector<vector<int>> board;
    nlohmann::json_abi_v3_11_3::json sizeOfTile;
    World(const vector<vector<int>>& initialBoard) {
        createBoard(initialBoard);
        printBoard();
    }

    void createBoard(const vector<vector<int>>& initialBoard) {
        ConfigurationReader cr;
        sizeOfTile = cr.getJsonObject()["Sizes"]["Tile"];
        int rows = initialBoard.size();
        int cols = 0;
        for (const auto& row : initialBoard) {
            if (row.size() > cols) {
                cols = row.size();
            }
        }

        board.resize(rows * sizeOfTile[0], vector<int>(cols * sizeOfTile[1], -1));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < initialBoard[i].size(); ++j) {
                for (int k = 0; k < 5; ++k) {
                    for (int l = 0; l < 5; ++l) {
                        board[i * 5 + k][j * 5 + l] = initialBoard[i][j];
                    }
                }
            }
        }
    }
};
