#include "Book.h"
#include <iostream>

Book::Book(string title, string author, string ISBN) 
    : title(title), author(author), ISBN(ISBN), isAvailable(true) {}

string Book::getTitle() { return title; }
string Book::getAuthor() { return author; }
string Book::getISBN() { return ISBN; }
bool Book::checkAvailability() { return isAvailable; }

void Book::displayBookDetails() {
    cout << "Title: " << title << ", Author: " << author << ", ISBN: " << ISBN
         << ", Available: " << (isAvailable ? "Yes" : "No") << endl;
}

void Book::markAsBorrowed() { isAvailable = false; }
void Book::markAsReturned() { isAvailable = true; }
