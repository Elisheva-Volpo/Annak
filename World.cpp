#include "World.h"
using namespace std;
//World* World::instance = nullptr;
//mutex World::mtx;
//void World::fillTile(int i, int j,int category) {
//    for (int a = i; a < a + 5; a++) {
//        for(int b=j;b<j+5;b++){
//            board[a][b] = category;
//        }
//    }
//}
//
//World& World::getInstance(const vector<vector<int>>& b) {
//    lock_guard<mutex> guard(mtx);
//    if (!instance) {
//        instance = new World(b);
//    }
//    return *instance;
//}
//World::World(const vector<vector<int>>& b) {
//    for (int i = 0; i < b[0].size(); i++) {
//        for (int j = 0; j < b.size(); j++) {
//            fillTile(i * 5, j * 5,b[i][j]);
//        }
//    }
//}
//World::~World() {
//    cout << "World destroyed" << endl;
//}
//void World::printBoard() const {
//    for (const auto& row : board) {
//        for (int cell : row) {
//            cout << cell << " ";
//        }
//        cout << endl;
//    }
//}

int World::getType(int x, int y)
{
	if (board.size() <= x || x < 0 || board[x].size() <= y || y < 0) {
		cout << "This location doesn't exist ";
		return -1;
	}
	cout << board[x][y];
	return board[x][y];
}
