#include "stdafx.h"
#include "Node.h"

Node::Node()
{
	dep = "";
}

Node::Node(const string& _depart, const string& _arrival, int _mileage, int _cost)
{
	dep = _depart;
	mile.push_back(_mileage);
	arr.push_back(_arrival);
	price.push_back(_cost);
}

string Node::getDep() const
{
	return dep;
}

void Node::setDep(const string& _depart)
{
	dep = _depart;
}

string Node::getArr(int i) const
{
	return arr.at(i);
}

void Node::setArr(const string& _arrival)
{
	arr.push_back(_arrival);
}

int Node::getMile(int i) const
{
	return mile.at(i);
}

void Node::setMile(int _mileage)
{
	mile.push_back(_mileage);
}

int Node::getPrice(int i) const
{
	return price.at(i);
}

void Node::setPrice(int _cost)
{
	price.push_back(_cost);
}

int Node::numOfArrivals()
{
	return arr.size();
}
