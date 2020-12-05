#include "LibraryManagementSystem.h"

LibraryManagementSystem::LibraryManagementSystem() {
	this->readers = this->loadReaders();
	this->copies = this->loadCopies();
	this->books = this->loadBooks();
	this->librarians = this->loadLibrarians();
	addCopiesToBooks();
	addCopiesToReaders();
}

void LibraryManagementSystem::addCopiesToBooks() {
	for (int i = 0; i < books.size(); i++) {
		Book* book = &books.at(i);
		for (int j = 0; j < copies.size(); j++) {
			Copy copy = copies.at(j);
			if (copy.getISBN() == book->getISBN()) {
				book->loadCopyIntoBook(copy);
			}
		}
	}
}

void LibraryManagementSystem::updateTime() {
	this->currentTimeSecs = Utils::getCurrentTimeSecs();
}

void LibraryManagementSystem::addCopiesToReaders() {
	for (int i = 0; i < readers.size(); i++) {
		Reader* reader = &readers.at(i);
		for (int j = 0; j < copies.size(); j++) {
			Copy copy = copies.at(j);
			if (copy.getReaderName() == reader->getUsername()) {
				reader->loadCopyIntoReader(copy);
			}
		}
	}
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

vector<Copy> LibraryManagementSystem::loadCopies() {
	ifstream copyInput(COPY_DATA_FILE);
	if (copyInput.fail()) {
		cerr << endl << "Error opening copies data file!" << endl;
		exit(1);
	}

	vector<Copy> copies;
	Copy copy;

	// Our data files always have a trailing line that we skip
	while (copyInput.eof() == 0 && copyInput.peek() != EOF) {
		copyInput >> copy;
		copies.push_back(copy);
	}
	copyInput.close();

	return copies;
}

void LibraryManagementSystem::saveReaders() {
	ofstream readerFile(READER_DATA_FILE);
	if (readerFile.fail()) {
		cerr << endl << "Error opening reader data file!" << endl;
		exit(1);
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

	for (int i = 0; i < this->books.size(); i++) {
		bookFile << this->books.at(i);
	}
	bookFile.close();
}

void LibraryManagementSystem::saveCopies() {
	ofstream copiesFile(COPY_DATA_FILE);
	if (copiesFile.fail()) {
		cerr << endl << "Error opening copies data file!" << endl;
		exit(1);
	}
	
	for (int i = 0; i < this->copies.size(); i++) {
		copiesFile << this->copies.at(i);
	}
	copiesFile.close();
}

void LibraryManagementSystem::saveLibrarians() {
	ofstream librarianFile(LIBRARIAN_DATA_FILE);
	if (librarianFile.fail()) {
		cerr << endl << "Error opening librarian data file!" << endl;
		exit(1);
	}

	for (int i = 0; i < this->librarians.size(); i++) {
		librarianFile << this->librarians.at(i);
	}
	librarianFile.close();
}

void LibraryManagementSystem::reserveBook(int isbn) {
	Reader* reader = findReader(user.getUsername());
	if (!reader->getOverdueCopies().empty()) {
		cout << "You cannot reserve a book while you have overdue copies! You have ";
		cout << reader->getOverdueCopies().size() << " overdue copies.";
	}

	Book* book = findBook(isbn);
	book->reserveFor(user.getUsername());
}

void LibraryManagementSystem::changePassword() {
	string newPassword;
	cout << "Enter new password: ";
	cin >> newPassword;
	cout << endl;
	User* user = findUser(this->user.getUsername());
	user->setPassword(newPassword);
	this->user = *user;
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

bool LibraryManagementSystem::compareBooksByPopularity(Book& book1, Book& book2) {
	return book1.getReservers() < book2.getReservers();
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
	for (int i = 0; i < this->readers.size(); i++) {
		if (this->readers.at(i).getUsername() == username) {
			return &this->readers.at(i);
		}
	}

	for (int i = 0; i < this->librarians.size(); i++) {
		if (this->librarians.at(i).getUsername() == username) {
			return &this->librarians.at(i);
		}
	}

	return nullptr;
}

void LibraryManagementSystem::cancelReservation(int isbn) {
	Book* book = findBook(isbn);
	book->removeFromReservationsIfPresent(user.getUsername());
}

void LibraryManagementSystem::searchForUser(string username) {
	vector<User> users = getAllUsers();
	for (int i = 0; i < users.size(); i++) {
		user = users.at(i);
		if (user.getUsername() == username) {
			cout << "Username: " << user.getUsername() << ", ";
			cout << "Password: " << user.getPassword() << ", ";
			cout << "Type: " << user.getUserTypeDisplay();
			if (user.isReader()) {
				Reader* reader = findReader(username);
				cout << ", User Copies: " << endl;
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
		Book* book = &books.at(i);
		if (isbn == book->getISBN()) {
			return book;
		}
	}
	return nullptr;
}

Copy* LibraryManagementSystem::findCopy(int copyId) {
	for (int i = 0; i < copies.size(); i++) {
		Copy* copy = &copies.at(i);
		if (copyId == copy->getId()) {
			return copy;
		}
	}
	return nullptr;
}

vector<Book> LibraryManagementSystem::getBooks() {
	return this->books;
}

Reader* LibraryManagementSystem::findReader(string username) {
	for (int i = 0; i < this->readers.size(); i++) {
		Reader* reader = &this->readers.at(i);
		if (reader->getUsername() == username) {
			return reader;
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

	sort(result.begin(), result.end(), compareBooksByPopularity);
	return result;
}

void LibraryManagementSystem::displayGreeting() {
	cout << "-------------------------------------------------------------------" << endl;
	cout << "---------------------" << "Welcome to My Library!" << "------------------------" << endl;
	cout << "-------------------------------------------------------------------";

	cout << endl << endl << "Welcome back, " << user.getUserTypeDisplay() << endl << endl;
}

LMSReaderMenuOption LibraryManagementSystem::promptReaderMenuScreen() {
	cout << "Please choose:" << endl;
	cout << "\t\t" << LMSReaderMenuOption::READER_SEARCH_BOOKS			<< " -- Search Books" << endl;
	cout << "\t\t" << LMSReaderMenuOption::READER_BORROW_BOOK			<< " -- Borrow Books" << endl;
	cout << "\t\t" << LMSReaderMenuOption::READER_RETURN_BOOK			<< " -- Return Books" << endl;
	cout << "\t\t" << LMSReaderMenuOption::READER_RESERVE_BOOK			<< " -- Reserve Books" << endl;
	cout << "\t\t" << LMSReaderMenuOption::READER_CANCEL_RESERVATION	<< " -- Cancel Reservations" << endl;
	cout << "\t\t" << LMSReaderMenuOption::READER_CHANGE_PASSWORD		<< " -- Change Password" << endl;
	cout << "\t\t" << LMSReaderMenuOption::READER_LOG_OUT				<< " -- Log Out" << endl;

	int option;
	cout << "Please select an option: ";
	cin >> option;
	return (LMSReaderMenuOption)option;
}

LMSLibrarianMenuOption LibraryManagementSystem::promptLibrarianMenuScreen() {
	cout << "\t\t" << LMSLibrarianMenuOption::LIBRARIAN_SEARCH_BOOKS		<< " -- Search Books" << endl;
	cout << "\t\t" << LMSLibrarianMenuOption::LIBRARIAN_ADD_BOOK			<< " -- Add Books" << endl;
	cout << "\t\t" << LMSLibrarianMenuOption::LIBRARIAN_DELETE_BOOK			<< " -- Delete Books" << endl;
	cout << "\t\t" << LMSLibrarianMenuOption::LIBRARIAN_SEARCH_USERS		<< " -- Search Users" << endl;
	cout << "\t\t" << LMSLibrarianMenuOption::LIBRARIAN_ADD_USER			<< " -- Add Users" << endl;
	cout << "\t\t" << LMSLibrarianMenuOption::LIBRARIAN_DELETE_USER			<< " -- Delete Users" << endl;
	cout << "\t\t" << LMSLibrarianMenuOption::LIBRARIAN_CHANGE_PASSWORD		<< " -- Change Password" << endl;
	cout << "\t\t" << LMSLibrarianMenuOption::LIBRARIAN_LOG_OUT				<< " -- Log Out" << endl;

	int option;
	cout << "Please select an option: ";
	cin >> option;
	return (LMSLibrarianMenuOption) option;
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
	saveCopies();
}

void LibraryManagementSystem::deleteUser(string username) {
	User* user = findUser(username);
	if (user == nullptr) {
		cout << "No user exists with username \"" << username << "\"" << endl;
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
			book->removeFromReservationsIfPresent(reader->getUsername());
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
	cout << "Successfully deleted user!" << endl << endl;
}

void LibraryManagementSystem::deleteCopyFromLibrary(int copyId) {
	Copy* copy = findCopy(copyId);
	if (copy == nullptr) {
		cout << "The provided copy ID does not exist." << endl;
		return;
	}

	if (!copy->isAvailable()) {
		cout << "The copy is already lent out and therefore unavailable." << endl;
		return;
	}

	int isbn = copy->getISBN();
	Book* book = findBook(isbn);
	book->removeCopy(copyId);

	vector<Copy> updatedCopies;
	for (int i = 0; i < copies.size(); i++) {
		// Remove the copy with this ID from the list
		if (copies.at(i).getId() == copyId) {
			continue;
		}
		updatedCopies.push_back(copies.at(i));
	}
	this->copies = updatedCopies;

	// Delete this book from the system
	if (book->getCopyCount() == 0) {
		vector<Book> updatedBooks;
		for (int i = 0; i < books.size(); i++) {
			if (books.at(i).getISBN() == isbn) {
				continue;
			}
			updatedBooks.push_back(books.at(i));
		}
		this->books = updatedBooks;
	}
	cout << "Successfully deleted copy from library!" << endl << endl;
}

void LibraryManagementSystem::addCopyToLibrary() {
	int isbn;
	string title, author, category;
	cout << "\nEnter the ISBN: ";
	cin >> isbn;

	Book* existingBook = findBook(isbn);
	// If the book doesn't exist, create it
	if (existingBook = nullptr) {
		Book newBook;
		newBook.setISBN(isbn);

		cout << "\nEnter the title: ";
		cin >> title;
		newBook.setTitle(title);

		cout << "\nEnter the author: ";
		cin >> author;
		newBook.setAuthor(author);

		cout << "\nEnter the category: ";
		cin >> category;
		newBook.setCategory(category);
		this->books.push_back(newBook);
	}

	Book* book = findBook(isbn);
	Copy copy = book->addCopy();
	this->copies.push_back(copy);
	cout << "Successfully added copy to library!" << endl << endl;
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
	cout << "Successfully created new user!" << endl << endl;
}

int LibraryManagementSystem::getUniqueCopyId() {
	int maxId = 0;
	for (int i = 0; i < this->copies.size(); i++) {
		Copy copy = copies.at(i);
		maxId = max(maxId, copy.getId());
	}
	return maxId + 1;
}

void LibraryManagementSystem::renewCopy(int copyId) {
	// if the book is overdue, you cant renew it
	Copy* copy = findCopy(copyId);
	if (copy == nullptr) {
		cout << "You cannot renew a book that does not exist!" << endl;
		return;
	}

	if (copy->getReaderName() != this->user.getUsername()) {
		cout << "You cannot renew a copy you do not have checked out!" << endl;
	}

	Reader* reader = findReader(user.getUsername());
	if (!reader->getOverdueCopies().empty()) {
		cout << "You cannot renew a copy while you have overdue copies!" << endl;
		return;
	}

	Book* book = findBook(copy->getISBN());
	if (!book->getReservers().empty()) {
		cout << "You cannot renew a book that has reservations!" << endl;
		return;
	}

	// To renew the copy, simply return and re-borrow it
	returnCopy(copyId);
	borrowCopy(copyId);
}

void LibraryManagementSystem::returnCopy(int copyId) {
	Reader* reader = findReader(user.getUsername());
	
	bool hasCopy = false;
	for (int i = 0; i < reader->getBorrowedCopies().size(); i++) {
		if (reader->getBorrowedCopies().at(i).getId() == copyId) {
			hasCopy = true;
		}
	}

	if (!hasCopy) {
		cout << "You cannot return a copy you do not have!" << endl;
		return;
	}

	reader->deleteCopy(copyId);
	Copy* copy = findCopy(copyId);

	reader->increasePenaltyIfOverdue(copy);

	copy->resetReaderFields();
	findBook(copy->getISBN())->returnCopyToLibrary(copyId);
	cout << "\nReturned copy " << copyId << "!" << endl;

}

void LibraryManagementSystem::borrowCopy(int copyId) {
	Reader* reader = findReader(user.getUsername());
	
	// Don't allow users with overdue copies to borrow another copy
	if (reader->getOverdueCopies().size() > 0) {
		cout << "\nYou cannot borrow a copy while you have overdue copies! You have ";
		cout << reader->getOverdueCopies().size() << "overdue copies." << endl;
		return;
	}

	// Don't let the user borrow a book if they have max copies already
	if (reader->getBorrowedCopies().size() == reader->getMaxCopies()) {
		cout << "\nYou already have the maximum amount of copies borrowed! You have ";
		cout << reader->getBorrowedCopies().size() << " borrowed copies." << endl;
		return;
	}

	Copy* copy = findCopy(copyId);
	if (copy == nullptr) {
		cout << "No copy exists with ID " << copyId << "!" << endl;
		return;
	}

	if (!copy->isAvailable()) {
		cout << "This copy is currently checked out." << endl;
		return;
	}

	Book* book = findBook(copy->getISBN());
	if (!book->isBorrowableFor(reader->getUsername())) {
		cout << "This copy has already been reserved." << endl;
		return;
	}

	// Max borrow days is reduced by 1 day for every 20 reservations on the book being borrowed
	int borrowDaysReservationOffset = book->getReservers().size() / 20;
	// Use max(1, val) to prevent negative values
	int maxBorrowDays = max(1, reader->getMaxBorrowDays() - borrowDaysReservationOffset);
	
	copy->setReaderName(reader->getUsername());
	int currentTime = Utils::getCurrentTimeSecs();
	copy->setBorrowDate(currentTime);
	copy->setExpirationDate(currentTime + (5 * maxBorrowDays)); // Each day is 5 seconds
	book->borrowCopyFor(reader, copy);
	book->removeFromReservationsIfPresent(reader->getUsername());
	cout << "\nSuccessfully borrowed copy ID " << copyId << " of book: " << endl;
	cout << "\t";
	book->print();
	cout << endl;
}