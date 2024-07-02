#include <iostream>
//#include "World.h"
//#include "Input.h"
#include <string>
#include "Game.h"
using namespace std;

vector<vector<int>> readGraphEdgesFromStdin();



int main() {
    Game::initTiles();
    Game g;
    string s = "Sizes";
    cout<<g.reader.getData(s).dump(4);
    //Input i;
    //i.parse_and_store();
    //World& world = World::getInstance(convertToIntVector(i.world->data));
    //// world.printBoard();
    //int select1 = stoi(i.steps[0]->arguments[0]);
    //int select2 = stoi(i.steps[0]->arguments[1]);
    //string resource = world.getType(select2 - 1, select1 - 1);
    //cout << "SelectedCategory " << resource << endl;
    return 0;
}

//vector<vector<int>> readGraphEdgesFromStdin() {
//    string input;
//    cout << "Enter edges in the format [[0,1], [0,2], [3,5], [5,4], [4,3]]: ";
//    getline(cin, input);
//
//    // Remove all spaces from the input
//    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());
//
//    vector<vector<int>> edges;
//    stringstream ss(input);
//    char ch;
//
//    // Check if input starts and ends with square brackets
//    if (input.front() != '[' || input.back() != ']') {
//        cerr << "Invalid format! Input should start with '[' and end with ']'." << endl;
//        return edges;
//    }
//
//    // Remove the outer square brackets
//    ss.ignore(1); // Ignore the first '['
//
//    while (ss >> ch) {
//        if (ch == '[') {
//            int src, dest;
//            char comma;
//            ss >> src >> comma >> dest >> ch; // Read src, comma, dest, and closing ']'
//            if (ch == ']') {
//                edges.push_back({ src, dest });
//            }
//            else {
//                cerr << "Invalid format! Each edge should be enclosed in square brackets." << endl;
//                return edges;
//            }
//        }
//        if (ss.peek() == ',') {
//            ss.ignore(); // Ignore the comma between edge definitions
//        }
//    }
//
//    return edges;
//}

