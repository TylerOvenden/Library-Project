#include <iostream>
#include <vector>
#include "Student.h"
using namespace std;

// Load list of students from students.txt
vector<Student> loadStudents() {
	vector<Student> students;
	Student fakeStudent = Student("avery", "pass");
	students.push_back(fakeStudent);
	return students;
}

// Load list of books from book.txt
vector<Book> loadBooks() {
	vector<Book> books;
	Book fakeBook = Book();
	books.push_back(fakeBook);
	return books;
}

// Prompt for user input
string promptForInput(string description) {
	cout << "Enter your " << description << ": ";
	string input;
	cin >> input;
	return input;
}

int main() {

	vector<Book> books = loadBooks();
	vector<Student> students = loadStudents();

	// Ask for username and password
	string username = promptForInput("username");
	string password = promptForInput("password");


	bool authenticated = false;
	Student authenticatedStudent;

	// Compare username and password to all in file
	for (int i = 0; i < students.size(); i++) {
		Student student = students.at(i);
		if ((student.getUser() == username) && 
			(student.getPass() == password)){
			authenticatedStudent = student;
			authenticated = true;
			break;
		}
	}

	// Check if login was successful 
	if (authenticated = false) {
		cout << "The username or password was incorrect" << endl;
		return 0;
	}
	else {
		// Code after authentication success!
		//
		//
		//
		//
		//
	}
}