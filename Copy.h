#include <string>
#include <vector>
#include <ctime>
#include <queue>    
#include "Book.h"

using namespace std;

class Copy 
{
private:
	// Which book this copy belongs to
	Book book;
	
	int id;

	string reader;
	string reserver;
	
	bool available;
	int start;
	int expiration;

	int since; 

	int reservedate;
	int borrowdate;
	int expiredate;
	queue<Reader> reserved;

public: 
	Copy();
	Copy(Book b, int id);
	void setReader(string r);
	string getReader();
	void setReserver(string r);
	bool getAvail();
	void setAvail(bool b);
	string getReserver();
	int getReserveDate();
	int getBorrowDate();
	int getExpireDate();
	Book getBook();
	
	void setReserveDate(int r);
	void setBorrowDate(int r);
	void setExpireDate(int r);
	
	
	void setStart();
	void setEnd(int end);
	int getEnd();
	int getStart();

	int getSince();
	void setSince(int s);



	void setID(int id);
	int getID();
	void addCopy(Reader r, int enteri, vector<Copy>& copies);
	void reserveCopy(Reader r, int enteri, vector<Copy>& copies);
	void deleteCopy(Reader r, int enteri, vector<Copy>& copies);
	void findOverdue(Reader r, vector<Copy>& borrow);
	
	void search(vector<Copy>& borrow, istream& in);


};


