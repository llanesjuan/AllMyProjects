// Book_Data_Base.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "bookType.h"
#include "bookListType.h"
using namespace std;

void createBookList(ifstream& infile, bookListType& bookList);
void displayMenu();
void entManualData(bookListType& bookList);
void createArchive(bookListType& bookList);
void swapp(char &a, char &b);
void permutation(string str, int start, int end, bookListType& bookList, int& count);


int main(){
	string inputInfileAddress;
	bookListType bookList;
	int choice;
	char ch;
	string title;
	ifstream infile;
	string newAddress;
	char newAdd;
	cout << "Do you want to input a new address of system file: enter y or n?\n";
	cin.get(newAdd);
	cin.get(ch);
	if (newAdd == 'y') {
		cout << "Enter new address\n";
		getline(cin, inputInfileAddress);
		inputInfileAddress = inputInfileAddress.c_str();
	}
	else
		//open the input file
		inputInfileAddress = "C:\\Users\\juan\\Desktop\\bookDat.txt";
		infile.open(inputInfileAddress);
	if (!infile)
	{
		cout << "The input file does not exist. "
			<< "The program terminates!!!" << endl;
		return 1;
	}
	//create the book list
	createBookList(infile, bookList);
	infile.close();
	displayMenu();
	cout << "Enter your choice: ";
	cin >> choice; //get the request
	cin.get(ch);
	cout << endl;
	//process the requests
	while (choice <9){
		switch (choice)
		{
		case 1:
			cout << "Enter the title: ";
			getline(cin, title);
			cout << endl;
			if (bookList.bookSearch(title))
				cout << "The store carries " << title
				<< endl;
			else
				cout << "The store does not carry "
				<< title << endl;
			break;
		case 2:
			cout << "Enter the title: ";
			getline(cin, title);
			cout << endl;
			if (bookList.bookSearch(title))
			{
				if (bookList.isBookAvailable(title))
				{
					bookList.bookCheckOut(title);
					bookList.saveBookList();
					cout << "Enjoy your movie: " << title << endl;
				}
				else
					cout << "Currently " << title << " is out of stock." << endl;
			}
			else
				cout << "The store does not carry " << title << endl;
			break;
		case 3:
			cout << "Enter the title: ";
			getline(cin, title);
			cout << endl;
			if (bookList.bookSearch(title))
			{
				bookList.bookCheckIn(title);
				bookList.saveBookList();
				cout << "Thanks for returning " << title << endl;
			}
			else
				cout << "The store does not carry " << title << endl;
			break;
		case 4:
			cout << "Enter the title: ";
			getline(cin, title);
			cout << endl;
			if (bookList.bookSearch(title))
			{
				if (bookList.isBookAvailable(title))
					cout << title << " is currently in " << "stock." << endl;
				else
					cout << title << " is currently out " << "of stock." << endl;
			}
			else
				cout << "The store does not carry " << title << endl;
			break;
		case 5:
			bookList.bookPrintTitle();
			break;
		case 6:
			if (bookList.isEmptyList()) {
				cout << "No entries\n";
				break;
			}
			bookList.print();
			cout << endl;
			break;
		case 7:
			entManualData(bookList);
			bookList.saveBookList();
			break;
		default:
			cout << "Invalid selection." << endl;
		}//end switch
		displayMenu(); //display menu
		cout << "Enter your choice: ";
		cin >> choice; //get the next request
		cin.get(ch);
		cout << endl;
	}//end while
	return 0;
}

