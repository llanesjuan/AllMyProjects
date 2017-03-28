#include "stdafx.h"
#include "CppUnitTest.h"
#include"..\ManagerEmployeeSystem\Node.cpp"
//#include"..\ManagerEmployeeSystem\Manager.cpp"
//#include"..\ManagerEmployeeSystem\Employee.cpp"
#include"..\ManagerEmployeeSystem\RelationshipParser.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ManagerEmployeeSystemUnitTest
{
	TEST_CLASS(RelationshipParserUnitTest)
	{
	public:

		TEST_METHOD(RelationshipParserUnitTest_nodeListMaker)
		{
			string manEmp = "a->b,c,d.b->e,f.";
			Manager manager;
			list<string>managerList = manager.parseManager(manEmp);
			Employee employee;
			list<list<string>> employeeList = employee.parseEmployee(manEmp);
			RelationshipParser relationshipParser;
			list<Node>* nodeList = relationshipParser.nodeListMaker(managerList, employeeList);
			string expected = "a";
			Assert::AreEqual(expected, (nodeList->front()).name);
			nodeList->pop_front();
			string expected2 = "b";
			Assert::AreEqual(expected2, (nodeList->front()).name);
			string expected3 = "e";			
			Assert::AreEqual(expected3, nodeList->front().nodeList->front().name);
		}		
	};
}
