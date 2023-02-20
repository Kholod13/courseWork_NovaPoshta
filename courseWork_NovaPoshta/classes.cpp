#include <iostream>
#include <vector>
#include <fstream>
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
	fstream newServices;
	string nameDS = "Done Services";
	fstream doneServices;

	StatusService status;

public:
	Mail(int balance) : balance(balance)
	{
		newServices.open(nameNS);
		doneServices.open(nameDS);
	}
	~Mail()
	{
		newServices.close();
		doneServices.close();
	}



};