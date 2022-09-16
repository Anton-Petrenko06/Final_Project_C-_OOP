#include "Library.h"
int main() {

	Library A;
	Library B;
	int menu = 0,menu1=0,year,number;
	string ISBN, nameBook, surnameAuthor;
	bool available;
	float printing;
	string s1, s2,s3,s4;
	do
	{
		cout << "1-Add edition\n";
		cout << "2-Del edition\n";
		cout << "3-Show all catalog.\n";
		cout << "4-Show all books.\n";
		cout << "5-Show all articals.\n";
		cout << "6-Show all webreserses.\n";
		cout << "7-Show all atlases.\n";
		cout << "8-Show all brochures.\n";
		cout << "9-Search by name edition.\n";
		cout << "10-Sort by name edition.\n";
		cout << "11-User's registration.\n";
		cout << "12-Show user list.\n";
		cout << "13-Give edition\n";
		cout << "14-Show user's info.\n";
		cout << "15-Exit user's.\n";
		cout << "16-Save edition.\n";
		cout << "17-Load edition.\n";
		cin >> menu;
		switch (menu)
		{
		case 1: 
			cout << "1-Add book.\n";
			cout << "2-Add article.\n";
			cout << "3-Add electronic resource.\n";
			cout << "4-Add atlas.\n";
			cout << "5-Add brochure.\n";
			cin >> menu1;
			switch (menu1)
			{
			case 1:
				cin.ignore();
				cout << "Input ISBN: ";
				getline(cin, ISBN);
				cout << "Input name book: ";
				getline(cin, nameBook);
				cout << "Input surname author: ";
				getline(cin, surnameAuthor);
				cout << "Is the book available to read [1]-true,[0]-false: ";
				cin >> available;
				cout << "Input printing: ";
				cin >> printing;
				cout << "Input year: ";
				cin >> year;
				cout << "Input publisher: ";
				cin.ignore();
				getline(cin, s1);
				A.addEdition(new Book(ISBN, nameBook, surnameAuthor, available, printing, year, s1));
				break;
			case 2:
				cin.ignore();
				cout << "Input ISBN: ";
				getline(cin, ISBN);
				cout << "Input name article: ";
				getline(cin, nameBook);
				cout << "Input surname author: ";
				getline(cin, surnameAuthor);
				cout << "Is the book available to read [1]-true,[0]-false: ";
				cin >> available;
				cout << "Input printing: ";
				cin >> printing;
				cin.ignore();
				cout << "Input number: ";
				cin >> number;
				cout << "Input year: ";
				cin >> year;
				A.addEdition(new Article(ISBN, nameBook, surnameAuthor, available, printing, number, year));
				break;
			case 3:
				cin.ignore();
				cout << "Input ISBN: ";
				getline(cin, ISBN);
				cout << "Input name electronic resource: ";
				getline(cin, nameBook);
				cout << "Input surname author: ";
				getline(cin, surnameAuthor);
				cout << "Is the book available to read [1]-true,[0]-false: ";
				cin >> available;
				cout << "Input printing: ";
				cin >> printing;
				cin.ignore();
				cout << "Input link: ";
				getline(cin, s1);
				cout << "Input text: ";
				getline(cin, s2);
				A.addEdition(new ElectronicResource(ISBN, nameBook, surnameAuthor, available, printing, s1, s2));
				break;
			case 4:
				cin.ignore();
				cout << "Input ISBN: ";
				getline(cin, ISBN);
				cout << "Input name atlas: ";
				getline(cin, nameBook);
				cout << "Input surname author: ";
				getline(cin, surnameAuthor);
				cout << "Is the book available to read [1]-true,[0]-false: ";
				cin >> available;
				cout << "Input printing: ";
				cin >> printing;
				cin.ignore();
				cout << "Input type of weaving: ";
				getline(cin, s2);
				A.addEdition(new Atlas(ISBN, nameBook, surnameAuthor, available, printing, s2));
				break;
			case 5:
				cin.ignore();
				cout << "Input ISBN: ";
				getline(cin, ISBN);
				cout << "Input name brochure: ";
				getline(cin, nameBook);
				cout << "Input surname author: ";
				getline(cin, surnameAuthor);
				cout << "Is the book available to read [1]-true,[0]-false: ";
				cin >> available;
				cout << "Input printing: ";
				cin >> printing;
				cin.ignore();
				cout << "Input format: ";
				getline(cin, s1);
				cout << "Input bonding method: ";
				getline(cin, s2);
				A.addEdition(new Brochure(ISBN, nameBook, surnameAuthor, available, printing, s1, s2));
				break;
			}
			break;
		case 2:
			cin.ignore();
			cout << "Input ISBN: ";
			getline(cin, ISBN);
			A.delEdition(ISBN);
			break;
		case 3:
			A.showCatalog();
			break;
		case 4: 
			A.showBook();
			break;
		case 5: 
			A.showArticle();
			break;
		case 6:
			A.showElectronicResource();
			break;
		case 7: 
			A.showAtlas();
			break;
		case 8:
			A.showBrochure();
			break;
		case 9:
			cin.ignore();
			cout << "Enter the name of the publication : ";
			getline(cin, s1);
			A.searchNameEdition(s1);
			break;
		case 10: 
			A.sortName();
			break;
		case 11:
			cout << "\nInput your initials: ";
			cin.ignore();
			getline(cin, s1);
			cout << "Input your phone number: ";
			getline(cin, s2);
			cout << "Input your address: ";
			getline(cin, s4);
			cout << "Input number of ISBN, which needed: ";
			getline(cin, s3);

			A.registration(s1, s2, s3, s4);
			break;
		case 12:
			A.showUserList();
			break;
		case 13: 
			cin.ignore();
			cout << "\nInput your phone number: ";
			getline(cin, s2);
			cout << "Input number of ISBN, which needed: ";
			getline(cin, s3);
			A.giveEdition(s2, s3);
			break;
		case 14: 
			cin.ignore();
			cout << "\nInput your phone number: ";
			getline(cin, s2);
			A.showUserInfo(s2);
			break;
		case 15:
			cin.ignore();
			cout << "\nInput your phone number: ";
			getline(cin, s2);
			A.delUser(s2);
			break;
		case 16:
			A.saveEdition();
			break;
		case 17:
			B.loadEdition();
			B.showCatalog();
			break;
		}
	} while (menu!=0);
	return 0;
}	