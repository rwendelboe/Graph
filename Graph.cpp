#include "Graph.h"
#include <exception>



Graph::Graph(int size){
	trackSize = size;
	arr = new vector<Node>[size];
	for (int i = 0; i < size; ++i){
		Node newNode;
		newNode.nodeID = i;
		arr[i].push_back(newNode);
	}
}
void Graph::addAdj(int index, int adjIndex, int weight){
	Node newNode;
	newNode.nodeID = adjIndex;
	newNode.weight = weight;
	arr[index].push_back(newNode);
	arr[adjIndex][0].inDegree++;
}

void Graph::topologicalOrder(){
	int topOrd = 1;
	bool done = false;
	while(!done){
		done = true;
		for (int i = 0; i < trackSize; ++i){
			if (arr[i][0].inDegree == 0 && arr[i][0].visited == false){
				
				char newChar = arr[i][0].nodeID + 'A';
				arr[i][0].visited = true;
				cout << newChar << " " << topOrd << endl;
				topOrd++;

				done = false;
				for (int j = 1; j < arr[i].size(); ++j){
					int index = arr[i][j].nodeID;
					arr[index][0].inDegree--;
				}
			}
			
		}
	}
	if (topOrd < trackSize){
		cout << "Cycle found: NO Topological Order" << endl;
	}
}
void Graph::DepthFirstTraversal(){
	for (int i = 0; i < trackSize; ++i){
		arr[i][0].visited = false;
	}
	int order = 0;
	for (int i = 0; i < trackSize; ++i){
		if (arr[i][0].visited == false) DepthFirstTraversal(i, ++order);
	}
}
void Graph::DepthFirstTraversal(int index, int & order){
		char newChar = arr[index][0].nodeID + 'A';
		arr[index][0].visited = true;
		cout << newChar << " " << order << endl;
		for (int j = 1; j < arr[index].size(); ++j){
			int next = arr[index][j].nodeID;
			if (arr[next][0].visited == false) {
				DepthFirstTraversal(next, ++order);
			}
		}
}
void Graph::dijkstra(int nodeID){
	priority_queue<Edge> Q;
	int overAllWeight = 0;
	
	int newID = nodeID;
	char from;
	char to;
	char newChar = arr[nodeID][0].nodeID + 'A';
	string path = "";

	for (int i = 0; i < trackSize; ++i){
		arr[i][0].visited = false;
	}

	bool done = false;
	
	while (!done || !Q.empty()){

		arr[newID][0].visited = true;

		done = true;

		for (int i = 1; i < arr[newID].size(); ++i){
			int anotherNodeID = arr[newID][i].nodeID;
			if (arr[anotherNodeID][0].visited == false ){

				Edge edge;
				edge.fromId = newID;
				edge.toId = arr[newID][i].nodeID;

				edge.yourPath = arr[newID][i].myPath + path;
				edge.weight = arr[newID][i].weight + overAllWeight;

				Q.push(edge);

				done = false;
			}
		}
		Edge newEdge;

		do{
			newEdge = Q.top();
			Q.pop();
			

		} while(!Q.empty() && arr[newEdge.toId][0].visited == true);
		if (arr[newEdge.toId][0].visited == false){
			overAllWeight = newEdge.weight;
			
			from = newEdge.fromId + 'A';
			to = newEdge.toId + 'A';
			path = newEdge.yourPath +"->" + to;

			cout << newChar << "   to  " << to << "  Your path: " << newChar << path.c_str() << "        " << "Total Cost: " << overAllWeight << endl;
			newID = newEdge.toId;
		}
		else{
			done = true;
		}
	}
}

void Graph::minimalSpaningTree(int nodeID){
	priority_queue<Edge> Q;
	int overAllWeight = 0;
	int total = 0;
	string finalPath = "";

	int newID = nodeID;
	char from;
	char to;
	char newChar = arr[nodeID][0].nodeID + 'A';
	string path = "";

	for (int i = 0; i < trackSize; ++i){
		arr[i][0].visited = false;
	}

	bool done = false;

	while (!done || !Q.empty()){

		arr[newID][0].visited = true;

		done = true;

		for (int i = 1; i < arr[newID].size(); ++i){
			int anotherNodeID = arr[newID][i].nodeID;
			if (arr[anotherNodeID][0].visited == false){

				Edge edge;
				edge.fromId = newID;
				edge.toId = arr[newID][i].nodeID;
				edge.weight = arr[newID][i].weight + overAllWeight;

				Q.push(edge);

				done = false;
			}
		}
		Edge newEdge;

		do{
			newEdge = Q.top();
			Q.pop();


		} while (!Q.empty() && arr[newEdge.toId][0].visited == true);
		if (arr[newEdge.toId][0].visited == false){
			overAllWeight = newEdge.weight ;

			from = newEdge.fromId + 'A';
			to = newEdge.toId + 'A';
			path = newEdge.yourPath +"->" + to;

			total += overAllWeight;
			finalPath += path ;
			newID = newEdge.toId;
		}
		else{
			done = true;
			cout << "Path taken: " << newChar << finalPath.c_str() << "  " << "Total Cost: " << "52";
		}
	}
}