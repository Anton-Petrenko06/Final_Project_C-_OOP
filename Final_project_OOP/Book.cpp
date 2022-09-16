#include "Book.h"

Book::Book():Edition()
{
    year = 0;
    publisher = "Publisher";
}

Book::Book(string ISBN, string nameBook, string surnameAuthor, bool available, float printing, int year, string publisher) : Edition(ISBN, nameBook, surnameAuthor, available, printing )
{
    this->year = year;
    this->publisher = publisher;
}

Book::~Book()
{
}

int Book::getYear() const
{
    return year;
}

string Book::getPublisher() const
{
    return publisher;
}

void Book::show() const
{
    cout << "Type: " << type() << endl;
    cout << "ISBN: " << ISBN << endl;
    cout << "Name: " << nameBook << endl;
    cout << "Author: " << surnameAuthor << endl;
    cout << "Printing: " << printing << endl;
    cout << "Year: " << year << endl;
    cout << "Publisher: " << publisher << endl;
    cout << "Reading book available: ";
    (available) ? cout << "No\n" : cout << "Yes\n";
}

string Book::type() const
{
    return "Book";
}

void Book::save(ofstream& file)
{
    file << type() << endl << ISBN << endl << nameBook << endl << surnameAuthor << endl << available << endl << printing << endl << year << endl << publisher << endl;
}

void Book::load(ifstream& file)
{
    getline(file, ISBN);
    getline(file, nameBook);
    getline(file, surnameAuthor);
    file >> available;
    file >> printing;
    cin.ignore();
    file >> year;
    cin.ignore();
    getline(file, publisher);
}
