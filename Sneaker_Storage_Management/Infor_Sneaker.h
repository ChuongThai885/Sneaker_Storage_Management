#pragma once
#include"Header.h"

class Infor_Sneaker{
private:
	int ID_Sneaker;
	float Size;
	int Amount;
	float Price;
public:
	Infor_Sneaker();
	Infor_Sneaker(int, float, int, float);
	Infor_Sneaker(const Infor_Sneaker&);
	~Infor_Sneaker() {};
	friend ostream& operator << (ostream&, Infor_Sneaker);
	int getID();
	float getsize();
	int getamount();
	float getprice();
	void in();  //in ra sz,amount ,price
};

