#include "Reader.h"

Reader::Reader() {}

void Reader::setReaderType(ReaderType type) {
	this->type = type;
}

ReaderType Reader::getReaderType() {
	return this->type;
}

void Reader::setPenalty(int penalty) {
	this->penalty = penalty;
}

int Reader::getPenalty(){
	return this->penalty;
}

void Reader::setMaxCopies(int maxCopies) {
	this->maxCopies = maxCopies;
}

int Reader::getMaxCopies() {
	return this->maxCopies;
}

void Reader::setMaxBorrowDays(int maxBorrowDays) {
	this->maxBorrowDays = maxBorrowDays;
}

int Reader::getMaxBorrowDays() {
	return this->maxBorrowDays;
}
