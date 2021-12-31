#include "Sneaker_Storage.h"


//-----------------------------------------------DEFAULT CONSTRUCTOR----------------------------------------------------

Sneaker_Storage::Sneaker_Storage() {
	Database.ketnoi();
	this->n_s = 0;
    S = new Sneaker[100];

	this->n_su = 0;
	Su = new Supplier[100];
	
	this->n_c = 0;
	c = new Customer[100];
	
	this->n_is = 0;
	is = new Infor_Sneaker[100];
	
	this->n_b = 0;
	b = new Bill[100];
	
	this->n_ib = 0;
	ib = new Infor_Bill[100];

	Database.upload_data(S, this->n_s, Su, this->n_su, c, this->n_c, is, this->n_is, b, this->n_b, ib, this->n_ib);
}


//---------------------------------------------------DESTRUCTOR--------------------------------------------------------------

Sneaker_Storage::~Sneaker_Storage() {
	Database.close();
}


//------------------------------------------------SEARCH ID SNEAKER-----------------------------------------------------

bool Sneaker_Storage::findID(int a) {
	for (int i = 0; i < this->n_is; i++) {
		if (this->is[i].getID() == a) {
			return TRUE;
		}
	}
	return FALSE;
}


//-----------------------------------------------SEARCH SIZE SNEAKER----------------------------------------------------

bool Sneaker_Storage::findsz(int a,float b) {
	for (int i = 0; i < this->n_is; i++) {
		if (this->is[i].getID() == a && this->is[i].getsize() == b) {
			return TRUE;
		}
	}
	return FALSE;
}


//---------------------------------------------GET AMOUNT SNEAKER-------------------------------------------------------

int Sneaker_Storage::geta(int a, float b) {
	for (int i = 0; i < this->n_is; i++) {
		if (this->is[i].getID() == a && this->is[i].getsize() == b) {
			return this->is[i].getamount();
		}
	}
	return -1;
}


//---------------------------------------------------GET PRICE-----------------------------------------------------------

float Sneaker_Storage::getp(int a, float b) {
	for (int i = 0; i < this->n_is; i++) {
		if (this->is[i].getID() == a && this->is[i].getsize() == b) {
			return this->is[i].getprice();
		}
	}
	return -1;
}


//------------------------------------------------SHOW NAME SNEAKER---------------------------------------------------------

void Sneaker_Storage::Show_Name_Sneaker( int n) {
	for (int i = 0; i < this->n_s; i++) {
		if (this->S[i].getID() == n) {
			this->S[i].coutName();   // cout ID and name of this sneaker
		}
	}
}


//--------------------------------------------------SHOW SNEAKER-----------------------------------------------------------

void Sneaker_Storage::Show_Sneaker() {
	cout << endl;
	cout << "  _____________________________________________________________________________________________________________________________________________________________________________________________" << endl;
	cout << " |      |                   |                             |                                            |       |                   |                   |                              |        |" << endl;
	cout << " |  ID  |   Brand Sneaker   |        Model Sneaker        |                  Name Sneaker              | Colab | Name Brand Colab  |       Users       |             Colors           | Luxury |" << endl;
	cout << " |______|___________________|_____________________________|____________________________________________|_______|___________________|___________________|______________________________|________|" << endl << endl;
	for (int i = 0; i < this->n_s; i++) {
		cout << this->S[i];
	}
	cout << endl;
}



//--------------------------------------------------SHOW SUPPLIER----------------------------------------------------------

void Sneaker_Storage::Show_Supplier() {
	cout << endl;
	cout << "  ___________________________________________________________________________________________________________________________________________________________________________________" << endl;
	cout << " |      |                              |                                                            |                   |                                                            |" << endl;
	cout << " |  ID  |         Name Supplier        |                           Address                          |   Phone Number    |                        Email Supplier                      |" << endl;
	cout << " |______|______________________________|____________________________________________________________|___________________|____________________________________________________________|" << endl << endl;
	for (int i = 0; i < this->n_su; i++) {
		cout << this->Su[i];
	}
	cout << endl;
}


//--------------------------------------------------SHOW CUSTORMER---------------------------------------------------------

void Sneaker_Storage::Show_Customer() {
	cout << endl;
	cout << "  ___________________________________________________________________________________________________________________________________________________________________________________" << endl;
	cout << " |      |                              |                                                            |                   |                                                            |" << endl;
	cout << " |  ID  |         Name Customer        |                           Address                          |   Phone Number    |                        Email Customer                      |" << endl;
	cout << " |______|______________________________|____________________________________________________________|___________________|____________________________________________________________|" << endl << endl;
	for (int i = 0; i < this->n_c; i++) {
		cout << this->c[i];
	}
}


//-----------------------------------------------SHOW INFOR SNEAKER--------------------------------------------------------

