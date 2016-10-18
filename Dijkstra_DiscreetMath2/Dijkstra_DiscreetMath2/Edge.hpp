/*

*/

#ifndef EDGE_HPP
#define EDGE_HPP

#include<string>

class Edge
{
public:
	Edge(std::string nodeA, std::string nodeB, double cost);
	bool Edge::operator<(const Edge &other) const;

	std::string getNodeA();
	std::string getNodeB();
	double getCost();

private: 
	std::string m_nodeA, m_nodeB;
	double m_cost;
	

};





#endif