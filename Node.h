#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

struct Node
{
	string myPath = "";
	int nodeID = -1;
	int weight = 0;
	bool visited = false;
	int inDegree = 0;
	int predID = -1;
};
struct Edge
{
	int weight = 0;
	int fromId = -1;
	int toId = -1;
	string yourPath = "";
	bool operator == (Edge rhs) const { return weight == rhs.weight; }
	bool operator < (Edge rhs)const { return weight > rhs.weight; }
	bool operator > (Edge rhs) const { return weight < rhs.weight; }
	bool operator <= (Edge rhs) const { return weight >= rhs.weight; }
	bool operator >= (Edge rhs) const{ return weight <= rhs.weight; }
	bool operator != (Edge rhs) const { return weight != rhs.weight; }
};
#endif