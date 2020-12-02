#include "Book.h"

using namespace std;

Book::Book() {
}

Book::Book(int isbn, string title, string author, string category, int copyCount, int favor) {
	this->isbn = isbn;
	this->title = title;
	this->author = author;
	this->category = category;
	this->copyCount = copyCount;
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

int Book::getCopyCount() {
	return this->copyCount;
}

void Book::setCopyCount(int copyCount) {
	this->copyCount = copyCount;
}

int Book::getFavor() {
	return this->favor;
}


int Book::getFavor() {
	return this->favor;
}

//adds id of copy when another copy of book is added
void Book::addCopy(int id) {

	copyIDs.push_back(id);

}

void Book::print() {

	cout << getAuthor() << ", " << getTitle() << ", " << getCategory() <<  ", " << getISBN()  << endl;

	cout << "ids of copies: " << endl;
	//print the ids for copies
	for (int i = 0; i < copyIDs.size(); i++)
		std::cout << copyIDs.at(i) << ' ';
}
void Book:: setIDs(vector<int> t) {
	this->copyIDs = t;

}
std::vector<int> Book::getIDs() {
	return copyIDs;

}
