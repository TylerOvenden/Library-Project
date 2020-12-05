#include "Reader.h"

Reader::Reader() {

}

Reader::Reader(string username, string password)
{
}

Reader::Reader(int type, string username, string password, int maxCopies, int maxBorrowDays) {
	this->setUserType(static_cast<UserType>(type));
	this->setUsername(username);
	this->setPassword(password);
	this->setMaxCopies(maxCopies);
	this->setMaxBorrowDays(maxBorrowDays);
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
std::vector<Copy> Reader::getBorrowedCopies() {
	return std::vector<Copy>();
}

std::vector<int> Reader::getReservedISBNs() {
	return std::vector<int>();
}

void Reader::addCopy(Copy copy) {

}

void Reader::deleteCopy(int copyId) {
}

vector<Copy> Reader::getOverdueCopies() {
	return vector<Copy>();
}

/*
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
		//if this copy exists
		if (copies.at(i).getID() == enteri) {

			b = copies.at(i);
			//check if this copy is available
			if (b.getAvail() == true)
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
	
	queue<string> reserUser = b.getReserveQueue();
	//checks if someone else reserved the book first
	if (reserUser.size() != 0) {
		string temp = reserUser.front();
		if (getUsername() != temp) {
			cout << "someone else reserved the book" << endl;
			return;
		}
		//user is at front of reservations
		reserUser.pop();

	}

	//sets book's reader to the username
	string reader = getUsername();
	b.setReader(reader);


	//also sets the reader of the book in the vector of all books
	copies.at(pos).setReader(reader);
	//determines the number of days the user could borrow the book
	int mult = getMaxBorrowDays();
	if (reserUser.size() > 20) {
		mult--;
	}

	//starts checkout time for 
	b.setStart();
	int time = b.getStart();
	b.setEnd(time + (5 * mult));

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
		//current time is after the book's expiration date
		if ((int)clock() >= borrow.at(i).getEnd()) {
			setOverdue(true);
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
			b = copies.at(i);
			queue<string> reserUser = b.getReserveQueue();
			reserUser.push(getUsername());
			reserved.push_back(b);
			b.setReserveQueue(reserUser);
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
}


//returns copy, removing it from user's vector of borrowed copies
void Reader::deleteCopy(int enteri, vector<Copy>& copies) {


	int pos = 0;
	bool found = false;
	vector<Copy> bor = getBorrow();
//	borrowed
	//finds position of where to remove book
	for (int i = 0; i < borrowed.size(); i++) {
		if (copies.at(i).getID() == enteri){
			pos = (i - 1);
			bor.erase(bor.begin() + pos);
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
	//time for first reserver of book to borrow books starts now
	if (reserUser.size() > 0) {
		temp.setSince((int)clock());
	}
	temp.setReserveQueue(reserUser);

	cout << "successfully removed!" << endl;
}
*/
