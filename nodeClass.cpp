#ifndef NODECLASS_CPP
#define NODECLASS_CPP

#include "nodeClass.hpp"

Node::Node()
{
	this->d = NULL;
	this->link = NULL;
}
Node::Node(studentPtr& d, Node* link)
{
	this->setData(d);
	this->setLink(link);
}
studentPtr Node::getData()
{
	return this->d;
}
Node* Node::getLink()const
{
	return this->link;
}
void Node::setData(studentPtr d)
{
	this->d = d;
}
void Node::setLink(Node* link)
{
	this->link = link;
}

#endif