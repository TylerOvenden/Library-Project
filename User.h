#include <string>

using namespace std;

class User {
private:
	string username;
	string password;

public: 
	User();
	User(string password, string username);

	string getUsername();
	string getPassword();

	void setPassword(string password);
	void setUsername(string username);
};

