#include <iostream>
#include <iomanip>
#include <vector>
#include "Book.h"
#include "Student.h"
using namespace std;

// Load list of students from students.txt
vector<Student> loadStudents() {
	// Open book txt file and check that it lodes in
	fstream importStudent("Student.txt");
	if (importStudent.fail())
	{
		cerr << endl << "Error opening input file!" << endl;
		exit(1);
	}
	else cout << endl << "Seccessfully opens the target file!" << endl << endl;

	// Import all info for a student
	string studentName, password;
	vector<Student> students;
	do {
		importStudent >> studentName;
		importStudent >> password;
		Student storeStudentInfo = Student(studentName, password);
		// Stor all books into "books" vector
		students.push_back(storeStudentInfo);
	} while (importStudent.eof() == 0);
	// Retern a vector with all books
	return students;
}

// Load list of books from book.txt
vector<Book> loadBooks() {
	// Open book txt file and check that it lodes in
	fstream importBooks("Book.txt");
	if (importBooks.fail())
	{
		cerr << endl << "Error opening input file!" << endl;
		exit(1);
	}
	else cout << endl << "Seccessfully opens the target file!" << endl << endl;

	// Import all info for a book
	string title, author, category/*, bookHolder*/;
	int isbn, id/*, startTime*/;
	vector<Book> books;
	do {
		importBooks >> title;
		importBooks >> author;
		importBooks >> isbn;
		importBooks >> category;
		importBooks >> id;
		//importBooks >> bookHolder;
		//importBooks >> startTime
		Book storeBookInfo = Book(title, author, isbn, category, id/*, bookHolder*/ /*, startTime*/);
		// Stor all books into "books" vector
		books.push_back(storeBookInfo);
	} while (importBooks.eof() == 0);
	// Retern a vector with all books
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
	cout << "-------------------------------------------------------------------" << endl;
	cout << "---------------------" << "Welcome to My Library!" << "------------------------" << endl;
	cout << "-------------------------------------------------------------------";

	//TODO: fix user.getUser() so that it outputs the user's name 
	cout << endl << endl << "Welcome back, " << user.getUser() << endl << endl;

	cout << "Please choose:" << endl;
	//cout << "\t\t" << "1 -- Search Books" << endl;
	cout << "\t\t" << "2 -- Borrow Books" << endl;
	cout << "\t\t" << "3 -- Return Books" << endl;
	//cout << "\t\t" << "4 -- Reserve Books" << endl;
	//cout << "\t\t" << "5 -- Cancel Reservations" << endl;
	//cout << "\t\t" << "6 -- My Information" << endl;
	//cout << "\t\t" << "7 -- Change Password" << endl;
	cout << "\t\t" << "0 -- Log Out" << endl;

}

int main() {

	// Books is array of all books in library
	vector<Book> books = loadBooks();
	// Borrowed is array of user's borrowed books
	vector<Book> borrowed;
	// students is array of all students in library
	vector<Student> students = loadStudents();

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

	int userChoice;
	// This determins what prosses to use
	cin >> userChoice;

	char input = 9;
	int id;
	Book b1 = Book();
	while (input != 0){
		b1.findOverdue(*authenticatedStudent, borrowed);
		cout << "\nPlease select an option: ";
		cin >> input;

		switch (input){
		case 1:
			cout << "enter an id " << endl;
			cin >> id;
			b1.addCopy(*authenticatedStudent, id, books, borrowed);
			break;
		case 2:
			cout << "enter an id " << endl;
			cin >> id;
			b1.removeCopy(*authenticatedStudent, id, books, borrowed);
			break;
		case 0:
			exit(1);
		}
	}
}
