

#include "Node.hpp";
#include<string>

Node::Node(std::string id, double cost, std::string pathHistory)
{
	m_pathHistory = pathHistory + " -> " + id;
	m_id = id;
	m_cost = cost;
}

Node::Node(std::string id, double cost)
{
	m_pathHistory = id;
	m_id = id;
	m_cost = cost;
}

std::string Node::getNode()
{
	return m_id;
}

double Node::getCost()
{
	return m_cost;
}

std::string Node::getPathHistory()
{
	return m_pathHistory;
}

bool Node::operator<(const Node &other) const
{
	return m_cost < other.m_cost;
}