#include <iostream>
#include <vector>
#include "LibraryManagementSystem.h"

using namespace std;

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

int runLMSForReader(LibraryManagementSystem* lms) {
    LMSReaderMenuOption menuOption = LMSReaderMenuOption::READER_START;


    while (menuOption != LMSReaderMenuOption::READER_LOG_OUT) {
        lms->updateTime();
        menuOption = lms->promptReaderMenuScreen();

        switch (menuOption) {
        case LMSReaderMenuOption::READER_SEARCH_BOOKS: {
            searchBooks(lms);
            break;
        }
        case LMSReaderMenuOption::READER_BORROW_BOOK: {
            int copyId = atoi(Utils::promptForInput("Enter the ID of the copy you'd like to borrow: ").c_str());
            lms->borrowCopy(copyId);
            break;
        }
        case LMSReaderMenuOption::READER_RETURN_BOOK: {
            int copyId = atoi(Utils::promptForInput("Enter the ID of the copy you'd like to return: ").c_str());
            lms->returnCopy(copyId);
            break;
        }
        case LMSReaderMenuOption::READER_RENEW_BOOK: {
            int copyId = atoi(Utils::promptForInput("Enter the ID of the copy you'd like to renew: ").c_str());
            lms->renewCopy(copyId);
            break;
        }
        case LMSReaderMenuOption::READER_RESERVE_BOOK: {
            int isbn = atoi(Utils::promptForInput("Enter the ISBN of the book you'd like to reserve: ").c_str());
            lms->reserveBook(isbn);
            break;
        }
        case LMSReaderMenuOption::READER_CANCEL_RESERVATION: {
            int isbn = atoi(Utils::promptForInput("Enter the ISBN of the book you'd like to cancel your reservation for: ").c_str());
            lms->cancelReservation(isbn);
            break;
        }
        case LMSReaderMenuOption::READER_CHANGE_PASSWORD:
            lms->changePassword();
            break;
        case LMSReaderMenuOption::READER_LOG_OUT:
            return logOut(lms);
        default:
            cout << "Entered option is not allowed!" << endl;
        }
    }
}

int runLMSForLibrarian(LibraryManagementSystem* lms) {
    LMSLibrarianMenuOption menuOption = LMSLibrarianMenuOption::LIBRARIAN_START;

    while (menuOption != LMSLibrarianMenuOption::LIBRARIAN_LOG_OUT) {
        lms->updateTime();
        menuOption = lms->promptLibrarianMenuScreen();

        switch (menuOption) {
        case LMSLibrarianMenuOption::LIBRARIAN_SEARCH_BOOKS: {
            searchBooks(lms);
            break;
        }
        case LMSLibrarianMenuOption::LIBRARIAN_ADD_BOOK:
            lms->addCopyToLibrary();
            break;
        case LMSLibrarianMenuOption::LIBRARIAN_DELETE_BOOK: {
            int copyId = atoi(Utils::promptForInput("Enter the ID of the copy you'd like to delete: ").c_str());
            lms->deleteCopyFromLibrary(copyId);
            break;
        }
        case LMSLibrarianMenuOption::LIBRARIAN_SEARCH_USERS: {
            string username = Utils::promptForInput("Enter username to search for: ");
            lms->searchForUser(username);
            break;
        }
        case LMSLibrarianMenuOption::LIBRARIAN_ADD_USER: {
            string username = Utils::promptForInput("Enter username: ");
            string password = Utils::promptForInput("Enter password: ");
            lms->addUser(username, password);
            break;
        }
        case LMSLibrarianMenuOption::LIBRARIAN_DELETE_USER: {
            string username = Utils::promptForInput("Enter username: ");
            lms->deleteUser(username);
            break;
        }
        case LMSLibrarianMenuOption::LIBRARIAN_CHANGE_PASSWORD:
            lms->changePassword();
            break;
        case LMSLibrarianMenuOption::LIBRARIAN_LOG_OUT:
            return logOut(lms);
        default:
            cout << "Entered option is not allowed!" << endl;
        }
    }
}

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
