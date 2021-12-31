#include "Bill.h"

Bill::Bill() {
	ID = 0;
	ID_Customer = 0;
	ID_Supplier = 0;
	strcpy_s(Date_Bill, "");
	Bill_in = 0;
}

Bill::Bill(int id, int idc, int ids, char* date, bool b) {
	this->ID = id;
	this->ID_Customer = idc;
	this->ID_Supplier = ids;
	strcpy_s(this->Date_Bill, 12, date);
	this->Bill_in = b;
}

Bill::Bill(const Bill& b) {
	this->ID = b.ID;
	this->ID_Customer = b.ID_Customer;
	this->ID_Supplier = b.ID_Supplier;
	strcpy_s(this->Date_Bill, 12, b.Date_Bill);
	this->Bill_in = b.Bill_in;
}

ostream& operator <<(ostream& out, Bill& b) {
	out << "      " << setw(7) << left << b.ID;
	if (b.ID_Customer == -1) {
		out << setw(14) << "NULL";
	}
	else out << setw(14) << b.ID_Customer;
	if (b.ID_Supplier == -1) {
		out << setw(14) << "NULL";
	}
	else out << setw(14) << b.ID_Supplier;
	out << setw(22) << b.Date_Bill ;
	if (b.Bill_in == 1) {
		out << setw(6) << "YES" << endl;
	}else out << setw(6) << "NO" << endl;
	return out;
}