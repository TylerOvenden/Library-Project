#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Book.h"
#include "Student.h"
using namespace std;
Book::Book() {
	reader = "";
//	expiration = -999;
//	start = -999;
}
Book::Book(string title, string author, int isbn, string category, int id) {
	Book();
	this->reader = "";
	this->title = title; 
	this->author = author;
	this->isbn = isbn;
	this->category = category;
	this->id = id;
}
void Book:: setTitle(string t) {
	title = t;
}
string Book::getTitle(){ 
	return title;
}
void Book::setAuthor(string aut) {
	author = aut;
}
string Book::getAuthor() {
	return author;
}
void Book::setISBN(int is) {
	isbn = is;
}
int Book::getISBN() {
	return isbn;
}
void Book::setCat(string cat) {
	category = cat;
}
string Book::getCat() {
	return category;
}
void Book::setID(int ide) {
    
	id = ide;
}
int Book::getID() {
	return id;
}

void Book::setRead(string read) {
	reader = read;
}
string Book::getRead() {
	return reader;


}


void Book::setStart() {
	this->start = (int) clock();        //set borrowStartTime to when the book is taken out in seconds
	double end = start + (5 * 30);  //since 5 seconds = 1 day, 30 days = 5*30
	setEnd(end);
}
double Book::getStart() {
	return start;

}
void  Book:: setEnd(double end) {
	expiration = end;

}
double Book::getEnd() {
	return expiration;
}
//loops through vector of borrowed books
//if current time is found to be greater than one of the expiration dates of any of the books
//sets user's attribute of having overdue books to true
void Book::findOverdue(Student s, vector<Book>& borrow) {
	for (int i = 0; i < borrow.size(); i++) {
		if ((int) clock() >= borrow.at(i).getEnd())
		{
			s.setLate(true);
		}
	
	}


}
//parameters: student, the current student borrowing the book
//id represents the unique id used to identify the book
//books is a vector of all books in the system
//borrow is a vector of the user's books borrowed
void Book::addCopy(Student s, int id, vector<Book>& books, vector<Book>& borrow) {
	//if user has overdue books, cannot check any more out
	if (s.getLate()) {
		cout << "you have overdue books, cannot add any more" << endl;
		return;
	}
	Book b;
	bool search = false;
	//searchs vector of available books for book to be borrowed
	//breaks when book is found
	int pos;
	for (int i = 0; i < books.size(); i++) {
		if (books.at(i).getID() == id) {
			search = true;
			b = books.at(i);
			pos = i;
			break;
			}

	}
	//if book was not found ends ends method
	if (search == false)
	{
		cout << "book not found, can't borrow" << endl;
		return;
	}

	//if user is borrowing 5 books already, ends because it cannot borrow more
	int currentAmount = s.getBook();
	if (currentAmount == 5) {
		cout << "too many books " << endl;
		return;
	}

	//checks if book already has a reader, therefore already borrowed
	if (b.getRead() != "") {
		cout << "book is already borrowed" << endl;
		return;
	}
	//sets attributes for book based on the reader & time
	string reader = s.getUser();
	b.setRead(reader);
	//also sets the reader of the book in the vector of all books
	books.at(pos).setRead(reader);
	b.setStart();
	//pushs the b to the array of borrowed books by user
	borrow.push_back(b);
	//increases number of books borrowed
	s.setBook(currentAmount+1);

	cout << "successfully added!" << endl;
}

//removes copy of book from vector of user's borrowed books by searching for id
void Book::removeCopy(Student s, int id, vector<Book>& books, vector<Book>& borrow) {
	int pos = 0;
	bool found = false;
	//finds position of where to remove book
	for (int i = 0; i < borrow.size(); i++) {
		if (books.at(i).getID() == id) {
			pos = (i-1);
			borrow.erase(borrow.begin()+pos);

	//decreases number of books borrowed
			int currentAmount = s.getBook();
			s.setBook(currentAmount - 1);
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
	//finds the book in the vector of all books & clears the reader name
	for (int i = 0; i < books.size(); i++) {
		if (books.at(i).getID() == id) {
			books.at(i).setRead("");
		}
	}
	
	cout << "successfully removed!" << endl;
}
