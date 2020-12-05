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

void LibraryManagementSystem::changePassword() {
	string newPassword;
	cout << "Enter new password: ";
	cin >> newPassword;
	cout << endl;
	this->user.setPassword(newPassword);
	cout << "Password changed successfully!" << endl;
}

bool LibraryManagementSystem::loginUser(string username, string password) {
	// Compare username and password of all students and teachers
	for (int i = 0; i < readers.size(); i++) {
		User reader = readers.at(i);
		if ((reader.getUsername() == username) &&
			(reader.getPassword() == password)) {
			this->user = reader;
			return true;
		}
	}
	// Compare username and password of all librarians
	for (int i = 0; i < this->librarians.size(); i++){
	    User librarian = this->librarians.at(i);
	    if(librarian.getUsername() == username &&
	       librarian.getPassword() == password){
	        this->user = librarian;
	        return true;
	    }
	}
	return false;
}

User LibraryManagementSystem::getUser() {
    return this->user;
}

// todo get this working
bool LibraryManagementSystem::compareBooksByPopularity(Book& book1, Book& book2) {
	// return book1.getresCount() < book2.getresCount();
	return false;
}

vector<Reader> LibraryManagementSystem::getReaders() {
	return this->readers;
}

void LibraryManagementSystem::setReaders(vector<Reader> readers){
	this->readers = readers;
}

vector<Librarian> LibraryManagementSystem::getLibrarian() {
    return this->librarians;
}

vector<User> LibraryManagementSystem::getAllUsers() {
	vector<User> users;
    for(int i = 0; i < readers.size(); i++){
        users.push_back(readers.at(i));
    }
    for(int i = 0; i < librarians.size(); i++){
        users.push_back(librarians.at(i));
    }
    return users;
}

User* LibraryManagementSystem::findUser(string username) {
	vector<User> users = getAllUsers();
	for (int i = 0; i < users.size(); i++) {
		User user = users.at(i);
		if (user.getUsername() == username) {
			return &user;
		}
	}
	return nullptr;
}

void LibraryManagementSystem::searchForUser(string username) {
	vector<User> users = getAllUsers();
	for (int i = 0; i < users.size(); i++) {
		user = users.at(i);
		if (user.getUsername() == username) {
			cout << "Username: " << user.getUsername() << ", ";
			cout << "Password: " << user.getPassword();
			if (user.isReader()) {
				Reader* reader = findReader(username);
				cout << ", Type: " << user.getUserTypeDisplay() << endl;
				cout << "User Copies: " << endl;
				for (int i = 0; i < reader->getBorrowedCopies().size(); i++) {
					reader->getBorrowedCopies().at(i).print();
				}
			}
			cout << endl;
			return;
		}
	}
	cout << "Username \"" << username << "\" doesn't exist!" << endl;
}

Book* LibraryManagementSystem::findBook(int isbn) {
	for (int i = 0; i < books.size(); i++) {
		Book book = books.at(i);
		if (isbn == book.getISBN()) {
			return &book;
		}
	}
	return nullptr;
}

vector<Book> LibraryManagementSystem::getBooks() {
	return this->books;
}

Reader* LibraryManagementSystem::findReader(string username) {
	for (int i = 0; i < this->readers.size(); i++) {
		Reader reader = this->readers.at(i);
		if (reader.getUsername() == username) {
			return &reader;
		}
	}
	return nullptr;
}

void LibraryManagementSystem::displayBookSearchResultsFor(LMSBookSearchOption searchOption, string searchValue) {
	vector<Book> books = this->searchBooks(searchOption, searchValue);
	
	if (books.size()) {
		cout << "\nSearch results:\n";
		for (int i = 0; i < books.size(); i++) {
			cout << "\t";
			books.at(i).print();
		};
		cout << "\n";
	} else {
		cout << "\nNo results found!\n" << endl;
	}
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

	cout << endl << endl << "Welcome back, " << user.getUserTypeDisplay() << endl << endl;
}

LMSStudentMenuOption LibraryManagementSystem::promptReaderMenuScreen() {
	cout << "Please choose:" << endl;
	cout << "\t\t" << LMSStudentMenuOption::SEARCH_BOOKS			<< " -- Search Books" << endl;
	cout << "\t\t" << LMSStudentMenuOption::BORROW_BOOKS			<< " -- Borrow Books" << endl;
	cout << "\t\t" << LMSStudentMenuOption::RETURN_BOOKS			<< " -- Return Books" << endl;
	cout << "\t\t" << LMSStudentMenuOption::RESERVE_BOOKS			<< " -- Reserve Books" << endl;
	cout << "\t\t" << LMSStudentMenuOption::CANCEL_RESERVATION		<< " -- Cancel Reservations" << endl;
	cout << "\t\t" << LMSStudentMenuOption::MY_INFORMATION			<< " -- My Information" << endl;
	cout << "\t\t" << LMSStudentMenuOption::CHANGE_PASSWORD			<< " -- Change Password" << endl;
	cout << "\t\t" << LMSStudentMenuOption::LOG_OUT					<< " -- Log Out" << endl;
}

