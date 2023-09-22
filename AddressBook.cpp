//
// Created by heygears on 23-9-22.
//

#include "AddressBook.h"
using namespace std;

AddressBook &AddressBook::GetInstance() {
    static AddressBook instance;
    return instance;
}

AddressBook::AddressBook() {
    showMenu();
    sinOut();
}

AddressBook::~AddressBook() {

}

void AddressBook::showMenu() {
    cout << "1.添加联系人" << endl;
    cout << "2.显示联系人" << endl;
    cout << "3.查找联系人" << endl;
    cout << "4.修改联系人" << endl;
    cout << "0.退出通讯录" << endl;
}

void AddressBook::sinOut() {
    int select = 0;
    cin >> select;
    switch (select) {
        case 0:
        {
            cout << "bye" << endl;
        }
        break;
        default:
            cout << "input again:" << endl;
            break;
    }
}
