#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stack>
#include "Node.h"

const int BIG_NUMBER = 999;

using namespace std;

class Graph
{
private:
	vector<Node*> airport;
	Node* start;
	vector<vector<int>> gCost;
	vector<vector<int>> gMiles;
	vector<int> cost;
	vector<int> path;
	string** adjFlight;
public:
	Graph();
	void insert(const string&, const string&, int, int);
	void buildGraph();
	bool isNode(const string&, const string&, int, int);
	void sort();
	void printAirports();
	void shortestPath(const string&);
	void printPrice(const string&);
	void readFile(ifstream&);
};