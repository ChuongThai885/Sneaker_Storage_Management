#include"Header.h"
#include"Sneaker.h"
#include"Infor_Sneaker.h"

#include"Supplier.h"
#include"Customer.h"

#include"Bill.h"
#include"Infor_Bill.h"

class DB{
    private:
		SQLHANDLE SQLEnvHandle = NULL;
	    SQLHANDLE SQLConnectionHandle = NULL;
	    SQLHANDLE SQLStatementHandle = NULL;
	    SQLRETURN retCode = 0;
    public:
		void ketnoi();
		void close();
		void upload_data(Sneaker*&, int&, Supplier*&, int&, Customer*&, int&, Infor_Sneaker*&, int&, Bill*&, int&, Infor_Bill*&, int&);
		void create_bill_in(Sneaker*&, int&, Supplier*&, int&, Infor_Sneaker*&, int&, Bill*&, int&, Infor_Bill*&, int&);
		void create_bill_out(Customer*&, int&, Bill*&, int&);
		void upload_data_bill_out(Infor_Sneaker*&, int&, Infor_Bill*&, int&,int ,int ,float,int);
		void update_price(Infor_Sneaker*&, int, float, float);
		void funcionforsearch(test*&, int&);
};