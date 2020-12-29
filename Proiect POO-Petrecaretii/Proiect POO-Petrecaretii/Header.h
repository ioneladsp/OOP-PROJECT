#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <ctype.h>
using namespace std;

char* uppercase(char* caractere)
{
	int len = strlen(caractere);
	for (int i = 0; i < len; i++)
	{
		caractere[i] = toupper(caractere[i]);
	}
	return caractere;
}

class coloana_tabel
{
	char* nume_coloana = nullptr;
	char* tip_coloana = nullptr;
	char* dim_tip_coloana = nullptr;
	char* valoare_implicita = nullptr; //sau static string?
	int id_coloana = 0;
	int ordine[10];
public:
	coloana_tabel()
	{
		nume_coloana = nullptr;
		tip_coloana = nullptr;
		dim_tip_coloana = nullptr;
		valoare_implicita = nullptr;
		id_coloana = 0;
		for (int i = 0; i < 10; i++)
			ordine[i] = 0;
	}
	coloana_tabel(const char* nume_coloana, const char* tip_coloana, const char* dim_tip_coloana)
	{
		if (nume_coloana != nullptr)
		{
			this->nume_coloana = new char[strlen(nume_coloana) + 1];
			strcpy(this->nume_coloana, nume_coloana);
		}
		if (tip_coloana != nullptr)
		{
			this->tip_coloana = new char[strlen(tip_coloana) + 1];
			strcpy(this->tip_coloana, tip_coloana);
		}
		if (dim_tip_coloana != nullptr)
		{
			this->dim_tip_coloana = new char[strlen(dim_tip_coloana) + 1];
			strcpy(this->dim_tip_coloana, dim_tip_coloana);
		}
	}

	coloana_tabel(const char* valoare_implicita)
	{
		if (valoare_implicita != nullptr)
		{
			this->valoare_implicita = new char[strlen(valoare_implicita) + 1];
			strcpy(this->valoare_implicita, valoare_implicita);
		}
	}

	char* get_nume_coloana()
	{
		return this->nume_coloana;
	}

	char* get_tip_coloana()
	{
		return this->tip_coloana;
	}

	char* get_dim_tip_coloana()
	{
		return this->dim_tip_coloana;
	}

	char* get_valoare_implicita()
	{
		return this->valoare_implicita;
	}

	int get_id_coloana()
	{
		return this->id_coloana;
	}

	int get_ordine()
	{
		for (int i = 0; i < 10; i++)
			return this->ordine[i];
	}

	void set_nume_coloana(const char* nume_coloana)
	{
		if (nume_coloana != nullptr)
		{
			if (this->nume_coloana != nullptr)
			{
				delete this->nume_coloana;
				this->nume_coloana = new char[strlen(nume_coloana) + 1];
				strcpy(this->nume_coloana, nume_coloana);
			}
			else
			{
				this->nume_coloana = new char[strlen(nume_coloana) + 1];
				strcpy(this->nume_coloana, nume_coloana);
			}
		}
	}

	void set_tip_coloana(const char* tip_coloana)
	{
		if (tip_coloana != nullptr)
		{
			if (this->tip_coloana != nullptr)
			{
				delete this->tip_coloana;
				this->tip_coloana = new char[strlen(tip_coloana) + 1];
				strcpy(this->tip_coloana, tip_coloana);
			}
			else
			{
				this->tip_coloana = new char[strlen(tip_coloana) + 1];
				strcpy(this->tip_coloana, tip_coloana);
			}
		}
	}

	void set_dim_tip_coloana(const char* dim_tip_coloana)
	{
		if (dim_tip_coloana != nullptr)
		{
			if (this->dim_tip_coloana != nullptr)
			{
				delete this->dim_tip_coloana;
				this->dim_tip_coloana = new char[strlen(dim_tip_coloana) + 1];
				strcpy(this->dim_tip_coloana, dim_tip_coloana);
			}
			else
			{
				this->dim_tip_coloana = new char[strlen(dim_tip_coloana) + 1];
				strcpy(this->dim_tip_coloana, dim_tip_coloana);
			}
		}
	}

	void set_valoare_implicita(const char* valoare_implicita)
	{
		if (valoare_implicita != nullptr)
		{
			if (this->valoare_implicita != nullptr)
			{
				delete this->valoare_implicita;
				this->valoare_implicita = new char[strlen(valoare_implicita) + 1];
				strcpy(this->valoare_implicita, valoare_implicita);
			}
			else
			{
				this->valoare_implicita = new char[strlen(valoare_implicita) + 1];
				strcpy(this->valoare_implicita, valoare_implicita);
			}
		}
	}

	void set_id_coloana(int  id_coloana)
	{
		this->id_coloana = id_coloana;
	}

	void set_ordine(int ordine[10])
	{
		for (int i = 0; i < 10; i++)
			this->ordine[i] = ordine[i];
	}

