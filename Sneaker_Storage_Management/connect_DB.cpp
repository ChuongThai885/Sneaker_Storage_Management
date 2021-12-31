#include"connect_DB.h"
using namespace std;

//--------------------------------------------------CHECK LENGTH STRING-------------------------------------------------

bool checklength(string m, int n) {
    if (m.length() <= n) return 1;
    else return 0;
}

//----------------------------------------------SHOW  ERROR FROM DATABASE-----------------------------------------------

void showSQLError(unsigned int handleType, const SQLHANDLE& handle){
    SQLCHAR SQLState[1024];
    SQLCHAR message[1024];
    if (SQL_SUCCESS == SQLGetDiagRec(handleType, handle, 1, SQLState, NULL, message, 1024, NULL))
        cout << "SQL driver message: " << message << "\nSQL state: " << SQLState << "." << endl;
}

//-----------------------------------------------CONNECT DATABASE-------------------------------------------------------

void DB::ketnoi(){
    do {
        if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &SQLEnvHandle))
            break;

        if (SQL_SUCCESS != SQLSetEnvAttr(SQLEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
            break;

        if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, SQLEnvHandle, &SQLConnectionHandle))
            break;

        if (SQL_SUCCESS != SQLSetConnectAttr(SQLConnectionHandle, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0))
            break;

        SQLCHAR retConString[1024];
        switch (SQLDriverConnect(SQLConnectionHandle, NULL, (SQLCHAR*)"DRIVER={SQL Server}; SERVER=LAPTOP-2T731P5F\\SQLEXPRESS02; DATABASE=Sneaker_Storage; Trusted_Connection=yes;", SQL_NTS, retConString, 1024, NULL, SQL_DRIVER_NOPROMPT)) {

        case SQL_SUCCESS:
            break;
        case SQL_SUCCESS_WITH_INFO:
            break;
        case SQL_NO_DATA_FOUND:
            showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
            retCode = -1;
            break;
        case SQL_INVALID_HANDLE:
            showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
            retCode = -1;
            break;
        case SQL_ERROR:
            showSQLError(SQL_HANDLE_DBC, SQLConnectionHandle);
            retCode = -1;
            break;
        default:
            break;
        }

        if (retCode == -1)
            break;

        if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, SQLConnectionHandle, &SQLStatementHandle))
            break;
        if (SQLFetch(SQLStatementHandle) == SQL_SUCCESS) {
            cout << "Connect OK" << endl;
        }

    } while (FALSE);
}


//-----------------------------------------------UPLOAD DATA------------------------------------------------------------

