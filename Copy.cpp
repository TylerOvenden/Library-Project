#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Copy.h"
#include "Student.h"
using namespace std;

Copy::Copy() {


}
void Copy::setReader(string r) {
	reader = r;
}

void Copy::setReserver(string r) {
	reserver = r;
}
string Copy::getReader() {

	return reader;
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
	return expireDate;
}



