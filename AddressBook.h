//
// Created by heygears on 23-9-22.
//

#ifndef UNTITLED_ADDRESSBOOK_H
#define UNTITLED_ADDRESSBOOK_H
#include <iostream>

class AddressBook {
public:
    static AddressBook& GetInstance();
    void showMenu();
    void sinOut();
private:
    AddressBook();
    ~AddressBook();
    AddressBook(const AddressBook &) = delete;
    AddressBook& operator=(const AddressBook&) = delete;
};


#endif //UNTITLED_ADDRESSBOOK_H