void DB::upload_data(Sneaker *& Sneakers,int &n, Supplier *& Sup, int& ns, Customer *& Cus, int& nc, Infor_Sneaker *& InforSneaker, int& nis, Bill *& bill, int& nb, Infor_Bill *& ib, int& nib){
    this->ketnoi();

    //  SNEAKER
    char SQLQuery[] = "SELECT * FROM Sneaker";
    if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)SQLQuery, SQL_NTS)) {
        showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
        close();
    }
    else {
        int i=1;
        int id;
        char brand[30];
        char model[30];
        char name[60];
        bool collab;
        char Name_collab[30];
        char user[30];
        char color[30];
        bool lux;
        while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS) {
            if (i > n) {
                SQLGetData(SQLStatementHandle, 1, SQL_C_DEFAULT, &id, sizeof(id), NULL);
                SQLGetData(SQLStatementHandle, 2, SQL_C_DEFAULT, &brand, sizeof(brand), NULL);
                SQLGetData(SQLStatementHandle, 3, SQL_C_DEFAULT, &model, sizeof(model), NULL);
                SQLGetData(SQLStatementHandle, 4, SQL_C_DEFAULT, &name, sizeof(name), NULL);
                SQLGetData(SQLStatementHandle, 5, SQL_C_DEFAULT, &collab, sizeof(collab), NULL);
                if (SQLGetData(SQLStatementHandle, 6, SQL_C_DEFAULT, &Name_collab, sizeof(Name_collab), NULL) == -1) {
                    strcpy_s(Name_collab, "NULL");
                }
                SQLGetData(SQLStatementHandle, 7, SQL_C_DEFAULT, &user, sizeof(user), NULL);
                SQLGetData(SQLStatementHandle, 8, SQL_C_DEFAULT, &color, sizeof(color), NULL);
                SQLGetData(SQLStatementHandle, 9, SQL_C_DEFAULT, &lux, sizeof(lux), NULL);

                Sneaker* st = new Sneaker(id, brand, model, name, collab, Name_collab, user, color, lux);
                *(Sneakers + n) = *st;
                n++;
            }i++;
        }
    }
    SQLCancel(SQLStatementHandle);
    ;
    //  SUPPLIER
    char s[] = "SELECT * FROM Supplier";
    if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)s, SQL_NTS)) {
        showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
        close();
    }
    else {
        int i = 1;
        int id;
        char name[30];
        char add[60];
        char phone_number[20];
        char email[60];
        while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS) {
            if (i > ns) {
                SQLGetData(SQLStatementHandle, 1, SQL_C_DEFAULT, &id, sizeof(id), NULL);
                SQLGetData(SQLStatementHandle, 2, SQL_C_DEFAULT, &name, sizeof(name), NULL);
                if (SQLGetData(SQLStatementHandle, 3, SQL_C_DEFAULT, &add, sizeof(add), NULL) == -1) {
                    strcpy_s(add, "NULL");
                }
                if (SQLGetData(SQLStatementHandle, 4, SQL_C_DEFAULT, &phone_number, sizeof(phone_number), NULL) == -1) {
                    strcpy_s(phone_number, "NULL");
                }
                if (SQLGetData(SQLStatementHandle, 5, SQL_C_DEFAULT, &email, sizeof(email), NULL) == -1) {
                    strcpy_s(email, "NULL");
                }
                Supplier* Supply = new Supplier(id, name, add, phone_number, email);
                *(Sup + ns) = *Supply;
                ns++;
            }
            i++;
        }
    }
    SQLCancel(SQLStatementHandle);


    //  CUSTOMER
    char c[] = "SELECT * FROM Customer";
    if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)c, SQL_NTS)) {
        showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
        close();
    }
    else {
        int i = 1;
        int id;
        char name[30];
        char add[60];
        char phone_number[20];
        char email[60];
        while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS) {
            if (i > nc) {
                SQLGetData(SQLStatementHandle, 1, SQL_C_DEFAULT, &id, sizeof(id), NULL);
                SQLGetData(SQLStatementHandle, 2, SQL_C_DEFAULT, &name, sizeof(name), NULL);
                if (SQLGetData(SQLStatementHandle, 3, SQL_C_DEFAULT, &add, sizeof(add), NULL) == -1) {
                    strcpy_s(add, "NULL");
                }
                if (SQLGetData(SQLStatementHandle, 4, SQL_C_DEFAULT, &phone_number, sizeof(phone_number), NULL) == -1) {
                    strcpy_s(phone_number, "NULL");
                }
                if (SQLGetData(SQLStatementHandle, 5, SQL_C_DEFAULT, &email, sizeof(email), NULL) == -1) {
                    strcpy_s(email, "NULL");
                }
                Customer* customer = new Customer(id, name, add, phone_number, email);
                *(Cus + nc) = *customer;
                nc++;
            }
            i++;
        }
    }
    SQLCancel(SQLStatementHandle);


    //  INFOR_SNEAKER
    char IS[] = "SELECT * FROM Infor_Sneaker";
    if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)IS, SQL_NTS)) {
        showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
    close();
    }
    else {
        int i = 1;
        int id_s;
        float sz;
        int amount;
        float Pr;
        while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS) {
            if (i > nis) {
                SQLGetData(SQLStatementHandle, 1, SQL_C_DEFAULT, &id_s, sizeof(id_s), NULL);
                SQLGetData(SQLStatementHandle, 2, SQL_C_FLOAT, &sz, sizeof(sz), NULL);
                SQLGetData(SQLStatementHandle, 3, SQL_C_DEFAULT, &amount, sizeof(amount), NULL);
                SQLGetData(SQLStatementHandle, 4, SQL_C_FLOAT, &Pr, sizeof(Pr), NULL);
                Infor_Sneaker* is1 = new Infor_Sneaker(id_s, sz, amount, Pr);
                *(InforSneaker + nis) = *is1;
                nis++;
            }
            i++;
        }
    }
    SQLCancel(SQLStatementHandle);


    //  BILL
    char b[] = "SELECT * FROM Bill";
    if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)b, SQL_NTS)) {
        showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
        close();
    }
    else {
        int i = 1;
        int ID, ID_Customer, ID_Supplier;
        char Date_Bill[12];
        bool Bill_in;
        while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS) {
            if (i > nb) {
                SQLGetData(SQLStatementHandle, 1, SQL_C_DEFAULT, &ID, sizeof(ID), NULL);
                if (SQLGetData(SQLStatementHandle, 2, SQL_C_DEFAULT, &ID_Customer, sizeof(ID_Customer), NULL) == -1) {
                    ID_Customer = -1;
                }
                if (SQLGetData(SQLStatementHandle, 3, SQL_C_DEFAULT, &ID_Supplier, sizeof(ID_Supplier), NULL) == -1) {
                    ID_Supplier = -1;
                }
                SQLGetData(SQLStatementHandle, 4, SQL_C_DEFAULT, &Date_Bill, sizeof(Date_Bill), NULL);
                SQLGetData(SQLStatementHandle, 5, SQL_C_DEFAULT, &Bill_in, sizeof(Bill_in), NULL);
                Bill* bl = new Bill(ID, ID_Customer, ID_Supplier, Date_Bill, Bill_in);
                //cout << *bl;
                *(bill + nb) = *bl;
                nb++;
            }
            i++;
        }
    }
    SQLCancel(SQLStatementHandle);


    //  INFOR_BILL
    char IB[] = "SELECT * FROM Infor_Bill";
    if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)IB, SQL_NTS)) {
        showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
        close();
    }
    else {
        int i = 1;
        int ID_Bill, ID_Sneaker;
        float Size;
        int amount;
        float Price_in, Price_out;
        while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS) {
            if (i > nib) {
                SQLGetData(SQLStatementHandle, 1, SQL_C_DEFAULT, &ID_Bill, sizeof(ID_Bill), NULL);
                SQLGetData(SQLStatementHandle, 2, SQL_C_DEFAULT, &ID_Sneaker, sizeof(ID_Sneaker), NULL);
                SQLGetData(SQLStatementHandle, 3, SQL_C_FLOAT, &Size, sizeof(Size), NULL);
                SQLGetData(SQLStatementHandle, 4, SQL_C_DEFAULT, &amount, sizeof(amount), NULL);
                if (SQLGetData(SQLStatementHandle, 5, SQL_C_FLOAT, &Price_in, sizeof(Price_in), NULL) == -1) {
                    Price_in = -1;
                }
                if (SQLGetData(SQLStatementHandle, 6, SQL_C_FLOAT, &Price_out, sizeof(Price_out), NULL) == -1) {
                    Price_out = -1;
                }
                Infor_Bill* ifb = new Infor_Bill(ID_Bill, ID_Sneaker, Size, amount, Price_in, Price_out);
                *(ib + nib) = *ifb;
                nib++;
            }
            i++;
        }
    }
    SQLCancel(SQLStatementHandle);
}


