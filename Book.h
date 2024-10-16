#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;
    bool isAvailable;

public:
    Book(string title, string author, string ISBN);

    string getTitle();
    string getAuthor();
    string getISBN();
    bool checkAvailability();

    void displayBookDetails();
    void markAsBorrowed();
    void markAsReturned();
};

#endif
