#include "Atlas.h"

Atlas::Atlas()
{
    typeOfWeaving = "";
}

Atlas::Atlas(string ISBN, string nameBook, string surnameAuthor, bool available, float printing, string typeOfWeaving)
    : Edition(ISBN, nameBook, surnameAuthor, available, printing)
{
    this->typeOfWeaving = typeOfWeaving;
}

Atlas::~Atlas()
{
}

void Atlas::show() const
{
    cout << "Type: " << type() << endl;
    cout << "ISBN: " << ISBN << endl;
    cout << "Name: " << nameBook << endl;
    cout << "Author: " << surnameAuthor << endl;
    cout << "Printing: " << printing << endl;
    cout << "Type of weaving: " << typeOfWeaving << endl;
    cout << "Atlas available for reading: ";
    (available) ? cout << "No\n" : cout << "Yes\n";
}

string Atlas::type() const
{
    return "Atlas";
}

void Atlas::setTypeOfWeaving(string typeOfWeaving)
{
    this->typeOfWeaving = typeOfWeaving;
}

string Atlas::getTypeOfWeaving() const
{
    return typeOfWeaving;
}

void Atlas::save(ofstream& file)
{
    file << type() << endl << ISBN << endl << nameBook << endl << surnameAuthor << endl << available << endl << printing << endl << typeOfWeaving << endl;
}

void Atlas::load(ifstream& file)
{
    getline(file, ISBN);
    getline(file, nameBook);
    getline(file, surnameAuthor);
    file >> available;
    file >> printing;
    cin.ignore();
    getline(file, typeOfWeaving);
}
