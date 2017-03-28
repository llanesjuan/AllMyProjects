#pragma once
#include<list>
#include<string>
#include"Node.h"
#include"Manager.h"
#include"Employee.h"
using namespace std;

class RelationshipParser
{
public:
	list<Node>*RelationshipParser::nodeListMaker(list<string>, list<list<string>>);
	list<Node>* RelationshipParser::nodeTreeLinker(list<Node>*);
	RelationshipParser();
	~RelationshipParser();
};

