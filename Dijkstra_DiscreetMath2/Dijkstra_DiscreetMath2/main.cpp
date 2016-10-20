/*
Mohd Sabra
dijkstra 


*/

#include<iostream>
#include<string>
#include<fstream>
#include <vector>
#include"Main.hpp"
#include<algorithm>
#include"Node.hpp"

using namespace std;

string FILE_NAME = "test.txt";

int main() // O( E * N )
{
	vector<Edge> edges;
	vector<Node> nodes;
	string nodeA, nodeB;

	parseDataFromFile(edges);
	sort(edges.begin(), edges.end()); // sort the edge vector
	overwriteFile(edges); 
	getInput(nodeA, nodeB); 

	Node curNode(nodeA, 0); // frist node

	// Repeat until the curNode = nodeB
	do {
		int  edgeIndexReached = 0; 
		for ( int curEdge = 0; curEdge < edges.size(); curEdge++) // O(E)  
		{
			if (edges[curEdge].getNodeA() == curNode.getNode())
			{
				matchEdge(edges[curEdge].getCost(), nodes, curNode, edges[curEdge].getNodeB()); // O(N)
				edges.erase(edges.begin() + curEdge);
				curEdge--;
			}
			else if (edges[curEdge].getNodeB() == curNode.getNode()) 
			{
				matchEdge(edges[curEdge].getCost(), nodes, curNode, edges[curEdge].getNodeA()); //O(N)
				edges.erase(edges.begin() + curEdge);
				curEdge--;
			}
		}

		if (nodes.size() == 0)
		{
			cout << "Error";
		}
		else
		{
			int curNodeIndex = leastCostNode(nodes);  // O(N)
			curNode = nodes[curNodeIndex];
			nodes.erase(nodes.begin() + curNodeIndex);

		}
	} while (curNode.getNode() != nodeB);

	cout << endl << curNode.getCost() << endl << curNode.getPathHistory();
	
	int ends;
	cin >> ends;

	return 1;
}

//find the index of the least costly node jump
// O(N)
int leastCostNode(vector<Node> &nodes)
{	
	int least = 0;
	for (int curNode = 0; curNode < nodes.size() ; curNode++)
	{
		if (nodes[least].getCost() > nodes[curNode].getCost())
		{
			least = curNode;
		}
	}

	return least;
}


//get starting and desination nodes
// O(N)
void matchEdge(double curEdgeCost, vector<Node> &nodes, Node curNode, string nodeId ) // toDo lower number of parameters
{
	int existedNodeLocation = -1; // check if the node already exists
	for (unsigned int node = 0; node < nodes.size(); node++)  // loop through all the nodes to check if it exists --- O(N)
	{
		if (nodes[node].getNode() == nodeId) 
		{
			existedNodeLocation = node;  // if found then extract the index and break out of loop
			break;
		}
	}
	double newNodeCost = curNode.getCost() + curEdgeCost;
	Node newNode( nodeId, newNodeCost, curNode.getPathHistory());  // create a newnode using the dataabove
	if (existedNodeLocation > -1)
	{
		if (nodes[existedNodeLocation].getCost() > newNodeCost)
		{
			nodes[existedNodeLocation] = newNode;
		}
	}
	else
	{
		nodes.push_back(newNode);
	}

}

//get starting and desination nodes
// O(1)
void getInput(string &nodeA, string &nodeB)
{
	cout << "Choose the starting node: ";
	cin >> nodeA;
	cout << "Choose the desination node: ";
	cin >> nodeB;
	cout << endl;
}

// read the entire edge vector and overright the file
// O(E)
void overwriteFile(vector<Edge> &edges)
{
	ofstream file(FILE_NAME);
	for (unsigned int curEdge = 0; curEdge < edges.size(); curEdge++)
	{
		file << edges[curEdge].getNodeA() << " " << edges[curEdge].getNodeB() << " " << edges[curEdge].getCost() << endl;
	}
}

// Extract all vectors from file and place them to the reference vector
// O(E)
void parseDataFromFile(vector<Edge> &edges)
{
	ifstream file;

	string nodeA, nodeB;
	double cost;

	file.open(FILE_NAME.c_str());

	if (file.is_open())
	{
		while (file >> nodeA )
		{
			file >> nodeB;
			file >> cost;
			if (nodeA == nodeB) {} // i dont want the disntace of a node to itself
			else
			{
				Edge newEdge(nodeA, nodeB, cost);
				edges.push_back(newEdge);
			}

		}
		file.close();
	}
	else
	{
		std::cout << " failed to open file";
	}

}