#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Copy.h"
using namespace std;

Copy::Copy() {
	this->setSince(-1);
}
Copy::Copy(Book b, int id) {
	this->book = b;
	this->id = id;
	this->start = -1;
	vector<int> temp = b.getIDs();
	temp.push_back(id);
	b.setIDs(temp);
	setAvail(true);
}
Book Copy::getBook() {
	return book;
}

void  Copy::setBook(Book b) {
	this->book = b;

}
void Copy::setStart() {
	this->start = (int)clock();        //set borrowStartTime to when the book is taken out in seconds
}
void Copy::resetStart() {
	this->start = -1;

}
int Copy::getStart() {

		return start;
}
void  Copy::setEnd(int end) {

		expiration = end;
}
int Copy::getEnd() {

		return expiration;
}

void Copy::setReader(string r) {
	this->reade = r;
}
void Copy::setReserver(string r) {
	this->reserver = r;
}
string Copy::getReader() {
	return reade;
}
string Copy::getReserver() {
	return reserver;
}
void Copy::setReserveDate(int r) {
	reservedate = r;
}
void Copy::setBorrowDate(int r) {
	borrowdate = r;
}
void Copy::setAvail(bool b) {
	this->available = b;
}
bool Copy::getAvail() {
	return available;
}
void Copy::search(vector<Copy>& borrow, istream& in){
	char c;
	in >> c;
}
void Copy::setExpireDate(int r) {
	expiredate = r;
}
int Copy::getBorrowDate() {
	return borrowdate;
}
int Copy::getReserveDate() {
	return reservedate;
}
int Copy::getExpireDate() {
	return expiredate;
}
void Copy::setSince(int s) {
	this->since = s;
}
int Copy::getSince() {
	return since;
}
void Copy::setID(int i) {
	id = i;
}
int Copy::getID() {
	return id;
}

queue<string> Copy::getReserveQueue() {
	return reserved;
}
void  Copy::setReserveQueue(queue<string> &r) {

	reserved = r;
}
