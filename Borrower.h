#ifndef BORROWER_H
#define BORROWER_H

#include "User.h"
#include <vector>
#include <string>
#include "Book.h"

class Borrower : public User {
private:
    vector<string> borrowedBooks;

public:
    Borrower(string name, int userID);

    void viewBooks(vector<Book>& libraryBooks) override;
    void borrowBook(vector<Book>& libraryBooks) override;
    void returnBook(vector<Book>& libraryBooks) override;
    void viewBorrowingHistory();
};

#endif
