#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Node
{
private:
	string dep;
	vector<string> arr;
	vector<int> mile;
	vector<int> price;
public:
	Node();
	Node(const string&, const string&, int, int);

	string getArr(int) const;
	void setArr(const string&);
	string getDep() const;
	void setDep(const string&);
	int getPrice(int) const;
	void setPrice(int);
	int getMile(int) const;
	void setMile(int);
	int numOfArrivals();
};
