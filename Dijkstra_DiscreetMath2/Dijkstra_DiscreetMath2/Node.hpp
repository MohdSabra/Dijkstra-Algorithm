
#ifndef NODE_HPP
#define NODE_HPP

#include<vector>
#include<string>


class Node
{
public:
	Node::Node(std::string id, double cost);
	Node(std::string id, double cost,std::string pathHistory);
	std::string getNode();
	double getCost();
	std::string getPathHistory();
	bool Node::operator<(const Node &other) const;


private:
	std::string m_id;
	double m_cost;
	std::string m_pathHistory;

};









#endif