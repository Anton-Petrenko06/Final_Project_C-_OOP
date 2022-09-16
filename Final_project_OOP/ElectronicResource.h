#pragma once
#include "Edition.h"
class ElectronicResource :
    public Edition
{
protected:
    string link;
    string text;
public:
    ElectronicResource();
    ElectronicResource(string ISBN, string nameBook, string surnameAuthor,bool available, float printing, string link,string text);
    ~ElectronicResource();
    void show()const override;
    string type()const override;
    string getLink()const;
    string getText()const;

    void save(ofstream& file) override;
    void load(ifstream& file)override;
};

