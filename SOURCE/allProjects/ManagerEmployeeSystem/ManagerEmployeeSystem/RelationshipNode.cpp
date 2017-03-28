#include "RelationshipNode.h"
Node RelationshipNode::findRoot(list<Node>* nodeList)
{
	list<Node>*nodeListParent = nodeList;
	list<Node>::iterator itrListList;
	list<Node>::iterator itrList;
	list<Node>::iterator itrListParent;
	for (itrListList = nodeList->begin(); itrListList != nodeList->end(); itrListList++) {
		for (itrList = (*itrListList).nodeList->begin(); itrList != (*itrListList).nodeList->end(); itrList++) {
			for (itrListParent = nodeListParent->begin(); itrListParent != nodeListParent->end(); itrListParent++) {
				if ((*itrListParent).name == (*itrList).name) {
					nodeListParent->erase(itrListParent);
					break;
				}
			}
		}
	}
	return nodeListParent->front();
}
void RelationshipNode::createManagerStack(Node root, string employee, stack<Node>& myStack, bool &founded)
{
	// Base case
	if (root.nodeList == NULL || founded) {

		// Remove root from the stack when node is a leaf
		if (!founded)
			myStack.pop();
		return;
	}
	list<Node>* nodeList = root.nodeList;
	list<Node>::iterator itrNode;
	// Recursion
	// Recurse over each children in root
	for (itrNode = nodeList->begin(); itrNode != nodeList->end(); itrNode++)
	{
		if ((*itrNode).name == employee) {
			founded = true;
			break;
		}
			if (founded){
				break;
		}
		myStack.push(*itrNode);
		createManagerStack((*itrNode), employee, myStack, founded);
	}
	if (!founded)
		myStack.pop();
}
Node RelationshipNode::findCommonEmployeeManager(stack<Node>s1, stack<Node>s2) {
	//Node temp;
	stack<Node>s3;
	//inverting stack s1
	while (s1.size() != 0) {
		s3.push(s1.top());
		s1.pop();
	}
	//inverting stack 2
	while (s2.size() != 0) {
		s1.push(s2.top());
		s2.pop();
	}
	Node temp;
	while (s1.top().name == s3.top().name) {//&& s2.size()!=0 && s3.size()!=0
		temp = s1.top();
		s1.pop();
		s3.pop();
		if (s1.size() == 0 || s3.size() == 0)
			break;
	}
	return temp;
}
RelationshipNode::RelationshipNode()
{
}


RelationshipNode::~RelationshipNode()
{
}
