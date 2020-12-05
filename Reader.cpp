#include "Reader.h"

Reader::Reader() {

}

Reader::Reader(int type, string username, string password, int maxCopies, int maxBorrowDays) {
	this->setUserType(static_cast<UserType>(type));
	this->setUsername(username);
	this->setPassword(password);
	this->setMaxCopies(maxCopies);
	this->setMaxBorrowDays(maxBorrowDays);
	this->overdue = false; 
}

void Reader::setPenalty(int penalty) {
	this->penalty = penalty;
}
void Reader::increasePenalty() {
	this->penalty++;
}

int Reader::getPenalty() {
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

int Reader::getBook() {
	return this->books;
}
void Reader::increaseBook() {
	this->books++;

}
void Reader::setBook(int num) {

	this->books = num;
}
std::vector<Copy> Reader::getBorrow() {
	return borrowed;
}
std::vector<Copy> Reader::getReserve() {
	return reserved;
}
void Reader::setBorrow(std::vector<Copy> borrow) {
	this->borrowed = borrow;
}
void Reader::setReserve(std::vector<Copy> reserve) {
	this->reserved = reserve;
}
void Reader::setOverdue(bool b) {

	this->overdue = b;
}
bool Reader::getOverdue() {

	return overdue;
 }


//method for user to borrow copy, adding it to their vector of borrowed books 
//
void Reader::addCopy(int enteri, vector<Copy>& copies) {
	//can't borrow copies if book is overdue
	if (getOverdue() == true) {
		cout << "you have overdue books" << endl;
		return;
	}
	//can't borrow books if too many books
	if (getBook() == getMaxCopies()) {
		cout << "you have too many books, cannot borrow more" << endl;
		return;
	}
	Copy b;
	bool search = false;
	//searchs vector of available books for book to be borrowed
		//breaks when book is found
	int pos;
	for (int i = 0; i < copies.size(); i++) {
		c = &copies.at(i);
		
		//if this copy exists
		if (c->getID() == enteri) {
			b = copies.at(i);
			//b = copies.at(i);
			//check if this copy is available
			if (c->getAvail() == true && c->getReader() == "" )
			{
				pos = i;
				search = true;
			
				break; 
			}
			//if there are no reserved readers for the copy
			else {
				cout << "this copy is not available currently" << endl;
				return;
			}

		}
	}

	//if copy was not found ends ends method
	if (search == false)
	{
		cout << "copy not found, can't borrow" << endl;
		return;
	}
	
	
	queue<string> reserUser = c->getReserveQueue();

	
	if (reserUser.size() != 0) {
		string temp = reserUser.front();\
			string user = getUsername();

		if (user != temp) {

			cout << "someone else reserved the book" << endl;
			return;
		}
		//user is at front of reservations
		reserUser.pop();

	}

	//sets book's reader to the username
	string reader = getUsername();
	c->setReader(reader);


	//also sets the reader of the book in the vector of all books
	copies.at(pos).setReader(reader);
	//determines the number of days the user could borrow the book
	int mult = getMaxBorrowDays();
	if (reserUser.size() > 20) {
		mult--;
	}

	//starts checkout time for 
	c->setStart();
	int time = c->getStart();
	c->setEnd(time + (5 * mult));

	//pushs the b to the array of borrowed books by user, represents user checking out book
	
	
	borrowed.push_back(b);
	
	
	//book borrowed & spot not opened anymore
	b.setAvail(false);
	
	b.setSince(-1);
	b.setReserveQueue(reserUser);
	//	//increases number of books borrowed

}



 //loops through vector of borrowed books
//if current time is found to be greater than one of the expiration dates of any of the books
//increases number of pentalites for reader

void Reader::findOverdue(vector<Copy>& borrow) {
	
	for (int i = 0; i < borrow.size(); i++) {
		queue<string> reserUser = borrow.at(i).getReserveQueue();
		if (reserUser.size() != 0) {
			int temp = borrow.at(i).getSince();
			//check if time to check out book has been open for more than 5 days
			//if so remove user from reserve list automatically
			if ((int)clock() > temp + 25) {
				reserUser.pop();
				if (reserUser.size() != 0) {
					borrow.at(i).setSince((int)clock());
				}
				else {
					borrow.at(i).setSince(-1);
				}
				borrow.at(i).setReserveQueue(reserUser);

			}
		}
		//checks if book is borrowed currently
		if (borrow.at(i).getStart() != -1)
		{
			if ((int)clock() >= borrow.at(i).getEnd()) {
			setOverdue(true);
		}
	}
	}
}
//reserve copy of book for user if copy exists
//
void Reader::reserveCopy(int enteri, vector<Copy>& copies) {
	//can't reserve books if have an overdue book
	if (getOverdue() == true) {
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
			c = &copies.at(i);
			b = copies.at(i);
			queue<string> reserUser = c->getReserveQueue();
		//	new string(getUsername())
			reserUser.push(getUsername());
			reserved.push_back(b);
			cout << "size: " << reserUser.size() << endl;
			c->setReserveQueue(reserUser);
			break;
		}
	}
	//if book was not found ends ends method
	if (search == false)
	{
		cout << "copy not found, can't reserve" << endl;
		return;
	}

	
	
	cout << "copy reserved" << endl;
	queue<string> reserUser = c->getReserveQueue();
	cout << "size: " << reserUser.size() << endl;
	c->setReserveQueue(reserUser);


}


//returns copy, removing it from user's vector of borrowed copies
void Reader::deleteCopy(int enteri, vector<Copy>& copies) {


	int pos = 0;
	bool found = false;
	//vector<Copy> bor = getBorrow();
//	borrowed
	//finds position of where to remove book
	for (int i = 0; i < borrowed.size(); i++) {
		if (copies.at(i).getID() == enteri){
		
			pos = (i);
			borrowed.erase(borrowed.begin() + pos);
			//decreases number of books borrowed
			int currentAmount = getBook();
			setBook(currentAmount - 1);
			found = true;
			//checks if the found book is overdue
			if (getOverdue() == true) {
				cout << "you have overdue books" << endl;
				increasePenalty();
			}
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
		if (copies.at(i).getID() == enteri) {
			//temp = returned book
			temp = copies.at(i);
			temp.setReader("");
			temp.setAvail(true);
		}
	}
	queue<string> reserUser = temp.getReserveQueue();
	
	//if no one reserving, signify book is not borrowed currently
	if (reserUser.size() == 0) {
		temp.resetStart();
	}
	//time for first reserver of book to borrow books starts now
	if (reserUser.size() > 0) {
		temp.setSince((int)clock());
	}
	temp.setReserveQueue(reserUser);

	cout << "successfully removed!" << endl;
}
