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

	parseDataFromFile(edges);
	sort(edges.begin(), edges.end()); // sort the edge vector
	overwriteFile(edges); 
	getInput(nodeA, nodeB); 

	Node curNode(nodeA, 0); // frist node

	// Repeat until the curNode = nodeB
	do {
		int  edgeIndexReached = 0; 
		for ( int curEdge = 0; curEdge < edges.size(); curEdge++)
		{
			if (edges[curEdge].getNodeA() == curNode.getNode())
			{

				matchEdge(curEdge, edges, nodes, curNode, edges[curEdge].getNodeB());
				edges.erase(edges.begin() + curEdge);
				curEdge--;
				

			}
			else if (edges[curEdge].getNodeA() > curNode.getNode())
			{
				break;
			}
			else
			{
				edgeIndexReached++; // we are still counting last 
			}


		}


		for (int curEdge = edgeIndexReached - 1; curEdge >= 0; curEdge--)
		{
			if (edges[curEdge ].getNodeB() == curNode.getNode())
			{
				matchEdge(curEdge, edges, nodes, curNode, edges[curEdge].getNodeA()); // get frist node id
				edges.erase(edges.begin() + curEdge);
				
			}
		}
		sort(nodes.begin(), nodes.end()); // sort after all the addition is done


		if (nodes.size() == 0)
		{
			cout << "Error";
		}
		else
		{
			curNode = nodes[0];
			nodes.erase(nodes.begin());


		}
	} while (curNode.getNode() != nodeB);

	cout << endl << curNode.getCost() << endl << curNode.getPathHistory();
	
	int ends;
	cin >> ends;

	return 1;
}


void printCurrNodes()
{

}

//get starting and desination nodes
// O(K)
void matchEdge(int curEdge, vector<Edge> &edges, vector<Node> &nodes, Node curNode, string nodeId ) // toDo lower number of parameters
{
	int   existedNodeLocation = -1;

	for (unsigned int node = 0; node < nodes.size(); node++)  // binary search???
	{
		if (nodes[node].getNode() == nodeId) // compare to node ID
		{
			existedNodeLocation = node;
			break;
		}
	}
	double newNodeCost = curNode.getCost() + edges[curEdge].getCost();
	Node newNode( nodeId, newNodeCost, curNode.getPathHistory());
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
// O(N)
void overwriteFile(vector<Edge> &edges)
{
	ofstream file("test.txt"); //TODO make file name static

	for (unsigned int curEdge = 0; curEdge < edges.size(); curEdge++)
	{
		file << edges[curEdge].getNodeA() << " " << edges[curEdge].getNodeB() << " " << edges[curEdge].getCost() << endl;
	}
	


}

// Extract all vectors from file and place them to the reference vector
// O(N)
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