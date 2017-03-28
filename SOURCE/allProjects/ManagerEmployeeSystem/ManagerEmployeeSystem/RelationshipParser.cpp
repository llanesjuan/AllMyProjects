#include "RelationshipParser.h"

list<Node>* RelationshipParser::nodeListMaker(list<string> managerList, list<list<string>>employeeList)
{	
	Node manager;
	list<Node>*listNodeList;
	Node employee;	
	list<Node>*listNode;
	list<list<string>>::iterator itrParent;
	list<string>::iterator itrChild;
	listNodeList = new list<Node>;
	for (itrParent = employeeList.begin(); itrParent != employeeList.end(); itrParent++) {
		listNode = new list<Node>;
		for (itrChild = (*itrParent).begin(); itrChild != (*itrParent).end(); itrChild++) {		
			employee = Node(*itrChild);
			listNode->push_back(employee);
		}
		manager = Node(managerList.front(),listNode);
		managerList.pop_front();
		listNodeList->push_back(manager);		
	}
	return listNodeList;
}
list<Node>* RelationshipParser::nodeTreeLinker(list<Node>* nodeList)
{
	list<Node>::iterator itrParent;
	list<Node>::iterator itrNewParent;
	list<Node>::iterator itrChild;
	list<Node>* myNodeList = nodeList;
	list<Node>*nodeListParent = nodeList;
	for (itrParent = myNodeList->begin(); itrParent != myNodeList->end(); itrParent++) {
		for (itrChild = (*itrParent).nodeList->begin(); itrChild!=(*itrParent).nodeList->end(); itrChild++) {
			for (itrNewParent = nodeListParent->begin(); itrNewParent != nodeListParent->end(); itrNewParent++) {
				if ((*itrNewParent).name == (*itrChild).name) {
					(*itrChild).nodeList = (*itrNewParent).nodeList;
				}
			}
		}
	}
	return myNodeList;
}

RelationshipParser::RelationshipParser()
{
}


RelationshipParser::~RelationshipParser()
{
}
