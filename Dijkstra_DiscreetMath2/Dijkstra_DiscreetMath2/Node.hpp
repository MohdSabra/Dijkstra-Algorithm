
#ifndef NODE_HPP
#define NODE_HPP

#include<vector>
#include<string>


class Node
{
public:
	Node(std::string id, double cost,std::string pathHistory);
	std::string getNode();
	double getCost();
	std::string pathHistory();

private:
	std::string m_id;
	double m_cost;
	std::string m_pathHistory;

};









#endif