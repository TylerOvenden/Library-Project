#pragma once

#include <string>

using namespace std;
class User
{
private:
	string username;
	string password;
	int test; 
public: 
	User();
	User(string p, string u);
	string getUser();
	string getPass();
	void setPass(string p);
	void setUser(string u);
};