	coloana_tabel(const coloana_tabel& c)
	{
		if (c.nume_coloana != nullptr)
		{
			this->nume_coloana = new char[strlen(c.nume_coloana) + 1];
			strcpy(this->nume_coloana, c.nume_coloana);
		}
		if (c.tip_coloana != nullptr)
		{
			this->tip_coloana = new char[strlen(c.tip_coloana) + 1];
			strcpy(this->tip_coloana, c.tip_coloana);
		}
		if (c.dim_tip_coloana != nullptr)
		{
			this->dim_tip_coloana = new char[strlen(c.dim_tip_coloana) + 1];
			strcpy(this->dim_tip_coloana, c.dim_tip_coloana);
		}
		if (c.valoare_implicita != nullptr)
		{
			this->valoare_implicita = new char[strlen(c.valoare_implicita) + 1];
			strcpy(this->valoare_implicita, c.valoare_implicita);
		}
		this->id_coloana = c.id_coloana;
		for (int i = 0; i < 10; i++)
			this->ordine[i] = c.ordine[i];
	}

	coloana_tabel& operator=(const coloana_tabel& c)
	{
		delete this->nume_coloana;
		delete this->dim_tip_coloana;
		delete this->tip_coloana;
		delete this->valoare_implicita;
		if (c.nume_coloana != nullptr)
		{
			this->nume_coloana = new char[strlen(c.nume_coloana) + 1];
			strcpy(this->nume_coloana, c.nume_coloana);
		}
		if (c.tip_coloana != nullptr)
		{
			this->tip_coloana = new char[strlen(c.tip_coloana) + 1];
			strcpy(this->tip_coloana, c.tip_coloana);
		}
		if (c.dim_tip_coloana != nullptr)
		{
			this->dim_tip_coloana = new char[strlen(c.dim_tip_coloana) + 1];
			strcpy(this->dim_tip_coloana, c.dim_tip_coloana);
		}
		if (c.valoare_implicita != nullptr)
		{
			this->valoare_implicita = new char[strlen(c.valoare_implicita) + 1];
			strcpy(this->valoare_implicita, c.valoare_implicita);
		}
		this->id_coloana = c.id_coloana;
		for (int i = 0; i < 10; i++)
			this->ordine[i] = c.ordine[i];
		return *this;
	}

	~coloana_tabel()
	{
		if (nume_coloana != nullptr)
		{
			delete this->nume_coloana;
		}
		if (tip_coloana != nullptr)
		{
			delete this->dim_tip_coloana;
		}
		if (dim_tip_coloana != nullptr)
		{
			delete this->tip_coloana;
		}
		if (valoare_implicita != nullptr)
		{
			delete this->valoare_implicita;
		}
	}
	coloana_tabel operator++()
	{
		this->id_coloana++;
		return *this;
	}

	coloana_tabel operator++(int i)
	{
		coloana_tabel copie = *this;
		this->id_coloana++;
		return copie;
	}

	coloana_tabel operator+(int valoare)
	{
		if (this->id_coloana > 0)
		{
			coloana_tabel copie = *this;
			copie.id_coloana += valoare;
			return copie;
		}
		else
		{

			throw "Nu exista coloana in baza de date";
		}
	}

	int& operator[](int index)
	{
		if (index >= 0 && index < this->id_coloana)
		{
			return ordine[index];
		}
		throw exception("index invalid");
	}
	bool operator!()
	{
		return id_coloana > 0;
	}

	explicit operator int()
	{
		return id_coloana;
	}
	bool  operator==(const coloana_tabel& c2)
	{
		return this->id_coloana == c2.id_coloana;
	}

	bool operator<(const coloana_tabel& c2) {
		return this->id_coloana < c2.id_coloana;
	}

	friend ostream& operator<<(ostream&, coloana_tabel);
	friend istream& operator>>(istream&, coloana_tabel&);
	friend class identificator_comanda;
};

ostream& operator<<(ostream& out, coloana_tabel c)
{
	if (c.nume_coloana != nullptr)
	{
		out << c.nume_coloana << " ";
	}
	if (c.tip_coloana != nullptr)
	{
		out << c.tip_coloana << " ";
	}
	if (c.dim_tip_coloana != nullptr)
	{
		out << c.dim_tip_coloana << " ";
	}
	if (c.valoare_implicita != nullptr)
	{
		out << c.valoare_implicita;
	}
	out << endl;
	return out;
}

istream& operator>>(istream& in, coloana_tabel& c)
{
	string buffer;
	in >> buffer;
	if (c.nume_coloana != nullptr)
	{
		delete[] c.nume_coloana;
	}
	c.nume_coloana = new char[buffer.length() + 1];
	strcpy(c.nume_coloana, buffer.c_str());
	in >> buffer;
	if (c.tip_coloana != nullptr)
	{
		delete[] c.tip_coloana;
	}
	c.tip_coloana = new char[buffer.length() + 1];
	strcpy(c.tip_coloana, buffer.c_str());
	in >> buffer;
	if (c.dim_tip_coloana != nullptr)
	{
		delete[] c.dim_tip_coloana;
	}
	c.dim_tip_coloana = new char[buffer.length() + 1];
	strcpy(c.dim_tip_coloana, buffer.c_str());
	in >> buffer;
	if (c.valoare_implicita != nullptr)
	{
		delete[] c.valoare_implicita;
	}
	c.valoare_implicita = new char[buffer.length() + 1];
	strcpy(c.valoare_implicita, buffer.c_str());
	return in;
}

