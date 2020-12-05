#pragma once
#include <algorithm>
#include <ctime>
#include "Book.h"
#include "Reader.h"
#include "Librarian.h"
#include "Student.h"
#include "Teacher.h"


static const string READER_DATA_FILE = "reader.txt";
static const string LIBRARIAN_DATA_FILE = "librarian.txt";
static const string BOOK_DATA_FILE = "book.txt";
static const string COPIES_DATA_FILE = "copy.txt";

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
enum LMSMenuOptionLibrarian {
	LOG_OUT_LIBRARIAN,
	SEARCH_BOOKS_LIBRARIAN,
	ADD_BOOKS_LIBRARIAN,
	DELETE_BOOKS_LIBRARIAN,
	SEARCH_USERS_LIBRARIAN,
	ADD_USERS_LIBRARIAN,
	DELETE_USERS_LIBRARIAN,
	MY_INFORMATION_LIBRARIAN,
	CHANGE_PASSWORD_LIBRARIAN,

	START_LIBRARIAN
};
class LibraryManagementSystem {
private:
	User user;
	Reader currentReader;
	vector<Book> books;
	vector<Copy> copies;
	vector<Reader> readers;
	vector<Librarian> librarians;
	vector<User> allUsers;
	vector<Librarian> loadLibrarians();
	vector<Reader> loadReaders();
	vector<Book> loadBooks();
	vector<Copy> loadCopies();

public:
	LibraryManagementSystem();

	LMSMenuOption promptMenuScreen();
	LMSBookSearchOption promptBookSearchTypeScreen();

	LMSMenuOptionLibrarian promptLibrarianScreen();

	void displayGreeting();

	void saveReaders();
	void saveBooks();
	void saveLibrarians();

	bool loginUser(string username, string password);

	User getUser();

	vector<Reader> getReaders();
	vector<Librarian> getLibrarian();
	vector<Book> getBooks();
	vector<User> getAllUsers();
	void setReaders(vector<Reader> readers);
	bool compareBooksByPopularity(Book& book1, Book& book2);
	vector<Book> searchBooks(LMSBookSearchOption searchOption, string searchValue);
};
