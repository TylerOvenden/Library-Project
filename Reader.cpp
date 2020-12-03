#include "Reader.h"

Reader::Reader() {
}

void Reader::setPenalty(int penalty) {
	this->penalty = penalty;
}
void Reader::increasePenalty(){
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
//std::vector<Copy> Reader::getBorrow() {
//	return borrowed;
//}
//std::vector<Copy> Reader::getReserve() {
//	return reserved;
//}
//void Reader::setBorrow(std::vector<Copy> borrow) {
//	this->borrowed = borrow;
//}
//void Reader::setReserve(std::vector<Copy> reserve) {
//	this->reserved = reserve;
//}
//parameters: student, the current student borrowing the book
//id represents the unique id used to identify the book
//books is a vector of all books in the system
//borrow is a vector of the user's books borrowed
//void Book::addCopy(Student s, int id, vector<Book>& books, vector<Book>& borrow) {
//	//if user has overdue books, cannot check any more out
//	if (s.getLate()) {
//		cout << "you have overdue books, cannot add any more" << endl;
//		return;
//	}
//	Book b;
//	bool search = false;
//	//searchs vector of available books for book to be borrowed
//	//breaks when book is found
//	int pos;
//	for (int i = 0; i < books.size(); i++) {
//		if (books.at(i).getID() == id) {
//			search = true;
//			b = books.at(i);
//			pos = i;
//			break;
//			}
//
//	}
//	//if book was not found ends ends method
//	if (search == false)
//	{
//		cout << "book not found, can't borrow" << endl;
//		return;
//	}
//
//	//if user is borrowing 5 books already, ends because it cannot borrow more
//	int currentAmount = s.getBook();
//	if (currentAmount == 5) {
//		cout << "too many books " << endl;
//		return;
//	}
//
//	//checks if book already has a reader, therefore already borrowed
//	if (b.getRead() != "") {
//		cout << "book is already borrowed" << endl;
//		return;
//	}
//	//sets attributes for book based on the reader & time
//	string reader = s.getUser();
//	b.setRead(reader);
//	//also sets the reader of the book in the vector of all books
//	books.at(pos).setRead(reader);
//	b.setStart();
//	//pushs the b to the array of borrowed books by user
//	borrow.push_back(b);
//	//increases number of books borrowed
//	s.setBook(currentAmount+1);
//
//	cout << "successfully added!" << endl;
//}

//removes copy of book from vector of user's borrowed books by searching for id
//void Book::removeCopy(Student s, int id, vector<Book>& books, vector<Book>& borrow) {
//	int pos = 0;
//	bool found = false;
//	//finds position of where to remove book
//	for (int i = 0; i < borrow.size(); i++) {
//		if (books.at(i).getID() == id) {
//			pos = (i-1);
//			borrow.erase(borrow.begin()+pos);
//
//	//decreases number of books borrowed
//			int currentAmount = s.getBook();
//			s.setBook(currentAmount - 1);
//			found = true;
//			break;
//		}
//	}
//
//	//if book was not found, nothing is removed
//	if (!found)
//	{
//		cout << "book not found, can't remove" << endl;
//		return;
//	}
//	//finds the book in the vector of all books & clears the reader name
//	for (int i = 0; i < books.size(); i++) {
//		if (books.at(i).getID() == id) {
//			books.at(i).setRead("");
//		}
//	}
//	
//	cout << "successfully removed!" << endl;
//}