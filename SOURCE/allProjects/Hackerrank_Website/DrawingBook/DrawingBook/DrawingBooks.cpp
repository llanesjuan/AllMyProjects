#include "DrawingBooks.h"



int DrawingBooks::bookPager(int n, int p)
{
	if (p > n / 2) {
		p = n - p;
	}	
		return  p  / 2;
}

DrawingBooks::DrawingBooks()
{
}


DrawingBooks::~DrawingBooks()
{
}
