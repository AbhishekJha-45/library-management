#include "Borrower.h"
#include <iostream>
#include <algorithm>

Borrower::Borrower(string name, int userID) : User(name, userID) {}

void Borrower::viewBooks(vector<Book>& libraryBooks) {
    cout << "\nAvailable Books in the Library:\n";
    for (auto& book : libraryBooks) {
        if (book.checkAvailability()) {
            book.displayBookDetails();
        }
    }
}

void Borrower::borrowBook(vector<Book>& libraryBooks) {
    string bookTitle;
    cout << "Enter the title of the book to borrow: ";
    cin.ignore();
    getline(cin, bookTitle);

    for (auto& book : libraryBooks) {
        if (book.getTitle() == bookTitle && book.checkAvailability()) {
            book.markAsBorrowed();
            borrowedBooks.push_back(book.getTitle());
            cout << "Book borrowed successfully!\n";
            return;
        }
    }
    cout << "Book not available or doesn't exist.\n";
}

void Borrower::returnBook(vector<Book>& libraryBooks) {
    string bookTitle;
    cout << "Enter the title of the book to return: ";
    cin.ignore();
    getline(cin, bookTitle);

    for (auto& book : libraryBooks) {
        if (book.getTitle() == bookTitle && !book.checkAvailability()) {
            book.markAsReturned();
            borrowedBooks.erase(
                std::remove(borrowedBooks.begin(), borrowedBooks.end(), bookTitle),
                borrowedBooks.end()
            );
            cout << "Book returned successfully!\n";
            return;
        }
    }
    cout << "Book not found in borrowed list.\n";
}

void Borrower::viewBorrowingHistory() {
    cout << "\nBorrowed Books History:\n";
    for (const auto& book : borrowedBooks) {
        cout << "- " << book << endl;
    }
}
