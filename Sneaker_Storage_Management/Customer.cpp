#include"Customer.h"

Customer::Customer() {
	ID = 0;
	strcpy_s(Name, " ");
	strcpy_s(Address, " ");
	strcpy_s(Phone_Number, " ");
	strcpy_s(Email, " ");
}

Customer::Customer(int id, char* name, char* address, char* phonenumber, char* email) {
	this->ID = id;
	strcpy_s(this->Name, 30, name);
	strcpy_s(this->Address, 60, address);
	strcpy_s(this->Phone_Number, 20, phonenumber);
	strcpy_s(this->Email, 60, email);
}

Customer::Customer(const Customer& p) {
	this->ID = p.ID;
	strcpy_s(this->Name, 30, p.Name);
	strcpy_s(this->Address, 60, p.Address);
	strcpy_s(this->Phone_Number, 20, p.Phone_Number);
	strcpy_s(this->Email, 60, p.Email);
}

Customer::~Customer() {

}

ostream& operator << (ostream& o, Customer& s) {
	o << "    " << setw(6) << left << s.ID << setw(31) << s.Name << setw(61) << s.Address << setw(20) << s.Phone_Number << setw(60) << s.Email << endl;
	return o;
}