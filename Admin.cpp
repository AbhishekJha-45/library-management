#include "Admin.h"
#include <iostream>

Admin::Admin(string name, int userID) : User(name, userID) {}

void Admin::addBook(vector<Book>& libraryBooks) {
    string title, author, ISBN;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter book author: ";
    getline(cin, author);
    cout << "Enter book ISBN: ";
    getline(cin, ISBN);
    libraryBooks.push_back(Book(title, author, ISBN));
    cout << "Book added successfully!\n";
}

void Admin::removeBook(vector<Book>& libraryBooks) {
    string bookTitle;
    cout << "Enter the title of the book to remove: ";
    cin.ignore();
    getline(cin, bookTitle);

    for (auto it = libraryBooks.begin(); it != libraryBooks.end(); ++it) {
        if (it->getTitle() == bookTitle) {
            libraryBooks.erase(it);
            cout << "Book removed successfully!\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

void Admin::viewBooks(vector<Book>& libraryBooks) {
    cout << "\nAll Books in the Library:\n";
    for (auto& book : libraryBooks) {
        book.displayBookDetails();
    }
}

void Admin::borrowBook(vector<Book>& libraryBooks) {
    cout << "Admin cannot borrow books.\n";
}

void Admin::returnBook(vector<Book>& libraryBooks) {
    cout << "Admin cannot return books.\n";
}

void Admin::viewAllBorrowedBooks(vector<Book>& libraryBooks) {
    cout << "\nBorrowed Books:\n";
    for (auto& book : libraryBooks) {
        if (!book.checkAvailability()) {
            book.displayBookDetails();
        }
    }
}
