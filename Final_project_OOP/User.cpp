#include "User.h"

User::User()
{
	name = "UserName";
	phnumber = "UserPhone";
	address = "UserAddress";
}

User::User(string name, string phnumber, string address):name(name),phnumber(phnumber),address(address)
{
	if (name.size() == 0) throw new NameExeption();
	if (phnumber.size() == 0) throw new PhoneExeption();
	if (address.size() == 0) throw new AddressExeption();
}

User::~User()
{
}

string User::getName() const
{
	return name;
}

string User::getPhnumber() const
{
	return phnumber;
}

string User::getAddress() const
{
	return address;
}

void User::show() const
{
	cout << "\nName: " << name << endl;
	cout << "Phone number: " << phnumber << endl;
	cout << "Address: " << address << endl;
}

