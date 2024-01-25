#ifndef HEADER_H
#define HEADER_H

struct Product
{
	char ProductName[50];
	float UnitPrice;
	int Quantity;
	float TotalPrice; // TotalPrice = UnitPrice * Quantity
};

struct Shop
{
	char ShopName[50];
	char ShopAddress[50];
};

struct Customer
{
	char CustomerName[50];
	char PhoneNumber[50];
};

struct Person
{
	Shop shop;
	Customer customer;
	Product product;
};


// FUNCTION PROTOTYPES
void FillShoppingInfo(Person &);
void WriteReceipt(Person);

#endif // HEADER_H