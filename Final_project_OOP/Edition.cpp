#include "Edition.h"

Edition::Edition()
{
    ISBN = "12314";
    nameBook = "NameBook";
    surnameAuthor = "SurnameAuthor";
    available = false;
    printing = 1;
}

Edition::Edition(string ISBN, string nameBook, string surnameAuthor, bool available, float printing):ISBN(ISBN), nameBook(nameBook), surnameAuthor(surnameAuthor), available(available), printing(printing)
{
    if (ISBN.size() == 0)throw new ISBNExeption();
    if (nameBook.size() == 0)throw new NameBookExeption();
    if (surnameAuthor.size() == 0)throw new SurnameAuthorExeption();
    if (printing == 0)throw new PrintingExeption();
}

Edition::~Edition()
{
}

void Edition::setISBN(string ISBN)
{
    this->ISBN = ISBN;
}

void Edition::setNameBook(string nameBook)
{
    this->nameBook = nameBook;
}

void Edition::setSurnameAuthor(string surnameAuthor)
{
    this->surnameAuthor = surnameAuthor;
}

void Edition::setAvailable(bool available)
{
    this->available = available;
}

void Edition::setPrinting(float printing)
{
    this->printing = printing;
}

string Edition::getISBN() const
{
    return ISBN;
}

string Edition::getNameBook() const
{
    return nameBook;
}

string Edition::getSurnameAuthor() const
{
    return surnameAuthor;
}

bool Edition::getAvailable() const
{
    return available;
}

float Edition::getPrinting() const
{
    return printing;;
}

bool Edition::operator<(const Edition& obj) const
{
    return this->ISBN<obj.ISBN;
}

