#include <iostream>
#include "classes.cpp"

int main()
{
	Mail vlad(600);

	vlad.Menu();
	
	string name = "aaa.txt";
	ofstream outf(name);
	outf << name << "\n\n\n\n\n5555";
}
