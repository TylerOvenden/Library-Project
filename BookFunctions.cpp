#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Book.h"
#include "Student.h"
#include "BookFunctions.h"
using namespace std;

void BookFunctions::addCopy(Student s, Book b, vector<Book>& v) {
	//need to implement time function rn just using 1 
	//need to check if book is borrowed, too many books borrowed
	//
	int currentAmount = s.getBook();
	if (currentAmount == 5) {
		cout << "too many books " << endl;
	}
	string reader = s.getUser();  
	b.setRead(reader);
	b.setStart(1);
	b.setEnd(b.getStart() + 30);
	v.push_back(b);
}
void BookFunctions::removeCopy(Student s, Book b, vector<Book>& v) {
	for (int i = 0; i < v.size(); i++) {
		

	}
	
	b.setRead("");

}
