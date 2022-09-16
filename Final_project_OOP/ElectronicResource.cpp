#include "ElectronicResource.h"

ElectronicResource::ElectronicResource()
{
    link = "";
    text = "";
}

ElectronicResource::ElectronicResource(string ISBN, string nameBook, string surnameAuthor, bool available,float printing, string link, string text)
    : Edition(ISBN, nameBook, surnameAuthor, available,printing)
{
    this->link = link;
    this->text = text;
}

ElectronicResource::~ElectronicResource()
{
}

string ElectronicResource::getLink() const
{
    return link;
}

string ElectronicResource::getText() const
{
    return text;
}

void ElectronicResource::save(ofstream& file)
{
    file << type() << endl << ISBN << endl << nameBook << endl << surnameAuthor << endl << available << endl << printing << endl << link << endl << text << endl;
}

void ElectronicResource::load(ifstream& file)
{
    getline(file, ISBN);
    getline(file, nameBook);
    getline(file, surnameAuthor);
    file >> available;
    file >> printing;
    cin.ignore();
    getline(file, link);
    getline(file, text);
}

void ElectronicResource::show() const
{
    cout << "Type: " << type() << endl;
    cout << "ISBN: " << ISBN << endl;
    cout << "Name: " << nameBook << endl;
    cout << "Author: " << surnameAuthor << endl;
    cout << "Printing: " << printing << endl;
    cout << "Link: " << link << endl;
    cout << "Text: " << text << endl;
    cout << "Web resource available for reading: ";
    (available) ? cout << "No\n" : cout << "Yes\n";
}

string ElectronicResource::type() const
{
    return "Electronic Resource";
}
