#pragma once
#include "Edition.h"
#include "User.h"
class CompareEdition:public binary_function<Edition*,Edition*,bool>
{
public:
	bool operator()(const Edition* obj1, const Edition* obj2) const {
		return obj1->getNameBook() < obj2->getNameBook();
	}
};
class Compare_user :public binary_function<User*, User*, bool>
{
public:
	bool operator()(const User* obj1, const User* obj2) const {
		return obj1->getPhnumber() < obj2->getPhnumber();
	}
};
