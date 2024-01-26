#include <iostream>
#include "header.h"

using namespace std;

// Entry Point
int main(void)
{
	Person me;

	FillShoppingInfo(me);
	WriteReceipt(me);


	system("pause");
	return (0);
}