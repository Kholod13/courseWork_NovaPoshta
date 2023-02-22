#include <iostream>
#include "links.h"
#include "classes.cpp"

int main()
{
	Mail vlad(400);

	vlad.ShowListProducts();
	vlad.AddProduct();
	vlad.ShowListProducts();

}
