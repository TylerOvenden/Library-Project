#pragma once
#include <algorithm>
#include "Book.h"
#include "Reader.h"
#include "Librarian.h"

static const string READER_DATA_FILE = "reader.txt";
static const string LIBRARIAN_DATA_FILE = "librarian.txt";
static const string BOOK_DATA_FILE = "book.txt";

enum LMSBookSearchOption {
	SEARCH_BY_ISBN,
	SEARCH_BY_TITLE,
	SEARCH_BY_AUTHOR,
	SEARCH_BY_CATEGORY,
};

enum LMSMenuOption {
	LOG_OUT,
	SEARCH_BOOKS,
	BORROW_BOOKS,
	RETURN_BOOKS,
	RESERVE_BOOKS,
	CANCEL_RESERVATION,
	INFO,
	CHANGE_PASS,

	START,
};

class LibraryManagementSystem {
private:
	User user;

	vector<Book> books;
	vector<Reader> readers;
	vector<Librarian> librarians;

	vector<Librarian> loadLibrarians();
	vector<Reader> loadReaders();
	vector<Book> loadBooks();

public:
	LibraryManagementSystem();

	LMSMenuOption promptMenuScreen();
	LMSBookSearchOption promptBookSearchTypeScreen();

	void displayGreeting();

	void saveReaders();
	void saveBooks();
	void saveLibrarians();

	bool loginUser(string username, string password);

	vector<Reader> getReaders();
	vector<Book> getBooks();

	bool compareBooksByPopularity(Book& book1, Book& book2);
	vector<Book> searchBooks(LMSBookSearchOption searchOption, string searchValue);
	void displayBookSearchResultsFor(LMSBookSearchOption searchOption, string searchValue);

	Reader* findReader(string username);
};