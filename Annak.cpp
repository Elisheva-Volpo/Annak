#include <iostream>
#include "World.h"
#include "Input.h"
using namespace std;

vector<vector<int>> readGraphEdgesFromStdin();


int main() {

    //Input i;
    vector<vector<int>> v = { {1} };
    //i.parse_and_store();//readGraphEdgesFromStdin();
    World* w= &World::getInstance(v/**(i.world)*/);
    int x, y;
    cin >> x >> y;
    w->getType(x,y);

    return 0;
}

vector<vector<int>> readGraphEdgesFromStdin() {
    string input;
    cout << "Enter edges in the format [[0,1], [0,2], [3,5], [5,4], [4,3]]: ";
    getline(cin, input);

    // Remove all spaces from the input
    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());

    vector<vector<int>> edges;
    stringstream ss(input);
    char ch;

    // Check if input starts and ends with square brackets
    if (input.front() != '[' || input.back() != ']') {
        cerr << "Invalid format! Input should start with '[' and end with ']'." << endl;
        return edges;
    }

    // Remove the outer square brackets
    ss.ignore(1); // Ignore the first '['

    while (ss >> ch) {
        if (ch == '[') {
            int src, dest;
            char comma;
            ss >> src >> comma >> dest >> ch; // Read src, comma, dest, and closing ']'
            if (ch == ']') {
                edges.push_back({ src, dest });
            }
            else {
                cerr << "Invalid format! Each edge should be enclosed in square brackets." << endl;
                return edges;
            }
        }
        if (ss.peek() == ',') {
            ss.ignore(); // Ignore the comma between edge definitions
        }
    }

    return edges;
}