//----------------------------------------------------BILL IN----------------------------------------------------------------

void DB::create_bill_in(Sneaker*& Sneakers, int& n, Supplier*& Sup, int& ns, Infor_Sneaker*& InforSneaker, int& nis, Bill*& bill, int& nb, Infor_Bill*& ib, int& nib) {
    string m;
    string m1 ="declare @d date = getdate() execute Insert_Bil_in ";
    m1 += to_string(nb+1);
    //cout << m1.length() << endl;
    //cout << nb << endl;

    //  insert bill in
    cout << "\n Name supplier                 : ";
    do {
        cin.ignore();
        getline(cin, m);
        if (checklength(m, 30) == 0) {
            cout << "\n Please re-enter the name of the supplier !!" << endl;
        }
    } while (checklength(m, 30) == 0);
    if (m == "NULL") {
        m = ", NULL, NULL, NULL, NULL, @d;";
    }
    else {
        m = " , '" + m + "' , ";

        string n1, n2, n3;
        cout << "\n Enter supplier's address      : ";
        do {
            //cin.ignore();
            getline(cin, n1);
            if (checklength(n1, 60) == 0) {
                cout << "\n Please re-enter supplier's address !!" << endl;
            }
        } while (checklength(n1, 60) == 0);
        if (n1 == "NULL") {
            m += "NULL , ";
        }
        else {
            m += "'";
            m += n1;
            m += "' , ";
        }

        cout << "\n Enter supplier's phone number : ";
        do {
            //cin.ignore();
            getline(cin, n2);
            if (checklength(n2, 20) == 0) {
                cout << "\n Please re-enter supplier's phone number !!" << endl;
            }
        } while (checklength(n2, 20) == 0);
        if (n2 == "NULL") {
            m += "NULL , ";
        }
        else {
            m += "'";
            m += n2;
            m += "' , ";
        }

        cout << "\n Enter supplier's email        : ";
        do {
            //cin.ignore();
            getline(cin, n3);
            if (checklength(n3, 60) == 0) {
                cout << "\n Please re-enter supplier's email !!" << endl;
            }
        } while (checklength(n3, 60) == 0);
        if (n3 == "NULL") {
            m += "NULL , @d;";
        }
        else {
            m += "'";
            m += n3;
            m += "' , @d;";
        }
    }
    m1 += m;
    cout << m1 << endl;
    
    const char* a = m1.c_str();
    if (SQL_SUCCESS != SQLExecDirectA(SQLStatementHandle, (SQLCHAR*)a, SQL_NTS)) {

        cout << "\n";
        showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
        cout << "\n";
        close();
    }
    SQLCancel(SQLStatementHandle);

    //  Insert Data
    
    int am;
    cout << "\nHow many sneakers do you want to import : "; 
    do {
        cin >> am;
        if (am < 0) cout << "\nError occurred, please re-enter !!" << endl;
    } while (am < 0);
    for (int i = 0; i < am; i++) {
        string chuoinhapdata;
        string chuoiupdate;
        chuoinhapdata = "Execute Insert_Data ";
        chuoiupdate = "UPDATE Infor_Sneaker SET Price_out = ";
        chuoinhapdata += to_string(nb + 1);
        string n1;

        cout << "\n\nEnter brand's name             : ";
        do {
            cin.ignore();
            getline(cin, n1);
            if (checklength(n1, 30) == 0) {
                cout << "\nPlease re-enter brand's name !!" << endl;
            }
        } while (checklength(n1, 30) == 0);
        chuoinhapdata = chuoinhapdata + ", '" + n1;

        string n2;
        cout << "\nEnter model's name              : ";
        do {
            //cin.ignore();
            getline(cin, n2);
            if (checklength(n2, 30) == 0) {
                cout << "\nPlease re-enter model's name !!" << endl;
            }
        } while (checklength(n2, 30) == 0);
        chuoinhapdata += "' , '" + n2;

        string n3;
        cout << "\nEnter sneaker's name            : ";
        do {
            //cin.ignore();
            getline(cin, n3);
            if (checklength(n3, 60) == 0) {
                cout << "\nPlease re-enter sneaker's name !!" << endl;
            }
        } while (checklength(n3, 60) == 0);
        chuoinhapdata += "' , '" + n3;
        chuoinhapdata += "' , ";

        cout << "\nCollaboration ? (0.no  1.yes)   : ";
        int cn;
        do {
            cin >> cn;
            if (cn > 1 || cn < 0) {
                cout << "\nPlease re-enter collaboration status !!" << endl;
            }
        } while (cn > 1 || cn < 0);
        chuoinhapdata += to_string(cn);

        if (cn == 1) {
            cout << "\nEnter name of brand collab with : ";
            do {
                cin.ignore();
                getline(cin, n1);
                if (checklength(n1, 30) == 0) {
                    cout << "\nPlease re-enter name of brand collab with !!" << endl;
                }
            } while (checklength(n1, 30) == 0);
            chuoinhapdata += " , '" + n1;
            chuoinhapdata += "'";
        }
        else {
            chuoinhapdata += ", NULL";
            cin.ignore();
        }
        
        string n4;
        cout << "\nUsers                           : ";
        do {
            //cin.ignore();
            getline(cin, n4);
            if (checklength(n4, 30) == 0) {
                cout << "\nPlease re-enter users !!" << endl;
            }
        } while (checklength(n4, 30) == 0);
        chuoinhapdata += " , '" + n4;

        string n5;
        cout << "\nColors                          : ";
        do {
            //cin.ignore();
            getline(cin, n5);
            if (checklength(n5, 30) == 0) {
                cout << "\nPlease re-enter colors !!" << endl;
            }
        } while (checklength(n5, 30) == 0);
        chuoinhapdata += "' , '" + n5;

        cout << "\nLuxury ?(0.no  1.yes)    : ";
        do {
            cin >> cn;
            if (cn > 1 || cn < 0) {
                cout << "\nPlease re-enter Luxury status !!" << endl;
            }
        } while (cn > 1 || cn < 0);
        chuoinhapdata += "' , " + to_string(cn);
        
        float s;
        cout << "\nEnter sneaker's size : ";
        do {
            cin >> s;
            if (s < 0) {
                cout << "\nPlease re-enter sneaker's size !!" << endl;
            }
        } while (s < 0);
        chuoinhapdata += ", ";
        chuoinhapdata += to_string(s);

        int am;
        cout << "\nEnter sneaker's amount : ";
        do {
            cin >> am;
            if (am < 0) {
                cout << "\nPlease re-enter sneaker's size !!" << endl;
            }
        } while (am < 0);
        chuoinhapdata += ", ";
        
        chuoinhapdata += to_string(am);

        float pi;
        cout << "\nEnter import prices : ";
        do {
            cin >> pi;
            if (pi < 0) {
                cout << "\nPlease re-enter import prices !!" << endl;
            }
        } while (pi < 0);
        chuoinhapdata += ", ";
        chuoinhapdata += to_string(pi);
        cout << chuoinhapdata << endl;

        
        const char*a1= chuoinhapdata.c_str();
        if (SQL_SUCCESS != SQLExecDirectA(SQLStatementHandle, (SQLCHAR*)a1, SQL_NTS)) {
            cout << "\n";
            showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
            cout << "\n";
            close();
        }
        SQLCancel(SQLStatementHandle);

        float po;
        cout << "\nEnter sales prices : ";
        do {
            cin >> po;
            if (po < 0) {
                cout << "\nPlease re-enter sales prices !!" << endl;
            }
        } while (po < 0);
        chuoiupdate += to_string(po);
        chuoiupdate += " WHERE ID_Sneaker = (SELECT ID_Sneaker FROM Sneaker WHERE Name_Sneaker = '";
        chuoiupdate += n3;
        chuoiupdate += "' ) AND Size = ";
        chuoiupdate += to_string(s);
        //cout << chuoiupdate << endl;

        const char* a2 = chuoiupdate.c_str();
        if (SQL_SUCCESS != SQLExecDirectA(SQLStatementHandle, (SQLCHAR*)a2, SQL_NTS)) {
            cout << "\n";
            showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
            cout << "\n";
            close();
        }
        else {

            cout << "\nINSERT SUCCESS" << endl;
        }
        SQLCancel(SQLStatementHandle);
    }
}


