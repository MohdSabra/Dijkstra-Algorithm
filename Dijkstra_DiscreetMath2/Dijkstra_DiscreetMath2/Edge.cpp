/*

*/

#include "Edge.hpp"
#include<string>


Edge::Edge(std::string nodeA, std::string nodeB, double cost)
{
	if (nodeA < nodeB)
	{
		m_nodeA = nodeA;
		m_nodeB = nodeB;
	}
	else
	{
		m_nodeB = nodeA;
		m_nodeA = nodeB;
	}


	m_cost = cost;
}

bool Edge::operator<(const Edge &other) const
{
	return m_nodeA < other.m_nodeA;;
}




std::string Edge::getNodeA()
{
	return m_nodeA;
}

std::string Edge::getNodeB()
{
	return m_nodeB;
}

double Edge::getCost()
{
	return m_cost;
}


















