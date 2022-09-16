#include "Article.h"

Article::Article():Edition()
{
    nameZur = "";
    number = 0;
    year = 0;
}

Article::Article(string ISBN, string nameBook, string surnameAuthor, bool available,float printing, int number, int year)
    : Edition(ISBN, nameBook, surnameAuthor, available,printing)
{
    this->nameZur = nameZur;
    this->number = number;
    this->year = year;
}

Article::~Article()
{
}

int Article::getNumber() const
{
    return number;
}

int Article::getYear() const
{
    return year;
}

void Article::show() const
{
    cout << "Type: " << type() << endl;
    cout << "ISBN: " << ISBN << endl;
    cout << "Name: " << nameBook << endl;
    cout << "Author: " << surnameAuthor << endl;
    cout << "Printing: " << printing << endl;
    cout << "Name zurnal: " << nameZur << endl;
    cout << "Number: " << number << endl;
    cout << "Year: " << year << endl;
    cout<<"Article available for reading: ";
    (available) ? cout << "No\n" : cout << "Yes\n";
}

string Article::type() const
{
    return "Article";
}

void Article::save(ofstream& file)
{
    file << type() << endl << ISBN << endl << nameBook << endl << surnameAuthor << endl << available << endl << printing << endl << nameZur << endl << number << endl << year << endl;
}

void Article::load(ifstream& file)
{
    getline(file, ISBN);
    getline(file, nameBook);
    getline(file, surnameAuthor);
    file >> available;
    file >> printing;
    cin.ignore();
    getline(file, nameZur);
    file >> number;
    file >> year;
}
