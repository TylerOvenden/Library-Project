#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Book.h"

using namespace std;
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
void Book::setStart(int s) {
	start = s;

}
int Book::getStart() {
	return start;

}
void  Book:: setEnd(int end) {
	expiration = end;

}
int Book::getEnd() {
	return expiration;
}