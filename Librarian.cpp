#include "Librarian.h"

Librarian::Librarian() {
	this->setUserType(UserType::LIBRARIAN);
}

void Librarian::searchUser(vector<User> users, string username) {
    User current;
    for(int i = 0; i < users.size(); i++){
        current = users.at(i);
        if(current.getUsername() == username){
            if(current.getUserTypeString() == "Student" || current.getUserTypeString() == "Teacher"){
                cout
                << "Username: " <<  current.getUsername() << "\n"
                << "Password: " << current.getPassword() << "\n"
                << "Type: " << current.getUserType() << endl;

            }else if(current.getUserTypeString() == "Librarian"){
                cout
                        << "Username: " <<  current.getUsername() << "\n"
                        << "Password: " << current.getPassword() << "\n"
                        << endl;
            }
        }
    }
    cout << "Entered username doesnt exist!" << endl;
}

vector<Reader> Librarian::addUser(vector<Reader> users) {
    string username;
    string password;
    string type;
    int typeInt;
    int maxCopies;
    int maxBorrowDays;
    cout << "Enter usertype, Student or Teacher" << endl;
    cin >> type;
    if(type == "Student"){
        typeInt = 0;
        maxCopies = 5;
        maxBorrowDays = 30;
    }else{
        typeInt = 1;
        maxCopies = 10;
        maxBorrowDays = 50;
    }
    cout << "Enter username" << endl;
    cin >> username;
    for(int i = 0; i < users.size(); i++){
        if(users.at(i).getUsername() == username){
            cout << "User already exists!" << endl;
            return users;
        }
    }
    cout << "Enter password" << endl;
    cin >> password;
    Reader newReader(typeInt, username, password, maxCopies, maxBorrowDays);
    users.push_back(newReader);
    return users;
}

vector<Reader> Librarian::deleteUser(vector<Reader> users) {
    string username;
    cout << "Enter username" << endl;
    cin >> username;
    Reader current;
    for(int i = 0; i < users.size(); i++){
        current = users.at(i);
        if(current.getUsername() == username){
            users.erase(users.begin() + i);
            cout << "User deleted!" << endl;
            return users;
        }
    }
    cout << "User does not exist!" << endl;
    return users;
}
