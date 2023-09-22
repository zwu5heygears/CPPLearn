//
// Created by heygears on 23-9-22.
//

#ifndef UNTITLED_ADDRESSBOOK_H
#define UNTITLED_ADDRESSBOOK_H
#include <iostream>
#include <string>


class AddressBook {
public:
    static AddressBook& GetInstance();
    void showMenu();
    void sinOut();

protected:

private:
    std::string name;  // 成员属性私有化
    AddressBook();
    ~AddressBook();
    AddressBook(const AddressBook &) = delete;
    AddressBook& operator=(const AddressBook&) = delete;
};


#endif //UNTITLED_ADDRESSBOOK_H
