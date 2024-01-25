#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
#include "header.h"

using namespace std;

void FillShoppingInfo(Person &owner)
{
	// GET SHOP INFO
	cout << "Enter the name of your shop: ";
	cin.getline(owner.shop.ShopName, 50);
	cout << "Enter the Address of your shop: ";
	cin.getline(owner.shop.ShopAddress, 50);

	// GET CUSTOMER INFO
	cout << "Enter Customer name: ";
	cin.getline(owner.customer.CustomerName, 50);
	cout << "Enter Customer PhoneNumber: ";
	cin >> owner.customer.PhoneNumber;
	cin.ignore();

	// GET PRODUCT INFO
	cout << "Enter ProductName name: ";
	cin.getline(owner.product.ProductName, 50);
	cout << "Enter cost of a unit Product: ";
	cin >> owner.product.UnitPrice;
	cin.ignore();
	cout << "Enter the quantity you have: ";
	cin >> owner.product.Quantity;
	cin.ignore();
	owner.product.TotalPrice = owner.product.Quantity * owner.product.UnitPrice;
}

void WriteReceipt(Person owner)
{
	ofstream ourFile;
	
	ourFile.open("Receipt.txt");
	ourFile << setprecision(9);

	int fw = 72;
	int nameLen = strlen(owner.shop.ShopName);
	int addressLen = strlen(owner.shop.ShopAddress);

	ourFile << "***********************************************************************\n";
	int space1 = (fw - nameLen) / 2;
	int space2 = (fw - addressLen) / 2;

	for (int i = 0; i < space1; i++)
		ourFile <<" ";
	ourFile << owner.shop.ShopName << endl;

	for (int i = 0; i < space2; i++)
		ourFile <<" ";
	ourFile << owner.shop.ShopAddress << "\n\n";

	ourFile << left << setw(24) << "Customer" << setw(24) << owner.customer.CustomerName << endl;
	ourFile << left << setw(24) << "Phone Number" << owner.customer.PhoneNumber << "\n\n";

	ourFile << "Your Order\n\n";

	ourFile << left << setw(24) << "Product Name" << setw(24) << "UnitPrice" << setw(24) << "Quantity Ordered" << endl;
	ourFile << left << setw(24) << owner.product.ProductName  << setw(24) << owner.product.UnitPrice << setw(24) << owner.product.Quantity << endl;

	for (int i = 0; i < 48; i++)
		ourFile << " ";
	ourFile << setw(24) << "*******" << endl;

	for (int i = 0; i < 24; i++)
		ourFile <<" ";
	ourFile << left << setw(24) << "Total Price:" << setw(24) << owner.product.TotalPrice << endl;
		for (int i = 0; i < 48; i++)
		ourFile <<" ";
	ourFile << setw(24) << "*******" << endl;

	ourFile << "\tThanks for your Patronage\n";
	ourFile << "***********************************************************************\n";

	ourFile.close();
}