void Sneaker_Storage::Show_Infor_Sneaker() {
	
	cout << endl;
	cout << "  _______________________________________________________________" << endl;
	cout << " |            |              |                 |                 |" << endl;
	cout << " | ID_Sneaker |     Size     |     Amount      |      Price      |" << endl;
	cout << " |____________|______________|_________________|_________________|" << endl << endl;

	for (int i = 0; i < this->n_is; i++) {
		if (i == 0) {
			cout << this->is[i];
		}
		else {
			if (this->is[i].getID() == this->is[i - 1].getID()) {
				cout << "       " << setw(9) << left << "";
				this->is[i].in();
			}
			else {
				cout << "  _______________________________________________________________" << endl << endl;
				cout << this->is[i];
			}
		}

		//cout << this->is[i];
	}
	cout << endl;
}


//----------------------------------------------------SHOW BILL------------------------------------------------------------

void Sneaker_Storage::show_Bill() {
	cout << endl;
	cout << "  _____________________________________________________________________" << endl;
	cout << " |         |             |             |                 |             |" << endl;
	cout << " | ID_Bill | ID Customer | ID Supplier |    Date_Bill    |  Bill_in ?  |" << endl;
	cout << " |_________|_____________|_____________|_________________|_____________|" << endl << endl;
	for (int i = 0; i < this->n_b; i++) {
		cout << this->b[i];
	}
	cout << endl;
}


//-----------------------------------------------------SHOW INFOR BILL-----------------------------------------------------

void Sneaker_Storage::Show_Infor_Bill() {
	cout << endl;
	cout << "  _________________________________________________________________________________" << endl;
	cout << " |         |              |          |          |                |                 |" << endl;
	cout << " | ID_Bill |  ID Sneaker  |   Size   |  Amount  |    Price in    |    Price out    |" << endl;
	cout << " |_________|______________|__________|__________|________________|_________________|" << endl << endl;
	for (int i = 0; i < this->n_ib; i++) {
		cout << this->ib[i];
	}
}


//------------------------------------------------------PHIEU NHAP---------------------------------------------------------

void Sneaker_Storage::Phieu_Nhap() {
	cout << endl << "\n                          PHIEU NHAP" << endl;
	Database.create_bill_in(S, this->n_s, Su, this->n_su, is, this->n_is, b, this->n_b, ib, this->n_ib);
	this->n_is = 0;
	Database.upload_data(S, this->n_s, Su, this->n_su, c, this->n_c, is, this->n_is, b, this->n_b, ib, this->n_ib);
}



//--------------------------------------------TIM KIEM THEO KHOANG GIA-----------------------------------------------------

void Sneaker_Storage::search(test*&x,int a,int b,float c, float d) {
	if (a == b) {
		if (x[a].sz <= c && x[a].sz >= d) {
			Show_Name_Sneaker(x[a].id);
			cout << setw(10) << setprecision(2) << fixed << x[a].sz << endl;
		}
	}
	else {
		search(x, a, (a + b) / 2, c, d);
		search(x, (a + b) / 2 + 1, b, c, d);
	}
}

void Sneaker_Storage::price_search() {
	test* n = new test[100];
	int n_n=0;
	Database.funcionforsearch(n, n_n);

	float p1, p2;
	cout << "\n Lowest Price : ";
	do {
		cin >> p1;
		if (p1 < 0) {
			cout << "\n Please re-enter the lowest Price : ";
		}
	} while (p1 < 0);

	cout << "\n Highest Price : ";
	do {
		cin >> p2;
		if (p1 > p2) {
			cout << "\n Please re-enter the highest Price : ";
		}
	} while (p1 > p2);
	cout << endl;
	cout << "  _____________________________________________________________________________" << endl;
	cout << " |            |                                              |                 |" << endl;
	cout << " | ID_Sneaker |                  Name Sneaker                |  Average Price  |" << endl;
	cout << " |____________|______________________________________________|_________________|" << endl << endl;

	search(n, 0, n_n - 1, p2, p1);
	delete[] n;
}


//------------------------------------------------CAP NHAT GIA BAN---------------------------------------------------------

void Sneaker_Storage::update_price() {
	cout << endl;
	cout << "  _____________________________________________________________________________________________________________" << endl;
	cout << " |            |                                             |              |                 |                 |" << endl;
	cout << " | ID_Sneaker |                  Name Sneaker               |     Size     |     Amount      |      Price      |" << endl;
	cout << " |____________|_____________________________________________|______________|_________________|_________________|" << endl << endl;
	for (int i = 0; i < this->n_is; i++) {
		if (i == 0) {
			Show_Name_Sneaker(this->is[i].getID());
			this->is[i].in();
		}
		else {
			if (this->is[i].getID() == this->is[i - 1].getID()) {
				cout << "       " << setw(9) << left << " " << setw(47) << " ";
				this->is[i].in();
			}
			else {
				cout << "  _____________________________________________________________________________________________________________" << endl << endl;
				Show_Name_Sneaker(this->is[i].getID());
				this->is[i].in();
			}
		}
	}
	cout << endl;
	
	int id;
	float ex, pri,sz;
	cout << "\nenter the ID of the sneakers you want to update the price : ";
	do {
		cin >> ex;
		id = (int)ex;
		if (this->findID(id) == FALSE || ex != (int)ex) {
			cout << "\nPlease re-enter the ID of the sneakers ! ";
		}
	} while (this->findID(id) == FALSE || ex != (int)ex);
	
	cout << "\nEnter sneaker's size you want to buy : ";
	do {
		cin.ignore();
		cin >> sz;
		if (this->findsz(id, sz) == FALSE) {
			cout << "\nPlease re-enter sneaker's size ! ";
		}
	} while (this->findsz(id, sz) == FALSE);

	cout << "\nEnter the price you want to update for sneakers : ";
	do {
		cin.ignore();
		cin >> pri;
		if (pri < 1) {
			cout << "\nPlease re-enter the price ! ";
		}
	} while (pri < 1);
	Database.update_price(is, id, pri, sz);

	this->n_is = 0;
	Database.upload_data(S, this->n_s, Su, this->n_su, c, this->n_c, is, this->n_is, b, this->n_b, ib, this->n_ib);
}


