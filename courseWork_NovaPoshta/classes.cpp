#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
#include <ofstream>
#include <fstream>
#include <ctime>
#include <string>

//додавати невиконані доставки в 1 файл
//додавати виконані доставки в 2 файл
//змінювати статус виконання в Database
//Доповнення(редагування, видалення ) послуги

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;
using std::fstream;

struct Product {
	string name;
	string company;
	int price;
	int guarantee;
};

/*
struct Receipt {
	string nameProduct;
	string priceProduct;
	int year;
	int month;
	int day;
};
*/

struct StatusService {
	string none = "none!";
	string inProcess = "become...";
	string done = "done!";
};

struct Database {
	Product product;
	int year;
	int month;
	int day;
	string status;
};

class Mail {
private:
	vector<Product>listProducts;
	vector<Database>database;

	int balance;
	
	string nameNS = "New Services";
	//ofstream newServices;
	string nameDS = "Done Services";
	//ofstream doneServices;

	StatusService status;

public:
	Mail(int balance) : balance(balance)
	{
		//newServices.open(nameNS);
		//doneServices.open(nameDS);

		Product p;

		p.name = "Telephone";
		p.company = "Samsung";
		p.guarantee = 24;
		p.price = 650;

		listProducts.push_back(p);

		p.name = "Lamp";
		p.company = "Smart light";
		p.guarantee = 6;
		p.price = 74;

		listProducts.push_back(p);

		p.name = "Sneakers";
		p.company = "Nike";
		p.guarantee = 12;
		p.price = 150;

		listProducts.push_back(p);

	}
	~Mail()
	{
		//newServices.close();
		//doneServices.close();
	}

	void AddProduct() {
		Product p;
		cout << "\n|ADD|\n";

		cout << "Name >> ";
		cin >> p.name;
		cout << "Company >> ";
		cin >> p.company;
		cout << "Quarantee >> ";
		cin >> p.guarantee;
		cout << "Price: ";
		cin >> p.price;

		listProducts.push_back(p);

	}

	void ShowListProducts() {

		cout << "|PRODUCTS|";

		for (int i = 0; i < listProducts.size(); i++) {
			cout << "\n#" << i + 1 << endl;

			cout << "Name >> " << listProducts[i].name << endl;
			cout << "Company >> " << listProducts[i].company << endl;
			cout << "Quarantee >> " << listProducts[i].guarantee << endl;
			cout << "Price >> " << listProducts[i].price << endl;
		}
	}

	void Receipt() {

		for (int i = 0; i < database.size(); i++) {
			cout << "#" << i + 1 << endl;

			cout << "Name: " << database[i].product.name << endl;
			cout << "Company: " << database[i].product.company << endl;
			cout << "Guarantee: " << database[i].product.guarantee << endl;
			cout << "Price: " << database[i].product.price << endl;
			cout << "Date: " << database[i].year << "/" << database[i].month << "/" << database[i].day << endl;
			cout << "Status: " << database[i].status << endl;

		}

	}

	void Order() {
		ShowListProducts();
		cout << "\nYour balance: " << balance << endl;

		Database db;
		int val = 0;
		
		try {
			cout << "Input number product >> ";
			cin >> val;
			val = val - 1;

			balance = balance - listProducts[val].price;
		}
		catch (const std::exception& ex) {

			cout << "Error: " << ex.what() << endl;
			cout << "Small balance!!\n";
			return;
		}

		StatusService ss;

		time_t now = time(0);
		tm* ltm = localtime(&now);

		db.product = listProducts[val];
		db.year = 1900 + ltm->tm_year;
		db.month = 1 + ltm->tm_mon;
		db.day = ltm->tm_mday;
		db.status = ss.inProcess;

		database.push_back(db);

		int v = 0;

		cout << "\n1 - continue shoping\n";
		cout << "2 - to order\n";

		cin >> v;

		switch (v) {
		case 1:
			Order();
			break;
		default:
			break;
		}
		cout << "\n|RECEIPTS|\n\n";
		Receipt();

	}
	//невиконані
	
	void ShowServiceOrder() {

		ofstream outf("d.txt");
		
		cout << "\n\nFile is create...\n\n";
		
		outf << "cccc";
		
		for (int i = 0; i < database.size(); i++) {
			outf << "#" << i + 1 << endl;
			/*
			outf << "Name: " << database[i].product.name << endl;
			outf << "Company: " << database[i].product.company << endl;
			outf << "Guarantee: " << database[i].product.guarantee << endl;
			outf << "Price: " << database[i].product.price << endl;
			outf << "Date: " << database[i].year << "/" << database[i].month << "/" << database[i].day << endl;
			outf << "Status: " << database[i].status << endl;
			*/
		}
		outf.close();
	}

	
	//виконані
	/*
	void ShowPerformedServices() {



	}
	*/
	void Menu() {
		cout << "\n|MENU| Nova Poshta - Serivses\n\n";
		cout << "1 - Add product\n";
		cout << "2 - Order a product\n";
		cout << "3 - Show the service order\n";
		cout << "4 - Show performed services\n";
		cout << "5 - Show list products\n";
		cout << "6 - Edit service\n";
		cout << "7 - Check status\n";
		cout << "8 - End prccees!\n";

		int val = 0;
		cout << "Input number item >>> ";
		cin >> val;

		switch (val)
		{
		case 1:
			AddProduct();
			Menu();
			break;
		case 2:
			Order();
			Menu();
			break;
		case 3:
			//ShowServiceOrder();
			Menu();
			break;
		case 4:
			//ShowPerformedServices();
			Menu();
			break;
		case 5:
			ShowListProducts();
			Menu();
			break;
		case 6:
			cout << "\n\nTemporarily not working :(  ......\n\n";
			Menu();
			break;
		case 7:
			cout << "\n|RECEIPTS|\n\n";
			Receipt();
			Menu();
			break;
		default:
			break;
		}
	};

};