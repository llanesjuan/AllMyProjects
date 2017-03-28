#pragma once
#include<string>
#include<list>
#include"Node.h"
#include<stack>
#include"Employee.h"
#include"Manager.h"
#include"RelationshipParser.h"
using namespace std;

class RelationshipNode
{
public:
	void RelationshipNode::createManagerStack(Node , string , stack<Node>& , bool &);
	Node RelationshipNode::findRoot(list<Node>* );
	Node RelationshipNode::findCommonEmployeeManager(stack<Node>, stack<Node>);
	RelationshipNode();
	~RelationshipNode();
};

