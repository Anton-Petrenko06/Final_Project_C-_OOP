#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "AllExeption.h"
using namespace std;
class Edition
{
protected:
	string ISBN;
	string nameBook;
	string surnameAuthor;
	bool available;
	float printing;
public:
	Edition();
	Edition(string ISBN,string nameBook,string surnameAuthor, bool available,float printing);
	~Edition();

	void setISBN(string ISBN);
	void setNameBook(string nameBook);
	void setSurnameAuthor(string surnameAuthor);
	void setAvailable(bool available);
	void setPrinting(float printing);
	string getISBN()const;
	string getNameBook()const;
	string getSurnameAuthor()const;
	bool getAvailable()const;
	float getPrinting()const;
	virtual void show()const=0;
	virtual string type()const=0;
	virtual void save(ofstream& file) = 0;
	virtual void load(ifstream& file) = 0;
	bool operator<(const Edition& obj)const;
};

