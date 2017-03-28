#pragma once
#include<list>
#include<string>
using namespace std;

class Node
{
public:
	string name;
	list<Node>* nodeList;
	Node(string);
	Node(string, list<Node>*);
	Node();
	~Node();
};

