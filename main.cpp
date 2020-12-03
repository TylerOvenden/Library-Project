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

	//Variables used in the various switch statements
	//Define them outside
	//Probably should move them inside
    vector<Book> booksFound;
    string searchValue;
    LMSBookSearchOption searchOption;
    string searchUsernametemp;
    vector<Reader> tempReader;
    int stayInLibrary = 1;
    while(stayInLibrary) {
        string username = promptForInput("Enter your username: ");
        string password = promptForInput("Enter your password: ");

        bool loginSuccess = lms->loginUser(username, password);
        if (!loginSuccess) {
            cout << "The username or password was incorrect" << endl;
            return 0;
        }

        lms->displayGreeting();

        //Check if usertype is student or teacher
        if (lms->getUser().getUserTypeString() == "Student" || lms->getUser().getUserTypeString() == "Teacher") {
            LMSMenuOption menuOption = LMSMenuOption::START;
            while (menuOption != LMSMenuOption::LOG_OUT) {
                menuOption = lms->promptMenuScreen();

                switch (menuOption) {
                    case LMSMenuOption::SEARCH_BOOKS:
                        searchOption = lms->promptBookSearchTypeScreen();
                        searchValue = promptForInput("Enter your search value: ");
                        booksFound = lms->searchBooks(searchOption, searchValue);
                        if (booksFound.size() != 0) {
                            cout << "\nSearch results:\n";
                            for (int i = 0; i < booksFound.size(); i++) {
                                booksFound.at(i).print();
                            }
                        } else {
                            cout << "\nNo results found!\n" << endl;
                        }
                        break;
                    case LMSMenuOption::BORROW_BOOKS:
                        break;
                    case LMSMenuOption::RETURN_BOOKS:
                        break;
                    case LMSMenuOption::RESERVE_BOOKS:
                        break;
                    case LMSMenuOption::CANCEL_RESERVATION:
                        break;
                    case LMSMenuOption::INFO:
                        break;
                    case LMSMenuOption::CHANGE_PASS:
                        break;
                    case LMSMenuOption::LOG_OUT:
                        cout << "Logging out!" << endl;
                        break;
                    default:
                        cout << "Entered option is not allowed!" << endl;
                }
            }
        }
        //check if student type is librarian
        if (lms->getUser().getUserTypeString() == "Librarian") {
            Librarian tempLibrarian;
            LMSMenuOptionLibrarian menuOptionLibrarian = START_LIBRARIAN;
            while (menuOptionLibrarian != LMSMenuOptionLibrarian::LOG_OUT_LIBRARIAN) {
                menuOptionLibrarian = lms->promptLibrarianScreen();
                switch (menuOptionLibrarian) {
                    case LMSMenuOptionLibrarian::SEARCH_BOOKS_LIBRARIAN:
                        searchOption = lms->promptBookSearchTypeScreen();
                        searchValue = promptForInput("Enter your search value: ");
                        booksFound = lms->searchBooks(searchOption, searchValue);
                        if (booksFound.size() != 0) {
                            cout << "\nSearch results:\n";
                            for (int i = 0; i < booksFound.size(); i++) {
                                booksFound.at(i).print();
                            };
                        } else {
                            cout << "\nNo results found!\n" << endl;
                        }
                        break;
                    case LMSMenuOptionLibrarian::ADD_BOOKS_LIBRARIAN:
                        break;
                    case LMSMenuOptionLibrarian::DELETE_BOOKS_LIBRARIAN:
                        break;
                    case LMSMenuOptionLibrarian::SEARCH_USERS_LIBRARIAN:
                        searchUsernametemp = promptForInput("Enter username");
                        tempLibrarian.searchUser(lms->getAllUsers(), searchUsernametemp);
                        break;
                    case LMSMenuOptionLibrarian::ADD_USERS_LIBRARIAN:
                        lms->setReaders(tempLibrarian.addUser(lms->getReaders()));
                        lms->saveReaders();
                        break;
                    case LMSMenuOptionLibrarian::DELETE_USERS_LIBRARIAN:
                        break;
                    case LMSMenuOptionLibrarian::MY_INFORMATION_LIBRARIAN:
                        break;
                    case LMSMenuOptionLibrarian::CHANGE_PASSWORD_LIBRARIAN:
                        break;
                    case LMSMenuOptionLibrarian::LOG_OUT_LIBRARIAN:
                        cout << "Logging out!" << endl;
                        break;
                    default:
                        cout << "Entered option is not allowed!" << endl;
                }
            }
        }
        cout << "Enter 0 to quit, Enter 1 to stay in the library" << endl;
        cin >> stayInLibrary;
    }
}