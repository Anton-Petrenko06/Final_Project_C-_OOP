#pragma once
#include <iostream>
#include <string>
using namespace std;
class AllExeption
{
public:
	virtual void showExeption() = 0;
};
//---------------------------Edition----------------------------------
class ISBNExeption : public AllExeption {
public:
	void showExeption() override
	{
		cout << "\nThe ISBN field cannot be empty!" << endl;
	}
};
class NameBookExeption : public AllExeption {
public:
	void showExeption() override
	{
		cout << "\nBook name field cannot be empty!" << endl;
	}
};
class SurnameAuthorExeption : public AllExeption {
public:
	void showExeption() override
	{
		cout << "\nThe author name field cannot be empty!" << endl;
	}
};
class PrintingExeption : public AllExeption {
public:
	void showExeption() override
	{
		cout << "\nThe Printing field cannot be empty!" << endl;
	}
};
//---------------------------User-------------------------------------
class PhoneExeption : public AllExeption {
public:
	void showExeption() override 
	{
		cout << "\nPhone number field cannot be empty!"<<endl;
	}
};
class NameExeption : public AllExeption {
public:
	void showExeption() override
	{
		cout << "\nThe name field cannot be empty!" << endl;
	}
};
class AddressExeption : public AllExeption {
public:
	void showExeption() override
	{
		cout << "\nThe address field cannot be empty!" << endl;
	}
};