class date
{
	char* date_introduse = nullptr;
	int id_date = 0;
	string cuvinte[10];
public:
	date()
	{
		this->date_introduse = nullptr;
		this->id_date = 0;
		for (int i = 0; i < 10; i++)
			this->cuvinte[i] = "necunoscut";
	}

	date(char* date_introduse)
	{
		this->date_introduse = date_introduse;
	}

	date(char* date_introduse, int id_date)
	{
		this->date_introduse = date_introduse;
		this->id_date = id_date;
	}

	date(const date& d)
	{
		if (d.date_introduse != nullptr)
		{
			this->date_introduse = new char[strlen(d.date_introduse) + 1];
			strcpy(this->date_introduse, d.date_introduse);
		}
		this->id_date = d.id_date;
		for (int i = 0; i < 10; i++)
			this->cuvinte[i] = d.cuvinte[i];
	}
	date& operator=(const date& d)
	{
		if (this->date_introduse != nullptr)
		{
			delete[] date_introduse;
		}
		if (d.date_introduse != nullptr)
		{
			this->date_introduse = new char[strlen(d.date_introduse) + 1];
			strcpy(this->date_introduse, d.date_introduse);
		}
		this->id_date = d.id_date;
		for (int i = 0; i < 10; i++)
			this->cuvinte[i] = d.cuvinte[i];
		return *this;
	}

	int get_id_date()
	{
		return this->id_date;
	}

	void set_id_date(int id_date)
	{
		this->id_date = id_date;
	}

	string get_cuvinte()
	{
		for (int i = 0; i < 10; i++)
			return this->cuvinte[i];
	}

	void set_cuvinte(string cuvinte[10])
	{
		for (int i = 0; i < 10; i++)
			this->cuvinte[i] = cuvinte[i];
	}

	char* get_date_introduse()
	{
		return this->date_introduse;
	}
	void set_date_introduse(const char* date_introduse)
	{
		if (date_introduse != nullptr)
		{
			if (this->date_introduse != nullptr)
			{
				delete[] this->date_introduse;
				this->date_introduse = new char[strlen(date_introduse) + 1];
				strcpy(this->date_introduse, date_introduse);
			}
			else
			{
				this->date_introduse = new char[strlen(date_introduse) + 1];
				strcpy(this->date_introduse, date_introduse);
			}
		}
	}
	~date()
	{
		delete[] this->date_introduse;
	}
	date operator++()
	{
		this->id_date++;
		return *this;
	}
	date operator++(int i)
	{
		date copie = *this;
		this->id_date++;
		return copie;
	}
	date operator+(int valoare)
	{
		if (this->id_date > 0)
		{
			date copie = *this;
			copie.id_date += valoare;
			return copie;
		}
		else
		{
			throw "Nu exista inregistrarea in baza de date";
		}
	}
	string& operator[](int index)
	{
		if (index >= 0 && index < this->id_date)
		{
			return cuvinte[index];
		}
		throw exception("index invalid");
	}
	bool operator!()
	{
		return id_date > 0;
	}
	explicit operator int()
	{
		return id_date;
	}
	bool  operator==(const date& c2)
	{
		return this->id_date == c2.id_date;
	}

	bool operator<(const date& c2) {
		return this->id_date < c2.id_date;
	}
	friend ostream& operator<<(ostream&, date);
	friend istream& operator>>(istream&, date&);
	friend class tabela;
};

ostream& operator<<(ostream& out, date c)
{
	if (c.date_introduse != nullptr)
	{
		out << c.date_introduse << " ";
	}
	out << c.cuvinte;
	out << endl;
	out << c.id_date;
	return out;
}
istream& operator>>(istream& in, date& c)
{
	string buffer;
	in >> buffer;
	if (c.date_introduse != nullptr)
	{
		delete[] c.date_introduse;
	}
	c.date_introduse = new char[buffer.length() + 1];
	strcpy(c.date_introduse, buffer.c_str());
	in >> buffer;
	in >> c.id_date;
	in >> c.cuvinte[c.id_date];
	return in;
}

class tabela
{
	int numar_date;
	char nume_tabela[20];
	int id_tabela;
	int numar_tabele;
	int numar_coloane;
	coloana_tabel coloane[10];
	date d[10][10];
public:
	tabela()
	{
		this->numar_date = 0;
		this->id_tabela = 0;
		this->numar_coloane = 0;
	}

	tabela(int numar_date, int numar_coloane)
	{
		this->numar_date = numar_date;
		this->numar_coloane = numar_coloane;
	}

	tabela(int numar_date, int numar_coloane, int id_tabela)
	{
		this->numar_date = numar_date;
		this->numar_coloane = numar_coloane;
		this->id_tabela = id_tabela;
	}

