#include "unorderedLinkedList.h"
#include"bookListType.h"
#include"bookType.h"
#include<string>
#include<fstream>
using namespace std;


void bookListType::searchBookList(string title, bool& found, nodeType<bookType>* &current) const
{
	found = false; //set found to false
	current = first; //set current to point to the first node
					 //in the list
	while (current != NULL && !found) //search the list
		if (current->info.checkTitle(title)) //the item is found
			found = true;
		else
			current = current->link; //advance current to
									 //the next node

}//
bool bookListType::isBookAvailable(string title) const
{
	bool found;
	nodeType<bookType> *location;
	searchBookList(title, found, location);
	if (found)
		found = (location->info.getNoOfCopiesInStock() > 0);
	else
		found = false;
	return found;
}
void bookListType::bookCheckIn(string title)
{
	bool found = false;
	nodeType<bookType> *location;
	searchBookList(title, found, location);
	if (found)
		location->info.checkIn();
	else
		cout << "The store does not carry " << title
		<< endl;
}
void bookListType::bookCheckOut(string title)
{
	bool found = false;
	nodeType<bookType> *location;
	searchBookList(title, found, location); //search the list
	if (found)
		location->info.checkOut();
	else
		cout << "The store does not carry " << title
		<< endl;
}

bool bookListType::bookCheckTitle(string title) const
{
	bool found = false;
	nodeType<bookType> *location;
	searchBookList(title, found, location); //search the list
	return found;
}
void bookListType::bookUpdateInStock(string title, int num)
{
	bool found = false;
	nodeType<bookType> *location;
	searchBookList(title, found, location); //search the list
	if (found)
		location->info.updateInStock(num);
	else
		cout << "The store does not carry " << title
		<< endl;
}
void bookListType::bookSetCopiesInStock(string title, int num)
{
	bool found = false;
	nodeType<bookType> *location;
	searchBookList(title, found, location);
	if (found)
		location->info.setCopiesInStock(num);
	else
		cout << "The store does not carry " << title
		<< endl;
}
bool bookListType::bookSearch(string title) const
{
	bool found = false;
	nodeType<bookType> *location;
	searchBookList(title, found, location);
	return found;
}
void bookListType::bookPrintTitle() const
{
	nodeType<bookType>* current;
	current = first;
	while (current != NULL)
	{
		current->info.printTitle();
		current = current->link;
	}
}
void bookListType::saveBookList() const
{
	ofstream outfile;
	outfile.open("C:\\Users\\juan\\Desktop\\bookDat.txt");
	nodeType<bookType>* current = first; //set current to point to the first node
										 //in the list
	while (current != NULL) //search the list				
	{
		outfile << current->info << endl;
		current = current->link; //advance current to
								 //the next node
	}
	outfile.close();
}//