#include <string>
#include "User.h"
using namespace std;
User::User()
{
	username = "";
	password = "";
}
User::User(string p, string u)
{
	username = p;
	password = u;
}
string User::getUser() {
	return username;
}
string User::getPass() {
	return password;
}
void User::setUser(string u) {
	username = u;
}
void User::setPass(string p) {
	password = p;
}