#include"Sneaker.h"
//#include <string.h>
//#include <iostream>
//#include<iomanip>
using namespace std;

Sneaker::Sneaker() {
	ID = 0;
	strcpy_s(Brand, "");
	strcpy_s(Model, "");
	strcpy_s(Name, "");
	Collaboration = 0;
	strcpy_s(Name_Collaboration, "");
	strcpy_s(users, "");
	strcpy_s(Color, "");
	Luxury = 0;
}

Sneaker::Sneaker(int id, char* brand, char *type, char *name,bool collab, char* name_collab, char* user, char* colors, bool lux) {
	this->ID = id;
	strcpy_s(this->Brand, 30, brand);
	strcpy_s(this->Model, 30, type);
	strcpy_s(this->Name, 60, name);
	this->Collaboration = collab;
	strcpy_s(this->Name_Collaboration, 30, name_collab);
	strcpy_s(this->users, 30, user);
	strcpy_s(this->Color, 30, colors);
	this->Luxury = lux;
}

Sneaker::Sneaker(const Sneaker& p) {
	this->ID = p.ID;
	strcpy_s(this->Brand, 30, p.Brand);
	strcpy_s(this->Model, 30, p.Model);
	strcpy_s(this->Name, 60, p.Name);
	this->Collaboration = p.Collaboration;
	strcpy_s(this->Name_Collaboration, 30, p.Name_Collaboration);
	strcpy_s(this->users, 30, p.users);
	strcpy_s(this->Color, 30, p.Color);
	this->Luxury = p.Luxury;
}

ostream& operator << (ostream& out, const Sneaker& p) {
	out << "    " << setw(6) << left << p.ID << setw(20) << p.Brand << setw(30) << p.Model << setw(47) << p.Name << setw(6) << p.Collaboration;
	out << setw(20) << p.Name_Collaboration;
	out << setw(20) << p.users << setw(34) << p.Color << setw(5) << p.Luxury << endl;
	return out;
}

int Sneaker::getID() {
	return this->ID;
}

char* Sneaker::getname() {
	return this->Name;
}

void Sneaker::coutName() {
	cout << "       " << setw(9) << left << this->ID << setw(47) << this->Name;
}