	void set_id_tabela(int numar)
	{
		this->id_tabela = numar;
	}
	int get_id_tabela()
	{
		return id_tabela;
	}
	void set_numar_date(int numar_date)
	{
		this->numar_date = numar_date;
	}
	void set_numar_coloane(int numar)
	{
		this->numar_coloane = numar;
	}
	int get_numar_coloane()
	{
		return numar_coloane;
	}
	void set_nume_tabela(const char* nume)
	{
		strcpy(nume_tabela, nume);
	}
	void afisare_tabela(int nr_coloane)
	{

		int j;
		int val;
		cout << "----------" << nume_tabela << "----------" << endl;
		for (int i = 0; i < nr_coloane; i++)
		{
			cout << " " << coloane[i].get_nume_coloana();
			val = 12 - strlen(coloane[i].get_nume_coloana());
			for (j = 0; j < val; j++)
				cout << " ";
			cout << "|  ";
			cout << coloane[i].get_tip_coloana();
			val = 12 - strlen(coloane[i].get_tip_coloana());
			for (j = 0; j < val; j++)
				cout << " ";
			cout << "|  ";
			cout << coloane[i].get_dim_tip_coloana();
			val = 8 - strlen(coloane[i].get_dim_tip_coloana());
			for (j = 0; j < val; j++)
				cout << " ";
			cout << "|  ";
			cout << coloane[i].get_valoare_implicita();
			cout << endl;
		}
		for (int i = 0; i < strlen(nume_tabela); i++) {
			cout << '.';
		}
		cout << endl;
		system("pause");
		system("cls");
	}

	void afiseaza_date(int numar_coloane)
	{
		for (int i = 0; i <= numar_date; i++)
		{
			for (int j = 1; j <= numar_coloane; j++)
				cout << d[i][j].get_date_introduse() << " ";
			cout << endl;
		}
	}

	tabela operator++()
	{
		this->id_tabela++;
		return *this;
	}

	tabela operator++(int i)
	{
		tabela* copie = this;
		this->id_tabela++;
		return *copie;
	}

	tabela operator+(int valoare)
	{
		this->id_tabela = this->id_tabela + valoare;
		return *this;
	}

	coloana_tabel& operator[](int index)
	{
		if (index >= 0 && index < this->numar_coloane)
		{
			return coloane[index];
		}
		throw exception("index invalid");
	}
	bool operator!()
	{
		return numar_coloane > 0;
	}

	explicit operator int()
	{
		return id_tabela;
	}
	bool  operator==(const tabela& t2)
	{
		return this->id_tabela == t2.id_tabela;
	}
	bool operator <(const tabela& t2)
	{
		return this->id_tabela < t2.id_tabela;
	}

	friend class identificator_comanda;
	friend class date;
	friend ostream& operator<<(ostream&, tabela);
	friend istream& operator>>(istream&, tabela&);
};
int numar_tabele = 1;

ostream& operator<<(ostream& out, tabela c)
{
	out << c.numar_date;
	out << c.nume_tabela;
	out << c.id_tabela;
	out << c.numar_tabele;
	out << c.coloane;
	out << c.d;
	return out;
}

istream& operator>>(istream& in, tabela& c)
{
	in >> c.nume_tabela;
	in >> c.numar_date;
	in >> c.id_tabela;
	in >> c.numar_tabele;
	in >> c.coloane[c.id_tabela];
	in >> c.d[c.numar_date][c.numar_coloane];
	return in;
}

class identificator_comanda
{
	vector<string> nume_tabele;
	tabela t[10];
	int aux;
public:

	identificator_comanda()
	{
	}

	identificator_comanda(int aux)
	{
		this->aux = aux;
	}

	identificator_comanda(int aux, tabela t[10])
	{
		this->aux = aux;
		for (int i = 0; i < 10; i++)
		{
			this->t[10] = t[10];
		}
	}

