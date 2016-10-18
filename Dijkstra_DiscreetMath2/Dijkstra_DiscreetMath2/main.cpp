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

int main()
{
	vector<Edge> edges;
	vector<Node> nodes;
	string nodeA, nodeB;

	parseDataFromFile(edges); // extract all the edges from the text file
	sort(edges.begin(), edges.end()); // sort the edges based on the first node ( nodeA) string name
	getInput(nodeA, nodeB);


	double prevCost = 0;
	int   existedNodeLocation = -1; 

	for (int curEdge = 0; curEdge < edges.size(); curEdge++)
	{
		if (edges[curEdge].getNodeA() == nodeA)
		{
			for (int curNode = 0; curNode < nodes.size(); curNode++)
			{
				if (nodes[curNode].getNode() == edges[curEdge].getNodeB())
				{
					existedNodeLocation = curNode;
					break;
				}
			}
			int newNodeCost = prevCost + edges[curEdge].getCost(); // prevCost????
			Node newNode(edges[curEdge].getNodeB(), newNodeCost, "hist" );
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
		else if () /// do the back glip
	}

	return 1;
}

void getInput(string &nodeA, string &nodeB)
{
	cout << "Choose the starting node: ";
	cin >> nodeA;
	cout << "Choose the desination node: ";
	cin >> nodeB;
	cout << endl;
}

void parseDataFromFile(vector<Edge> &edges)
{
	string fileName = "test.txt";
	ifstream file;

	string nodeA, nodeB;
	double cost;

	file.open(fileName.c_str());

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