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

void Book::addCopy() {
	int maxId = 0;
	for (int i = 0; i < copies.size(); i++) {
		maxId = max(maxId, copies.at(i).getId());
	}
	Copy* newCopy = new Copy(maxId + 1, this);
	this->copies.push_back(*newCopy);
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

void Book::addReservations(Reader reader) {
}

queue<Reader> Book::getReservations() {
	return this->reservations;
}

void Book::addReservations(Reader reader) {
	this->reservations.push(reader);
}

void Book::reserveFor(Reader reader) {
	long currentTimeMs = Utils::getCurrentTimeMs();
	this->reservations.push(reader);
	this->reservationTimes.push(currentTimeMs);
}

void Book::returnCopyToLibrary(Copy copy) {
	copy.resetReaderFields();
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

		copyIds += copy.getId();
		if (i != this->copies.size() - 1) {
			cout << ", ";
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

