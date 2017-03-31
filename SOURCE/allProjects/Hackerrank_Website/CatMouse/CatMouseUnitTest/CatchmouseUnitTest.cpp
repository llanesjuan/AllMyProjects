#include "stdafx.h"
#include "CppUnitTest.h"
#include"..\CatMouse\CatchMouse.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CatMouseUnitTest
{		
	TEST_CLASS(CatchmouseUnitTest)
	{
	public:
		
		TEST_METHOD(CatchmouseUnitTest_mouseCatcher)
		{
			CatchMouse catchMouse;
			int c1 = 1, c2 = 5, m = 0;
			string res = catchMouse.mouseCatcher(c1, c2, m);
			Assert::AreEqual(string("A"), res);
		}

	};
}