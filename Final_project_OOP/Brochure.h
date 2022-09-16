#pragma once
#include "Edition.h"
class Brochure :
    public Edition
{
protected:
    string format;
    string bondingMethod;
public:
    Brochure();
    Brochure(string ISBN, string nameBook, string surnameAuthor, bool available, float printing, string format,string bondingMethod);
    ~Brochure();
    void show()const override;
    string type()const override;
    void setFormat(string format);
    void setBondingMethod(string bondingMethod);
    string getFormat()const;
    string getBondingMethod()const;

    void save(ofstream& file) override;
    void load(ifstream& file)override;
};

