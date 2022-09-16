#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "AllExeption.h"
using namespace std;
class User
{
	string name;
	string phnumber;
	string address;
public:
	User();
	User(string name,string phnumber,string address);
	~User();
	string getName()const;
	string getPhnumber()const;
	string getAddress()const;
	void show()const;
};

