#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Book.h"
#include "Student.h"
#include "BookFunctions.h"
using namespace std;

void BookFunctions::addCopy(Student s, Book b) {
	//need to implement time function rn just using 1 
	//need to check if book is borrowed, too many books borrowed
	//
	string reader = s.getUser();
	b.setRead(reader);
	b.setStart(1);
	b.setEnd(b.getStart() + 30);
	 
}
