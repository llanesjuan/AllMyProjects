#include "stdafx.h"
#include "CppUnitTest.h"
#include"..\ManagerEmployeeSystem\Employee.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ManagerEmployeeSystemUnitTest
{
	TEST_CLASS(EmployeeUnitTest)
	{
	public:

		TEST_METHOD(EmployeeUnitTest_parseEmployee)
		{
			string manEmp = "a->b,c,d.b->e,f.";
			Employee employee;
			list<list<string>>employeeList = employee.parseEmployee(manEmp);
			employeeList.pop_front();
			Assert::AreEqual(string("e"), employeeList.front().front());
		}

	};
}