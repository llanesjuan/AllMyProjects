#include "Node.h"



Node::Node(string str)
{
	this->name = str;
	this->nodeList = NULL;
}

Node::Node(string str, list<Node>* nodeList)
{
	this->name = str;
	this->nodeList = nodeList;
}

Node::Node()
{
	this->name = "";
	this->nodeList = NULL;
}


Node::~Node()
{
}
