#include "Infor_Sneaker.h"

Infor_Sneaker::Infor_Sneaker() {
	ID_Sneaker = 0;
	Size = 0;
	Amount = 0;
	Price = 0;
}

Infor_Sneaker::Infor_Sneaker(int id, float sz, int n, float p) {
	this->ID_Sneaker = id;
	this->Size = sz;
	this->Amount = n;
	this->Price = p;
}

Infor_Sneaker::Infor_Sneaker(const Infor_Sneaker& p) {
	this->ID_Sneaker = p.ID_Sneaker;
	this->Size = p.Size;
	this->Amount = p.Amount;
	this->Price = p.Price;
}

ostream& operator << (ostream& out, Infor_Sneaker p) {
	out << "       " << setw(9) << left << p.ID_Sneaker << setw(15) << p.Size << setw(18) << p.Amount << setw(10) << p.Price << endl;
	return out;
}

int Infor_Sneaker::getID() {
	return this->ID_Sneaker;
}

float Infor_Sneaker::getsize() {
	return this->Size;
}

int Infor_Sneaker::getamount() {
	return this->Amount;
}

float Infor_Sneaker::getprice() {
	return this->Price;
}

void Infor_Sneaker::in(){
	cout << left << setw(15) << this->Size << setw(18) << this->Amount << setw(10) <<  this->Price << endl;
}