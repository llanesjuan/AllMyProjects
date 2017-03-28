#include "stdafx.h"
#include "CppUnitTest.h"
//#include"..\ManagerEmployeeSystem\Node.cpp"
//#include"..\ManagerEmployeeSystem\Manager.cpp"
//#include"..\ManagerEmployeeSystem\Employee.cpp"
//#include"..\ManagerEmployeeSystem\RelationshipParser.cpp"
#include"..\ManagerEmployeeSystem\RelationshipNode.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ManagerEmployeeSystemUnitTest
{
	TEST_CLASS(RelationshipNodeUnitTest)
	{
	public:

		TEST_METHOD(RelationshipNodeUnitTest_findRoot)
		{
			string manEmp = "a->b,c,d.b->e,f.e->h,j,k";
			Manager manager;
			list<string>managerList = manager.parseManager(manEmp);
			Employee employee;
			list<list<string>> employeeList = employee.parseEmployee(manEmp);
			RelationshipParser relationshipParser;
			list<Node>* nodeList = relationshipParser.nodeListMaker(managerList, employeeList);
			list<Node>* nodeListLinked = relationshipParser.nodeTreeLinker(nodeList);
			RelationshipNode relationshipNode;
			Node root = relationshipNode.findRoot(nodeListLinked);
			string expected = "a";
			Assert::AreEqual(expected, root.name);
		}
		TEST_METHOD(RelationshipNodeUnitTest_createManagerStack)
		{
			string manEmp = "a->b,c,d.b->e,f.e->h,j,k";
			Manager manager;
			list<string>managerList = manager.parseManager(manEmp);
			Employee employee;
			list<list<string>> employeeList = employee.parseEmployee(manEmp);
			RelationshipParser relationshipParser;
			list<Node>* nodeList = relationshipParser.nodeListMaker(managerList, employeeList);
			list<Node>* nodeListLinked = relationshipParser.nodeTreeLinker(nodeList);
			RelationshipNode relationshipNode;
			Node root = relationshipNode.findRoot(nodeListLinked);
			stack<Node>stackManager;
			string stringEmployee = "f";
			bool founded = false;
			stackManager.push(root);
			relationshipNode.createManagerStack(root, stringEmployee, stackManager,founded);
			string expected = "b";
			Assert::AreEqual(expected, stackManager.top().name);
		}



		
		TEST_METHOD(RelationshipNodeUnitTest_findCommonManager)
		{
			string manEmp = "a->b,c,d.b->e,f.e->h,j,k";
			Manager manager;
			list<string>managerList = manager.parseManager(manEmp);
			Employee employee;
			list<list<string>> employeeList = employee.parseEmployee(manEmp);
			RelationshipParser relationshipParser;
			list<Node>* nodeList = relationshipParser.nodeListMaker(managerList, employeeList);
			list<Node>* nodeListLinked = relationshipParser.nodeTreeLinker(nodeList);
			RelationshipNode relationshipNode;
			Node root = relationshipNode.findRoot(nodeListLinked);
			stack<Node>stackFirstEmployee;
			string stringFirstEmployee = "d";
			bool founded = false;
			stackFirstEmployee.push(root);
			relationshipNode.createManagerStack(root, stringFirstEmployee, stackFirstEmployee, founded);
			stack<Node>stackSecondEmployee;
			bool foundedSec = false;
			string stringSecondEmployee = "k";
			stackSecondEmployee.push(root);
			relationshipNode.createManagerStack(root, stringSecondEmployee, stackSecondEmployee, foundedSec);
			string expected = "a";
			Node result = relationshipNode.findCommonEmployeeManager(stackFirstEmployee, stackFirstEmployee);
			Assert::AreEqual(expected, result.name);
		}
	};
}