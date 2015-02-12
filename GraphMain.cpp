#include "Graph.h"
#include <iostream>
#include <fstream>
using namespace std;

int changeLetterstoNum(char toconvert){
	int newVal;
	newVal = toconvert - 'A';
	return newVal;
}

int main(){
	ifstream file;

	int numOfNodes;
	int numOfEdges;
	char vertex;
	char adjVertex;
	int weight;

	//file.open("prog7.txt");

	////uncomment to test second file.
	file.open("prog7b.txt");

	file >> numOfNodes;
	file >> numOfEdges;
	Graph graph(numOfNodes);
	Graph undirectedGraph(numOfNodes);
	for (int i = 0; i < numOfEdges; ++i){
		file >> vertex;
		file >> adjVertex;
		file >> weight;
		graph.addAdj(changeLetterstoNum(vertex), changeLetterstoNum(adjVertex), weight);
		undirectedGraph.addAdj(changeLetterstoNum(vertex), changeLetterstoNum(adjVertex), weight);
		undirectedGraph.addAdj(changeLetterstoNum(adjVertex), changeLetterstoNum(vertex), weight);
	}
	
	cout << "Prog 7b" << endl;
	cout << endl;
	cout << "Topological Order" << endl;
	graph.topologicalOrder();
	cout << endl;
	cout << "Depth First Traversal" << endl;
	graph.DepthFirstTraversal();
	cout << endl;
	cout << "Shortest path Dijkstra’s algorithm" << endl;
	cout << endl;
	undirectedGraph.dijkstra(13);
	cout << endl;
	cout << "Minimal spanning tree Prim's Algorithm" << endl;
	cout << endl;
	undirectedGraph.minimalSpaningTree(13);

	file.close();
	cin.get();
	return 0;
}
