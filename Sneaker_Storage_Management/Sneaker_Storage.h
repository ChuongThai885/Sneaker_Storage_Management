#pragma once
// In this class we will program the functions for the main program
#include"connect_DB.h"

class Sneaker_Storage
{
private:
	DB Database;
	Sneaker* S;
	int n_s;

	Supplier* Su;
	int n_su;

	Customer* c;
	int n_c;

	Infor_Sneaker* is;
	int n_is;

	Bill* b;
	int n_b;

	Infor_Bill* ib;
	int n_ib;
public:
	Sneaker_Storage();
	~Sneaker_Storage();
	void Show_Name_Sneaker(int);

	void Show_Sneaker();
	void Show_Supplier();
	void Show_Infor_Sneaker();
	void show_Bill();
	void Show_Customer();
	void Show_Infor_Bill();

	void price_search();
	void update_price();

	void Phieu_Nhap();
	void Phieu_Xuat();

	bool findID(int);
	bool findsz(int,float);
	int geta(int,float);
	float getp(int, float);

	void search(test*&, int, int, float, float);
	//friend ostream& operator << (ostream&, const Sneaker_Storage&);
};

