#include "stdafx.h"
#include "CppUnitTest.h"
#include"..\BreakingRecords\breakRecord.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BreakingRecordsUnitTest
{		
	TEST_CLASS(breakRecordUnitTest)
	{
	public:
		
		TEST_METHOD(breakRecordUnitTest_recordBreaker)
		{
			vector<int>a;
			a.push_back(3);
			a.push_back(4);
			a.push_back(21);
			a.push_back(36);
			a.push_back(10);
			a.push_back(28);
			a.push_back(35);
			a.push_back(5);
			a.push_back(24);
			a.push_back(42);
			breakRecord breakRec;
			int inc = 0, dec = 0;
			breakRec.recordBreaker(a, inc, dec);
			Assert::AreEqual(4, inc);
			Assert::AreEqual(0, dec);
		}

	};
}