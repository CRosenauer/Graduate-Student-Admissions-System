#ifndef NODECLASS_HPP
#define NODECLASS_HPP

#include"DomesticStudent.hpp"
#include"internationalStudent.hpp"

class Node
{
private:
	studentPtr d;
	Node* link;
public:
	Node();
	Node(studentPtr& data, Node* link);
	studentPtr getData();
	Node* getLink()const;
	void setData(studentPtr d);
	void setLink(Node* link);
};

typedef Node* NodePtr;

#endif
