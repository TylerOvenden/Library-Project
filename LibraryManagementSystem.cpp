#include "LibraryManagementSystem.h"

LibraryManagementSystem::LibraryManagementSystem() {
	this->readers = this->loadReaders();
	this->books = this->loadBooks();
	this->librarians = this->loadLibrarians();
	this->copies = this->loadCopies();
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
	int i = 0;
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


	Book book;

	// Our data files always have a trailing line that we skip
	while (bookInput.eof() == 0 && bookInput.peek() != EOF) {
		bookInput >> book;

		books.push_back(book);
	}
	bookInput.close();
	


	return books;
}
//temp created of copies manually, delete when fixed
vector<Copy> LibraryManagementSystem::loadCopies() { 
	Copy c1 = Copy(books.at(0), 945);
	Copy c2 = Copy(books.at(1), 1245);
	Copy c3 = Copy(books.at(2), 983);
	Copy c4 = Copy(books.at(0), 500);
	copies.push_back(c1);
	copies.push_back(c2);
	copies.push_back(c3);
	copies.push_back(c4);


	return copies;


}
//uncomment this 
/*
vector<Copy> LibraryManagementSystem::loadCopies() {
	ifstream copyInput(COPIES_DATA_FILE);
	if (copyInput.fail()) {
		cerr << endl << "Error opening book data file!" << endl;
		exit(1);
	}


	Book book;
	while (copyInput.eof() == 0 && copyInput.peek() != EOF) {
		int isbn;
		string title;
		string author;
		string category;
		int copyCount;
		int favor;
		int id;
		copyInput >> isbn >> title >> author >> category >> copyCount >> favor >> id;
		book.setISBN(isbn);
		book.setTitle(title);
		book.setAuthor(author);
		book.setCategory(category);
		book.setCopyCount(copyCount);
		book.setFavor(favor);
		for (int i = 0; i < books.size(); i++) {
			if (isbn = books.at(i).getISBN()) {
				book = books.at(i);
			}

		}
		Copy c = Copy(book, id);
		copies.push_back(c);
		// Our data files always have a trailing line that we skip

	}
		copyInput.close();

		cout << "size: " << copies.size() << endl;
		for (int i = 0; i < copies.size(); i++)
		{
			copies.at(i).getBook().print();
			cout << copies.at(i).getID();
		}

		return copies;
	
}



*/
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
	readerFile.close();
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
		bookFile.close();
	}

	void LibraryManagementSystem::saveLibrarians() {
		ofstream librarianFile(LIBRARIAN_DATA_FILE);
		if (librarianFile.fail()) {
			cerr << endl << "Error opening librarian data file!" << endl;
			exit(1);
		}
		else {
			cout << endl << "Successfully opened librarian data file!" << endl << endl;
		}

		for (int i = 0; i < this->librarians.size(); i++) {
			librarianFile << this->librarians.at(i);
		}
		librarianFile.close();
	}


bool LibraryManagementSystem::loginUser(string username, string password) {
	// Compare username and password of students and teachers to see if they match
	for (int i = 0; i < readers.size(); i++) {
		
		User reader = readers.at(i);
		if ((reader.getUsername() == username) &&
			(reader.getPassword() == password)) {
			user = reader;
			/*  test part*/
			Reader r = readers.at(i);
			//r.addCopy(113, copies);
			vector<Copy> tem = r.getBorrow();
			currentReader = readers.at(i);
			for (int i = 0; i < tem.size(); i++)
			{
				tem.at(i).getBook().print();
			}

			return true;
		}
	}
	//Compare username and password of all librarians
	for (int i = 0; i < this->librarians.size(); i++) {
		User librarian = this->librarians.at(i);
		if (librarian.getUsername() == username &&
			librarian.getPassword() == password) {
			this->user = librarian;
			return true;
		}
	}
	
	

	return false;
}
User LibraryManagementSystem::getUser() {
	return this->user;
}
bool LibraryManagementSystem::compareBooksByPopularity(Book& book1, Book& book2) {
	return book1.getresCount() < book2.getresCount();
}

