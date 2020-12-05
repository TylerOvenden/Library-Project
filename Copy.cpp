#include "Copy.h"

Copy::Copy() {
}

Copy::Copy(int id, int isbn) {
	this->id = id;
	this->isbn = isbn;
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

void Copy::setExpirationDate(long expirationDate)
{
}

int Copy::getISBN() {
	return this->isbn;
}

void Copy::print() {
	cout << this->isbn << ", ";
	cout << this->id << ", ";
	cout << this->reader << ", ";
	cout << this->borrowDate << ", ";
	cout << this->expirationDate << endl;
}

void Copy::setReaderName(string reader) {
	this->reader = reader;
}

string Copy::getReaderName() {
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
	this->setReaderName("");
	this->setBorrowDate(0);
	this->setExpirationDate(0);
}

void Copy::borrowFor(string username, int maxBorrowDays) {
	this->reader = username;
	
	long currentTimeMs = Utils::getCurrentTimeMs();
	this->borrowDate = currentTimeMs;
	this->expirationDate = currentTimeMs + (maxBorrowDays * 24 * 60 * 60 * 1000);
}

long Copy::getExpirationDate() {
	return this->expirationDate;
}

