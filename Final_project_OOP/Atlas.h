#pragma once
#include "Edition.h"
class Atlas :
    public Edition
{
protected:
    string typeOfWeaving;
public:
    Atlas();
    Atlas(string ISBN, string nameBook, string surnameAuthor, bool available, float printing,string typeOfWeaving);
    ~Atlas();
    void show()const override;
    string type()const override;
    void setTypeOfWeaving(string typeOfWeaving);
    string getView()const;
    string getTypeOfWeaving()const;

    void save(ofstream& file) override;
    void load(ifstream& file)override;
};