//----------------------------------------RUN PROCEDURE INSERT_BILL_OUT-------------------------------------------------

void DB::create_bill_out(Customer*& c, int& nc, Bill*& b, int& nb) {
    string st;
    string st1 = "EXECUTE Insert_Bill_out ";
    st1 += to_string(nb+1);

    cout << "\n Name Customer                 : ";
    do {
        cin.ignore();
        getline(cin, st);
        if (checklength(st, 30) == 0) {
            cout << "\n Please re-enter the name of the customer !!" << endl;
        }
    } while (checklength(st, 30) == 0);
    if (st == "NULL") {
        st = ", NULL, NULL, NULL, NULL";
    }
    else {
        st = " , '" + st + "' , ";

        string n1, n2, n3;
        cout << "\n Enter customer's address      : ";
        do {
            //cin.ignore();
            getline(cin, n1);
            if (checklength(n1, 60) == 0) {
                cout << "\n Please re-enter customer's address !!" << endl;
            }
        } while (checklength(n1, 60) == 0);
        if (n1 == "NULL") {
            st += "NULL , ";
        }
        else {
            st += "'";
            st += n1;
            st += "' , ";
        }

        cout << "\n Enter customer's phone number : ";
        do {
            //cin.ignore();
            getline(cin, n2);
            if (checklength(n2, 20) == 0) {
                cout << "\n Please re-enter customer's phone number !!" << endl;
            }
        } while (checklength(n2, 20) == 0);
        if (n2 == "NULL") {
            st += "NULL , ";
        }
        else {
            st += "'";
            st += n2;
            st += "' , ";
        }

        cout << "\n Enter customer's email        : ";
        do {
            //cin.ignore();
            getline(cin, n3);
            if (checklength(n3, 60) == 0) {
                cout << "\n Please re-enter customer's email !!" << endl;
            }
        } while (checklength(n3, 60) == 0);
        if (n3 == "NULL") {
            st += "NULL ";
        }
        else {
            st += "'";
            st += n3;
            st += "' ";
        }
    }
    st1 += st;

    const char* x = st1.c_str();
    if (SQL_SUCCESS != SQLExecDirectA(SQLStatementHandle, (SQLCHAR*)x, SQL_NTS)) {

        cout << "\n";
        showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
        cout << "\n";
        close();
    }
    SQLCancel(SQLStatementHandle);
}


