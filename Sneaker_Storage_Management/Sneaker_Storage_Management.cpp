#include"Sneaker_Storage.h"

int main() {
    Sneaker_Storage a;
    int cv;
    do {
        cout << "\n         SNEAKER WAREHOUSE MANAGEMENT PROGRAM" << endl;
        cout << "   ________________________________________________" << endl;
        cout << "  |                                                |" << endl;
        cout << "  |  1.Create import bill                          |" << endl;
        cout << "  |  2.Create sales bill                           |" << endl;
        cout << "  |  3.Show current list                           |" << endl;
        cout << "  |  4.Update sneakers price                       |" << endl;
        cout << "  |  5.Search function by price range              |" << endl;
        cout << "  |  0.Close program                               |" << endl;
        cout << "  |________________________________________________|" << endl;
        do {
            cin >> cv;
            if (cv < 0 || cv > 5) {
                cout << "\n  Please re-enter the values !!!";
            }
        } while (cv < 0 || cv > 5);
        switch (cv) {
        case 1:    // tạo phiếu nhập
            a.Phieu_Nhap();
            system("pause");
            break;
        case 2:   // tạo phiếu xuất
            a.Phieu_Xuat();
            cout << endl;
            system("pause");
            break;
        case 3:   //in ra bảng tự chọn
            int i;
            cout << endl << "   ___________________________";
            cout << endl << "  |                           |";
            cout << endl << "  | 1.Sneaker list            |";
            cout << endl << "  | 2.Infor Sneaker list      |";
            cout << endl << "  | 3.Supplier list           |";
            cout << endl << "  | 4.Customer list           |";
            cout << endl << "  | 5.Bill list               |";
            cout << endl << "  | 6.Infor Bill list         |" ;
            cout << endl << "  |___________________________|" << endl;
            do {
                cin >> i;
                if (i > 6 || i < 1) cout << "\n  Please re-enter the values !!!";
            } while (i > 6 || i < 1);
            switch (i) {
                case 1:  // Sneaker
                    a.Show_Sneaker();
                    cout << endl;
                    system("pause");
                    break;
                case 2:  //Infor Sneaker
                    a.Show_Infor_Sneaker();
                    cout << endl;
                    system("pause");
                    break;
                case 3:  //Supplier
                    a.Show_Supplier();
                    cout << endl;
                    system("pause");
                    break;
                case 4:  //Customer
                    a.Show_Customer();
                    cout << endl;
                    system("pause");
                    break;
                case 5:  //Bill
                    a.show_Bill();
                    cout << endl;
                    system("pause");
                    break;
                case 6:  //Infor Bill
                    a.Show_Infor_Bill();
                    cout << endl;
                    system("pause");
                    break;
            }
            //system("pause");
            break;
        case 4:   // Sửa giá bán
            a.update_price();
            cout << endl;
            system("pause");
            break;
        case 5:   // tìm kiếm giày theo khoảng giá
            a.price_search();
            cout << endl;
            system("pause");
            break;
        }
        system("cls");
    } while (cv != 0);
}