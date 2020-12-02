#pragma once
#include "Book.h"
#include "Reader.h"

static const string READER_DATA_FILE = "reader.txt";
static const string BOOK_DATA_FILE = "book.txt";

class LibraryManagementSystem {
private:
	User user;

	vector<Book> books;
	vector<Reader> readers;

	vector<Reader> loadReaders();
	vector<Book> loadBooks();

public:
	LibraryManagementSystem();

	void displayWelcomeScreen();

	void saveReaders();
	void saveBooks();

	bool loginUser(string username, string password);

	vector<Reader> getReaders();
	vector<Book> getBooks();
};