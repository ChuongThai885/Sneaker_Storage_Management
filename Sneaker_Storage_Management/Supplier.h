#pragma once
#include"Header.h"
class Supplier
{
private:
	int ID;
	char Name[30];
	char Address[60];
	char Phone_Number[20];
	char Email[60];
public:
	Supplier();
	Supplier(const Supplier&);
	Supplier(int, char*, char*, char*, char*);
	~Supplier() {};
	friend ostream& operator << (ostream&,const Supplier&);
};

