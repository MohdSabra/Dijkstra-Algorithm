
#ifndef MAIN_HPP
#define MAIN_HPP

#include<vector>
#include"Edge.hpp"
#include"Node.hpp"

void parseDataFromFile (std::vector<Edge> &edges);

void getInput(std::string &nodeA, std::string &nodeB);

void matchEdge(double curEdgeCost, std::vector<Node> &nodes, Node curNode, std::string nodeId);


void overwriteFile(std::vector<Edge> &edges);

int leastCostNode(std::vector<Node> &nodes);



#endif