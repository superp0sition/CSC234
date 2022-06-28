// This file gave me a lot of trouble when coding, but it was one part. That part is commented to explain the problem.

#include "Book.h"

// Reads data from the file "books.txt" and places it in the books array. Iterates numBook to match number of books entered
void getBookData(Book books[], int& numBook);

// Calls the display method for each book from the array parameter. Counts using the numBooks value
void printBookData(Book books[], int numBook);

// Searches every book for a matching ISBN (Case sensitive)
void searchBookByISBN(Book books[], int numBook);

// Searches every book for specified string in title, displays all matching books (Case sensitive)
void searchBookByTitle(Book books[], int numBook);

int main()
{
	Book library[50];
	int selectedOption;
	int booksRead = 0;

	getBookData(library, booksRead);

	while(1){
		cout << "1. List all available books" << endl // display user menu
			<< "2. Search for a book by title" << endl
			<< "3. Search for a book using ISBN" << endl
			<< "4. Exit program" << endl;
		cin >> selectedOption; // 
		switch (selectedOption) {
		case 1:
			printBookData(library, booksRead);
			break;
		case 2:
			searchBookByTitle(library, booksRead);
			break;
		case 3:
			searchBookByISBN(library, booksRead);
			break;
		case 4:
			return 0;
			break;
		default:
			cout << "That is not an option" << endl;
			return -1; // if a string is input is causes the text to keep looping, so the program is stopped
			break;
		}
	}
	
}

void getBookData(Book books[], int& numBook)
{
	// The title of the book and all other data fields required to construct a book
	string title, isbn, publisher, year, cost, numCopies, numAuthors, authors[10];

	//pointer to hold value of new books
	Book* temp;

	// file stream
	ifstream inFile;

	inFile.open("books.txt");
	if (!inFile.is_open()) {
		cout << "File could not be opened!" << endl; // outputs to user that file could not be located in the base directory
		return; // returns since nothing can be done about this
	}

	while (getline(inFile, title)) // get values line by line since they are formatted that way
	{
		getline(inFile, isbn);
		getline(inFile, publisher);
		getline(inFile, year);
		getline(inFile, cost);
		getline(inFile, numCopies);
		getline(inFile, numAuthors);

		for (int i = 0; i < stoi(numAuthors); i++) // add number of authors specified since there is no delimiter between books
			getline(inFile, authors[i]);
		// my main issue came from the line below, it kept causing an access violation. Initially, because 
		// my breakpoints weren't placed well, I believed my issue was coming from memcpy trying to edit the
		// private array in Book. This took me a few hours to figure out and I feel a bit dumb for neglecting the one
		// line below.
		temp = new Book(title, isbn, publisher, stoi(year), stof(cost), stoi(numCopies), stoi(numAuthors), authors); // creates a new book

		// assigns the book to the next place in the storage array and iterates the number of books at the same time.
		books[numBook++] = *temp;
	}

	//closes the file
	inFile.close();
}

void printBookData(Book books[], int numBook)
{
	// iterates over all books in the storage array
	for (int i = 0; i < numBook; i++)
		books[i].displayBook();
}

void searchBookByISBN(Book books[], int numBook)
{
	string search;
	int matches = 0;
	cout << "\nWhat would you like to search for? "; // prompts the user to search for a string containing an ISBN
	cin >> search;
	for (int i = 0; i < numBook; i++)
		if (books[i].getISBN().find(search) != -1) {
			books[i].displayBook(); // displays every book that contains these characters
			matches++;
		}
		
	cout << matches << " match(es) were found." << endl; // displays the number of matches that were found containing the given string
}

void searchBookByTitle(Book books[], int numBook)
{
	string search;
	int matches = 0;
	cout << "What would you like to search for? ";
	cin >> search;
	for (int i = 0; i < numBook; i++)
		if (books[i].getTitle().find(search) != -1) {
			books[i].displayBook();
			matches++;
		}

	cout << matches << " match(es) were found." << endl; // same as function above other than that it iterates over each title rather than ISBN
}
