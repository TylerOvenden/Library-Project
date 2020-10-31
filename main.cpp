#include <iostream>
#include <iomanip>
#include <vector>
#include "Book.h"
#include "Student.h"
using namespace std;

// Load list of students from students.txt
// todo: load student text file instead of fake student data
vector<Student> loadStudents() {
	vector<Student> students;
	Student fakeStudent = Student("avery", "pass");
	students.push_back(fakeStudent);
	return students;
}

// Load list of books from book.txt
// todo: load book text file instead of fake book data
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

void displayWelcomeScreen(Student user) {
	cout << setfill('-') << setw(50) << " " << endl;
	// todo: center later
	cout << "-" << setw(48) << "Welcome to My Library!" << "-" << endl;
	cout << setfill('-') << setw(50) << endl << endl;

	cout << "Welcome back, " << user.getUser() << endl << endl;

	cout << "Please choose:" << endl;
	cout << "\t\t" << "1 -- Search Books" << endl;
	cout << "\t\t" << "2 -- Borrow Books" << endl;
	cout << "\t\t" << "3 -- Return Books" << endl;
	cout << "\t\t" << "4 -- Reserve Books" << endl;
	cout << "\t\t" << "5 -- Cancel Reservations" << endl;
	cout << "\t\t" << "6 -- My Information" << endl;
	cout << "\t\t" << "7 -- Change Password" << endl;
	cout << "\t\t" << "0 -- Log Out" << endl;
}

int main() {
	//these calls are just to test that the functions work

	//books is array of all books in library
	vector<Book> books = loadBooks();
	//borrowed is array of user's borrowed books
	vector<Book> borrowed;
	vector<Student> students = loadStudents();

	Book b1 = Book();
	//test book examples first added to vector of all books
	Book book1 = Book("book title", "jeff ", 2345, "mystery", 1990);
	Book book2 = Book("second book", "john ", 1234, "history", 2000);
	Book book3 = Book("third book", "jim ", 583, "science", 2004);
	books.push_back(book1);
	Student s = Student("wordpass", "John Doe");
	books.push_back(book2);
	books.push_back(book3);
	
	b1.addCopy(s, 1990, books, borrowed);
	b1.addCopy(s, 2000, books, borrowed);
	b1.addCopy(s, 2004, books, borrowed);

	for (int i = 0; i < borrowed.size(); i++) {
		cout << borrowed.at(i).getAuthor() << endl;
	}
	cout << "now remove books " << endl;
	b1.removeCopy(s, 1990, books, borrowed);
	for (int i = 0; i < borrowed.size(); i++) {
		cout << borrowed.at(i).getAuthor() << endl;
	}

	// Ask for username and password
	string username = promptForInput("username");
	string password = promptForInput("password");

	Student* authenticatedStudent = NULL;

	// Compare username and password to all in file
	for (int i = 0; i < students.size(); i++) {
		Student student = students.at(i);
		if ((student.getUser() == username) &&
			(student.getPass() == password)) {
			authenticatedStudent = &student;
			break;
		}
	}

	// Check if login was successful 
	if (!authenticatedStudent) {
		cout << "The username or password was incorrect" << endl;
		return 0;
	}

	// Code after authentication success!
	displayWelcomeScreen(*authenticatedStudent);
}
