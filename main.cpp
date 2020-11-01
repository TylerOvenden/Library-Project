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

	//TODO: integrate if/case statements for borrow book, and return book
	//TODO: connect the file's inputs insted of temp inputs
	Book b1 = Book();
	//test book examples first added to vector of all books
	//Book book1 = Book("book title", "jeff ", 2345, "mystery", 1990);
	//Book book2 = Book("second book", "john ", 1234, "history", 2000);
	//Book book3 = Book("third book", "jim ", 583, "science", 2004);
	//books.push_back(book1);
	Student s = Student("wordpass", "John Doe");
	//books.push_back(book2);
	//books.push_back(book3);
	
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
}
