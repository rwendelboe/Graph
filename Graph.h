#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include "Node.h"
#include <queue>
#include <exception>

using namespace std;

class Graph
{
private:
	vector<Node>* arr;
	int trackSize;
public:
	
	Graph(int size); 

	void addAdj(int index, int adjIndex, int weight);
	string toString(string label, ostream & fout);
	void topologicalOrder();
	void DepthFirstTraversal(int index, int & order);
	void DepthFirstTraversal();
	void minimalSpaningTree(int nodeID);
	void dijkstra(int nodeID);

};
#endif