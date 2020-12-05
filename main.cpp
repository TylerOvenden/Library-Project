#include <iostream>
#include <vector>
#include "Utils.h"
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

int main() {
    LibraryManagementSystem* lms = new LibraryManagementSystem();

    string username = Utils::promptForInput("Enter your username: ");
    string password = Utils::promptForInput("Enter your password: ");

    bool loginSuccess = lms->loginUser(username, password);
    if (!loginSuccess) {
        cout << "The username or password was incorrect" << endl;
        return 1;
    }

    lms->displayGreeting();
    if (lms->getUser().isReader()) {
        return runLMSForReader(lms);
    } else {
        return runLMSForLibrarian(lms);
    }
}

int runLMSForReader(LibraryManagementSystem* lms) {
    LMSStudentMenuOption menuOption = LMSStudentMenuOption::START;

    while (menuOption != LMSStudentMenuOption::LOG_OUT) {
        menuOption = lms->promptReaderMenuScreen();

        switch (menuOption) {
        case LMSStudentMenuOption::SEARCH_BOOKS: {
            searchBooks(lms);
            break;
        }
        case LMSStudentMenuOption::BORROW_BOOKS: {
            int copyId = atoi(Utils::promptForInput("Enter the ID of the copy you'd like to borrow: ").c_str());
            lms->borrowCopy(copyId);
        }
        case LMSStudentMenuOption::RETURN_BOOKS:
            break;
        case LMSStudentMenuOption::RESERVE_BOOKS:
            break;
        case LMSStudentMenuOption::CANCEL_RESERVATION:
            break;
        case LMSStudentMenuOption::MY_INFORMATION:
            break;
        case LMSStudentMenuOption::CHANGE_PASSWORD:
            lms->changePassword();
            break;
        case LMSStudentMenuOption::LOG_OUT:
            return logOut(lms);
        default:
            cout << "Entered option is not allowed!" << endl;
        }
    }
}

int runLMSForLibrarian(LibraryManagementSystem* lms) {
    LMSLibrarianMenuOption menuOption = LMSLibrarianMenuOption::START;

    while (menuOption != LMSLibrarianMenuOption::LOG_OUT) {
        menuOption = lms->promptLibrarianMenuScreen();

        switch (menuOption) {
        case LMSLibrarianMenuOption::SEARCH_BOOKS: {
            // todo - sort by popularity
            searchBooks(lms);
            break;
        }
        case LMSLibrarianMenuOption::ADD_BOOK:
            // todo
            break;
        case LMSLibrarianMenuOption::DELETE_BOOK:
            // todo
            break;
        case LMSLibrarianMenuOption::SEARCH_USERS: {
            string username = Utils::promptForInput("Enter username to search for: ");
            lms->searchForUser(username);
            break;
        }
        case LMSLibrarianMenuOption::ADD_USER: {
            string username = Utils::promptForInput("Enter username: ");
            string password = Utils::promptForInput("Enter password: ");
            lms->addUser(username, password);
            break;
        }
        case LMSLibrarianMenuOption::DELETE_USER: {
            string username = Utils::promptForInput("Enter username: ");
            lms->deleteUser(username);
            break;
        }
        case LMSLibrarianMenuOption::MY_INFORMATION:
            // todo
            break;
        case LMSLibrarianMenuOption::CHANGE_PASSWORD:
            lms->changePassword();
            break;
        case LMSLibrarianMenuOption::LOG_OUT:
            return logOut(lms);
        default:
            cout << "Entered option is not allowed!" << endl;
        }
    }
}

int logOut(LibraryManagementSystem* lms) {
    lms->saveAll();
    cout << "Logging out!";
    return 0;
}

void searchBooks(LibraryManagementSystem* lms) {
    LMSBookSearchOption searchOption = lms->promptBookSearchTypeScreen();
    string searchValue = Utils::promptForInput("Enter your search value: ");
    lms->displayBookSearchResultsFor(searchOption, searchValue);
}