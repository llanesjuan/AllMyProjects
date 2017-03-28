#pragma once
//*************************************************************
// Author: Juan Llanes
//
// class bookListType
// This class specifies the members to implement a list of
// books.
//************************************************************
#include <string>
#include "unorderedLinkedList.h"
#include "bookType.h"
using namespace std;

class bookListType :public unorderedLinkedList<bookType>
{
public:
	bool bookSearch(string title) const;
	//Function to search the list to see whether a
	//particular title, specified by the parameter title,
	//is in the store.
	//Postcondition: Returns true if the title is found,
	// and false otherwise.
	bool isBookAvailable(string title) const;
	//Function to determine whether a copy of a particular
	//book is in the store.
	//Postcondition: Returns true if at least one copy of the
	// book specified by title is in the store,
	// and false otherwise.
	void bookCheckOut(string title);
	//Function to check out a book, that is, rent a book.
	//Postcondition: copiesInStock is decremented by one.
	void bookCheckIn(string title);
	//Function to check in a book returned by a customer.
	//Postcondition: copiesInStock is incremented by one.
	bool bookCheckTitle(string title) const;
	//Function to determine whether a particular book is in
	//the store.
	//Postcondition: Returns true if the book’s title is
	// the same as title, and false otherwise.
	void bookUpdateInStock(string title, int num);
	//Function to update the number of copies of a book
	//by adding the value of the parameter num. The
	//parameter title specifies the name of the book for
	//which the number of copies is to be updated.
	//Postcondition: copiesInStock = copiesInStock + num;
	void bookSetCopiesInStock(string title, int num);
	//Function to reset the number of copies of a book.
	//The parameter title specifies the name of the book
	//for which the number of copies is to be reset, and the
	//parameter num specifies the number of copies.
	//Postcondition: copiesInStock = num;
	void bookPrintTitle() const;
	//Function to print the titles of all the book in
	//the store.
	void saveBookList() const;
	//void saveToDisc();
private:
	//void searchbookList(string title, bool& found,unorderedLinkedList<bookType>* &current) const;
	void searchBookList(string title, bool& found, nodeType<bookType>* &current) const;
	//This function searches the book list for a
	//particular book, specified by the parameter title.
	//Postcondition: If the book is found, the parameter
	// found is set to true, otherwise it is set
	// to false. The parameter current points
	// to the node containing the book.
};
