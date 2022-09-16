#include "Library.h"

void Library::showCatalog() const&
{
	for (set<Edition*, CompareEdition>::const_iterator item = catalog.begin(); item != catalog.end(); item++)
	{
		(*(item))->show();
		cout << endl;
	}
}

void Library::showBook() const&
{
	for (set<Edition*, CompareEdition>::const_iterator item = catalog.begin(); item != catalog.end(); item++)
	{
		if ((*(item))->type() == "Book") {
			(*(item))->show();
			cout << endl;
		}
	}
}

void Library::showArticle() const&
{
	for (set<Edition*, CompareEdition>::const_iterator item = catalog.begin(); item != catalog.end(); item++)
	{
		if ((*(item))->type() == "Article") {
			(*(item))->show();
			cout << endl;
		}
	}
}

void Library::showElectronicResource() const&
{
	for (set<Edition*, CompareEdition>::const_iterator item = catalog.begin(); item != catalog.end(); item++)
	{
		if ((*(item))->type() == "Electronic Resource") {
			(*(item))->show();
			cout << endl;
		}
	}
}

void Library::showAtlas() const&
{
	for (set<Edition*, CompareEdition>::const_iterator item = catalog.begin(); item != catalog.end(); item++)
	{
		if ((*(item))->type() == "Atlas") {
			(*(item))->show();
			cout << endl;
		}
	}
}

void Library::showBrochure() const&
{
	for (set<Edition*, CompareEdition>::const_iterator item = catalog.begin(); item != catalog.end(); item++)
	{
		if ((*(item))->type() == "Brochure") {
			(*(item))->show();
			cout << endl;
		}
	}
}

void Library::addEdition(Edition* item)
{
	catalog.insert(item);
}

void Library::delEdition(string ISBN)
{
	for (item = catalog.begin(); item != catalog.end(); item++)
	{
		if ((*item)->getISBN() == ISBN) {
			catalog.erase(item);
			item = catalog.begin();
			break;
		}
	}
}

void Library::registration(string s1, string s2, string s3, string s4)
{
	for (item = catalog.begin(); item != catalog.end(); item++)
	{
		if ((*(item))->getISBN()== s3)
		{
			break;
		}
	}
	if (item != catalog.end() && (*(item))->getAvailable() == false)
	{
		User* tmp = nullptr;
		try
		{
			tmp = new User(s1, s2, s4);
		}
		catch (AllExeption* obj)
		{
			obj->showExeption();
		}
		library.insert(pair<User*, vector<Edition*>>(tmp, vector<Edition*>{*item}));
		(*(item))->setAvailable(true);
	}
	else if ((*(item))->getAvailable() == true)
	{
		User* tmp = nullptr;
		try
		{
			tmp = new User(s1, s2, s4);
		}
		catch (AllExeption* obj)
		{
			obj->showExeption();
		}
		library.insert(pair<User*, vector<Edition*>>(tmp, vector<Edition*>{}));
		cout << "Sorry, but this material was taken by another user, take something else." << endl;
	}
	else
	{
		User* tmp = nullptr;
		try
		{
			tmp = new User(s1, s2, s4);
		}
		catch (AllExeption* obj)
		{
			obj->showExeption();
		}
		library.insert(pair<User*, vector<Edition*>>(tmp, vector<Edition*>{}));
		cout << "\tWrong ISBN!\n";
	}
}
void Library::showUserList()
{

	for (iuser = library.begin(); iuser != library.end(); iuser++)
	{
		(iuser->first)->show();
		cout << endl;
	}
}


void Library::showUserInfo(string phone)
{
	for (iuser = library.begin(); iuser != library.end(); iuser++)
	{
		if ((iuser->first)->getPhnumber() == phone) {

			for (Edition* item : iuser->second)
			{
				item->show();
				cout << endl;
			}
		}

	}
}



void Library::giveEdition(string s1, string s2)
{

	for (item = catalog.begin(); item != catalog.end(); item++)
	{
		if ((*(item))->getISBN() == s2)
		{
			break;
		}
	}
	for (iuser = library.begin(); iuser != library.end(); iuser++)
	{
		try
		{
			if ((iuser->first)->getPhnumber() == s1)
			{
				if (item != catalog.end() && (*(item))->getAvailable() == false)
				{
					iuser->second.push_back(*item);
					(*(item))->setAvailable(true);
				}
				else
				{
					cout << "Sorry, but this material was taken by another user, take something else." << endl;
				}
			}
		}
		catch (AllExeption* obj)
		{
			obj->showExeption();
		}

	}
}

void Library::delUser(string phone)
{
	for (iuser = library.begin(); iuser != library.end(); iuser++)
	{
		if ((iuser->first)->getPhnumber() == phone)
		{
			if (iuser->second.size() > 0)
			{
				for (Edition* obj : iuser->second)
				{
					obj->setAvailable(false);
				}
				iuser->second.clear();
			}
			else
			{
				cout << "You have taken nothing to the libraries, you have nothing to return." << endl;
			}
			break;
		}
	}
	library.erase(iuser);
}

void Library::searchNameEdition(string n)
{
	for (item = catalog.begin(); item != catalog.end(); item++)
	{
		if ((*item)->getNameBook() == n) {

			(*(item))->show();
		}
	}
}

void Library::sortName()
{
	catalog.swap(catalog);
	showCatalog();
}

void Library::loadEdition()
{
	ifstream fw("Library.txt");
	Edition* ptr = nullptr;

	if (fw.is_open())
	{
		string p;
		while (!fw.eof())
		{
			getline(fw, p);

			if (p == "Book")
			{
				ptr = new Book();
				ptr->load(fw);
				addEdition(ptr);
			}
			else if (p == "Article")
			{
				ptr = new Article();
				ptr->load(fw);
				addEdition(ptr);
			}
			else if (p == "Electronic Resource")
			{
				ptr = new ElectronicResource();
				ptr->load(fw);
				addEdition(ptr);
			}
			else if (p == "Atlas")
			{
				ptr = new Atlas();
				ptr->load(fw);
				addEdition(ptr);
			}
			else if (p == "Brochure")
			{
				ptr = new Brochure();
				ptr->load(fw);
				addEdition(ptr);
			}
		}
		fw.close();
		cout << "\nLibrary data uploaded successfully!\n";
	}
}

void Library::saveEdition()
{
	ofstream fw("Library.txt");
	if (fw.is_open())
	{
		if (catalog.size() == 0)
		{
			cout << "\nNo data for save.\n";
			fw.close();
		}
		else
		{
			for (item = catalog.begin(); item != catalog.end(); item++)
			{
				(*(item))->save(fw);
			}
			fw.close();
		}
		cout << "Data was successfully written!" << endl;
	}
	else
	{
		cout << "\nSome error!\n";
	}
}