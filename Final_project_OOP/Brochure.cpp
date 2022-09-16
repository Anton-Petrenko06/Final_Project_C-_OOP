#include "Brochure.h"

Brochure::Brochure()
{
	format = "";
	bondingMethod = "";
}

Brochure::Brochure(string ISBN, string nameBook, string surnameAuthor, bool available, float printing, string format, string bondingMethod)
	: Edition(ISBN, nameBook, surnameAuthor, available, printing)
{
	this->format = format;
	this->bondingMethod = bondingMethod;
}

Brochure::~Brochure()
{
}

void Brochure::show() const
{
	cout << "Type: " << type() << endl;
	cout << "ISBN: " << ISBN << endl;
	cout << "Name: " << nameBook << endl;
	cout << "Author: " << surnameAuthor << endl;
	cout << "Printing: " << printing << endl;
	cout << "Format: " << format << endl;
	cout << "Bonding Method: " << bondingMethod << endl;
	cout << "Brochure available for reading: ";
	(available) ? cout << "No\n" : cout << "Yes\n";
}

string Brochure::type() const
{
	return "Brochure";
}

void Brochure::setFormat(string format)
{
	this->format = format;
}

void Brochure::setBondingMethod(string bondingMethod)
{
	this->bondingMethod = bondingMethod;
}

string Brochure::getFormat() const
{
	return format;
}

string Brochure::getBondingMethod() const
{
	return bondingMethod;
}

void Brochure::save(ofstream& file)
{
	file << type() << endl << ISBN << endl << nameBook << endl << surnameAuthor << endl << available << endl << printing << endl << format << endl << bondingMethod << endl;
}

void Brochure::load(ifstream& file)
{
	getline(file, ISBN);
	getline(file, nameBook);
	getline(file, surnameAuthor);
	file >> available;
	file >> printing;
	cin.ignore();
	getline(file, format);
	getline(file, bondingMethod);
}