//------------------------------------------RUN PROCEDURE UPDATE DATA---------------------------------------------------

void DB::upload_data_bill_out(Infor_Sneaker*& is, int& nis, Infor_Bill*& ib, int& nib,int ID_Bill,int ID_Sneaker,float Size,int Amount) {
    string str = "execute update_data ";
    str += to_string(ID_Bill + 1);
    str = str + " , " + to_string(ID_Sneaker) + " , " + to_string(Size) + " , " + to_string(Amount);
    const char* x1 = str.c_str();
    if (SQL_SUCCESS != SQLExecDirectA(SQLStatementHandle, (SQLCHAR*)x1, SQL_NTS)) {

        cout << "\n";
        showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
        cout << "\n";
        close();
    }
    SQLCancel(SQLStatementHandle);
}


//---------------------------------------------------UPDATE DATA--------------------------------------------------------

void DB::update_price(Infor_Sneaker*& is, int id, float price,float size) {
    string strg = "UPDATE Infor_Sneaker SET Price_out = ";
    strg += to_string(price);
    strg = strg + " WHERE  ID_Sneaker = ";
    strg += to_string(id);
    strg += " AND Size = ";
    strg += to_string(size);
    //cout << endl << "  " << strg << endl;
    const char* y = strg.c_str();
    if (SQL_SUCCESS != SQLExecDirectA(SQLStatementHandle, (SQLCHAR*)y, SQL_NTS)) {

        cout << "\n";
        showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
        cout << "\n";
        close();
    }
    else {

        cout << "\nUPDATE SUCCESS" << endl;
    }
    SQLCancel(SQLStatementHandle);
}


