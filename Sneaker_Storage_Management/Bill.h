#pragma once
#include"Header.h"
class Bill
{
private:
	int ID,ID_Customer,ID_Supplier;
	char Date_Bill[12];
	bool Bill_in;
public:
	Bill();
	Bill(int, int, int, char*, bool);
	Bill(const Bill&);
	~Bill() {};
	friend ostream& operator <<(ostream&, Bill&);
};

