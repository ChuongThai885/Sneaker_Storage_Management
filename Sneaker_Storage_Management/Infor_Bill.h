#pragma once
#include"Header.h"

class Infor_Bill
{
private:
	int ID_Bill, ID_Sneaker;
	float Size;
	int amount;
	float Price_in, Price_out;
public :
	Infor_Bill();
	Infor_Bill(int, int, float, int,float, float);
	Infor_Bill(const Infor_Bill&);
	~Infor_Bill() {};
	friend ostream& operator << (ostream&,const Infor_Bill&);
	float getpriceout();
	int getamount();
};

