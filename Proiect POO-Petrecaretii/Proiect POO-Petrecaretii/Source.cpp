#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <ctype.h>
#include "Header.h"
using namespace std;

int main(int argc, char* argv[])
{
	cout << "Numar parametri (maxim 5) = " << argc << endl;
	if (argc <= 5)
	{
		for (int i = 0; i < argc; i++)
		{
			cout << argv[i] << endl;
		}
		system("title Proiect POO");
		system("cls");
		system("color 8F");
		meniu a;
		a.verifica();
	}
	else
	{
		cout << " Numarul de parametri introdusi este prea mare." << endl;
	}
	cout << " Multumim!";
	cout << endl;
}