#pragma once
#include <algorithm>
#include "Book.h"
#include "Student.h"
#include "Teacher.h"
#include "Librarian.h"

static const string READER_DATA_FILE = "reader.txt";
static const string LIBRARIAN_DATA_FILE = "librarian.txt";
static const string BOOK_DATA_FILE = "book.txt";
static const string COPY_DATA_FILE = "copies.txt";

enum LMSBookSearchOption {
	SEARCH_BY_ISBN,
	SEARCH_BY_TITLE,
	SEARCH_BY_AUTHOR,
	SEARCH_BY_CATEGORY,
};

enum LMSReaderMenuOption {
	READER_LOG_OUT,
	READER_SEARCH_BOOKS,
	READER_BORROW_BOOK,
	READER_RETURN_BOOK,
	READER_RESERVE_BOOK,
	READER_RENEW_BOOK,
	READER_CANCEL_RESERVATION,
	READER_CHANGE_PASSWORD,

	READER_START,
};

enum LMSLibrarianMenuOption {
    LIBRARIAN_LOG_OUT,
	LIBRARIAN_SEARCH_BOOKS,
	LIBRARIAN_ADD_BOOK,
	LIBRARIAN_DELETE_BOOK,
	LIBRARIAN_SEARCH_USERS,
	LIBRARIAN_ADD_USER,
	LIBRARIAN_DELETE_USER,
	LIBRARIAN_CHANGE_PASSWORD,

	LIBRARIAN_START,
};

class LibraryManagementSystem {
private:
	User user;

	int currentTimeSecs;

	vector<Copy> copies;
	vector<Book> books;
	vector<Reader> readers;
	vector<Librarian> librarians;

	vector<Librarian> loadLibrarians();
	vector<Reader> loadReaders();
	vector<Book> loadBooks();

	vector<Copy> loadCopies();

	void updateUserPassword(string username, string password);
public:
	LibraryManagementSystem();

	void addCopiesToBooks();

	void updateTime();

	void addCopiesToReaders();

	LMSBookSearchOption promptBookSearchTypeScreen();

	void saveAll();

	void returnCopy(int copyId);

	void deleteUser(string username);

	void deleteCopyFromLibrary(int copyId);

	void deleteCopyFromLibrary();

	void addCopyToLibrary();

	void addUser(string username, string password);

	int getUniqueCopyId();

	void renewCopy(int copyId);

	void borrowCopy(int copyId);

	LMSReaderMenuOption promptReaderMenuScreen();
	LMSLibrarianMenuOption promptLibrarianMenuScreen();

	void displayGreeting();

	void saveReaders();
	void saveBooks();
	void saveCopies();
	void saveLibrarians();

	void reserveBook(int isbn);

	void changePassword();

	bool loginUser(string username, string password);

	User getUser();

	vector<Reader> getReaders();
	vector<Librarian> getLibrarian();
	vector<Book> getBooks();

	vector<User> getAllUsers();

	User* findUser(string username);

	void cancelReservation(int isbn);

	void searchForUser(string username);

	Book* findBook(int isbn);

	Copy* findCopy(int copyId);

	void setReaders(vector<Reader> readers);
	static bool compareBooksByPopularity(Book& book1, Book& book2);
	vector<Book> searchBooks(LMSBookSearchOption searchOption, string searchValue);
	void displayBookSearchResultsFor(LMSBookSearchOption searchOption, string searchValue);

	Reader* findReader(string username);
};