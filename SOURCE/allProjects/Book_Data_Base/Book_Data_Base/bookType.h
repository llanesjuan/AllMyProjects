#pragma once
//************************************************************
// Author: Juan Llanes
//
// class bookType
// This class specifies the members of book.
//************************************************************
#include <iostream>
#include <string>
using namespace std;


class bookType
{
	friend ostream& operator<< (ostream&, const bookType&);
public:
	void setBookInfo(string title, string author,
		string publisher, string cover,
		string isbn, string year, string edition, string language,
		int setInStock);
	//Function to set the details of a book.
	//The member variables are set according to the
	//parameters.
	//Postcondition: bookTitle = title; bookAuthor = author;
	// bookPublisher = publisher; bookCover = cover; 
	// bookIsbn = isbn;bookYear = year;bookEdition = edition;bookLanguage = language
	// copiesInStock = setInStock;
	int getNoOfCopiesInStock() const;
	//Function to check the number of copies in stock.
	//Postcondition: The value of copiesInStock is returned.
	void checkOut();
	//Function to rent a book.
	//Postcondition: The number of copies in stock is
	// decremented by one.
	void checkIn();
	//Function to check in a book.
	//Postcondition: The number of copies in stock is
	// incremented by one.
	void printTitle() const;
	//Function to print the title of a book.
	void printInfo() const;
	//Function to print the details of a book.
	//Postcondition: The title of the book, author,
	// publisher, and so on are displayed
	// on the screen.
	bool checkTitle(string title);
	//Function to check whether the title is the same as the
	//title of the book.
	//Postcondition: Returns the value true if the title
	// is the same as the title of the book;
	// false otherwise.
	void updateInStock(int num);
	//Function to increment the number of copies in stock by
	//adding the value of the parameter num.
	//Postcondition: copiesInStock = copiesInStock + num;
	void setCopiesInStock(int num);
	//Function to set the number of copies in stock.
	//Postcondition: copiesInStock = num;
	string getTitle() const;
	//Function to return the title of the book.
	//Postcondition: The title of the book is returned.
	bookType(string bookTitle = "", string bookAuthor = "",
		string bookPublisher = "", string bookCover = "", string bookIsbn = "", string bookYear = "",
		string bookEdition = "", string bookLanguage = "", int setInStock = 0);
	//constructor
	//The member variables are set according to the
	//incoming parameters. If no values are specified, the
	//default values are assigned.
	//Postcondition: bookTitle = title; bookAuthor = author;
	// bookPublisher = publisher;
	// bookCover = cover;
	// bookIsbn = isbn;
	// bookYear = year;
	// copiesInStock = setInStock;
	//Overload the relational operators.
	bool operator==(const bookType&) const;
	bool operator!=(const bookType&) const;
private:
	string bookTitle; //variable to store the name
					  //of the book
	string bookAuthor; //variable to store the author
	string bookPublisher; //variable to store the publisher
	string bookCover; //variable to store thecover
	string bookIsbn; //variable to store theISBN
	string bookYear; //variable to store the year
	string bookEdition;// variable to store edition number
	string bookLanguage; //variable to store language 
	int copiesInStock; //variable to store the number of
					   //copies in stock
};