void createBookList(ifstream& infile, bookListType& bookList){
	string line;
	string title;
	string author;
	string publisher;
	string cover;
	string isbn;
	string year;
	string edition;
	string language;
	string cha = ":";
	int inStock;
	string inStockSt;
	bookType newBook;
	getline(infile, title);
	while (infile) {
		if (title == "") {
			cout << "file is empty\n";
			break;
		}
		title = title.substr((title.find(cha) + 2), 200);
		getline(infile, author);
		author = author.substr((author.find(cha) + 2), 200);
		getline(infile, publisher);
		publisher = publisher.substr(publisher.find(cha) + 2, 200);
		getline(infile, cover);
		cover = cover.substr((cover.find(cha) + 2), 200);
		getline(infile, isbn);
		isbn = isbn.substr((isbn.find(cha) + 2), 200);
		getline(infile, year);
		year = year.substr((year.find(cha) + 2), 200);
		getline(infile, edition);
		edition = edition.substr(edition.find(cha) + 2, 200);
		getline(infile, language);
		language = language.substr(language.find(cha) + 2, 200);
		getline(infile, inStockSt);
		inStockSt = inStockSt.substr((inStockSt.find(cha) + 2), 200);
		inStock = stoi(inStockSt);
		newBook.setBookInfo(title, author, publisher, cover, isbn, year, edition, language, inStock);
		bookList.insertFirst(newBook);
		getline(infile, line);
		getline(infile, title);
		if (title == "")
			break;
	}//end while
}//end createbookList
void entManualData(bookListType& bookList) {
	string title;
	string author;
	string publisher;
	string cover;
	string isbn;
	string year;
	string edition;
	string language;
	string cha = ":";
	int inStock;
	string inStockSt;
	bookType newbook;
	cout << "Enter title\n";
	getline(cin, title);
	cout << "Enter name of author\n";
	getline(cin, author);
	cout << "Enter publisher\n";
	getline(cin, publisher);
	cout << "Enter type of cover\n";
	getline(cin, cover);
	cout << "Enter ISBN\n";
	getline(cin, isbn);
	cout << "Enter Year\n";
	getline(cin, year);
	cout << "enter edition\n";
	getline(cin, edition);
	cout << "Enter language\n";
	getline(cin, language);
	cout << "Enter quantity of items of this book to be in existence\n";
	getline(cin, inStockSt);
	inStock = stoi(inStockSt);
	newbook.setBookInfo(title, author, publisher, cover, isbn, year, edition, language, inStock);
	bookList.insertFirst(newbook);
	bookList.saveBookList();
}
void displayMenu(){
	cout << "Select one of the following:" << endl;
	cout << "1: To check whether the store carries a "
		<< "particular book." << endl;
	cout << "2: To check out a book." << endl;
	cout << "3: To check in a book." << endl;
	cout << "4: To check whether a particular book is "
		<< "in stock." << endl;
	cout << "5: To print only the titles of all the books."
		<< endl;
	cout << "6: To print a list of all the books." << endl;
	cout << "7: To introduce data manually\n";
	cout << ">8: To exit" << endl;
}//end displayMenu
void createArchive(bookListType& bookList) {
	int count = 0;
	//ofstream outfile;
	//outfile.open("C:\\Users\\juan\\Desktop\\bookDat.txt");
	string str = "abc";
	int start = 0, end = 2;
	permutation(str, start, end, bookList, count);
	cout << "Number of books =  " << count << endl;
	bookList.saveBookList();
	//outfile.close();
}
void swapp(char &a, char &b){
	char temp = a;
	a = b;
	b = temp;
}
void permutation(string str, int start, int end, bookListType& bookList, int& count) {

	string title;
	string author = "a";
	string publisher = "z";
	string cover = "z";
	string isbn = "z";
	string year = "z";
	string edition = "z";
	string language = "z";
	string cha = ":";
	int inStock = 1;
	string inStockSt;
	bookType newbook;

	int i;
	if (start == end) {
		if (count <= 10) {
			count++;
			title = str;
			newbook.setBookInfo(title, author, publisher, cover, isbn, year, edition, language, inStock);
			bookList.insertFirst(newbook);
			//bookList.saveBookList();
		}
	}
	else
	{
		for (i = start; i <= end; i++)
		{
			swapp(str[start], str[i]);
			permutation(str, start + 1, end, bookList, count);
			swapp(str[start], str[i]);
		}
	}
}
