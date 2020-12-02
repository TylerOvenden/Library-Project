#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Copy.h"
#include "Reader.h"
using namespace std;

Copy::Copy() {

	this->setSince(-1);
}
void Copy::setStart() {
	this->start = (int)clock();        //set borrowStartTime to when the book is taken out in seconds
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
//loops through vector of borrowed books
//if current time is found to be greater than one of the expiration dates of any of the books
//increases number of pentalites for reader
void Copy::findOverdue(Reader r, vector<Copy>& borrow) {
	for (int i = 0; i < borrow.size(); i++) {
		//checks if any reserved users
		if (borrow.at(i).reserved.size() != 0) {
			int temp = borrow.at(i).getStart();
		//check if time to check out book has been open for more than 5 days 
		//if so remove user from reserve list automatically
			if ((int)clock() > temp + 25) {
				borrow.at(i).reserved.pop();
				
				if(borrow.at(i).reserved.size() != 0) {
					this->setSince((int)clock());
				}
				else {
					this->setSince(-1);
				}
			}

		}
		if ((int)clock() >= borrow.at(i).getEnd())
		{
			r.increasePenalty();
		}
		
	
	}



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
void Copy::setAvail(bool b) {

	this->available = b;
}
bool Copy::getAvail() {
	return available;

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
	//this->
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






void Copy::addCopy(Reader r, int enteri, vector<Copy>& copies) {
	if (r.getPenalty() > 0) {
		cout << "you have overdue books" << endl;
		return;
		}
	if (r.getBook() == r.getMaxCopies()) {

		cout << "you have too many books, cannot borrow more" << endl;
		return;

	}
	Copy b;
	bool search = false;
	//searchs vector of available books for book to be borrowed
		//breaks when book is found
	int pos;
	for (int i = 0; i < copies.size(); i++) {
		if (copies.at(i).getID() == enteri) {
			search = true;
			b = copies.at(i);
			pos = i;
			break;
		}

	}
	//if book was not found ends ends method
	if (search == false)
	{
		cout << "copy not found, can't borrow" << endl;
		return;
	}
	if (b.getAvail() == false)
	{
		cout << "someone else currently borrowing the copy" << endl;
		return;
	}

	if (b.reserved.size() != 0) {
		Reader temp =  b.reserved.front();
		if (r.getUsername() != temp.getUsername()) {
			cout << "someone else reserved the book" << endl;
			return;
		}
		
			b.reserved.pop();
	
	}
//if there are no reserved readers for the copy 
	
		string reader = r.getUsername();
		b.setReader(reader);
		//also sets the reader of the book in the vector of all books
		copies.at(pos).setReader(reader);
		int mult = 30;
		// b.reserved.size();
		if (b.reserved.size() > 20) {
			mult = 29;
		}
		b.setStart();
		int time = b.getStart();
		b.setEnd(time + (5 * mult));
		
		//	//pushs the b to the array of borrowed books by user
		
		vector<Copy> test = r.getBorrow();

		test.push_back(b);
		r.setBorrow(test);
		
		//book borrowed & spot not opened anymore
		b.setAvail(false);
		
		b.setSince(-1);


		//	//increases number of books borrowed
		



}
//deletes copy from vector of copies
void Copy::deleteCopy(Reader r, int enteri, vector<Copy>& copies) {
	int pos = 0;
	bool found = false;
	vector<Copy> bor = r.getBorrow();
	//finds position of where to remove book
	for (int i = 0; i < bor.size(); i++) {
		if (copies.at(i).getID() == id) {
			pos = (i - 1);
			bor.erase(bor.begin() + pos);

			//decreases number of books borrowed
			int currentAmount = r.getBook();
			r.setBook(currentAmount - 1);
			found = true;
			break;
		}
	}

	//if book was not found, nothing is removed
		if (!found)
		{
			cout << "book not found, can't remove" << endl;
			return;
		}
		Copy temp;
	//finds the book in the vector of all books & clears the reader name
	for (int i = 0; i < copies.size(); i++) {
		if (copies.at(i).getID() == id) {
			temp = copies.at(i);
			copies.at(i).setReader("");
			copies.at(i).setAvail(true);
		}
	}
	r.setBorrow(bor);
	if (temp.reserved.size() > 0) {
		temp.setSince((int)clock());

	}
//	r.getReserve();
	cout << "successfully removed!" << endl;



}

void Copy::reserveCopy(Reader r, int enteri, vector<Copy>& copies) { 
	if (r.getPenalty() > 0) {
		cout << "you have overdue books" << endl;
		return;
	}


	Copy b;
	bool search = false;
	//searchs vector of available books for book to be borrowed
		//breaks when book is found
	int pos;
	for (int i = 0; i < copies.size(); i++) {
		if (copies.at(i).getID() == enteri) {
			search = true;
			b = copies.at(i);
			pos = i;
			break;
		}

	}
	//if book was not found ends ends method
	if (search == false)
	{
		cout << "copy not found, can't borrow" << endl;
		return;
	}

	b.reserved.push(r);
	cout << "copy reserved" << endl;

}




