#include "Librarian.h"

Librarian::Librarian() {
	this->setUserType(UserType::LIBRARIAN);
}

Librarian::Librarian(string username, string password) {
    this->setUsername(username);
    this->setPassword(password);
}
