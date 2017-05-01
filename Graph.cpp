#include "stdafx.h"
#include "Graph.h"

Graph::Graph()
{
	start = nullptr;
}

void Graph::insert(const string& depart, const string& arrival, int mileage, int cost)
{
	if (isNode(depart, arrival, mileage, cost) == true)
	{
		Node* p = new Node(depart, arrival, mileage, cost);
		airport.push_back(p);
	}
}

void Graph::buildGraph()
{
	for (int i = 0; i < airport.size(); i++)
	{
		vector<int> newData;
		path.push_back(BIG_NUMBER);
		cost.push_back(BIG_NUMBER);
		for (int j = 0; j < airport.size(); j++)
		{
			newData.push_back(BIG_NUMBER);
		}
		gCost.push_back(newData);
		gMiles.push_back(newData);
	}
	for (int i = 0; i < airport.size(); i++)
	{
		for (int j = 0; j < airport.size(); j++)
		{
			for (int k = 0; k < airport[i]->numOfArrivals(); k++)
			{
				if (airport[i]->getArr(k) == airport[j]->getDep())
				{
					gCost[i][j] = airport[i]->getPrice(k);
					gMiles[i][j] = airport[i]->getMile(k);
				}
			}
		}
	}
}

bool Graph::isNode(const string& dep, const string& arr, int mile, int price)
{
	for (int i = 0; i < airport.size(); i++)
	{
		if (airport[i]->getDep() == dep)
		{
			airport[i]->setArr(arr);
			airport[i]->setMile(mile);
			airport[i]->setPrice(price);
			return false;
		}
	}
	return true;
}

void Graph::sort()
{
	for (int i = 0; i < airport.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (airport[i]->getDep() < airport[j]->getDep())
			{
				Node* temp = airport[i];
				airport[i] = airport[j];
				airport[j] = temp;
			}
		}
	}
}

void Graph::printAirports()
{
	for (int i = 0; i < airport.size(); i++)
	{
		for (int j = 0; j < airport.at(i)->numOfArrivals(); j++)
		{
			cout << airport.at(i)->getDep() << "\t" << airport.at(i)->getArr(j) << "\t" << airport.at(i)->getMile(j) << "\t$" << airport.at(i)->getPrice(j) << endl;
		}
	}
}

void Graph::shortestPath(const string& start)
{
	int value = 0;
	while (airport.at(value)->getDep() != start && value < airport.size())
	{
		value++;
	}
	if (value == airport.size())
	{
		cout << "Invalid Airport!" << endl;
	}
	else
	{
		int price = 0;
		int index = value;

		for (int i = 0; i < airport.size(); i++)
		{
			for (int j = 0; j < airport.size(); j++)
			{
				if (price + gCost[index][j] < cost[j])
				{
					path[j] = index;
					cost[j] = price + gCost[index][j];
				}
			}
			int lastPrice = price;
			price = BIG_NUMBER;
			for (int j = 0; j < airport.size(); j++)
			{
				if (lastPrice < cost[j])
				{
					if (cost[j] < price)
					{
						price = cost[j];
						index = j;
					}
				}
			}
			path[value] = BIG_NUMBER;
			cost[value] = BIG_NUMBER;
		}
	}
}

void Graph::printPrice(const string& start)
{
	stack<int> locateNode;
	int value = 0;
	int size = airport.size();
	while (airport.at(value)->getDep() != start)
	{
		value++;
	}
	if (value == airport.size())
	{
		cout << "Invalid Airport!" << endl;
	}
	else
	{
		cout << "Best Price Report" << endl;

		for (int i = 0; i < size; i++)
		{
			if (cost[i] < BIG_NUMBER)
			{
				cout << "\n--------------------------------------" << endl;
				int destination = i;
				int from = path[destination];
				int bestMileage = 0;
				locateNode.push(destination);
				while (path[destination] < BIG_NUMBER)
				{
					if (from != BIG_NUMBER)
						locateNode.push(destination);
					destination = from;
					from = path[destination];
					if (from == BIG_NUMBER)
						from = 0;
				}
				while (!locateNode.empty())
				{
					destination = locateNode.top();
					locateNode.pop();
					if (!locateNode.empty())
					{
						cout << airport[from]->getDep() << "->" << airport[destination]->getDep() << " \t$" << gCost[from][destination] << "\t" << gMiles[from][destination] << endl;
						bestMileage += gMiles[from][destination];
						from = destination;
					}
				}
				cout << "\nTrip " << airport[value]->getDep() << "->" << airport[i]->getDep() << "\t$" << cost[i] << "\t" << bestMileage << endl;
			}
		}
	}
}

void Graph::readFile(ifstream& input)
{
	string depart;
	string arrival;
	int mileage;
	int cost;
	while (!input.eof())
	{
		input >> depart;
		input.ignore();
		input >> arrival;
		input.ignore();
		input >> mileage;
		input.ignore();
		input >> cost;
		input.ignore();
		insert(depart, arrival, mileage, cost);
	}
}