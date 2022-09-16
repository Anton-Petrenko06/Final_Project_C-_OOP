#pragma once
#include <set>
#include <map>
#include <vector>
#include "User.h"
#include "Article.h"
#include "Book.h"
#include "Edition.h"
#include "ElectronicResource.h"
#include "Atlas.h"
#include "Brochure.h"
#include "CompareEdition.h"
#include <algorithm>
#include "AllExeption.h"
using namespace std;
class Library
{
protected:
	set<Edition*, CompareEdition>catalog;
	set<Edition*, CompareEdition>::const_iterator item;

	map<User*, vector<Edition*>, Compare_user> library;
	map<User*, vector<Edition*>, Compare_user> ::iterator iuser;
	
public:
	void showCatalog()const&;
	void showBook()const&;
	void showArticle()const&;
	void showElectronicResource()const&;
	void showAtlas()const&;
	void showBrochure()const&;
	void addEdition(Edition* item);
	void delEdition(string ISBN);
	void registration(string s1, string s2,string s3, string s4);
	void showUserList();
	void showUserInfo(string phone);
	void giveEdition(string s1, string s2);
	void delUser(string phone);
	void searchNameEdition(string n);
	void sortName();
	void loadEdition();
	void saveEdition();
};

