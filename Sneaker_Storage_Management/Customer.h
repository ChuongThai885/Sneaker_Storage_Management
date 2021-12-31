#include"Header.h"

class Customer {
private:
	int ID;
	char Name[30];
	char Address[60];
	char Phone_Number[20];
	char Email[60];
public:
	Customer();
	Customer(const Customer&);
	Customer(int, char*, char*, char*, char*);
	~Customer();
	friend ostream& operator << (ostream&, Customer&);
};