//-----------------------------------------------CANCEL CONNECTION---------------------------------------------------------

void DB::close() {
    SQLFreeHandle(SQL_HANDLE_STMT, SQLStatementHandle);
    SQLDisconnect(SQLConnectionHandle);
    SQLFreeHandle(SQL_HANDLE_DBC, SQLConnectionHandle);
    SQLFreeHandle(SQL_HANDLE_ENV, SQLEnvHandle);
}


//---------------------------------------------UPLOAD DATA FOR SEARCH---------------------------------------------------

void DB::funcionforsearch(test*& a, int &b) {
    char uh[] = "SELECT ID_Sneaker,AVG(Price_out) AS AVG_P FROM Infor_Sneaker GROUP BY ID_Sneaker ORDER BY AVG_P DESC";
    
    if (SQL_SUCCESS != SQLExecDirect(SQLStatementHandle, (SQLCHAR*)uh, SQL_NTS)) {
        showSQLError(SQL_HANDLE_STMT, SQLStatementHandle);
        close();
    }
    else {
        int x;
        float y;
        
        while (SQLFetch(SQLStatementHandle) == SQL_SUCCESS) {
            SQLGetData(SQLStatementHandle, 1, SQL_C_DEFAULT, &x, sizeof(x), NULL);
            SQLGetData(SQLStatementHandle, 2, SQL_C_FLOAT, &y, sizeof(y), NULL);
            a[b].id = x;
            a[b].sz = y;
            b++;
        }
    }
    SQLCancel(SQLStatementHandle);
    
}