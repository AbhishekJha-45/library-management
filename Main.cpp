#include "Admin.h"
#include "Borrower.h"
#include <iostream>
#include <vector>

int main() {
    vector<Book> libraryBooks;
    vector<User*> users;

    // Create some sample users
    Admin admin("AdminUser", 1);
    Borrower borrower("BorrowerUser", 2);

    users.push_back(&admin);
    users.push_back(&borrower);

    int choice, userType;

    while (true) {
        cout << "\nLibrary Management System\n";
        cout << "1. Admin Login\n";
        cout << "2. Borrower Login\n";
        cout << "3. Exit\n";
        cout << "Choose user type: ";
        cin >> userType;

        if (userType == 3) break;

        if (userType == 1) {
            while (true) {
                cout << "\nAdmin Menu:\n";
                cout << "1. Add Book\n";
                cout << "2. Remove Book\n";
                cout << "3. View All Books\n";
                cout << "4. View All Borrowed Books\n";
                cout << "5. Logout\n";
                cout << "Enter choice: ";
                cin >> choice;

                if (choice == 5) break;

                switch (choice) {
                    case 1: admin.addBook(libraryBooks); break;
                    case 2: admin.removeBook(libraryBooks); break;
                    case 3: admin.viewBooks(libraryBooks); break;
                    case 4: admin.viewAllBorrowedBooks(libraryBooks); break;
                    default: cout << "Invalid choice.\n";
                }
            }
        } else if (userType == 2) {
            while (true) {
                cout << "\nBorrower Menu:\n";
                cout << "1. View Available Books\n";
                cout << "2. Borrow Book\n";
                cout << "3. Return Book\n";
                cout << "4. View Borrowing History\n";
                cout << "5. Logout\n";
                cout << "Enter choice: ";
                cin >> choice;

                if (choice == 5) break;

                switch (choice) {
                    case 1: borrower.viewBooks(libraryBooks); break;
                    case 2: borrower.borrowBook(libraryBooks); break;
                    case 3: borrower.returnBook(libraryBooks); break;
                    case 4: borrower.viewBorrowingHistory(); break;
                    default: cout << "Invalid choice.\n";
                }
            }
        }
    }

    return 0;
}
