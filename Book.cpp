#include "Book.h"

using namespace std;

Book::Book() {
}

Book::Book(int isbn, string title, string author, string category, int favor) {
	this->isbn = isbn;
	this->title = title;
	this->author = author;
	this->category = category;
	this->favor = favor;
}

int Book::getISBN() {
	return this->isbn;
}

void Book::setISBN(int isbn) {
	this->isbn = isbn;
}

string Book::getTitle() {
	return this->title;
}

void Book::setTitle(string title) {
	this->title = title;
}

string Book::getAuthor() {
	return this->author;
}

void Book::setAuthor(string author) {
	this->author = author;
}

string Book::getCategory() {
	return this->category;
}

void Book::setCategory(string category) {
	this->category = category;
}

void Book::loadCopyIntoBook(Copy copy) {
	this->copies.push_back(copy);
}

Copy Book::addCopy() {
	int maxId = 0;
	for (int i = 0; i < copies.size(); i++) {
		maxId = max(maxId, copies.at(i).getId());
	}
	Copy* newCopy = new Copy(maxId + 1, this->isbn);
	this->copies.push_back(*newCopy);
	return *newCopy;
}

void Book::removeCopy(int copyIdToRemove) {
	vector<Copy> updatedCopies; 
	for (int i = 0; i < copies.size(); i++) {
		Copy copy = copies.at(i);
		if (copy.getId() != copyIdToRemove) {
			updatedCopies.push_back(copy);
		}
	}
	this->copies = updatedCopies;
}

int Book::getCopyCount() {
	return this->copies.size();
}

std::vector<Copy> Book::getCopies() {
	return this->copies;
}

int Book::getFavor() {
	return this->favor;
}

void Book::setFavor(int favor) {
	this->favor = favor;
}

void Book::reserveFor(string username) {
	int currentTime = Utils::getCurrentTimeSecs();
	this->reservers.push_back(username);
	this->reservationDates.push_back(currentTime);
}

void Book::returnCopyToLibrary(int copyId) {
	for (int i = 0; i < this->copies.size(); i++) {
		if (this->copies.at(i).getId() == copyId) {
			this->copies.at(i).resetReaderFields();
		}
	}
}

Copy* Book::borrowCopy(Reader reader) {
	Copy* copyToBorrow = nullptr;
	for (int i = 0; i < this->copies.size(); i++) {
		Copy copy = this->copies.at(i);
		if (copy.isAvailable()) {
			copyToBorrow = &this->copies.at(i);
		}
	}

	if (copyToBorrow != nullptr) {
		copyToBorrow->borrowFor(reader.getUsername(), reader.getMaxBorrowDays());
	}

	return copyToBorrow;
}

string Book::getFormattedCopyIds() {
	string copyIds;
	for (int i = 0; i < this->copies.size(); i++) {
		Copy copy = copies.at(i);
		if (!copy.isAvailable()) {
			continue;
		}

		copyIds += to_string(copy.getId());
		if (i != this->copies.size() - 1) {
			copyIds += ", ";
		}
	}
	return copyIds;
}

void Book::print() {
	cout << "Title: " << this->getTitle() << ", ";
	cout << "Category: " << this->getCategory() << ", ";
	cout << "Author: " << this->getAuthor() << ", ";
	cout << "Favor: " << this->getFavor() << ", ";
	cout << "ISBN: " << this->getISBN() << ", ";
	cout << "Available Copy Ids: " << this->getFormattedCopyIds() << endl;
}

void Book::removeFromReservationsIfPresent(string username) {
	vector<int> reservationDates;
	vector<string> reservers;

	for (int i = 0; i < this->reservers.size(); i++) {
		// Remove the reservation from the system if it belongs to the provided user
		if (this->reservers.at(i) == username) {
			continue;
		}
		reservers.push_back(this->reservers.at(i));
		reservationDates.push_back(this->reservationDates.at(i));
	}
	this->reservers = reservers;
	this->reservationDates = reservationDates;
}

vector<string> Book::getReservers() {
	return this->reservers;
}

void Book::setReservers(vector<string> reservers) {
	this->reservers = reservers;
}

bool Book::isBorrowableFor(string username) {
	vector<Copy> available = this->getAvailableCopies();
	if (available.size() > reservers.size()) {
		return true;
	}
	
	bool isReserver = false;
	for (int i = 0; i < reservers.size(); i++) {
		if (reservers.at(i) == username) {
			isReserver = true;
		}
	}

	if (!isReserver) {
		return false;
	} else {
		for (int i = 0; i < available.size(); i++) {
			if (reservers.at(i) == username) {
				return true;
			}
		}
		return false;
	}
}

void Book::borrowCopyFor(Reader* reader, Copy* copy) {
	reader->borrow(*copy);
	for (int i = 0; i < copies.size(); i++) {
		if (copy->getId() == copies.at(i).getId()) {
			copies[i] = *copy;
			break;
		}
	}
}

vector<int> Book::getReservationDates(){
	return this->reservationDates;
}

void Book::setReservationDates(vector<int> reservationDates) {
	this->reservationDates = reservationDates;
}

vector<Copy> Book::getAvailableCopies() {
	vector<Copy> available;
	for (int i = 0; i < copies.size(); i++) {
		if (copies.at(i).isAvailable()) {
			available.push_back(copies.at(i));
		}
	}
	return available;
}

// 2. Time system with integer
// 3. Various features