//#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<ctype.h>
using namespace std;
class COLOANA_TABEL {
public:
	friend class TABEL;
	string nume_coloana;
	string tip_coloana;
	int dim_tip_coloana;
	string valoare;
};


class TABLE
{

	COLOANA_TABEL* c;
	//definire tabel la modul general
	//coloane = atribute

	int nr_coloane;
	//string nume_tabel;

public:
	string nume_tabel;
	void CREATE()
	{
		//citire de la tastatura pentru comanda CREATE
		cout << "Va rugam tastati denumirea tabelului pe care doriti sa il creati:" << endl;
		cin >> nume_tabel;
		cout << "Numarul coloanelor din tabel:" << endl;
		cin >> nr_coloane;
		if (nr_coloane != 0)
		{
			c = new COLOANA_TABEL[nr_coloane];
			for (int i = 0; i < nr_coloane; i++)
			{
				cout << "Nume coloana: ";
				cin >> c[i].nume_coloana;
				cout << endl << "Tip coloana: ";
				cin >> c[i].tip_coloana;
				cout << endl << "Dimensiune coloana: "<<endl;

				
					if (c[i].tip_coloana == "VARCHAR2" || c[i].tip_coloana == "VARCHAR" || c[i].tip_coloana == "NUMBER")
					{
						cin >> c[i].dim_tip_coloana;
					}
					else


						if (c[i].tip_coloana == "DATE")
						{
							c[i].dim_tip_coloana = 10;
						}
						else
						{
							cout << endl << "Nu ai introdus tipul corect. Try again";
							
						}
					
			}
		}
	}

	void DISPLAY()
	{
		if (nr_coloane != 0) {
			cout << nume_tabel;
			for (int i = 0; i < nr_coloane; i++)
			{
				cout << endl;
				cout << "Nume coloana: " << c[i].nume_coloana << endl;
				cout << "Tip coloana: " << c[i].tip_coloana << endl;
				cout << "Dim tip coloana: " << c[i].dim_tip_coloana << endl;
			}
		}
	}

	void DROP_TABLE()
	{
		nume_tabel = "\0";
		nr_coloane = 0;
		delete[] c;
		cout <<endl<< "Tabelul a fost sters";
	}

	void UPDATE()
	{
		string nume_col;
		cout << "Introduceti numele coloanei: " << endl;
		cin >> nume_col;
		for (int i = 0; i < nr_coloane; i++)
		{
			if (c[i].nume_coloana == nume_col)
			{
				
				if (c[i].tip_coloana == "NUMBER")
				{
					string valoare;
					cout << "Cu ce valoare vrei sa modifici? " << endl;
					cin >> valoare;
					c[i].valoare = valoare;
					stof(c[i].valoare);
				}
				else
				{
					string valoare;
					cout << "Cu ce valoare vrei sa modifici? " << endl;
					cin >> valoare;
					c[i].valoare = valoare;
				}
			}
		}

	}

	
};

int main()
{
	
	//TABLE t1;
	//TABLE t2;
	//t1.CREATE();
	//t1.DISPLAY();
	//t1.DROP_TABLE();
	TABLE t[10];
	int verifica = 1;
	int i = 0;
	while (verifica)
	{
		string comanda;
		cout << "doriti sa creati un tabel?Scrieti 1 daca doriti, altfel 0" << endl;
		
		cin >> verifica;
		
		if (verifica)
		{
			cout << "Scrieti comanda de creare" << endl;
			cin >> comanda;
			if (comanda == "CREATE")
			{
				t[i].CREATE();
				i++;
			}
			else
			{
				cout << "Nu ati introdus corect comanda" << endl;
			}
		}
	}
	int verifica = 1;
	while (verifica) {
		string comanda;
		string nume;
		cout << "Doriti sa introduceti o comanda?Daca da 1, altfel 0" << endl;
		cin >> verifica;
		if (verifica)
		{
			cout << "Introduceti comanda pe care doriti sa o apelati" << endl;
			cin >> comanda;
		
			if (comanda == "DISPLAY")
			{
				cout << "Introduceti numele tabelei pe care doriti sa apelati comanda" << endl;
				cin >> nume;
				for (int j = 0; j < i; j++)
				{
					if (t[i].nume_tabel == nume)
					{
						t[i].DISPLAY();
					}
				}
			}
			if (comanda == "DROP")
			{
				cout << "Introduceti numele tabelei pe care doriti sa apelati comanda" << endl;
				cin >> nume;
				for (int j = 0; j < i; j++)
				{
					if (t[i].nume_tabel == nume)
					{
						t[i].DROP_TABLE();
					}
				}
			}
			
		}
	}
	
	
}
