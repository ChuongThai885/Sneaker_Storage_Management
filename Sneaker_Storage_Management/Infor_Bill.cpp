#include "Infor_Bill.h"

Infor_Bill::Infor_Bill() {
	ID_Bill = 0;
	ID_Sneaker = 0;
	Size = 0;
	amount = 0;
	Price_in = Price_out = 0;
}

Infor_Bill::Infor_Bill(int idb, int ids, float s, int n, float pi, float po) {
	this->ID_Bill = idb;
	this->ID_Sneaker = ids;
	this->Size = s;
	this->amount = n;
	this->Price_in = pi;
	this->Price_out = po;
}

Infor_Bill::Infor_Bill(const Infor_Bill& i) {
	this->ID_Bill = i.ID_Bill;
	this->ID_Sneaker = i.ID_Sneaker;
	this->Size = i.Size;
	this->amount = i.amount;
	this->Price_in = i.Price_in;
	this->Price_out = i.Price_out;
}

ostream& operator << (ostream& x, const Infor_Bill& p) {
	x << "      " << setw(12) << left << p.ID_Bill << setw(12) << p.ID_Sneaker << setw(12) << p.Size << setw(13) << p.amount;
	if (p.Price_in == -1) {
		x << setw(18) << "NULL" ;
	}
	else {
		x << setw(18) << p.Price_in ;
	}
	if (p.Price_out == -1) {
		x << setw(10) << "NULL" << endl;
	}
	else {
		x << setw(10) << p.Price_out << endl;
	}
	return x;
}

float Infor_Bill::getpriceout() {
	return this->Price_out;
}

int Infor_Bill::getamount() {
	return this->amount;
}