	void identifica_comanda(char s[])
	{
		char separator[5] = " ,()";
		char comanda[20];
		char nume_tabela[20];
		int numar_coloane;
		int nr_id = 0;
		char* verifica = strtok(s, separator);
		char* verifica1;
		verifica1 = new char[strlen(verifica) + 1];
		strcpy(verifica1, verifica);
		strcpy(comanda, verifica);
		// comanda
		if (verifica)
		{
			verifica = strtok(NULL, separator);
			strcat(comanda, " ");
			strcat(comanda, verifica);
			strcpy(comanda, uppercase(comanda));
			if (strcmp(comanda, "CREATE TABLE") == 0)
			{

				numar_coloane = 0;
				verifica = strtok(NULL, separator);
				if (verifica)
				{
					vector<string>::iterator it = find(nume_tabele.begin(), nume_tabele.end(), verifica);
					if (it != nume_tabele.end()) //daca se gaseste deja in vector
					{
						cout << " EROARE: Tabela exista deja. Incercati sa introduceti alt nume." << endl;
						cout << endl;
						system("pause");
						system("cls");
					}
					else
					{
						t[numar_tabele].set_nume_tabela(verifica);
						nume_tabele.push_back(verifica);
						verifica = strtok(NULL, separator);
						while (verifica)
						{
							t[numar_tabele].coloane[numar_coloane].set_nume_coloana(verifica);
							t[numar_tabele].d[0][numar_coloane + 1].set_date_introduse(verifica);
							verifica = strtok(NULL, separator);
							t[numar_tabele].coloane[numar_coloane].set_tip_coloana(verifica);
							verifica = strtok(NULL, separator);
							t[numar_tabele].coloane[numar_coloane].set_dim_tip_coloana(verifica);
							verifica = strtok(NULL, separator);
							t[numar_tabele].coloane[numar_coloane].set_valoare_implicita(verifica);
							numar_coloane++;
							verifica = strtok(NULL, separator);
						}
						cout << " Tabela a fost creata." << endl;
						cout << endl;
						system("pause");
						system("cls");
						t[numar_tabele].set_id_tabela(numar_tabele);
						t[numar_tabele].set_numar_coloane(numar_coloane);
						numar_tabele++; // acest numar tabele nu creste dupa ce am creat primul tabel
					}
				}

			}
			else if (strcmp(comanda, "DISPLAY TABLE") == 0)
			{
				verifica = strtok(NULL, separator);
				if (verifica)
				{
					vector<string>::iterator it = find(nume_tabele.begin(), nume_tabele.end(), verifica);
					if (it != nume_tabele.end()) //daca se gaseste deja in vector
					{
						for (int i = 1; i <= numar_tabele; i++)
						{
							if (strcmp(t[i].nume_tabela, verifica) == 0)
							{
								t[i].afisare_tabela(t[i].numar_coloane);
							}
						}
					}
					else
					{
						cout << " EROARE: Tabela nu exista." << endl;
						cout << endl;
						system("pause");
						system("cls");
					}
				}
			}
			else if (strcmp(comanda, "DROP TABLE") == 0)
			{
				verifica = strtok(NULL, separator);
				if (verifica)
				{
					vector<string>::iterator it = find(nume_tabele.begin(), nume_tabele.end(), verifica);
					if (it != nume_tabele.end()) //daca se gaseste deja in vector
					{
						for (int i = 0; i < nume_tabele.size(); i++)
						{
							if (nume_tabele[i] == verifica)
							{
								nume_tabele.erase(nume_tabele.begin() + i);
								numar_tabele--;
							}
						}
						cout << " Tabela a fost stearsa." << endl;
						cout << endl;
						system("pause");
						system("cls");
					}
					else
					{
						cout << " EROARE: Tabela nu exista" << endl;
						cout << endl;
						system("pause");
						system("cls");
					}
				}
			}
			else if (strcmp(comanda, "INSERT INTO") == 0)
			{
				verifica = strtok(NULL, separator);
				if (verifica)
				{
					vector<string>::iterator it = find(nume_tabele.begin(), nume_tabele.end(), verifica);
					if (it != nume_tabele.end()) //daca se gaseste in vector
					{
						aux = distance(nume_tabele.begin(), it);
						verifica = strtok(NULL, separator);
						if (verifica)
						{
							if (strcmp(uppercase(verifica), "VALUES") == 0)
							{
								int m = 1;
								verifica = strtok(NULL, separator);
								while (verifica && m <= t[aux + 1].numar_coloane)
								{
									t[aux + 1].d[t[aux + 1].numar_date + 1][m].set_date_introduse(verifica);
									verifica = strtok(NULL, separator);
									m++;
								}
								cout << " Inregistrare inserata." << endl;
								system("pause");
								system("cls");
								t[aux + 1].numar_date++; //numar insert
								t[aux + 1].set_numar_date(t[aux + 1].numar_date);
							}
							else
							{
								cout << "EROARE: Comanda nu a fost introdusa corect." << endl;
								system("pause");
								system("cls");
							}
						}
					}
					else
					{
						cout << " EROARE: Tabela nu exista sau a fost stearsa.";
						cout << endl;
						system("pause");
						system("cls");
					}
				}
			}
			else if (strcmp(comanda, "SELECT ALL") == 0)
			{
				verifica = strtok(NULL, separator);
				if (verifica != NULL && strcmp(uppercase(verifica), "FROM") == 0)
				{
					verifica = strtok(NULL, separator);
					if (verifica)
					{
						vector<string>::iterator it = find(nume_tabele.begin(), nume_tabele.end(), verifica);
						if (it != nume_tabele.end()) //daca se gaseste in vector
						{
							string copie_nume_tabela = verifica;
							verifica = strtok(NULL, separator); //poate am ajuns la where
							if (verifica)
							{
								if (strcmp(uppercase(verifica), "WHERE") == 0)
								{
									verifica = strtok(NULL, separator); //luam numele coloanei pentru conditie
									char nume_coloana_conditie[100];
									strcpy(nume_coloana_conditie, verifica);
									if (verifica)
									{
										for (int i = 1; i <= t[aux + 1].numar_coloane; i++)
										{
											if (strcmp(t[aux + 1].d[0][i].get_date_introduse(), verifica) == 0)
											{
												verifica = strtok(NULL, separator); //am luat egal
												if (strcmp(verifica, "=") == 0)
												{
													verifica = strtok(NULL, separator); //luam valoarea pentru care se vor afisa date
													if (verifica)
													{
														for (int g = 0; g < t[aux + 1].numar_date + 1; g++) //parcurgere pe linii
														{
															if (strcmp(t[aux + 1].d[g][i].get_date_introduse(), verifica) == 0 || strcmp(t[aux + 1].d[g][i].get_date_introduse(), nume_coloana_conditie) == 0)
															{
																for (int j = 1; j <= t[aux + 1].numar_coloane; j++)
																{
																	cout << t[aux + 1].d[g][j].get_date_introduse() << " ";
																}
																cout << endl;
															}
														}
														cout << endl;
														system("pause");
														system("cls");
													}
												}
											}
										}

									}
								}
							}
							else
							{
								for (int i = 1; i <= numar_tabele; i++)
								{
									if (t[i].nume_tabela == copie_nume_tabela)
									{
										cout << t[i].nume_tabela << endl;
										t[i].afiseaza_date(t[i].numar_coloane);
									}
								}
								cout << endl;
								system("pause");
								system("cls");
							}
						}
					}
				}
			}
			else if (strcmp(comanda, "DELETE FROM") == 0)
			{
				verifica = strtok(NULL, separator);
				if (verifica)
				{
					vector<string>::iterator it = find(nume_tabele.begin(), nume_tabele.end(), verifica);
					if (it != nume_tabele.end()) //daca se gaseste in vector
					{
						aux = distance(nume_tabele.begin(), it);
						verifica = strtok(NULL, separator);
						if (strcmp(uppercase(verifica), "WHERE") == 0) //verificam WHERE
						{
							verifica = strtok(NULL, separator); //luam numele coloanei
							if (verifica)
							{
								for (int i = 1; i <= t[aux + 1].numar_coloane; i++)
								{
									if (strcmp(verifica, t[aux + 1].coloane[i - 1].nume_coloana) == 0) //cautam daca exista coloana precizata
									{
										verifica = strtok(NULL, separator);
										if (strcmp(verifica, "=") == 0) //cautam egal
										{
											verifica = strtok(NULL, separator); //luam valoarea dorita
											if (verifica)
											{
												for (int j = 0; j < t[aux + 1].numar_coloane; j++)
												{
													if (strcmp(t[aux + 1].d[0][j + 1].get_date_introduse(), t[aux + 1].coloane[i - 1].nume_coloana) == 0) //cautam coloana corespunzatoare pretului 
													{
														for (int k = 1; k < t[aux + 1].numar_date; k++)
														{
															if (strcmp(t[aux + 1].d[k][j + 1].get_date_introduse(), verifica) == 0)
															{
																for (int l = k; l < t[aux + 1].numar_date; l++)
																{
																	for (int o = 1; o < t[aux + 1].numar_coloane + 1; o++)
																	{
																		t[aux + 1].d[l][o] = t[aux + 1].d[l + 1][o];
																	}
																}
																k--;
																t[aux + 1].numar_date = t[aux + 1].numar_date - 1;
																t[aux + 1].set_numar_date(t[aux + 1].numar_date);
															}
														}
														if (strcmp(t[aux + 1].d[t[aux + 1].numar_date][j + 1].get_date_introduse(), verifica) == 0)
														{
															t[aux + 1].numar_date = t[aux + 1].numar_date - 1;
															t[aux + 1].set_numar_date(t[aux + 1].numar_date);
														}
														cout << " Inregistrarea a fost stearsa." << endl;
														system("pause");
														system("cls");
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			else if (strcmp(verifica1, "SELECT") == 0)
			{
				vector<string> coloana;
				if (verifica)
				{
					while (verifica != NULL && strcmp(uppercase(verifica), "FROM") != 0)
					{
						coloana.push_back(verifica);
						verifica = strtok(NULL, separator);
					}
					verifica = strtok(NULL, separator); //am ajuns la numele tabelei
					vector<string>::iterator it = find(nume_tabele.begin(), nume_tabele.end(), verifica);
					if (it != nume_tabele.end()) //daca se gaseste in vector
					{
						aux = distance(nume_tabele.begin(), it);
						verifica = strtok(NULL, separator); //poate am ajuns la where
						if (verifica)
						{
							if (strcmp(uppercase(verifica), "WHERE") == 0)
							{
								verifica = strtok(NULL, separator); //luam numele coloanei pentru conditie
								char nume_coloana_conditie[100];
								strcpy(nume_coloana_conditie, verifica);
								if (verifica)
								{
									for (int i = 1; i <= t[aux + 1].numar_coloane; i++)
									{
										if (strcmp(t[aux + 1].d[0][i].get_date_introduse(), verifica) == 0)
										{
											verifica = strtok(NULL, separator); //am luat egal
											if (strcmp(verifica, "=") == 0)
											{
												verifica = strtok(NULL, separator); //luam valoarea pentru care se vor afisa date
												if (verifica)
												{
													for (int g = 0; g < t[aux + 1].numar_date + 1; g++) //parcurgere pe linii
													{
														if (strcmp(t[aux + 1].d[g][i].get_date_introduse(), verifica) == 0 || strcmp(t[aux + 1].d[g][i].get_date_introduse(), nume_coloana_conditie) == 0)
														{
															for (int j = 1; j <= t[aux + 1].numar_coloane; j++)
															{
																for (int k = 0; k < coloana.size(); k++)
																	if (coloana[k] == t[aux + 1].d[0][j].get_date_introduse())
																	{
																		cout << t[aux + 1].d[g][j].get_date_introduse() << " ";
																	}
															}
															cout << endl;
														}
													}
													cout << endl;
													system("pause");
													system("cls");
												}
											}
										}
									}

								}
							}
						}
						else
						{
							for (int l = 0; l < t[aux + 1].numar_date + 1; l++)
							{
								for (int j = 0; j < t[aux + 1].numar_date; j++)
								{
									for (int k = 0; k < coloana.size(); k++)
										if (coloana[k] == t[aux + 1].d[0][j + 1].get_date_introduse())
										{
											cout << t[aux + 1].d[l][j + 1].get_date_introduse() << " ";
										}
								}
								cout << endl;
							}
							cout << endl;
							system("pause");
							system("cls");
						}
					}
				}
			}
			else if (strcmp(verifica1, "UPDATE") == 0)
			{
				if (verifica)
				{
					vector<string>::iterator it = find(nume_tabele.begin(), nume_tabele.end(), verifica);
					if (it != nume_tabele.end()) //daca se gaseste in vector
					{
						aux = distance(nume_tabele.begin(), it);
						verifica = strtok(NULL, separator);
						if (strcmp(uppercase(verifica), "SET") == 0) //verificam SET
						{
							verifica = strtok(NULL, separator); //luam numele coloanei
							if (verifica)
							{
								for (int i = 0; i < t[aux + 1].numar_coloane; i++)
								{
									if (verifica)
										if (strcmp(verifica, t[aux + 1].coloane[i].nume_coloana) == 0) //cautam daca exista coloana precizata
										{
											verifica = strtok(NULL, separator);
											if (verifica)
												if (strcmp(verifica, "=") == 0) //cautam egal
												{
													verifica = strtok(NULL, separator); //luam valoarea dorita
													if (verifica)
													{
														char* valoare_dorita;
														valoare_dorita = new char[strlen(verifica) + 1];
														strcpy(valoare_dorita, verifica);
														for (int j = 0; j < t[aux + 1].numar_coloane; j++)
														{
															if (strcmp(t[aux + 1].d[0][j + 1].get_date_introduse(), t[aux + 1].coloane[i].nume_coloana) == 0) //cautam coloana corespunzatoare pretului
															{
																for (int k = 1; k <= t[aux + 1].numar_date; k++) //parcurgere pe linii
																{
																	verifica = strtok(NULL, separator);
																	if (verifica)
																	{
																		if (strcmp(uppercase(verifica), "WHERE") == 0)
																		{
																			verifica = strtok(NULL, separator); //nume coloana
																			if (verifica)
																			{
																				for (int w = 0; w < t[aux + 1].numar_coloane; w++)
																				{
																					if (strcmp(verifica, t[aux + 1].d[0][w + 1].get_date_introduse()) == 0)
																					{
																						verifica = strtok(NULL, separator); //il luam pe egal
																						if (strcmp(uppercase(verifica), "=") == 0)
																						{
																							verifica = strtok(NULL, separator); //luam valoarea cautata in ramura 2
																							if (verifica)
																							{
																								int nr = 0;
																								for (int q = 1; q <= t[aux + 1].numar_date; q++)
																								{
																									if (strcmp(t[aux + 1].d[q][w + 1].get_date_introduse(), verifica) == 0)
																									{
																										t[aux + 1].d[q][i + 1].set_date_introduse(valoare_dorita);
																										nr++;
																									}
																								}
																								if (nr == 0)
																								{
																									cout << " Nu a fost modificata nicio valoare." << endl;
																									system("pause");
																									system("cls");
																								}
																								else if (nr == 1)
																								{
																									cout << " A fost modificata o inregistrare." << endl;
																									system("pause");
																									system("cls");
																								}
																								else
																								{
																									cout << " Au fost modificate " << nr << " inregistrari." << endl;
																									system("pause");
																									system("cls");
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																		else
																		{
																			cout << " EROARE: Nu ati introdus cuvantul cheie 'WHERE'." << endl;
																			system("pause");
																			system("cls");
																		}
																	}
																}
															}
														}
													}
												}
										}
								}
							}
						}
						else
						{
							cout << " EROARE: Nu ati introdus cuvantul cheie 'SET'." << endl;
							system("pause");
							system("cls");
						}
					}
					else
					{
						cout << " EROARE: Tabela nu exista." << endl;
						system("pause");
						system("cls");
					}
				}
			}
			else
			{
				cout << " EROARE: Comanda nu a fost introdusa corect." << endl;
				cout << endl;
				system("pause");
				system("cls");
			}
		}
	}

	bool operator!()
	{
		return aux > 0;
	}

	explicit operator int()
	{
		return aux;
	}
	identificator_comanda operator++()
	{
		this->aux++;
		return *this;
	}

	identificator_comanda operator++(int i)
	{
		identificator_comanda* copie = this;
		this->aux++;
		return *copie;
	}

	identificator_comanda operator+(int valoare)
	{
		if (this->aux > 0)
		{
			identificator_comanda copie = *this;
			copie.aux += valoare;
			return copie;
		}
		else
		{
			throw "Nu exista  in baza de date";
		}
	}

	tabela& operator[](int index)
	{
		if (index >= 0 && index < this->aux)
		{
			return t[index];
		}
		throw exception("index invalid");
	}

	bool  operator==(const identificator_comanda& t2)
	{
		return this->aux == t2.aux;
	}
	bool operator <(const identificator_comanda& t2)
	{
		return this->aux < t2.aux;
	}
	friend class coloana_tabel;
	friend class tabela;
	friend class date;
	friend class meniu;
	friend ostream& operator<<(ostream&, identificator_comanda);
	friend istream& operator>>(istream&, identificator_comanda&);
};

ostream& operator<<(ostream& out, identificator_comanda ic)
{
	for (int i = 0; i < ic.nume_tabele.size(); i++)
	{
		out << ic.nume_tabele[i] << " ";
	}
	out << endl;
	out << ic.aux;
	for (int i = 0; i < numar_tabele; i++)
	{
		out << ic.t[i] << endl;
	}
	return out;
}

istream& operator>>(istream& in, identificator_comanda& ic)
{
	in >> ic.aux;
	for (int i = 0; i < numar_tabele; i++)
	{
		in >> ic.t[i];
	}
	return in;
}

class meniu
{
	char s[200];
	int z;
	int static numar_comanda;
	identificator_comanda a;
public:
	meniu()
	{
		this->z = 0;
		strcpy(s, " ");
	}

	void verifica()
	{
		/*cout << endl;
		cout << " _____  _____ ______ ______ ______      _                                       _    _  _ " << endl;
		cout << "/  ___| |  __ \| ___ \|  _  \| ___ \    | |                                    | |  (_)(_)" << endl;
		cout << "\ `--.  | |  \/| |_/ /| | | || |_/ /___ | |_  _ __  ___   ___  __ _  _ __  ___ | |_  _  _ " << endl;
		cout << " `--. \ | | __ | ___ \| | | ||  __// _ \| __|| '__|/ _ \ / __|/ _` || '__|/ _ \| __|| || |" << endl;
		cout << "/\__/ / | |_\ \| |_/ /| |/ / | |  |  __/| |_ | |  |  __/| (__| (_| || |  |  __/| |_ | || |" << endl;
		cout << "\____/   \____/\____/ |___/  \_|   \___| \__||_|   \___| \___|\__,_||_|   \___| \__||_||_|" << endl;*/

		cout << endl;
		cout << " Doriti sa introduceti o comanda? 1 sau 0" << endl;
		cout << " Raspuns: ";
		cin >> z;
		system("cls");
		if (z == 1)
		{
			cout << endl << " Introduceti comanda:" << endl << endl << " ";
			while (z == 1)
			{
				cin.get();
				cin.getline(s, 200);
				cout << endl;
				a.identifica_comanda(s);
				cout << endl;
				cout << " Doriti sa introduceti o comanda noua?" << endl;
				cout << " Raspuns: ";
				cin >> z;
				system("cls");
				cout << endl;
				if (z == 1)
					cout << " Introduceti comanda:" << endl << endl << " ";
			}
		}
	}

	bool operator!()
	{
		return z > 0;
	}

	explicit operator int()
	{
		return z;
	}

	meniu operator++()
	{
		this->z++;
		return *this;
	}

	meniu operator++(int i)
	{
		meniu* copie = this;
		this->z++;
		return *copie;
	}

	meniu operator+(int valoare)
	{
		if (this->z > 0)
		{
			meniu copie = *this;
			copie.z += valoare;
			return copie;
		}
		else
		{

			throw "Nu exista tabele in baza de date";
		}
	}

	friend ostream& operator<<(ostream&, meniu);
	friend istream& operator>>(istream&, meniu&);
	friend class identificator_comanda;
};

ostream& operator<<(ostream& out, meniu m)
{
	out << m.s << endl;
	out << m.z << endl;
	out << m.numar_comanda << endl;
	out << m.a << endl;
	return out;
}

istream& operator>>(istream& in, meniu& m)
{
	in >> m.s;
	in >> m.z;
	in >> m.numar_comanda;
	in >> m.a;
	return in;
}
int meniu::numar_comanda = 0;



