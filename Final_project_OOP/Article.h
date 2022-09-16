#pragma once
#include "Edition.h"
class Article :
    public Edition
{
protected:
    string nameZur;
    int number;
    int year;
public:
    Article();
    Article(string ISBN, string nameBook, string surnameAuthor, bool available, float printing, int number, int year);
    ~Article();
    int getNumber()const;
    int getYear()const;

    void show()const override;
    string type()const override;
    void save(ofstream& file) override;
    void load(ifstream& file)override;
};