//-----------------------------------------STRUCT TEST FOR INSERT INFOR BILL------------------------------------------------

bool thu(test *&a,int n,int x,float y) {
	if (n > 0) {
		for (int i = 0; i < n; i++) {
			if (a[i].id == x && a[i].sz == y) {
				return FALSE;
			}
		}
		return TRUE;
	}
	else {
		if (a[0].id == x && a[0].sz == y) {
			return FALSE;
		}
		else return TRUE;
	}
}


//---------------------------------------------------PHIEU XUAT------------------------------------------------------------

void Sneaker_Storage::Phieu_Xuat() {
	Database.create_bill_out(c, this->n_c, b, this->n_b);

	test *n=new test[100];

	cout << endl;
	cout << "  _____________________________________________________________________________________________________________" << endl;
	cout << " |            |                                             |              |                 |                 |" << endl;
	cout << " | ID_Sneaker |                  Name Sneaker               |     Size     |     Amount      |      Price      |" << endl;
	cout << " |____________|_____________________________________________|______________|_________________|_________________|" << endl << endl;
	for (int i = 0; i < this->n_is; i++) {
		if (i == 0) {
			Show_Name_Sneaker(this->is[i].getID());
			this->is[i].in();
		}
		else {
			if (this->is[i].getID() == this->is[i-1].getID()) {
				cout << "       " << setw(9) << left << " " << setw(47) << " ";
				this->is[i].in();
			}
			else {
				cout << "  _____________________________________________________________________________________________________________" << endl << endl;
				Show_Name_Sneaker(this->is[i].getID());
				this->is[i].in();
			}
		}
	}
	cout << endl;
	
	float price = 0;
	int n2;
	cout << "\nEnter the number of models you want to buy : ";
	do {
		cin >> n2;
		if (n2 < 0) {
			cout << "\nPlease re-enter the number of models you want to buy ! ";
		}
	} while (n2 < 0);

	for (int i = 0; i < n2; i++) {
		do {
			cout << "\nEnter sneaker's ID you want to buy : ";
			float ex;
			do {
				cin >> ex;
				n[i].id = (int)ex;
				if (this->findID(n[i].id) == FALSE || ex != (int)ex) {
					cout << "\nPlease re-enter sneaker's ID ! " ;
				}
			} while (this->findID(n[i].id) == FALSE || ex != (int)ex);

			cout << "\nEnter sneaker's size you want to buy : ";
			do {
				cin.ignore();
				cin >> n[i].sz;
				if (this->findsz(n[i].id, n[i].sz) == FALSE || this->geta(n[i].id, n[i].sz) ==0 ) {
					cout << "\nPlease re-enter sneaker's size ! ";
				}
			} while (this->findsz(n[i].id, n[i].sz) == FALSE || this->geta(n[i].id, n[i].sz) == 0 );
			if (i > 0) {
				if (thu(n, i - 1, n[i].id, n[i].sz) == FALSE) {
					cout << "\nPlease re-enter sneaker's ID ! ";
				}
			}
		} while (thu(n, i - 1, n[i].id, n[i].sz) == FALSE && i>0);

		int n3;
		cout << "\nEnter the number of sneakers you want to buy : ";
		do {
			cin >> n3;
			if (n3 <= 0 || n3 > this->geta(n[i].id, n[i].sz)) {
				cout << "\nPlease re-enter the number of models you want to buy ! ";
			}
		} while (n3 <= 0 || n3 > this->geta(n[i].id, n[i].sz));

		Database.upload_data_bill_out(is,this->n_is,ib,this->n_ib,this->n_b,n[i].id, n[i].sz,n3);
		price = price + (n3 * this->getp(n[i].id, n[i].sz));
	}
	cout << "\n  Total : " << setprecision(2) << fixed << price << "$" << endl;
	cout << "\n  Thanks for shopping in our store !"<< endl;

	this->n_is = 0;
	Database.upload_data(S, this->n_s, Su, this->n_su, c, this->n_c, is, this->n_is, b, this->n_b, ib, this->n_ib);
	delete[] n;
}