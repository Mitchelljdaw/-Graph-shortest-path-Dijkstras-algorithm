#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "Graph.h"

using namespace std;

void displayFlights(Graph&);

int main() {
	Graph airportGrid;
	ifstream _readFile;
	string file;
	string airportAbbr = "";
	cout << "Enter in a file name: ";
	cin >> file;
	_readFile.open(file);
	if (_readFile.fail())
	{
		cout << "Failed to open file " << file << ". Terminating program." << endl;
		_readFile.close();
		system("pause");
		return 1;
	}
	airportGrid.readFile(_readFile);
	airportGrid.sort();
	airportGrid.buildGraph();
	displayFlights(airportGrid);
	do {
		cout <<endl<< "Please enter the airport from which you want to leave. All flights paths will be shown below(to quit type stop):";
		cin >> airportAbbr;
		if (airportAbbr != "stop")
		{
			airportGrid.shortestPath(airportAbbr);
			airportGrid.printPrice(airportAbbr);
		}
	} while (airportAbbr != "stop");
	_readFile.close();
	system("pause");
	return 0;
}

void displayFlights(Graph& flights)
{
	cout << "---------- Flights ---------" << endl;
	cout << "Source\tMileage\tCost\n------\t----\t-------\t----" << endl;
	flights.printAirports();
}