#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include "LibraryManagementSystem.h"

using namespace std;

//1 Lode students with all exspected data
//2 lode books with all exspected data File Operation overlode
//3 user auth
//4 borrow book
//5 return book
//6 user accessors
//7 lode last accesses date
//8 date counter
//9 store date counter

string promptForInput(string description) {
	cout << "Enter your " << description << ": ";
	string input;
	cin >> input;
	return input;
}

int main() {
	LibraryManagementSystem* lms = new LibraryManagementSystem();

	vector<Book> books = lms->getBooks();
	vector<Reader> readers = lms->getReaders();

	// Ask for username and password
	string username = promptForInput("username");
	string password = promptForInput("password");

	bool loginSuccess = lms->loginUser(username, password);
	if (!loginSuccess) {
		cout << "The username or password was incorrect" << endl;
		return 0;
	}

	lms->displayWelcomeScreen();

	int userChoice;
	// This determins what prosses to use
	cin >> userChoice;

	char input = 9;
	int id;
	Book b1 = Book();
	while (input != 0) {
		// b1.findOverdue(*authenticatedStudent, borrowed);
		cout << "\nPlease select an option: ";
		cin >> input;

		switch (input) {
		case 1:
			cout << "enter an id " << endl;
			cin >> id;
			// b1.addCopy(*authenticatedStudent, id, books, borrowed);
			break;
		case 2:
			cout << "enter an id " << endl;
			cin >> id;
			// b1.removeCopy(*authenticatedStudent, id, books, borrowed);
			break;
		case 0:
			exit(1);
		}
	}
}