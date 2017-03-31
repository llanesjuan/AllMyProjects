#include "stdafx.h"
#include "CppUnitTest.h"
#include"..\BirdMigratory\BirdMigration.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BirdMigratoryUnitTest
{		
	TEST_CLASS(BirdMigrationUnitTest)
	{
	public:
		
		TEST_METHOD(BirdMigrationUnitTest_maxMigration)
		{
			BirdMigration birdMigration;
			vector<int>a;
			a.push_back(1);
			a.push_back(4);
			a.push_back(4);
			a.push_back(4);
			a.push_back(5);
			a.push_back(3);
			int maxTypeOfBird = birdMigration.maxMigration(a);
			Assert::AreEqual(4, maxTypeOfBird);
		}

	};
}