vector<Reader> LibraryManagementSystem::getReaders() {
	return this->readers;
}
void LibraryManagementSystem::setReaders(vector<Reader> readers) {
	this->readers.clear();
	for (int i = 0; i < readers.size(); i++) {
		this->readers.push_back(readers.at(i));
	}
}
vector<Librarian> LibraryManagementSystem::getLibrarian() {
	return this->librarians;
}
vector<User> LibraryManagementSystem::getAllUsers() {
	this->allUsers.clear();
	for (int i = 0; i < readers.size(); i++) {
		allUsers.push_back(readers.at(i));
	}
	for (int i = 0; i < librarians.size(); i++) {
		allUsers.push_back(librarians.at(i));
	}
	return allUsers;
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

	cout << endl << endl << "Welcome back, " << this->user.getUserTypeString() << "\n" << endl;
}

LMSMenuOption LibraryManagementSystem::promptMenuScreen() {
	cout << "Please choose:" << endl;
	cout << "\t\t" << LMSMenuOption::SEARCH_BOOKS << " -- Search Books" << endl;
	cout << "\t\t" << LMSMenuOption::BORROW_BOOKS << " -- Borrow Books" << endl;
	cout << "\t\t" << LMSMenuOption::RETURN_BOOKS << " -- Return Books" << endl;
	cout << "\t\t" << LMSMenuOption::RESERVE_BOOKS << " -- Reserve Books" << endl;
	cout << "\t\t" << LMSMenuOption::CANCEL_RESERVATION << " -- Cancel Reservations" << endl;
	cout << "\t\t" << LMSMenuOption::INFO << " -- My Information" << endl;
	cout << "\t\t" << LMSMenuOption::CHANGE_PASS << " -- Change Password" << endl;
	cout << "\t\t" << LMSMenuOption::LOG_OUT << " -- Log Out" << endl;
	int id;
	int option;
	//check if any books are overdue, comment this out if it makes it hard to test code 
	//time it takes for a book to be overdue very fast
	currentReader.findOverdue(copies);
	cout << "time: "  <<  (int)clock() << endl;
	cout << "Please select an option: ";
	cin >> option;
	if (option == BORROW_BOOKS) {
	
		cout << "enter the id of copy";
		cin >> id;

		currentReader.addCopy(id, copies);
		vector<Copy> tem = currentReader.getBorrow();
		for (int i = 0; i < tem.size(); i++)
		{
			tem.at(i).getBook().print();
		}

	}
	else if (option == RETURN_BOOKS) {

		cout << "enter the id of copy";
		cin >> id;

		currentReader.deleteCopy(id, copies);
		vector<Copy> tem = currentReader.getBorrow();
		for (int i = 0; i < tem.size(); i++)
		{
			tem.at(i).getBook().print();
		}

	}
	else if (option == RESERVE_BOOKS) {

		cout << "enter the id of copy";
		cin >> id;

		currentReader.reserveCopy(id, copies);
		vector<Copy> tem = currentReader.getReserve();
		for (int i = 0; i < tem.size(); i++)
		{
			tem.at(i).getBook().print();
		}


	}
	return (LMSMenuOption)option;
}
LMSMenuOptionLibrarian LibraryManagementSystem::promptLibrarianScreen() {
	cout << "Please choose:" << endl;
	cout << "\t\t" << LMSMenuOptionLibrarian::SEARCH_BOOKS_LIBRARIAN << " -- Search Books" << endl;
	cout << "\t\t" << LMSMenuOptionLibrarian::ADD_BOOKS_LIBRARIAN << " -- Aprompt odd Books" << endl;
	cout << "\t\t" << LMSMenuOptionLibrarian::DELETE_BOOKS_LIBRARIAN << " -- Delete Books" << endl;
	cout << "\t\t" << LMSMenuOptionLibrarian::SEARCH_USERS_LIBRARIAN << " -- Search Users" << endl;
	cout << "\t\t" << LMSMenuOptionLibrarian::ADD_USERS_LIBRARIAN << " -- Add Users" << endl;
	cout << "\t\t" << LMSMenuOptionLibrarian::DELETE_USERS_LIBRARIAN << " -- Delete Users" << endl;
	cout << "\t\t" << LMSMenuOptionLibrarian::MY_INFORMATION_LIBRARIAN << " -- My Information" << endl;
	cout << "\t\t" << LMSMenuOptionLibrarian::CHANGE_PASSWORD_LIBRARIAN << " -- Change Password" << endl;
	cout << "\t\t" << LMSMenuOptionLibrarian::LOG_OUT_LIBRARIAN << " -- Log Out" << endl;

	int option;
	cout << "Please select an option: ";
	cin >> option;
	return (LMSMenuOptionLibrarian)option;

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