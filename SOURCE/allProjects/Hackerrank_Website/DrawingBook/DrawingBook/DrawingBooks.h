
//Brie’s Drawing teacher asks her class to open their - page book to page number.Brie can either start 
//turning pages from the front of the book(i.e., page number) or from the back of the book(i.e., page number), 
//and she always turns pages one - by - one(as opposed to skipping through multiple pages at once).When she opens
//the book, page  is always on the right side.Each page in the book has two sides, front and back, except for 
//the last page which may only have a front side depending on the total number of pages of the book
//Given  and, find and print the minimum number of pages Brie must turn in order to arrive at page .
#pragma once
class DrawingBooks
{
public:
	int bookPager(int n, int p);
	DrawingBooks();
	~DrawingBooks();
};

