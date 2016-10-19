
#ifndef MAIN_HPP
#define MAIN_HPP

#include<vector>
#include"Edge.hpp"
#include"Node.hpp"

void parseDataFromFile (std::vector<Edge> &edges);

void getInput(std::string &nodeA, std::string &nodeB);

void matchEdge(int curEdge, std::vector<Edge> &edges, std::vector<Node> &nodes, Node curNode, std::string nodeId);

void overwriteFile(std::vector<Edge> &edges);



#endif