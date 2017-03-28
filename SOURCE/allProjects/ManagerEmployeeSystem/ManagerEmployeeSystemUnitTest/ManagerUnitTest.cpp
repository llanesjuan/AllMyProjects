#include "stdafx.h"
#include "CppUnitTest.h"
#include"..\ManagerEmployeeSystem\Manager.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ManagerEmployeeSystemUnitTest
{		
	TEST_CLASS(ManagerUnitTest)
	{
	public:
		
		TEST_METHOD(ManagerUnitTest_parseManager)
		{
			string manEmp = "a->b,c,d.b->e,f.";
			Manager manager;
			list<string>managerList = manager.parseManager(manEmp);
			string expected = "b";
			managerList.pop_front();
			Assert::AreEqual(expected, managerList.front());
		}

	};
}