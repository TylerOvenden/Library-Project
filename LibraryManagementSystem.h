#pragma once
#include <algorithm>
#include "Book.h"
#include "Reader.h"
#include "Student.h"
#include "Teacher.h"
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

enum LMSStudentMenuOption {
	LOG_OUT,
	SEARCH_BOOKS,
	BORROW_BOOKS,
	RETURN_BOOKS,
	RESERVE_BOOKS,
	CANCEL_RESERVATION,
	MY_INFORMATION,
	CHANGE_PASSWORD,

	START,
};

enum LMSLibrarianMenuOption {
    LOG_OUT,
    SEARCH_BOOKS,
    ADD_BOOK,
    DELETE_BOOK,
    SEARCH_USERS,
    ADD_USER,
    DELETE_USER,
    MY_INFORMATION,
    CHANGE_PASSWORD,

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

	LMSBookSearchOption promptBookSearchTypeScreen();

	void saveAll();

	void deleteUser(string username);

	void addUser(string username, string password);

	LMSStudentMenuOption promptReaderMenuScreen();
	LMSLibrarianMenuOption promptLibrarianMenuScreen();

	void displayGreeting();

	void saveReaders();
	void saveBooks();
	void saveLibrarians();

	void changePassword();

	bool loginUser(string username, string password);

	User getUser();

	vector<Reader> getReaders();
	vector<Librarian> getLibrarian();
	vector<Book> getBooks();

	vector<User> getAllUsers();

	User* findUser(string username);

	void searchForUser(string username);

	Book* findBook(int isbn);

	void setReaders(vector<Reader> readers);
	bool compareBooksByPopularity(Book& book1, Book& book2);
	vector<Book> searchBooks(LMSBookSearchOption searchOption, string searchValue);
	void displayBookSearchResultsFor(LMSBookSearchOption searchOption, string searchValue);

	Reader* findReader(string username);
};