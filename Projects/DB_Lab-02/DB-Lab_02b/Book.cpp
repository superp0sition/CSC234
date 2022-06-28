#include "Book.h";

// default constructor
Book::Book ()
{
}

// constructor taking all data fields from parameters
Book::Book(string _title, string _isbn, string _publisher, int _year, float _cost, int _numCopies, int _numAuthors, const string _authors[])
{
	title = _title; // assign values to all data members
	isbn = _isbn;
	publisher = _publisher;
	year = _year;
	cost = _cost;
	numCopies = _numCopies;
	numAuthors = _numAuthors;
	memcpy(authors, _authors, numAuthors * sizeof * _authors);
	// ^ had an issue that took me a long time to debug that I thjought was coming from this line, but was coming from elsewhere
}

// returns the title of book
string Book::getTitle()
{
	return title;
}

// returns the isbn of book
string Book::getISBN()
{
	return isbn;
}

// displays formatted data from the book to console, includes all data members
void Book::displayBook()
{
	printf("Title: %s\nISBN: %s\nPublisher: %s\nYear: %d\nPrice: $%.2f\nNumber of Copies: %d\nAuthors: \%d\n",
		title.c_str(), isbn.c_str(), publisher.c_str(), year, cost, numCopies, numAuthors);
	for (int i = 0; i < numAuthors; i++)
		printf("\t%s\n", authors[i].c_str());
	cout << endl;
}
