#include "Copy.h"

Copy::Copy() {
}

Copy::Copy(int id, Book* book) {
	this->id = id;
	this->book = book;
}

void Copy::setId(int id) {
	this->id = id;
}

int Copy::getId() {
	return this->id;
}

void Copy::setBorrowDate(long borrowDate)
{
}

void Copy::setExpiration(long expirationDate)
{
}

Book* Copy::getBook() {
	return this->book;
}

void Copy::setReader(string reader) {
	this->reader = reader;
}

string Copy::getReader() {
	return this->reader;
}

bool Copy::isAvailable() {
	// If the value for reader is empty it means that no reader is assigned to this copy, ie it is available
	if (this->reader == "") {
		return true;
	}
	return false;
}

bool Copy::isOverdue() {
	// todo implement timestamp comparison
	return false;
}

long Copy::getBorrowDate() {
	return this->borrowDate;
}

// todo: find better name
void Copy::resetReaderFields() {
	this->setReader("");
	this->setBorrowDate(0);
	this->setExpiration(0);
}

void Copy::borrowFor(string username, int maxBorrowDays) {

}

void Copy::addReservation(string reserver) {
	long currentTimeMs = Utils::getCurrentTimeMs();
	
}

long Copy::getExpirationDate() {
	return this->expirationDate;
}

