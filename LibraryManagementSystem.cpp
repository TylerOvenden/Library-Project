#include "LibraryManagementSystem.h"

LibraryManagementSystem::LibraryManagementSystem() {
	this->readers = this->loadReaders();
	this->books = this->loadBooks();
	this->librarians = this->loadLibrarians();
}

vector<Librarian> LibraryManagementSystem::loadLibrarians() {
	ifstream librarianFile(LIBRARIAN_DATA_FILE);

	if (librarianFile.fail()) {
		cerr << "Error opening reader data file!" << endl;
		exit(1);
	}

	vector<Librarian> librarians;
	Librarian librarian;
	// Our data files always have a trailing line that we skip
	while (librarianFile.eof() == 0 && librarianFile.peek() != EOF) {
		librarianFile >> librarian;
		librarians.push_back(librarian);
	}
	librarianFile.close();

	return librarians;
}

vector<Reader> LibraryManagementSystem::loadReaders() {
	ifstream readerFile(READER_DATA_FILE);

	if (readerFile.fail()) {
		cerr << "Error opening reader data file!" << endl;
		exit(1);
	}

	vector<Reader> readers;
	Reader reader;
	// Our data files always have a trailing line that we skip
	while (readerFile.eof() == 0 && readerFile.peek() != EOF) {
		readerFile >> reader;
		readers.push_back(reader);
	}
	readerFile.close();

	return readers;
}

vector<Book> LibraryManagementSystem::loadBooks() {
	ifstream bookInput(BOOK_DATA_FILE);
	if (bookInput.fail()) {
		cerr << endl << "Error opening book data file!" << endl;
		exit(1);
	}

	vector<Book> books;
	Book book;

	// Our data files always have a trailing line that we skip
	while (bookInput.eof() == 0 && bookInput.peek() != EOF) {
		bookInput >> book;
		books.push_back(book);
	}
	bookInput.close();

	return books;
}

void LibraryManagementSystem::saveReaders() {
	ofstream readerFile(READER_DATA_FILE);
	if (readerFile.fail()) {
		cerr << endl << "Error opening reader data file!" << endl;
		exit(1);
	}
	else {
		cout << endl << "Successfully opened reader data file!" << endl << endl;
	}

	for (int i = 0; i < this->readers.size(); i++) {
		readerFile << this->readers.at(i);
	}
}

void LibraryManagementSystem::saveBooks() {
	ofstream bookFile(BOOK_DATA_FILE);
	if (bookFile.fail()) {
		cerr << endl << "Error opening book data file!" << endl;
		exit(1);
	}
	else {
		cout << endl << "Successfully opened book data file!" << endl << endl;
	}

	for (int i = 0; i < this->books.size(); i++) {
		bookFile << this->books.at(i);
	}
}

void LibraryManagementSystem::saveLibrarians() {
	ofstream librarianFile(LIBRARIAN_DATA_FILE);
	if (librarianFile.fail()) {
		cerr << endl << "Error opening book data file!" << endl;
		exit(1);
	}
	else {
		cout << endl << "Successfully opened book data file!" << endl << endl;
	}

	for (int i = 0; i < this->librarians.size(); i++) {
		librarianFile << this->librarians.at(i);
	}
}

bool LibraryManagementSystem::loginUser(string username, string password) {
	// Compare username and password to all in file
	for (int i = 0; i < readers.size(); i++) {
		// todo: Include librarians in this check
		User reader = readers.at(i);
		if ((reader.getUsername() == username) &&
			(reader.getPassword() == password)) {
			user = reader;
			return true;
		}
	}
	return false;
}

bool LibraryManagementSystem::compareBooksByPopularity(Book& book1, Book& book2) {
	return book1.getresCount() < book2.getresCount();
}

vector<Reader> LibraryManagementSystem::getReaders() {
	return this->readers;
}

vector<Book> LibraryManagementSystem::getBooks() {
	return this->books;
}

vector<Book> LibraryManagementSystem::searchBooks(LMSBookSearchOption searchOption, string searchValue) {
	vector<Book> result;
	for (int i = 0; i < this->books.size(); i++) {
		Book book = this->books.at(i);

		switch (searchOption) {
		case LMSBookSearchOption::SEARCH_BY_AUTHOR:
			if (searchValue == book.getAuthor()) {
				result.push_back(book);
			}
			break;
		case LMSBookSearchOption::SEARCH_BY_CATEGORY:
			if (searchValue == book.getCategory()) {
				result.push_back(book);
			}
			break;
		case LMSBookSearchOption::SEARCH_BY_ISBN:
			if (std::atoi(searchValue.c_str()) == book.getISBN()) {
				result.push_back(book);
			}
			break;
		case LMSBookSearchOption::SEARCH_BY_TITLE:
			if (searchValue == book.getTitle()) {
				result.push_back(book);
			}
			break;
		}
	}

	// todo: figure out why this isn't compiling
	// sort(result.begin(), result.end(), compareBooksByPopularity);
	return result;
}

void LibraryManagementSystem::displayGreeting() {
	cout << "-------------------------------------------------------------------" << endl;
	cout << "---------------------" << "Welcome to My Library!" << "------------------------" << endl;
	cout << "-------------------------------------------------------------------";

	//TODO: fix user.getUser() so that it outputs the user's name 
	cout << endl << endl << "Welcome back, " << user.getUsername() << endl << endl;
}

LMSMenuOption LibraryManagementSystem::promptMenuScreen() {
	cout << "Please choose:" << endl;
	cout << "\t\t" << LMSMenuOption::SEARCH_BOOKS			<< " -- Search Books" << endl;
	cout << "\t\t" << LMSMenuOption::BORROW_BOOKS			<< " -- Borrow Books" << endl;
	cout << "\t\t" << LMSMenuOption::RETURN_BOOKS			<< " -- Return Books" << endl;
	cout << "\t\t" << LMSMenuOption::RESERVE_BOOKS			<< " -- Reserve Books" << endl;
	cout << "\t\t" << LMSMenuOption::CANCEL_RESERVATION		<< " -- Cancel Reservations" << endl;
	cout << "\t\t" << LMSMenuOption::INFO					<< " -- My Information" << endl;
	cout << "\t\t" << LMSMenuOption::CHANGE_PASS			<< " -- Change Password" << endl;
	cout << "\t\t" << LMSMenuOption::LOG_OUT				<< " -- Log Out" << endl;

	int option;
	cout << "Please select an option: ";
	cin >> option;
	return (LMSMenuOption)option;
}

LMSBookSearchOption LibraryManagementSystem::promptBookSearchTypeScreen() {
	cout << "\n\nPlease choose the field you would like to search by:" << endl;
	cout << "\t\t" << LMSBookSearchOption::SEARCH_BY_ISBN << " - Search by ISBN" << endl;
	cout << "\t\t" << LMSBookSearchOption::SEARCH_BY_TITLE << " - Search by Title" << endl;
	cout << "\t\t" << LMSBookSearchOption::SEARCH_BY_AUTHOR << " - Search by Author" << endl;
	cout << "\t\t" << LMSBookSearchOption::SEARCH_BY_CATEGORY << " - Search by Category" << endl;

	int option;
	cout << "Please select an option: ";
	cin >> option;
	return (LMSBookSearchOption)option;
}