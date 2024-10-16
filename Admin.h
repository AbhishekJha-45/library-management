#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include <vector>
#include "Book.h"

class Admin : public User {
public:
    Admin(string name, int userID);

    void addBook(vector<Book>& libraryBooks);
    void removeBook(vector<Book>& libraryBooks);
    void viewBooks(vector<Book>& libraryBooks) override;
    void borrowBook(vector<Book>& libraryBooks) override;
    void returnBook(vector<Book>& libraryBooks) override;
    void viewAllBorrowedBooks(vector<Book>& libraryBooks);
};

#endif
