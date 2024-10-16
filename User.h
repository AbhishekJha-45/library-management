#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Book.h"

using namespace std;

class User {
protected:
    string name;
    int userID;

public:
    User(string name, int userID);
    virtual void viewBooks(vector<Book>& libraryBooks) = 0;
    virtual void borrowBook(vector<Book>& libraryBooks) = 0;
    virtual void returnBook(vector<Book>& libraryBooks) = 0;
};

#endif
