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

// Prompt for user input
string promptForInput(string prompt) {
	cout << prompt;
	string input;
	cin >> input;
	return input;
}

int main() {
	LibraryManagementSystem* lms = new LibraryManagementSystem();

	string username = promptForInput("Enter your username: ");
	string password = promptForInput("Enter your password: ");

	bool loginSuccess = lms->loginUser(username, password);
	if (!loginSuccess) {
		cout << "The username or password was incorrect" << endl;
		return 0;
	}

	lms->displayGreeting();

	LMSMenuOption menuOption = LMSMenuOption::START;
	while (menuOption != LMSMenuOption::LOG_OUT) {
		menuOption = lms->promptMenuScreen();

		switch (menuOption) {
		case LMSMenuOption::SEARCH_BOOKS: {
			LMSBookSearchOption searchOption = lms->promptBookSearchTypeScreen();
			string searchValue = promptForInput("Enter your search value: ");

			vector<Book> books = lms->searchBooks(searchOption, searchValue);
			if (books.size()) {
				cout << "\nSearch results:\n";
				for (int i = 0; i < books.size(); i++) {
					books.at(i).print();
				};
				cout << "\n";
				break;
			}
			else {
				cout << "\nNo results found!\n" << endl;
			}
		
		}
		case LMSMenuOption::BORROW_BOOKS: {
			int isbn = atoi(promptForInput("Enter the ISBN: ").c_str());
			
		}
		}
	}
}