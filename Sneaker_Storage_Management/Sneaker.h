#pragma once
#include"Header.h"

class Sneaker {
private:
	int ID;
	char Brand[30];
	char Model[30];
	char Name[60];
	bool Collaboration;
	char Name_Collaboration[30];
	char users[30];
	char Color[30];
	bool Luxury;
public:
	Sneaker();
	Sneaker(const Sneaker&);
	Sneaker(int,char*,char*,char*,bool,char*, char*, char*, bool);
	friend ostream& operator << (ostream&, const Sneaker&);
	~Sneaker() {};
	int getID();
	char* getname();
	void coutName();
	friend bool checkname(Sneaker*& S, char m, int n);
};