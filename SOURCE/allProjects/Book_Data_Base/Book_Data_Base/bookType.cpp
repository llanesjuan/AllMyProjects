#include"bookType.h"
using namespace std;
#include<string>


void bookType::setBookInfo(string title, string author, string publisher,
	string cover, string isbn, string year, string edition, string language,
	int setInStock)
{
	bookTitle = title;
	bookAuthor = author;
	bookPublisher = publisher;
	bookCover = cover;
	bookIsbn = isbn;
	bookYear = year;
	bookEdition = edition;
	bookLanguage = language;
	copiesInStock = setInStock;
}
void bookType::checkOut()
{
	if (getNoOfCopiesInStock() > 0)
		copiesInStock--;
	else
		cout << "Currently out of stock" << endl;
}
void bookType::checkIn()
{
	copiesInStock++;
}
int bookType::getNoOfCopiesInStock() const
{
	return copiesInStock;
}
void bookType::printTitle() const
{
	cout << "Book Title: " << bookTitle << endl;
}
void bookType::printInfo() const
{
	cout << "Book Title: " << bookTitle << endl;
	cout << "Author: " << bookAuthor << " Publisher: " << bookPublisher << endl;
	cout << "Cover: " << bookCover << endl;
	cout << "ISBN: " << bookIsbn << endl;
	cout << "Year: " << bookYear << endl;
	cout << "Edition: " << bookEdition << endl;
	cout << "Labguage: " << bookLanguage << endl;
	cout << "Copies in stock: " << copiesInStock
		<< endl;
}
bool bookType::checkTitle(string title)
{
	bool findTitle = true;
	for (int i = 0; i < bookTitle.length(); i++) {
		if (tolower(bookTitle[i]) != tolower(title[i])) {
			findTitle = false;
			break;
		}
	}
	return findTitle;
	//return(tolower(dvdTitle) == tolower(title));
}
void bookType::updateInStock(int num)
{
	copiesInStock += num;
}
void bookType::setCopiesInStock(int num)
{
	copiesInStock = num;
}
string bookType::getTitle() const
{
	return bookTitle;
}
bookType::bookType(string title, string author,
	string publisher, string cover,
	string isbn, string year,
	string edition, string language, int setInStock)
{
	setBookInfo(title, author, publisher, cover, isbn,
		year, edition, language, setInStock);
}
bool bookType::operator==(const bookType& other) const
{
	return (bookTitle == other.bookTitle);
}
bool bookType::operator!=(const bookType& other) const
{
	return (bookTitle != other.bookTitle);
}
ostream& operator<< (ostream& osObject, const bookType& book)
{
	//osObject << endl;
	osObject << "Book Title: " << book.bookTitle << endl;
	osObject << "Author: " << book.bookAuthor << endl;
	osObject << "Publisher: " << book.bookPublisher << endl;
	osObject << "Cover: " << book.bookCover << endl;
	osObject << "ISBN: " << book.bookIsbn << endl;
	osObject << "Year: " << book.bookYear << endl;
	osObject << "Edition: " << book.bookEdition << endl;
	osObject << "Language: " << book.bookLanguage << endl;
	osObject << "Copies in stock: " << to_string(book.copiesInStock) << endl;
	return osObject;
}