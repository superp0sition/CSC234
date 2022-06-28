#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 

using namespace std;

class Book
{
public:
	Book();
	Book(string _title, string _isbn, string _publisher, int _year, float _cost, int _numCopies, int _numAuthors, const string _authors[10]);
	string getTitle();
	string getISBN();
	void displayBook();
private:
	// The title of the book
	string title;
	// The ISBN of the book
	string isbn;
	// The Book Publisher
	string publisher;
	// The year it was published
	int year;
	// The cost of the book
	float cost;
	// The number of copies of the book
	int numCopies;
	// The number of authors
	int numAuthors;
	// List of Authors
	string authors[10];
};