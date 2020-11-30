#include "LibraryManagementSystem.h"

LibraryManagementSystem::LibraryManagementSystem() {
	this->readers = this->loadReaders();
	this->books = this->loadBooks();
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
	ofstream bookFile("book.txt");
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

vector<Reader> LibraryManagementSystem::getReaders() {
	return this->readers;
}

vector<Book> LibraryManagementSystem::getBooks() {
	return this->books;
}

void LibraryManagementSystem::displayWelcomeScreen() {
	cout << "-------------------------------------------------------------------" << endl;
	cout << "---------------------" << "Welcome to My Library!" << "------------------------" << endl;
	cout << "-------------------------------------------------------------------";

	//TODO: fix user.getUser() so that it outputs the user's name 
	cout << endl << endl << "Welcome back, " << user.getUsername() << endl << endl;

	cout << "Please choose:" << endl;
	//cout << "\t\t" << "1 -- Search Books" << endl;
	cout << "\t\t" << "2 -- Borrow Books" << endl;
	cout << "\t\t" << "3 -- Return Books" << endl;
	//cout << "\t\t" << "4 -- Reserve Books" << endl;
	//cout << "\t\t" << "5 -- Cancel Reservations" << endl;
	//cout << "\t\t" << "6 -- My Information" << endl;
	//cout << "\t\t" << "7 -- Change Password" << endl;
	cout << "\t\t" << "0 -- Log Out" << endl;

}
