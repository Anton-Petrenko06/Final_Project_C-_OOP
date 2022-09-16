#pragma once
#include "Edition.h"
class Book :
    public Edition
{
protected:
    int year;
    string publisher;
public:  
    Book();
    Book(string ISBN, string nameBook, string surnameAuthor, bool available, float printing, int year, string publisher);
    ~Book();
    int getYear()const;
    string getPublisher()const;
    void show()const override;
    string type()const override;

    void save(ofstream& file) override;
    void load(ifstream& file)override;
};

