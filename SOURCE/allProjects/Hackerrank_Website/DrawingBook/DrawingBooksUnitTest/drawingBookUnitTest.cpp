#include "stdafx.h"
#include "CppUnitTest.h"
#include"..\DrawingBook\DrawingBooks.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DrawingBooksUnitTest
{		
	TEST_CLASS(drawingBookUnitTest)
	{
	public:
		
		TEST_METHOD(drawingBookUnitTest_bookPager)
		{
			DrawingBooks drawingBook;
			int n = 5;
			int pag =4;
			int res = drawingBook.bookPager(n, pag);
			Assert::AreEqual(0, res);
		}

	};
}