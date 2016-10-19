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
	overwriteFile(edges);
	getInput(nodeA, nodeB);

	Node curNode(nodeA, 0);

	int  edgeIndexReached = 0;
	int  numOfEdgesFound = 0;

	do {
		for ( int curEdge = 0; curEdge < edges.size(); curEdge++)
		{
			if (edges[curEdge].getNodeA() == curNode.getNode())
			{

				matchEdge(curEdge, edges, nodes, curNode);
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


		for (int curEdge = edgeIndexReached; curEdge > 0; curEdge--)
		{
			if (edges[curEdge].getNodeB() == curNode.getNode())
			{
				matchEdge(curEdge, edges, nodes, curNode);
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

void matchEdge(int curEdge, vector<Edge> &edges, vector<Node> &nodes, Node curNode )
{
	int   existedNodeLocation = -1;

	for (unsigned int node = 0; node < nodes.size(); node++)  // binary search???
	{
		if (nodes[node].getNode() == edges[curEdge].getNodeB())
		{
			existedNodeLocation = node;
			break;
		}
	}
	double newNodeCost = curNode.getCost() + edges[curEdge].getCost();
	Node newNode(edges[curEdge].getNodeB(), newNodeCost, curNode.getPathHistory());
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

void getInput(string &nodeA, string &nodeB)
{
	cout << "Choose the starting node: ";
	cin >> nodeA;
	cout << "Choose the desination node: ";
	cin >> nodeB;
	cout << endl;
}

void overwriteFile(vector<Edge> &edges)
{
	ofstream file("test.txt");

	for (unsigned int curEdge = 0; curEdge < edges.size(); curEdge++)
	{
		file << edges[curEdge].getNodeA() << " " << edges[curEdge].getNodeB() << " " << edges[curEdge].getCost() << endl;
	}
	


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