LMSLibrarianMenuOption LibraryManagementSystem::promptLibrarianMenuScreen() {
	cout << "\t\t" << LMSLibrarianMenuOption::SEARCH_BOOKS			<< " -- Search Books" << endl;
	cout << "\t\t" << LMSLibrarianMenuOption::ADD_BOOK				<< " -- Add Books" << endl;
	cout << "\t\t" << LMSLibrarianMenuOption::DELETE_BOOK			<< " -- Delete Books" << endl;
	cout << "\t\t" << LMSLibrarianMenuOption::SEARCH_USERS			<< " -- Search Users" << endl;
	cout << "\t\t" << LMSLibrarianMenuOption::ADD_USER				<< " -- Add Users" << endl;
	cout << "\t\t" << LMSLibrarianMenuOption::DELETE_USER			<< " -- Delete Users" << endl;
	cout << "\t\t" << LMSLibrarianMenuOption::MY_INFORMATION		<< " -- My Information" << endl;
	cout << "\t\t" << LMSLibrarianMenuOption::CHANGE_PASSWORD		<< " -- Change Password" << endl;
	cout << "\t\t" << LMSLibrarianMenuOption::LOG_OUT				<< " -- Log Out" << endl;

	int option;
	cout << "Please select an option: ";
	cin >> option;
	return (LMSLibrarianMenuOption)option;
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

void LibraryManagementSystem::saveAll() {
	saveReaders();
	saveLibrarians();
	saveBooks();
	// todo: saveCopies();
}

void LibraryManagementSystem::deleteUser(string username) {
	// Make sure the user exists
	User* user = findUser(username);
	if (user != nullptr) {
		cout << "A user with username \"" << username << "\" already exists." << endl;
		return;
	}

	// Check that the user is not deleting themselves
	if (this->user.getUsername() == user->getUsername()) {
		cout << "You cannot delete yourself!" << endl;
		return;
	}

	if (user->isReader()) {
		Reader* reader = findReader(username);
		
		// Don't delete if they have any copies
		if (!reader->getBorrowedCopies().empty()) {
			cout << "You cannot delete a user that still has copies - user has ";
			cout << reader->getBorrowedCopies().size() << " copies!";
			return;
		}
		
		// When deleting, remove all reservations
		for (int i = 0; i < reader->getReservedISBNs().size(); i++) {
			int reservedISBN = reader->getReservedISBNs().at(i);
			Book* book = findBook(reservedISBN);
			book->deleteReservationFor(reader->getUsername());
		}

		// Remove the reader from the system
		vector<Reader> readers;
		for (int i = 0; i < this->readers.size(); i++) {
			// If the reader is the one we're deleting then skip them
			if (reader->getUsername() == this->readers.at(i).getUsername()) {
				continue;
			}
			readers.push_back(this->readers.at(i));
		}
		this->readers = readers;

	} else {
		// Remove the librarian from the system
		vector<Librarian> librarians;
		for (int i = 0; i < this->librarians.size(); i++) {
			// If the librarian is the one we're deleting then skip them
			if (username == this->librarians.at(i).getUsername()) {
				continue;
			}
			librarians.push_back(this->librarians.at(i));
		}
		this->librarians = librarians;
	}

}

void LibraryManagementSystem::addUser(string username, string password) {
	cout << "\n\nPlease choose the user-type you would like to create:" << endl;
	cout << "\t\t" << UserType::STUDENT << " - Student" << endl;
	cout << "\t\t" << UserType::TEACHER << " - Teacher" << endl;
	cout << "\t\t" << UserType::LIBRARIAN << " - Librarian" << endl;
	
	int type;
	cin >> type;
	if (type != STUDENT && type != TEACHER && type != LIBRARIAN) {
		cout << type << " is not a valid user-type!";
		return;
	}

	if (findUser(username) != nullptr) {
		cout << "A user with username \"" << username << "\" already exists." << endl;
		return;
	}

	switch (type) {
	case LIBRARIAN: {
		Librarian* librarian = new Librarian(username, password);
		librarians.push_back(*librarian);
		break;
	}
	case STUDENT: {
		Student* student = new Student(username, password);
		readers.push_back(*student);
	}
	case TEACHER: {
		Teacher* teacher = new Teacher(username, password);
		readers.push_back(*teacher);
	}
	}
}

int LibraryManagementSystem::getUniqueCopyId() {
	/*int maxId = 0;
	for (int i = 0; i < this->copies.size(); i++) {
		Copy copy = copies.at(i);
		maxId = max(maxId, copy.getId());
	}
	return maxId + 1;*/
}

void LibraryManagementSystem::borrowCopy(int copyId) {

}