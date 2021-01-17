#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <ctype.h>
using namespace std;

class meniu;

int nr_display = 0;
int nr_select = 0;
int validare;

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
	char* valoare_implicita = nullptr;
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

	virtual void afiseaza()
	{
		cout << " " << tip_coloana;
	}

	virtual void afiseaza_cheie(string nume_tabela)
	{
		cout << " Pentru a verifica valorile luate de cheia primara consultati fisierul " << nume_tabela << "_pk." << endl;
		system("pause");
		system("cls");
	}

	friend ostream& operator<<(ostream&, coloana_tabel);
	friend istream& operator>>(istream&, coloana_tabel&);
	friend class identificator_comanda;
	friend class gestionare_fisiere;
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

class chei_primare : coloana_tabel
{
	map<string, int> mp;

	vector<string> initializare_vector_stl(string nume_tabela)
	{
		string x;
		string g = "_pk";
		vector<string> v;
		nume_tabela = nume_tabela + g;
		fstream f(nume_tabela, ios::in);
		while (!f.eof())
		{
			f >> x;
			v.push_back(x);
		}
		return v;
<<<<<<< HEAD
		f.close();
=======
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
	}

	void initializare_fisier(string nume_tabela, string data_de_adaugat)
	{
		string g = "_pk";
		nume_tabela = nume_tabela + g;
		fstream f(nume_tabela, ios::out | ios::app);
		f << data_de_adaugat << endl;
<<<<<<< HEAD
		f.close();
	}

	void stergere_din_fisier(string nume_tabela, vector<string> vector_nou)
	{
		string g = "_pk";
		nume_tabela = nume_tabela + g;
		fstream f(nume_tabela, ios::out | ios::trunc);
		for (vector<string>::iterator it = vector_nou.begin(); it != vector_nou.end(); it++)
		{
			f << *it << endl;
		}
		f.close();
	}

	void afiseaza() override
	{
		for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
		{
			cout << it->first << endl; //nume tabela
		}
	}

	virtual void afiseaza_cheie(string nume_tabela)
	{
		for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
		{
			if (it->first == nume_tabela)
			{
				string g = "_pk";
				nume_tabela = nume_tabela + g;
				fstream f(nume_tabela, ios::out | ios::trunc);
				string de_citit;
				while (!f.eof())
				{
					f >> de_citit;
					cout << " " << de_citit;
				}
				f.close();
			}
		}
=======
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
	}

	friend class identificator_comanda;
	friend class meniu;
	friend class baza_de_date;
};

class chei_primare_compuse : coloana_tabel
{
	map<string, vector<int>> mp;

	map<string, string> initializare_map_stl(string nume_tabela)
	{
		string g = "_pk";
		string x, y;
		map<string, string> mmp;
		nume_tabela = nume_tabela + g;
		fstream f(nume_tabela, ios::in);
		while (!f.eof())
		{
			f >> x;
			f >> y;
			mmp.insert(make_pair(x, y));
		}
		return mmp;
	}

<<<<<<< HEAD
	void initializare_fisier(string nume_tabela, string data_de_adaugat, int b)
=======
	void initializare_fisier(string nume_tabela, string data_de_adaugat1, string data_de_adaugat2)
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
	{
		string g = "_pk";
		nume_tabela = nume_tabela + g;
		fstream f(nume_tabela, ios::out | ios::app);
<<<<<<< HEAD
		if (b == 1)
			f << data_de_adaugat << " ";
		else if (b == 2)
			f << data_de_adaugat << endl;
	}

	void stergere_din_fisier(string nume_tabela, map<string, string> map_nou)
	{
		string g = "_pk";
		nume_tabela = nume_tabela + g;
		fstream f(nume_tabela, ios::out | ios::trunc);
		for (map<string, string>::iterator it = map_nou.begin(); it != map_nou.end(); it++)
		{
			f << it->first << " " << it->second << endl;
		}
		f.close();
	}

	void afiseaza() override
	{
		for (map<string, vector<int>>::iterator it = mp.begin(); it != mp.end(); it++)
		{
			cout << it->first << endl; //nume tabela
		}
	}

	void afiseaza_cheie(string nume_tabela) override
	{
		for (map<string, vector<int>>::iterator it = mp.begin(); it != mp.end(); it++)
		{
			if (it->first == nume_tabela)
			{
				string g = "_pk";
				nume_tabela = nume_tabela + g;
				fstream f(nume_tabela, ios::out | ios::trunc);
				string cheie1;
				string cheie2;
				while (!f.eof())
				{
					f >> cheie1;
					f >> cheie2;
					cout << " " << cheie1 << " " << cheie2 << endl;
				}
				f.close();
			}
		}
=======
		f << data_de_adaugat1 << " " << data_de_adaugat2 << endl;
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
	}

	friend class baza_de_date;
	friend class identificator_comanda;
	friend class meniu;
};

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
	friend class baza_de_date;
	friend class tabela;
	friend class gestionare_fisiere_binare;
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
	coloana_tabel get_coloane()
	{
		for (int i = 0; i < 10; i++)
			return coloane[i];
	}
	int get_numar_date()
	{
		return numar_date;
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
	char* get_nume_tabela()
	{
		return nume_tabela;
	}
	void afisare_tabela(int nr_coloane)
	{
		//CREATE TABLE ANGAJATI((NUME,VARCHAR2,30,ANONIM),(SALARIU,NUMBER,3,0),(OCUPATIE,VARCHAR2,30,SOMER)
		//DISPLAY TABLE ANGAJATI
		//INSERT INTO ANGAJATI VALUES(NICU,700,MECANIC)
		//INSERT INTO ANGAJATI VALUES(MARIA,500,VANZATOR)
		//INSERT INTO ANGAJATI VALUES(ALBERT,600,ASTRONAUT)
		//INSERT INTO ANGAJATI VALUES(ION,700,MANELIST)
		//INSERT INTO ANGAJATI VALUES(NICU,800,TAMPLAR)
		//SELECT ALL FROM ANGAJATI WHERE SALARIU = 700
		//SELECT NUME, SALARIU FROM ANGAJATI WHERE SALARIU = 700
		//UPDATE ANGAJATI SET SALARIU = 1000 WHERE NUME = ION
		//DELETE FROM ANGAJATI WHERE NUME = MARIA
		//CREATE TABLE ANIMALE((SPECIE,VARCHAR2,30,NECUNOSCUTA),(PRET,NUMBER,30,0))
		//INSERT INTO ANIMALE VALUES(RATON,300)
		//INSERT INTO ANIMALE VALUES(MAMUT,1000)
		//INSERT INTO ANIMALE VALUES(ZEBRA,500)
<<<<<<< HEAD
		//INSERT INTO ANIMALE VALUES(CERB,400)
		//INSERT INTO ANIMALE VALUES(LEOPARD,900)
		//INSERT INTO ANIMALE VALUES(PAUN, 1100)
		//SELECT ALL FROM ANIMALE WHERE SPECIE = MAMUT
		//UPDATE ANIMALE SET SPECIE = CIMPANZEU WHERE PRET = 999
=======
		//INSERT INTO ANIMALE VALUES(CERB,300)
		//SELECT ALL FROM ANIMALE WHERE SPECIE = MAMUT
		//UPDATE ANIMALE SET SPECIE
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
		int j;
		int lungime_coloana;
		int lungime_nume;
		cout << " ";
		lungime_nume = (54 - strlen(nume_tabela)) / 2;
		for (int i = 0; i < lungime_nume; i++)
		{
			cout << "-";
		}
		cout << " ";
		cout << nume_tabela;
		cout << " ";
		for (int i = 0; i < lungime_nume; i++)
		{
			cout << "-";
		}
		cout << endl;
		for (int i = 0; i < nr_coloane; i++)
		{
			cout << " | " << coloane[i].get_nume_coloana();
			lungime_coloana = 13 - strlen(coloane[i].get_nume_coloana());
			for (j = 0; j < lungime_coloana; j++)
				cout << " ";
			cout << "|   ";
			cout << coloane[i].get_tip_coloana();
			lungime_coloana = 11 - strlen(coloane[i].get_tip_coloana());
			for (j = 0; j < lungime_coloana; j++)
				cout << " ";
			cout << "|  ";
			cout << coloane[i].get_dim_tip_coloana();
			lungime_coloana = 5 - strlen(coloane[i].get_dim_tip_coloana());
			for (j = 0; j < lungime_coloana; j++)
				cout << " ";
			cout << "|  ";
			cout << coloane[i].get_valoare_implicita();
			lungime_coloana = 14 - strlen(coloane[i].get_valoare_implicita());
			for (j = 0; j < lungime_coloana; j++)
				cout << " ";
			cout << "|" << endl;
		}
		cout << " ";
		int lungime_bara_jos;
		if (strlen(nume_tabela) % 2 == 1)
		{
			lungime_bara_jos = 55;
		}
		else
			lungime_bara_jos = 56;
		for (int j = 0; j < lungime_bara_jos; j++)
		{
			cout << "-";
		}
		cout << endl;
		cout << endl;
		system("pause");
		system("cls");
	}

	void afiseaza_date(int numar_coloane)
	{
<<<<<<< HEAD
=======
		//cout << " numar_coloane: " << numar_coloane << endl;
		//cout << " nume_tabela: " << nume_tabela << endl;
		//cout << " numar date: " << numar_date << endl;
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
		int numar_spatii;
		int numar_liniute;
		int l = 1;
		numar_liniute = (20 * numar_coloane - strlen(nume_tabela)) / 2;
<<<<<<< HEAD
=======
		//cout << " numar_liniute: " << numar_liniute << endl;
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
		cout << " ";
		for (int i = 0; i < numar_liniute; i++)
			cout << "-";
		cout << nume_tabela;
		for (int i = 0; i < numar_liniute; i++)
			cout << "-";
		cout << endl;
		for (int i = 0; i <= numar_date; i++)
		{
			for (int j = 1; j <= numar_coloane; j++)
			{
				if (i == 1 && j == 1)
				{
					cout << " ";
					while (l <= numar_coloane)
					{
						cout << "--------------------"; //20
						l++;
					}
					cout << endl;
				}
				cout << " |  " << d[i][j].get_date_introduse();
				numar_spatii = 16 - strlen(d[i][j].get_date_introduse());
				for (int k = 0; k < numar_spatii; k++)
				{
					cout << " ";
				}
			}
			cout << "|" << endl;
		}
		cout << " ";
		for (int i = 1; i <= numar_coloane; i++)
		{
			cout << "--------------------";
		}
		//cout << " numar date again: " << numar_date << endl;
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
	friend class gestionare_fisiere;
	friend class baza_de_date;
	friend class gestionare_fisiere_binare;
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

tabela* t = new tabela[10];

class gestionare_fisiere
{
	fstream f;
	int nr_display;
	int nr_select;
	void set_nr_display(int val)
	{
		this->nr_display = val;
	}
	void set_nr_select(int val)
	{
		this->nr_select = val;
	}
	void display(int q)
	{
		char nume_fisier[12] = "";
		char display[9] = "DISPLAY_";
		char copie[3];
		strcpy(nume_fisier, display);
		itoa(nr_display, copie, 10);
		strcat(nume_fisier, copie);
		fstream f(nume_fisier, ios::out);
		int j;
		int lungime_coloana;
		int lungime_nume;
		f << " ";
		lungime_nume = (54 - strlen(t[q].get_nume_tabela())) / 2;
		for (int i = 0; i < lungime_nume; i++)
		{
			f << "-";
		}
		f << " ";
		f << t[q].get_nume_tabela();
		f << " ";
		for (int i = 0; i < lungime_nume; i++)
		{
			f << "-";
		}
		f << endl;
		for (int i = 0; i < t[q].get_numar_coloane(); i++)
		{
			f << " | " << t[q].coloane[i].get_nume_coloana();
			lungime_coloana = 13 - strlen(t[q].coloane[i].get_nume_coloana());
			for (j = 0; j < lungime_coloana; j++)
				f << " ";
			f << "|   ";
			f << t[q].coloane[i].get_tip_coloana();
			lungime_coloana = 11 - strlen(t[q].coloane[i].get_tip_coloana());
			for (j = 0; j < lungime_coloana; j++)
				f << " ";
			f << "|  ";
			f << t[q].coloane[i].get_dim_tip_coloana();
			lungime_coloana = 5 - strlen(t[q].coloane[i].get_dim_tip_coloana());
			for (j = 0; j < lungime_coloana; j++)
				f << " ";
			f << "|  ";
			f << t[q].coloane[i].get_valoare_implicita();
			lungime_coloana = 14 - strlen(t[q].coloane[i].get_valoare_implicita());
			for (j = 0; j < lungime_coloana; j++)
				f << " ";
			f << "|" << endl;
		}
		f << " ";
		int lungime_bara_jos;
		if (strlen(t[q].nume_tabela) % 2 == 1)
		{
			lungime_bara_jos = 55;
		}
		else
			lungime_bara_jos = 56;
		for (int j = 0; j < lungime_bara_jos; j++)
		{
			f << "-";
		}
		f << endl;
		f.close();
	}
	void select_all(int q)
	{
		char nume_fisier[12] = "";
		char display[9] = "SELECT_";
		char copie[3];
		strcpy(nume_fisier, display);
		itoa(nr_select, copie, 10);
		strcat(nume_fisier, copie);
		fstream f(nume_fisier, ios::out);
		int numar_spatii;
		int numar_liniute;
		int l = 1;
		numar_liniute = (20 * t[q].numar_coloane - strlen(t[q].nume_tabela)) / 2;
		f << " ";
		for (int i = 0; i < numar_liniute; i++)
			f << "-";
		f << t[q].nume_tabela;
		for (int i = 0; i < numar_liniute; i++)
			f << "-";
		f << endl;
		for (int i = 0; i < t[q].numar_date; i++)
		{
			for (int j = 1; j <= t[q].numar_coloane; j++)
			{
				if (i == 1 && j == 1)
				{
					f << " ";
					while (l <= t[q].numar_coloane)
					{
						f << "--------------------"; //20
						l++;
					}
					f << endl;
				}
				f << " |  " << t[q].d[i][j].get_date_introduse();
				numar_spatii = 16 - strlen(t[q].d[i][j].get_date_introduse());
				for (int k = 0; k < numar_spatii; k++)
				{
					f << " ";
				}
			}
			f << "|" << endl;
		}
		f << " ";
		for (int i = 1; i <= t[q].numar_coloane; i++)
		{
			f << "--------------------";
		}
	}
	void select(string** mat, int nr_linii, int nr_coloane)
	{
		char nume_fisier[12] = "";
		char display[9] = "SELECT_";
		char copie[3];
		strcpy(nume_fisier, display);
		itoa(nr_select, copie, 10);
		strcat(nume_fisier, copie);
		fstream f(nume_fisier, ios::out);
		for (int i = 0; i < nr_linii; i++)
		{
			for (int j = 0; j < nr_coloane; j++)
			{
				f << "| " << mat[i][j] << " ";
			}
			f << endl;
		}
	}
	friend class date;
	friend class baza_de_date;
	friend class coloana_tabel;
	friend class tabela;
	friend class identificator_comanda;
};

class gestionare_fisiere_binare
{
	FILE* f;
	fstream g;
	void create_binar(char* nume_fisier, string* vector, int dim, int numar_coloane)
	{
		char* copie_nume_fisier = new char[strlen(nume_fisier) + 1];
		strcpy(copie_nume_fisier, nume_fisier);
		strcat(nume_fisier, ".bin");
		f = fopen(nume_fisier, "wb+");
		for (int i = 0; i < dim; i++)
		{
			fwrite(vector[i].c_str(), sizeof(vector[i]), 1, f);
		}
		fclose(f);
		fstream g(copie_nume_fisier, ios::out);
		for (int i = 0; i < dim; i = i + 4)
		{
			g << vector[i] << " ";
			g << vector[i + 1] << " ";
			g << vector[i + 2] << " ";
			g << vector[i + 3];
			g << endl;
		}
		g.close();
	}
	void insert_binar(char nume_fisier[10], int dim, string* vector)
	{
		char* copie_nume_fisier = new char[strlen(nume_fisier) + 1];
		strcpy(copie_nume_fisier, nume_fisier);
		strcat(nume_fisier, ".bin");
		f = fopen(nume_fisier, "rb+");
		fseek(f, 0, SEEK_END);
		for (int j = 0; j < dim; j++)
		{
			fwrite(vector[j].c_str(), sizeof(vector[j]), 1, f);
		}
		fclose(f);
		fstream g(copie_nume_fisier, ios::out | ios::app);
		for (int j = 0; j < dim; j++)
		{
			g << vector[j] << " ";
		}
		g.close();
	}
	void update_binar(char nume_fisier[10], int nr_linii, int nr_coloane, string** matrice, int k)
	{
		fstream fisier(nume_fisier, ios::out | ios::trunc);
		for (int l = 0; l < t[k].get_numar_coloane(); l++)
		{
			fisier << t[k].coloane[l].get_nume_coloana() << " ";
			fisier << t[k].coloane[l].get_tip_coloana() << " ";
			fisier << t[k].coloane[l].get_dim_tip_coloana() << " ";
			fisier << t[k].coloane[l].get_valoare_implicita() << endl;
		}
		for (int i = 1; i < nr_linii; i++)
		{
			for (int j = 0; j < nr_coloane; j++)
			{
				fisier << matrice[i][j] << " ";
			}
		}
		strcat(nume_fisier, ".bin");
		f = fopen(nume_fisier, "wb+");
		fseek(f, 0, SEEK_END);
		for (int i = 0; i < nr_linii; i++)
		{
			for (int j = 0; j < nr_coloane; j++)
			{
				fwrite(matrice[i][j].c_str(), sizeof(matrice[i][j]), 1, f);
			}
		}
		fclose(f);
	}
	void drop_binar(char* nume_fisier)
	{
<<<<<<< HEAD
		char* copie_nume_fisier = new char[strlen(nume_fisier) + 4];
		strcpy(copie_nume_fisier, nume_fisier);
=======
		char* copie_nume_fisier = new char[strlen(nume_fisier) + 1];
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
		strcat(copie_nume_fisier, "_pk");
		remove(copie_nume_fisier);
		remove(nume_fisier);
		strcat(nume_fisier, ".bin");
		remove(nume_fisier);
	}
	void delete_binar(char nume_fisier[10], int nr_linii, int nr_coloane, string** matrice, int k)
	{
		fstream fisier(nume_fisier, ios::out | ios::trunc);
		for (int l = 0; l < t[k].get_numar_coloane(); l++)
		{
			fisier << t[k].coloane[l].get_nume_coloana() << " ";
			fisier << t[k].coloane[l].get_tip_coloana() << " ";
			fisier << t[k].coloane[l].get_dim_tip_coloana() << " ";
			fisier << t[k].coloane[l].get_valoare_implicita() << endl;
		}
		for (int i = 1; i < nr_linii; i++)
		{
			for (int j = 0; j < nr_coloane; j++)
			{
				fisier << matrice[i][j] << " ";
			}
		}
		strcat(nume_fisier, ".bin");
		f = fopen(nume_fisier, "wb+");
		for (int i = 0; i < nr_linii; i++)
		{
			for (int j = 0; j < nr_coloane; j++)
			{
				fwrite(matrice[i][j].c_str(), sizeof(matrice[i][j]), 1, f);
			}
		}
		fclose(f);
	}
	friend class coloana_tabel;
	friend class tabela;
	friend class identificator_comanda;
};

chei_primare C;
chei_primare_compuse CP;

class baza_de_date
{
	string* v;
	int dim = 0;
	int* nr_linii;
	int* nr_coloane;
public:

	void initializare()
	{
		v = new string[10];
		nr_linii = new int[10];
		nr_coloane = new int[10];
		int numar_cheie_primara1;
		int numar_cheie_primara2;
		char* nume_tabela;
		fstream fisier_date("Stocare_date", ios::in | ios::out);
<<<<<<< HEAD
		fisier_date >> validare;
		if (validare == 1)
		{
			fisier_date >> nr_display;
			fisier_date >> nr_select;
			int i = 0;
			while (!fisier_date.eof())
			{
				fisier_date >> v[i];
				t[i + 1].set_nume_tabela(v[i].c_str());
				fisier_date >> nr_linii[i];
				t[i + 1].set_numar_date(nr_linii[i]);
				fisier_date >> nr_coloane[i];
				t[i + 1].set_numar_coloane(nr_coloane[i]);
				fisier_date >> numar_cheie_primara1;
				fisier_date >> numar_cheie_primara2;
				vector<int> chei;
				chei.push_back(numar_cheie_primara1);
				chei.push_back(numar_cheie_primara2);
				if (numar_cheie_primara2 != -1)
				{
					CP.mp.insert((make_pair(t[i + 1].nume_tabela, chei)));
				}
				else
				{
					C.mp.insert(make_pair(t[i + 1].nume_tabela, numar_cheie_primara1));
				}
				char* s = new char[4];
				nume_tabela = new char[v[i].length() + 1];
				strcpy(nume_tabela, v[i].c_str());
				fstream f;
				f.open(nume_tabela, ios::in);
				for (int l = 0; l < nr_coloane[i]; l++)
				{
					f >> s;
					t[i + 1].coloane[l].set_nume_coloana(s);
					t[i + 1].d[0][l + 1].set_date_introduse(s);
					f >> s;
					t[i + 1].coloane[l].set_tip_coloana(s);
					f >> s;
					t[i + 1].coloane[l].set_dim_tip_coloana(s);
					f >> s;
					t[i + 1].coloane[l].set_valoare_implicita(s);
				}
				for (int j = 0; j < nr_linii[i]; j++)
				{
					for (int k = 1; k <= nr_coloane[i]; k++)
					{
						f >> s;
						t[i + 1].d[j + 1][k].set_date_introduse(s);
					}
=======
		fisier_date >> nr_display;
		//cout << " nr_display: " << nr_display << endl;
		fisier_date >> nr_select;
		//cout << " nr_select: " << nr_select << endl;
		int i = 0;
		while (!fisier_date.eof())
		{
			//cout << " A intrat in while!" << endl;
			fisier_date >> v[i];
			//cout << " v[i]: " << v[i] << endl;
			t[i + 1].set_nume_tabela(v[i].c_str());
			fisier_date >> nr_linii[i];
			//cout << " nr_linii[i]: " << nr_linii[i] << endl;
			t[i + 1].set_numar_date(nr_linii[i]);
			fisier_date >> nr_coloane[i];
			//cout << " nr_coloane[i]: " << nr_coloane[i] << endl;
			t[i + 1].set_numar_coloane(nr_coloane[i]);
			fisier_date >> numar_cheie_primara1;
			fisier_date >> numar_cheie_primara2;
			vector<int> chei;
			chei.push_back(numar_cheie_primara1);
			chei.push_back(numar_cheie_primara2);
			if (numar_cheie_primara2 != -1)
			{
				CP.mp.insert((make_pair(t[i + 1].nume_tabela, chei)));
			}
			else
			{
				C.mp.insert(make_pair(t[i + 1].nume_tabela, numar_cheie_primara1));
			}
			char* s = new char[4];
			nume_tabela = new char[v[i].length() + 1];
			strcpy(nume_tabela, v[i].c_str());
			//cout << " nume_tabela: " << nume_tabela;
			fstream f;
			f.open(nume_tabela, ios::in);
			for (int l = 0; l < nr_coloane[i]; l++)
			{
				f >> s;
				t[i + 1].coloane[l].set_nume_coloana(s);
				t[i + 1].d[0][l + 1].set_date_introduse(s);
				f >> s;
				t[i + 1].coloane[l].set_tip_coloana(s);
				f >> s;
				t[i + 1].coloane[l].set_dim_tip_coloana(s);
				f >> s;
				t[i + 1].coloane[l].set_valoare_implicita(s);
			}
			for (int j = 0; j < nr_linii[i]; j++)
			{
				//cout << " for2:" << endl;
				for (int k = 1; k <= nr_coloane[i]; k++)
				{
					//cout << " for3: " << endl;
					f >> s;
					//cout << " s: " << s <<endl;
					t[i + 1].d[j + 1][k].set_date_introduse(s);
					cout << " t[" << i << "].d[" << j + 1 << "][" << k << "].get_date_introduse(): " << t[i + 1].d[j + 1][k].get_date_introduse() << endl;
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
				}
				i++;
				numar_tabele++;
			}
			dim = i;
		}
<<<<<<< HEAD
=======
		//cout << " i: " << i << endl;
		dim = i;
		//cout << " dim: " << dim << endl;
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
	}

	int get_dim()
	{
		return dim;
	}

	string* get_v()
	{
		return v;
	}

	friend class date;
	friend class coloana_tabel;
	friend class tabela;
	friend class identificator_comanda;
	friend class meniu;

};

class documentatie
{
public:
	virtual void afiseaza() = 0;
};

class documentatie_CRUD : documentatie
{
public:
	// insert, select, update, delete
	void afiseaza() override
	{
		cout << " INSERT INTO nume_tabela VALUES(...); valorile sunt separate prin, si au numarul si ordinea exacta ca definitia tabelului" << endl;
		cout << " SELECT (cel_putin_o_coloana, ...) | ALL FROM nume_tabela [WHERE nume_coloana = valoare] - clauza WHERE este optionala" << endl;
		cout << " UPDATE nume_tabela SET nume_coloana = valoare WHERE nume_coloana = valoare (coloana SET poate fi diferita de cea WHERE; UPDATE merge doar pentru o coloana)" << endl;
		cout << " DELETE FROM nume_tabela WHERE nume_coloana = valoare (DELETE permite doar o coloana în clauza WHERE)" << endl;
	}
};

class documentatie_gestiuneBD : documentatie
{
public:
	// create, drop, display
	void afiseaza() override
	{
		cout << " CREATE TABLE nume_tabel [IF NOT EXISTS] ((nume_coloana_1, tip, dimensiune, valoare_implicita), (nume_coloana_2, tip, dimensiune, valoare_implicita), ...) - comanda ar trebui sa primeasca cel putin 1 coloana" << endl;
		cout << " DROP TABLE table_name" << endl;
		cout << " DISPLAY TABLE table_name" << endl;
	}
};

class identificator_comanda
{
	vector<string> nume_tabele;
	int aux;
	tabela* copie_tabele = nullptr;
	int dimensiune = 0;
public:

	identificator_comanda()
	{
	}

	identificator_comanda(int aux, int dimensiune)
	{
		this->aux = aux;
		this->dimensiune = dimensiune;
	}

	identificator_comanda(int aux, int dimensiune, tabela* copie_tabela)
	{
		this->aux = aux;
		if (dimensiune > 0)
		{
			this->dimensiune = dimensiune;
			this->copie_tabele = new tabela[dimensiune];
			for (int i = 0; i < dimensiune; i++)
			{
				this->copie_tabele[i] = copie_tabele[i];
			}
		}
	}

	void identifica_comanda(char s[])
	{
		char separator[5] = " ,()";
		char comanda[20];
		char nume_tabela[20];
		int numar_coloane;
		int raspuns;
		gestionare_fisiere G;
		gestionare_fisiere_binare F;
		baza_de_date B;
		documentatie_CRUD DC;
		documentatie_gestiuneBD DG;
		string** matrice = new string * [10];
		for (int i = 0; i < 10; i++)
			matrice[i] = new string[10];
		string** matrice1 = new string * [10];
		for (int i = 0; i < 10; i++)
			matrice1[i] = new string[10];
		int X = 0, Y = 0;
		int nr_id = 0;
		char* verifica = strtok(s, separator);
		if (verifica)
		{
			char* verifica1;
			verifica1 = new char[strlen(verifica) + 1];
			strcpy(verifica1, verifica);
			strcpy(comanda, verifica);
			verifica = strtok(NULL, separator);
			if (verifica)
			{
				strcat(comanda, " ");
				strcat(comanda, verifica);
				strcpy(comanda, uppercase(comanda));
			}
			if (strcmp(comanda, "CREATE TABLE") == 0)
			{
				string* vector_create = new string[100];
				numar_coloane = 0;
				verifica = strtok(NULL, separator);
				if (verifica)
				{
					vector<string>::iterator it = find(nume_tabele.begin(), nume_tabele.end(), verifica);
					if (it != nume_tabele.end()) //daca se gaseste deja in vector
					{
						cout << endl << " EROARE: Tabela exista deja. Incercati sa introduceti alt nume." << endl;
						cout << endl;
						system("pause");
						system("cls");
					}
					else
					{
						t[numar_tabele].set_nume_tabela(verifica);
						nume_tabele.push_back(verifica);
						char* nume_t = new char[strlen(verifica) + 1];
						char* nume_t_map = new char[strlen(verifica) + 1];
						strcpy(nume_t, verifica);
						strcpy(nume_t_map, verifica);
						string nume_t_map_string = nume_t_map;
						verifica = strtok(NULL, separator);
						int k = 0;
						while (verifica)
						{
							t[numar_tabele].coloane[numar_coloane].set_nume_coloana(verifica);
							vector_create[k++] = verifica;
							t[numar_tabele].d[0][numar_coloane + 1].set_date_introduse(verifica);
							verifica = strtok(NULL, separator);
							t[numar_tabele].coloane[numar_coloane].set_tip_coloana(verifica);
							vector_create[k++] = verifica;
							verifica = strtok(NULL, separator);
							t[numar_tabele].coloane[numar_coloane].set_dim_tip_coloana(verifica);
							vector_create[k++] = verifica;
							verifica = strtok(NULL, separator);
							t[numar_tabele].coloane[numar_coloane].set_valoare_implicita(verifica);
							vector_create[k++] = verifica;
							numar_coloane++;
							verifica = strtok(NULL, separator);
						}
						F.create_binar(nume_t, vector_create, k, numar_coloane);
						int ok = 0;
						string cheie;
						vector<int> cheie_compusa;
						cout << " Doriti o cheie primara simpla sau una compusa?" << endl;
						cout << " Apasati 1 pentru simpla" << endl;
<<<<<<< HEAD
						cout << " Apasati 2 pentru compusa" << endl;
						cout << " Raspuns: ";
						int raspuns_cheie;
						cin >> raspuns_cheie;
						int validare_raspuns = 0;
						while (validare_raspuns == 0)
						{
							cout << " Raspuns: ";
							cin >> raspuns_cheie;
							if (raspuns_cheie == 2 || raspuns_cheie == 1)
							{
								validare_raspuns = 1;
							}
						}
						cout << endl;
=======
						cout << " Apasati 2 pentru compusa" << endl << endl << " ";
						int raspuns_cheie;
						cin >> raspuns_cheie;
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
						if (raspuns_cheie == 1)
						{
							while (ok == 0)
							{
								cout << " Introduceti numele coloanei care doriti sa fie cheie primara: " << endl;
								cout << " ";
								cin >> cheie;
								int o = 0;
								while (o < numar_coloane)
								{
									if (t[numar_tabele].coloane[o].get_nume_coloana() == cheie)
									{
										C.mp.insert(make_pair(nume_t_map, o + 1));
										ok = 1;
									}
									o++;
								}
								if (ok == 0)
								{
									cout << " EROARE: Coloana " << cheie << " nu exista." << endl << endl;
									cout << " Doriti sa consultati instructiunile?" << endl;
<<<<<<< HEAD
									cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl;
									cout << " Raspuns: ";
									cin >> raspuns;
									cout << endl;
=======
									cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl << " ";
									cin >> raspuns;
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
									if (raspuns == 1)
									{
										DG.afiseaza();
									}
								}
							}
						}
						else if (raspuns_cheie == 2)
						{
							int ok1 = 0;
							int ok2 = 0;
<<<<<<< HEAD
							while (ok1 == 0 || ok2 == 0)
							{
								if (ok1 == 0)
								{
									cout << " Introduceti numele primei coloane care doriti sa fie cheie primara: " << endl;
									cout << " ";
									cin >> cheie;
									int o = 0;
									while (o < numar_coloane)
									{
										if (t[numar_tabele].coloane[o].get_nume_coloana() == cheie)
										{
											cheie_compusa.push_back(o + 1);
											ok1 = 1;
										}
										o++;
									}
								}
								if (ok2 == 0)
								{
									cout << " Introduceti numele celei de-a doua coloane care doriti sa fie cheie primara: " << endl;
									cout << " ";
									cin >> cheie;
									int o = 0;
									while (o < numar_coloane)
									{
										if (t[numar_tabele].coloane[o].get_nume_coloana() == cheie)
										{
											cheie_compusa.push_back(o + 1);
											ok2 = 1;
										}
										o++;
									}
=======
							while (ok1 == 0 && ok2 == 0)
							{
								cout << " Introduceti numele primei coloane care doriti sa fie cheie primara: " << endl;
								cout << " ";
								cin >> cheie;
								int o = 0;
								while (o < numar_coloane)
								{
									if (t[numar_tabele].coloane[o].get_nume_coloana() == cheie)
									{
										cheie_compusa.push_back(o + 1);
										ok1 = 1;
									}
									o++;
								}
								cout << " Introduceti numele celei de-a doua coloane care doriti sa fie cheie primara: " << endl;
								cout << " ";
								cin >> cheie;
								o = 0;
								while (o < numar_coloane)
								{
									if (t[numar_tabele].coloane[o].get_nume_coloana() == cheie)
									{
										cheie_compusa.push_back(o + 1);
										ok2 = 1;
									}
									o++;
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
								}
								if (ok1 == 0 && ok2 == 1)
								{
									cout << " EROARE: Prima coloana introdusa nu exista." << endl << endl;
									cout << " Doriti sa consultati instructiunile?" << endl;
<<<<<<< HEAD
									cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl;
									cout << " Raspuns: ";
									cin >> raspuns;
									cout << endl;
=======
									cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl << " ";
									cin >> raspuns;
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
									if (raspuns == 1)
									{
										DG.afiseaza();
									}
								}
								else if (ok1 == 1 && ok2 == 0)
								{
									cout << " EROARE: A doua coloana introdusa nu exista." << endl << endl;
									cout << " Doriti sa consultati instructiunile?" << endl;
<<<<<<< HEAD
									cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl;
									cout << " Raspuns: ";
									cin >> raspuns;
									cout << endl;
									if (raspuns == 1)
									{
										DG.afiseaza();
									}
=======
									cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl << " ";
									//cin >> raspuns;
									/*if (raspuns == 1)
									{
										DG.afiseaza();
									}*/
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
								}
								else if (ok1 == 1 && ok2 == 1)
								{
									CP.mp.insert(make_pair(nume_t_map_string, cheie_compusa));
								}
							}
						}
						cout << endl << " Tabela a fost creata." << endl;
						cout << endl;
						system("pause");
						system("cls");
						t[numar_tabele].set_id_tabela(numar_tabele);
						t[numar_tabele].set_numar_coloane(numar_coloane);
						numar_tabele++;
					}
				}
				else
				{
					cout << " EROARE: Introduceti numele tabelei." << endl;
					cout << " Doriti sa consultati instructiunile?" << endl;
<<<<<<< HEAD
					cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl;
					cout << " Raspuns: ";
					cin >> raspuns;
					cout << endl;
=======
					cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl << " ";
					cin >> raspuns;
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
					if (raspuns == 1)
					{
						DG.afiseaza();
					}
					system("pause");
					system("cls");
				}
				delete[] vector_create;
			}
			else if (strcmp(comanda, "DISPLAY TABLE") == 0)
			{
				verifica = strtok(NULL, separator);
				int ok = 0;
				if (verifica)
				{
					vector<string>::iterator it = find(nume_tabele.begin(), nume_tabele.end(), verifica);
					if (it != nume_tabele.end() || ok == 1) //daca se gaseste deja in vector
					{
						for (int i = 1; i <= numar_tabele; i++)
						{
							if (strcmp(t[i].nume_tabela, verifica) == 0)
							{
								t[i].afisare_tabela(t[i].numar_coloane);
								nr_display++;
								G.set_nr_display(nr_display);
								G.display(i);
							}
						}
					}
					else
					{
						cout << " EROARE: Tabela nu exista." << endl;
						cout << endl;
						cout << " Doriti sa consultati instructiunile?" << endl;
<<<<<<< HEAD
						cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl;
						cout << " Raspuns: ";
						cin >> raspuns;
						cout << endl;
=======
						cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl << " ";
						cin >> raspuns;
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
						if (raspuns == 1)
						{
							DG.afiseaza();
						}
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
								F.drop_binar(verifica);
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
						cout << " Doriti sa consultati instructiunile?" << endl;
<<<<<<< HEAD
						cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl;
						cout << " Raspuns: ";
						cin >> raspuns;
						cout << endl;
=======
						cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl << " ";
						cin >> raspuns;
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
						if (raspuns == 1)
						{
							DG.afiseaza();
						}
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
					vector<string> v;
					map<string, string> mpc;
					string* insert = new string[100];
					int y = 0;
					char* nume_tabela_binar = new char[strlen(verifica) + 1];
					char* nume_tabela_pk = new char[strlen(verifica) + 1];
					strcpy(nume_tabela_binar, verifica);
					strcpy(nume_tabela_pk, verifica);
					vector<string>::iterator it = find(nume_tabele.begin(), nume_tabele.end(), verifica);
					if (it != nume_tabele.end()) //daca se gaseste in vector
					{
						aux = distance(nume_tabele.begin(), it);
						verifica = strtok(NULL, separator);
						if (verifica)
						{
							if (strcmp(uppercase(verifica), "VALUES") == 0)
							{
<<<<<<< HEAD
								string cheie1 = "Nimic";
								string cheie2;
=======
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
								int ok = -1;
								int bec = 1;
								int m = 1;

								verifica = strtok(NULL, separator);
<<<<<<< HEAD
								int ok1 = 0, ok2 = 0;
								while (verifica && m <= t[aux + 1].numar_coloane && bec == 1)
=======
								while (verifica && m <= t[aux + 1].numar_coloane && bec == 1)
								{
									if (t[aux + 1].numar_date >= 1)
									{
										v = C.initializare_vector_stl(nume_tabela_pk);
										mpc = CP.initializare_map_stl(nume_tabela_pk);
										for (map<string, int>::iterator it = C.mp.begin(); it != C.mp.end(); it++)
										{
											if (it->first == t[aux + 1].nume_tabela)
											{
												if (it->second == m)
												{
													ok = 1;
													for (int L = 0; L < v.size(); L++)
													{
														if (v[L] == verifica)
														{
															ok = 0;
															bec = 0;
														}
													}
													if (ok == 1)
													{
														t[aux + 1].d[t[aux + 1].numar_date + 1][m].set_date_introduse(verifica);
														C.initializare_fisier(nume_tabela_binar, verifica);
														insert[y++] = t[aux + 1].d[t[aux + 1].numar_date + 1][m].get_date_introduse();
													}
												}
												else
												{
													ok = 1;
													t[aux + 1].d[t[aux + 1].numar_date + 1][m].set_date_introduse(verifica);
													insert[y++] = t[aux + 1].d[t[aux + 1].numar_date + 1][m].get_date_introduse();
												}
											}
											else
											{
												int ok1 = 0, ok2 = 0;

											}
										}
									}
									else if (t[aux + 1].numar_date < 1)
									{
										for (map<string, int>::iterator it = C.mp.begin(); it != C.mp.end(); it++)
										{
											if (it->first == t[aux + 1].nume_tabela)
											{
												if (it->second == m)
												{
													C.initializare_fisier(nume_tabela_binar, verifica);
													t[aux + 1].d[t[aux + 1].numar_date + 1][m].set_date_introduse(verifica);
													insert[y++] = t[aux + 1].d[t[aux + 1].numar_date + 1][m].get_date_introduse();
												}
												else
												{
													t[aux + 1].d[t[aux + 1].numar_date + 1][m].set_date_introduse(verifica);
													insert[y++] = t[aux + 1].d[t[aux + 1].numar_date + 1][m].get_date_introduse();
												}
											}
											ok = 1;
										}
									}
									m++;
									verifica = strtok(NULL, separator);
								}
								if (ok == 1 && bec == 1)
								{
									F.insert_binar(nume_tabela_binar, t[aux + 1].numar_coloane, insert);
									t[aux + 1].numar_date++; //numar insert
									cout << " Inregistrare inserata." << endl;
									cout << endl;
									t[aux + 1].set_numar_date(t[aux + 1].numar_date);
								}
								else
								{
									cout << " EROARE: Valoarea exista deja." << endl;
								}
								system("pause");
								system("cls");
							}
							else
							{
								cout << " EROARE: Nu ati introdus cuvantul cheie VALUES." << endl;
								cout << endl;
								cout << " Doriti sa consultati instructiunile?" << endl;
								cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl << " ";
								cin >> raspuns;
								if (raspuns == 1)
								{
									DC.afiseaza();
								}
								system("pause");
								system("cls");
							}
						}
					}
					else
					{
						cout << " EROARE: Tabela nu exista sau a fost stearsa." << endl;
						cout << endl;
						cout << " Doriti sa consultati instructiunile?" << endl;
						cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl << " ";
						cin >> raspuns;
						if (raspuns == 1)
						{
							DC.afiseaza();
						}
						system("pause");
						system("cls");
					}
				}
			}
			else if (strcmp(comanda, "SELECT ALL") == 0)
			{
				int date_afisate = 0;
				verifica = strtok(NULL, separator);
				if (verifica != NULL && strcmp(uppercase(verifica), "FROM") == 0)
				{
					verifica = strtok(NULL, separator);
					if (verifica)
					{
						vector<string>::iterator it = find(nume_tabele.begin(), nume_tabele.end(), verifica);
						if (it != nume_tabele.end()) //daca se gaseste in vector
						{
							aux = distance(nume_tabele.begin(), it);
							string copie_nume_tabela = verifica;
							verifica = strtok(NULL, separator); //poate am ajuns la where
							if (verifica)
							{
								if (strcmp(uppercase(verifica), "WHERE") == 0)
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
								{
									if (t[aux + 1].numar_date >= 1)
									{
										v = C.initializare_vector_stl(nume_tabela_pk);
										mpc = CP.initializare_map_stl(nume_tabela_pk);
										for (map<string, int>::iterator it = C.mp.begin(); it != C.mp.end(); it++)
										{
											if (it->first == t[aux + 1].nume_tabela)
											{
												if (it->second == m)
												{
													ok = 1;
													for (int L = 0; L < v.size(); L++)
													{
														if (v[L] == verifica)
														{
															ok = 0;
															bec = 0;
														}
													}
													if (ok == 1)
													{
														t[aux + 1].d[t[aux + 1].numar_date + 1][m].set_date_introduse(verifica);
														C.initializare_fisier(nume_tabela_binar, verifica);
														insert[y++] = t[aux + 1].d[t[aux + 1].numar_date + 1][m].get_date_introduse();
													}
												}
												else
												{
													ok = 1;
													t[aux + 1].d[t[aux + 1].numar_date + 1][m].set_date_introduse(verifica);
													insert[y++] = t[aux + 1].d[t[aux + 1].numar_date + 1][m].get_date_introduse();
												}
											}
										}
										for (map<string, vector<int>>::iterator it1 = CP.mp.begin(); it1 != CP.mp.end(); it1++)
										{
											if (it1->first == t[aux + 1].nume_tabela)
											{
												if (it1->second[0] == m || it1->second[1] == m)
												{
													map<string, string>::iterator it_map_1 = mpc.begin();
													int ok3 = 0;
													while (it_map_1 != mpc.end() && ok3 == 0)
													{
														if (it_map_1->first == verifica)
														{
															ok1 = 1;
															ok = 0;
															bec = 0;
														}
														if (it_map_1->second == verifica)
														{
															ok2 = 1;
															ok = 0;
															bec = 0;
														}
														if (ok1 == 0 && ok2 == 0)
														{
															if (cheie1 == "Nimic")
															{
																cheie1 = verifica;
																t[aux + 1].d[t[aux + 1].numar_date + 1][m].set_date_introduse(verifica);
																insert[y++] = t[aux + 1].d[t[aux + 1].numar_date + 1][m].get_date_introduse();
																ok3 = 1;
															}
															else
															{
																cheie2 = verifica;
																t[aux + 1].d[t[aux + 1].numar_date + 1][m].set_date_introduse(verifica);
																insert[y++] = t[aux + 1].d[t[aux + 1].numar_date + 1][m].get_date_introduse();
																ok3 = 1;
															}
														}
														it_map_1++;
													}
												}
												else
												{
													ok = 1;
													cout << verifica << endl;
													t[aux + 1].d[t[aux + 1].numar_date + 1][m].set_date_introduse(verifica);
													insert[y++] = t[aux + 1].d[t[aux + 1].numar_date + 1][m].get_date_introduse();
												}
											}
										}
									}
									else if (t[aux + 1].numar_date < 1)
									{
										for (map<string, int>::iterator it = C.mp.begin(); it != C.mp.end(); it++)
										{
											if (it->first == t[aux + 1].nume_tabela)
											{
												if (it->second == m)
												{
													C.initializare_fisier(nume_tabela_binar, verifica);
													t[aux + 1].d[t[aux + 1].numar_date + 1][m].set_date_introduse(verifica);
													insert[y++] = t[aux + 1].d[t[aux + 1].numar_date + 1][m].get_date_introduse();
												}
												else
												{
													t[aux + 1].d[t[aux + 1].numar_date + 1][m].set_date_introduse(verifica);
													insert[y++] = t[aux + 1].d[t[aux + 1].numar_date + 1][m].get_date_introduse();
												}
											}
										}
										for (map<string, vector<int>>::iterator it1 = CP.mp.begin(); it1 != CP.mp.end(); it1++)
										{
											if (it1->first == t[aux + 1].nume_tabela)
											{
												if (it1->second[0] == m)
												{
													t[aux + 1].d[t[aux + 1].numar_date + 1][m].set_date_introduse(verifica);
													CP.initializare_fisier(nume_tabela_binar, verifica, 1);
													insert[y++] = t[aux + 1].d[t[aux + 1].numar_date + 1][m].get_date_introduse();
												}
												else if (it1->second[1] == m)
												{
													t[aux + 1].d[t[aux + 1].numar_date + 1][m].set_date_introduse(verifica);
													CP.initializare_fisier(nume_tabela_binar, verifica, 2);
													insert[y++] = t[aux + 1].d[t[aux + 1].numar_date + 1][m].get_date_introduse();
												}
												else
												{
													t[aux + 1].d[t[aux + 1].numar_date + 1][m].set_date_introduse(verifica);
													insert[y++] = t[aux + 1].d[t[aux + 1].numar_date + 1][m].get_date_introduse();
												}
											}
										}
										ok = 1;
									}
									m++;
									verifica = strtok(NULL, separator);
								}
								if (ok1 == 0 && ok2 == 0 && cheie1 != "Nimic")
								{
									ok = 1;
									bec = 1;
									CP.initializare_fisier(nume_tabela_binar, cheie1.c_str(), 1);
									CP.initializare_fisier(nume_tabela_binar, cheie2.c_str(), 2);
								}
								if (ok == 1 && bec == 1)
								{
									F.insert_binar(nume_tabela_binar, t[aux + 1].numar_coloane, insert);
									t[aux + 1].numar_date++; //numar insert
									cout << " Inregistrare inserata." << endl;
									cout << endl;
									t[aux + 1].set_numar_date(t[aux + 1].numar_date);
								}
								else
								{
									cout << " EROARE: Valoarea exista deja." << endl << endl;
								}
								system("pause");
								system("cls");
							}
							else
							{
								cout << " EROARE: Nu ati introdus cuvantul cheie VALUES." << endl;
								cout << endl;
								cout << " Doriti sa consultati instructiunile?" << endl;
								cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl;
								cout << " Raspuns: ";
								cin >> raspuns;
								cout << endl;
								if (raspuns == 1)
								{
									DC.afiseaza();
								}
								system("pause");
								system("cls");
							}
						}
					}
					else
					{
						cout << " EROARE: Tabela nu exista sau a fost stearsa." << endl;
						cout << endl;
						cout << " Doriti sa consultati instructiunile?" << endl;
						cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl;
						cout << " Raspuns: ";
						cin >> raspuns;
						cout << endl;
						if (raspuns == 1)
						{
							DC.afiseaza();
						}
						system("pause");
						system("cls");
					}
				}
			}
			else if (strcmp(comanda, "SELECT ALL") == 0)
			{
				int date_afisate = 0;
				verifica = strtok(NULL, separator);
				if (verifica != NULL && strcmp(uppercase(verifica), "FROM") == 0)
				{
					verifica = strtok(NULL, separator);
					if (verifica)
					{
						vector<string>::iterator it = find(nume_tabele.begin(), nume_tabele.end(), verifica);
						if (it != nume_tabele.end()) //daca se gaseste in vector
						{
							aux = distance(nume_tabele.begin(), it);
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
										int i = 1;
										while (i <= t[aux + 1].numar_coloane && strcmp(t[aux + 1].d[0][i].get_date_introduse(), verifica) != 0)
										{
											i++;
										}
										if (i <= t[aux + 1].numar_coloane)
										{
											cout << " ";
											int lungime_nume = (17 * t[aux + 1].numar_coloane - copie_nume_tabela.length()) / 2;
											for (int H = 0; H < lungime_nume; H++)
											{
												cout << "-";
											}
											cout << " " << copie_nume_tabela << " ";
											for (int H = 0; H < lungime_nume; H++)
											{
												cout << "-";
											}
											cout << endl;
											verifica = strtok(NULL, separator); //am luat egal
											if (strcmp(verifica, "=") == 0)
											{
												verifica = strtok(NULL, separator); //luam valoarea pentru care se vor afisa date
												if (verifica)
												{
													int g;
													for (g = 0; g < t[aux + 1].numar_date; g++) //parcurgere pe linii
													{
														int numar_spatii;
														if (strcmp(t[aux + 1].d[g][i].get_date_introduse(), verifica) == 0 || strcmp(t[aux + 1].d[g][i].get_date_introduse(), nume_coloana_conditie) == 0)
														{
															date_afisate++;
															if (g == 0)
															{
																for (int j = 1; j <= t[aux + 1].numar_coloane; j++)
																{
																	cout << " |  " << t[aux + 1].d[g][j].get_date_introduse();
																	matrice[X][Y++] = t[aux + 1].d[g][j].get_date_introduse();
																	numar_spatii = 14 - strlen(t[aux + 1].d[g][j].get_date_introduse());
																	for (int k = 0; k < numar_spatii; k++)
																	{
																		cout << " ";
																	}
																}
																X++;
																cout << "|" << endl << " ";
																for (int d = 1; d <= t[aux + 1].numar_coloane; d++)
																{
																	cout << "------------------";
																}
																cout << endl;
															}
															else if (g == t[aux + 1].numar_date)
															{
																Y = 0;
																for (int j = 1; j <= t[aux + 1].numar_coloane; j++)
																{
																	cout << " |  " << t[aux + 1].d[g][j].get_date_introduse();
																	matrice[X][Y++] = t[aux + 1].d[g][j].get_date_introduse();
																	numar_spatii = 14 - strlen(t[aux + 1].d[g][j].get_date_introduse());
																	for (int k = 0; k < numar_spatii; k++)
																	{
																		cout << " ";
																	}
																}
																X++;
																cout << "|" << endl;
																cout << " ";
															}
															else
															{
																Y = 0;
																for (int j = 1; j <= t[aux + 1].numar_coloane; j++)
																{
																	cout << " |  " << t[aux + 1].d[g][j].get_date_introduse();
																	matrice[X][Y++] = t[aux + 1].d[g][j].get_date_introduse();
																	numar_spatii = 14 - strlen(t[aux + 1].d[g][j].get_date_introduse());
																	for (int k = 0; k < numar_spatii; k++)
																	{
																		cout << " ";
																	}
																}
																X++;
																cout << "|" << endl;
															}
														}
													}
													cout << " ";
													for (int Q = 1; Q <= t[aux + 1].numar_coloane; Q++)
													{
														cout << "------------------";
													}
													cout << endl;
													if (date_afisate == 1)
													{

														cout << endl << " Nu au fost gasite date." << endl;
													}
													cout << endl;
													system("pause");
													system("cls");
													nr_select++;
													G.set_nr_select(nr_select);
													G.select(matrice, X, Y);
												}
											}
										}
										else
										{
											cout << " EROARE: Coloana " << verifica << " nu exista." << endl;
											cout << endl;
											cout << " Doriti sa consultati instructiunile?" << endl;
<<<<<<< HEAD
											cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl;
											cout << " Raspuns: ";
											cin >> raspuns;
											cout << endl;
=======
											cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl << " ";
											cin >> raspuns;
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
											if (raspuns == 1)
											{
												DC.afiseaza();
											}
											system("pause");
											system("cls");
										}
									}
								}
								else
								{
									cout << " EROARE: Nu ati introdus cuvantul cheie WHERE." << endl;
									cout << endl;
									cout << " Doriti sa consultati instructiunile?" << endl;
<<<<<<< HEAD
									cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl;
									cout << " Raspuns: ";
									cin >> raspuns;
									cout << endl;
=======
									cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl << " ";
									cin >> raspuns;
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
									if (raspuns == 1)
									{
										DC.afiseaza();
									}
									system("pause");
									system("cls");
								}
							}
							else
							{
								int i = 1;
								while (i <= numar_tabele && t[i].nume_tabela != copie_nume_tabela)
								{
									i++;
								}
								t[i].afiseaza_date(t[i].numar_coloane);
								cout << endl;
								nr_select++;
								G.set_nr_select(nr_select);
								G.select_all(i);
								cout << endl;
								system("pause");
								system("cls");
							}
						}
						else
						{
							cout << " EROARE: Tabela nu exista sau a fost stearsa." << endl;
							cout << endl;
							cout << " Doriti sa consultati instructiunile?" << endl;
<<<<<<< HEAD
							cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl;
							cout << " Raspuns: ";
							cin >> raspuns;
							cout << endl;
=======
							cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl << " ";
							cin >> raspuns;
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
							if (raspuns == 1)
							{
								DC.afiseaza();
							}
							system("pause");
							system("cls");
						}
					}
				}
				else
				{
					cout << " EROARE: Nu ati introdus cuvantul cheie FROM." << endl;
					cout << endl;
					cout << " Doriti sa consultati instructiunile?" << endl;
<<<<<<< HEAD
					cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl;
					cout << " Raspuns: ";
					cin >> raspuns;
					cout << endl;
=======
					cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl << " ";
					cin >> raspuns;
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
					if (raspuns == 1)
					{
						DC.afiseaza();
					}
					system("pause");
					system("cls");
				}
			}
			else if (strcmp(comanda, "DELETE FROM") == 0)
			{
				int inregistrari_sterse = 0;
				string** matrice_delete = new string * [10];
				for (int i = 0; i < 10; i++)
				{
					matrice_delete[i] = new string[10];
				}
				verifica = strtok(NULL, separator);
				if (verifica)
				{
					string copie_nume_pk = verifica;
					map<string, string> mpc;
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
								int i = 1;
								while (i <= t[aux + 1].numar_coloane && strcmp(verifica, t[aux + 1].coloane[i - 1].nume_coloana) != 0)
								{
									i++;
								}
								if (i <= t[aux + 1].numar_coloane)
								{
									verifica = strtok(NULL, separator);
									if (strcmp(verifica, "=") == 0) //cautam egal
									{
										verifica = strtok(NULL, separator); //luam valoarea dorita
										if (verifica)
										{
											for (int j = 0; j < t[aux + 1].numar_coloane; j++)
											{
												if (strcmp(t[aux + 1].d[0][j + 1].get_date_introduse(), t[aux + 1].coloane[i - 1].nume_coloana) == 0)
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
															inregistrari_sterse++;
														}
													}
													if (strcmp(t[aux + 1].d[t[aux + 1].numar_date][j + 1].get_date_introduse(), verifica) == 0)
													{
														t[aux + 1].numar_date = t[aux + 1].numar_date - 1;
														t[aux + 1].set_numar_date(t[aux + 1].numar_date);
														inregistrari_sterse++;
													}
													for (int b = 0; b <= t[aux + 1].numar_date; b++)
													{
														for (int c = 0; c < t[aux + 1].numar_coloane; c++)
															matrice_delete[b][c] = t[aux + 1].d[b][c + 1].get_date_introduse();
													}
													char* nume_temporar = new char[strlen(t[aux + 1].get_nume_tabela()) + 1];
													strcpy(nume_temporar, t[aux + 1].get_nume_tabela());
													F.delete_binar(nume_temporar, t[aux + 1].numar_date + 1, t[aux + 1].numar_coloane, matrice_delete, aux + 1);
													if (inregistrari_sterse == 1)
													{
														cout << " A fost stearsa o inregistrare." << endl;
														cout << endl;
														system("pause");
														system("cls");
													}
													else if (inregistrari_sterse == 0)
													{
														cout << " Nu a fost stearsa nicio inregistrare." << endl;
														cout << endl;
														system("pause");
														system("cls");
													}
													else
													{
														cout << " Au fost sterse " << inregistrari_sterse << " inregistrari." << endl;
														cout << endl;
														system("pause");
														system("cls");
													}
													int validare_simpla = 0;
													int validare_compusa = 0;
													vector<string> chei_simple;
													for (int i_simpla = 1; i_simpla <= t[aux + 1].get_numar_date(); i_simpla++)
													{
														for (map<string, int>::iterator it_simpla = C.mp.begin(); it_simpla != C.mp.end(); it_simpla++)
														{
															if (it_simpla->first == t[aux + 1].nume_tabela)
															{
																string cheie_pk = t[aux + 1].d[i_simpla][it_simpla->second].get_date_introduse();
																chei_simple.push_back(cheie_pk);
																validare_simpla = 1;
															}
														}
													}
													if (validare_simpla == 1)
													{
														C.stergere_din_fisier(t[aux + 1].nume_tabela, chei_simple);
													}
													map<string, string> chei_compuse;
													for (int i_compusa = 1; i_compusa <= t[aux + 1].get_numar_date(); i_compusa++)
													{
														for (map<string, vector<int>>::iterator it_compusa = CP.mp.begin(); it_compusa != CP.mp.end(); it_compusa++)
														{
															if (it_compusa->first == t[aux + 1].nume_tabela)
															{
																string cheie_pk1 = t[aux + 1].d[i_compusa][it_compusa->second[0]].get_date_introduse();
																string cheie_pk2 = t[aux + 1].d[i_compusa][it_compusa->second[1]].get_date_introduse();
																chei_compuse.insert(make_pair(cheie_pk1, cheie_pk2));
																validare_compusa = 1;
															}
														}
													}
													if (validare_compusa == 1)
													{
														CP.stergere_din_fisier(t[aux + 1].nume_tabela, chei_compuse);
													}
												}
											}
										}
									}
								}
								else
								{
									cout << " EROARE: Coloana " << verifica << " nu exista." << endl;
									cout << endl;
									cout << " Doriti sa consultati instructiunile?" << endl;
<<<<<<< HEAD
									cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl;
									cout << " Raspuns: ";
									cin >> raspuns;
									cout << endl;
=======
									cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl << " ";
									cin >> raspuns;
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
									if (raspuns == 1)
									{
										DC.afiseaza();
									}
									system("pause");
									system("cls");
								}
							}
						}
						else
						{
							cout << " EROARE: Nu ati introdus cuvantul cheie WHERE." << endl;
							cout << endl;
							cout << " Doriti sa consultati instructiunile?" << endl;
<<<<<<< HEAD
							cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl;
							cout << " Raspuns: ";
							cin >> raspuns;
							cout << endl;
=======
							cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl << " ";
							cin >> raspuns;
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
							if (raspuns == 1)
							{
								DC.afiseaza();
							}
							system("pause");
							system("cls");
						}
					}
					else
					{
						cout << " EROARE: Tabela nu exista sau a fost stearsa." << endl;
						cout << endl;
						cout << " Doriti sa consultati instructiunile?" << endl;
<<<<<<< HEAD
						cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl;
						cout << " Raspuns: ";
						cin >> raspuns;
						cout << endl;
=======
						cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl << " ";
						cin >> raspuns;
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
						if (raspuns == 1)
						{
							DC.afiseaza();
						}
						system("pause");
						system("cls");
					}
				}
			}
			else if (strcmp(verifica1, "SELECT") == 0)
			{
				set<string> coloana;
				if (verifica)
				{
					while (verifica != NULL && strcmp(uppercase(verifica), "FROM") != 0)
					{
						coloana.insert(verifica);
						verifica = strtok(NULL, separator);
					}
					verifica = strtok(NULL, separator); //am ajuns la numele tabelei
					vector<string>::iterator it = find(nume_tabele.begin(), nume_tabele.end(), verifica);
					if (it != nume_tabele.end()) //daca se gaseste in vector
					{
						cout << " ";
						int lungime_nume = (18 * coloana.size() - strlen(verifica)) / 2;
						for (int H = 0; H < lungime_nume; H++)
						{
							cout << "-";
						}
						cout << " " << verifica << " ";
						for (int H = 0; H < lungime_nume; H++)
						{
							cout << "-";
						}
						cout << endl;
						aux = distance(nume_tabele.begin(), it);
						verifica = strtok(NULL, separator); //poate am ajuns la where
						if (verifica)
						{
							if (strcmp(uppercase(verifica), "WHERE") == 0)
							{
								//SELECT NUME, SALARIU FROM ANGAJATI WHERE NUME = NICU
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
													X = 0;
													for (int g = 0; g <= t[aux + 1].numar_date; g++) //parcurgere pe linii
													{
														Y = 0;
														if (strcmp(t[aux + 1].d[g][i].get_date_introduse(), verifica) == 0 || strcmp(t[aux + 1].d[g][i].get_date_introduse(), nume_coloana_conditie) == 0)
														{
															for (int j = 1; j <= t[aux + 1].numar_coloane; j++)
															{
																for (set<string>::iterator it = coloana.begin(); it != coloana.end(); it++)
																	if (*it == t[aux + 1].d[0][j].get_date_introduse())
																	{
																		cout << " |  " << t[aux + 1].d[g][j].get_date_introduse();
																		matrice1[X][Y++] = t[aux + 1].d[g][j].get_date_introduse();
																		int numar_spatii = 15 - strlen(t[aux + 1].d[g][j].get_date_introduse());
																		for (int P = 0; P < numar_spatii; P++)
																		{
																			cout << " ";
																		}
																	}
															}
															cout << "|" << endl;
															if (g == 0)
															{
																cout << " ";
																for (int E = 0; E < coloana.size(); E++)
																{
																	cout << "-------------------";
																}
																cout << endl;
															}
															X++;
														}
													}
													cout << " ";
													for (int E = 0; E < coloana.size(); E++)
													{
														cout << "-------------------";
													}
													cout << endl << endl;
													system("pause");
													system("cls");
													nr_select++;
													G.set_nr_select(nr_select);
													G.select(matrice1, X, Y);
												}
											}
										}
									}

								}
							}
							else
							{
								cout << " EROARE: Nu ati introdus cuvantul cheie WHERE." << endl;
								cout << " Doriti sa consultati instructiunile?" << endl;
								cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl;
								cout << " Raspuns: ";
								cin >> raspuns;
								cout << endl;
								if (raspuns == 1)
								{
									DC.afiseaza();
								}
								system("pause");
								system("cls");
							}
						}
						else
						{
							X = 0;
							for (int l = 0; l < t[aux + 1].numar_date + 1; l++)
							{
								Y = 0;
								for (int j = 0; j < t[aux + 1].numar_coloane; j++)
								{
									for (set<string>::iterator it = coloana.begin(); it != coloana.end(); it++)
									{
										if (*it == t[aux + 1].d[0][j + 1].get_date_introduse())
										{
											cout << " |  " << t[aux + 1].d[l][j + 1].get_date_introduse() << " ";
											matrice1[X][Y++] = t[aux + 1].d[l][j + 1].get_date_introduse();
											int numar_spatii = 14 - strlen(t[aux + 1].d[l][j + 1].get_date_introduse());
											for (int P = 0; P < numar_spatii; P++)
											{
												cout << " ";
											}
										}
									}
								}
								cout << "|" << endl;
								if (l == 0)
								{
									cout << " ";
									for (int E = 0; E < coloana.size(); E++)
									{
										cout << "-------------------";
									}
									cout << endl;
								}
								X++;
							}
							cout << " ";
							for (int E = 0; E < coloana.size(); E++)
							{
								cout << "-------------------";
							}
							cout << endl << endl;
							system("pause");
							system("cls");
							nr_select++;
							G.set_nr_select(nr_select);
							G.select(matrice1, X, Y);
						}
					}
				}
			}
			else if (strcmp(verifica1, "UPDATE") == 0)
			{
				if (verifica)
				{
					vector<string> v;
<<<<<<< HEAD
					map<string, string> mpc;
=======
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
					vector<string>::iterator it = find(nume_tabele.begin(), nume_tabele.end(), verifica);
					if (it != nume_tabele.end()) //daca se gaseste in vector
					{
						char* nume_tabela_pk = new char[strlen(verifica) + 1];
						strcpy(nume_tabela_pk, verifica);
						v = C.initializare_vector_stl(nume_tabela_pk);
<<<<<<< HEAD
						mpc = CP.initializare_map_stl(nume_tabela_pk);
=======
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
						aux = distance(nume_tabele.begin(), it);
						int modificam_cheie_simpla = 0;
						int modificam_cheie_compusa1 = 0;
						int modificam_cheie_compusa2 = 0;
						verifica = strtok(NULL, separator);
						string** matrice_update = new string * [10];
						for (int R = 0; R < t[aux + 1].numar_date + 1; R++)
						{
							matrice_update[R] = new string[10];
						}
						if (strcmp(uppercase(verifica), "SET") == 0) //verificam SET
						{
							verifica = strtok(NULL, separator); //luam numele coloanei
							if (verifica)
							{
								int i = 0;
								while (i < t[aux + 1].numar_coloane && strcmp(verifica, t[aux + 1].coloane[i].nume_coloana) != 0)
								{
									i++;
								}
								if (i < t[aux + 1].numar_coloane)
								{
									verifica = strtok(NULL, separator);
									if (verifica)
									{
										if (strcmp(verifica, "=") == 0) //cautam egal
										{
											verifica = strtok(NULL, separator); //luam valoarea dorita
											if (verifica)
											{
												int ok = 1;
												for (int A = 0; A < v.size(); A++)
												{
													if (v[A] == verifica)
													{
														ok = 0;
													}
												}
<<<<<<< HEAD
												for (map<string, string>::iterator it = mpc.begin(); it != mpc.end(); it++)
												{
													if (it->second == verifica || it->first == verifica)
													{
														ok = 0;
													}
												}
=======
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
												if (ok == 1)
												{
													char* valoare_dorita;
													valoare_dorita = new char[strlen(verifica) + 1];
													strcpy(valoare_dorita, verifica);
													for (int j = 0; j < t[aux + 1].numar_coloane; j++)
													{
<<<<<<< HEAD
														if (strcmp(t[aux + 1].d[0][j + 1].get_date_introduse(), t[aux + 1].coloane[i].nume_coloana) == 0)
=======
														if (strcmp(t[aux + 1].d[0][j + 1].get_date_introduse(), t[aux + 1].coloane[i].nume_coloana) == 0) //cautam coloana corespunzatoare pretului
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
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
																			int w = 0;
																			while (w < t[aux + 1].numar_coloane && strcmp(verifica, t[aux + 1].d[0][w + 1].get_date_introduse()) != 0)
<<<<<<< HEAD
																			{
																				w++;
																			}
																			if (w < t[aux + 1].numar_coloane)
																			{
=======
																			{
																				w++;
																			}
																			if (w < t[aux + 1].numar_coloane)
																			{
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
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
<<<<<<< HEAD
																						{
																							cout << " Nu a fost modificata nicio valoare." << endl;
																							system("pause");
																							system("cls");
																						}
																						else if (nr == 1)
																						{
=======
																						{
																							cout << " Nu a fost modificata nicio valoare." << endl;
																							system("pause");
																							system("cls");
																						}
																						else if (nr == 1)
																						{
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
																							for (int U = 0; U < t[aux + 1].numar_date + 1; U++)
																							{
																								for (int P = 0; P < t[aux + 1].numar_coloane; P++)
																								{
																									matrice_update[U][P] = t[aux + 1].d[U][P + 1].get_date_introduse();
																								}
																							}
																							char* nume_t = new char[strlen(t[aux + 1].get_nume_tabela()) + 1];
																							strcpy(nume_t, t[aux + 1].get_nume_tabela());
																							F.update_binar(nume_t, t[aux + 1].numar_date + 1, t[aux + 1].numar_coloane, matrice_update, aux + 1);
																							cout << " A fost modificata o inregistrare." << endl << endl;
																							system("pause");
																							system("cls");
																						}
																						else
																						{
																							for (int U = 0; U < t[aux + 1].numar_date + 1; U++)
																							{
																								for (int P = 0; P < t[aux + 1].numar_coloane; P++)
																								{
																									matrice_update[U][P] = t[aux + 1].d[U][P + 1].get_date_introduse();
																								}
																							}
																							char* nume_t = new char[strlen(t[aux + 1].get_nume_tabela()) + 1];
																							strcpy(nume_t, t[aux + 1].get_nume_tabela());
																							F.update_binar(nume_t, t[aux + 1].numar_date + 1, t[aux + 1].numar_coloane, matrice_update, aux + 1);
																							cout << " Au fost modificate " << nr << " inregistrari." << endl;
																							system("pause");
																							system("cls");
<<<<<<< HEAD
																						}
																						int validare_simpla = 0;
																						int validare_compusa = 0;
																						vector<string> chei_simple_update;
																						for (int i_simpla = 1; i_simpla <= t[aux + 1].get_numar_date(); i_simpla++)
																						{
																							for (map<string, int>::iterator it_simpla = C.mp.begin(); it_simpla != C.mp.end(); it_simpla++)
																							{
																								if (it_simpla->first == t[aux + 1].nume_tabela)
																								{
																									string cheie_pk = t[aux + 1].d[i_simpla][it_simpla->second].get_date_introduse();
																									chei_simple_update.push_back(cheie_pk);
																									validare_simpla = 1;
																								}
																							}
																						}
																						if (validare_simpla == 1)
																						{
																							C.stergere_din_fisier(t[aux + 1].nume_tabela, chei_simple_update);
																						}
																						map<string, string> chei_compuse_update;
																						for (int i_compusa = 1; i_compusa <= t[aux + 1].get_numar_date(); i_compusa++)
																						{
																							for (map<string, vector<int>>::iterator it_compusa = CP.mp.begin(); it_compusa != CP.mp.end(); it_compusa++)
																							{
																								if (it_compusa->first == t[aux + 1].nume_tabela)
																								{
																									string cheie_pk1 = t[aux + 1].d[i_compusa][it_compusa->second[0]].get_date_introduse();
																									string cheie_pk2 = t[aux + 1].d[i_compusa][it_compusa->second[1]].get_date_introduse();
																									chei_compuse_update.insert(make_pair(cheie_pk1, cheie_pk2));
																									validare_compusa = 1;
																								}
																							}
																						}
																						if (validare_compusa == 1)
																						{
																							CP.stergere_din_fisier(t[aux + 1].nume_tabela, chei_compuse_update);
=======
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
																						}
																					}
																				}
																				else
																				{
																					cout << " EROARE: Nu ati introdus '='." << endl;
																					cout << " Doriti sa consultati instructiunile?" << endl;
<<<<<<< HEAD
																					cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl;
																					cout << " Raspuns: ";
																					cin >> raspuns;
																					cout << endl;
=======
																					cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl << " ";
																					cin >> raspuns;
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
																					if (raspuns == 1)
																					{
																						DC.afiseaza();
																					}
																					system("pause");
																					system("cls");
																				}
																			}
																			else
																			{
																				cout << " EROARE: Coloana " << verifica << " nu exista." << endl;
																				cout << " Doriti sa consultati instructiunile?" << endl;
<<<<<<< HEAD
																				cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl;
																				cout << " Raspuns: ";
																				cin >> raspuns;
																				cout << endl;
=======
																				cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl << " ";
																				cin >> raspuns;
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
																				if (raspuns == 1)
																				{
																					DC.afiseaza();
																				}
																				cout << endl;
																				system("pause");
																				system("cls");
																			}
																		}
																	}
																	else
																	{
																		cout << " EROARE: Nu ati introdus cuvantul cheie WHERE." << endl;
																		cout << " Doriti sa consultati instructiunile?" << endl;
<<<<<<< HEAD
																		cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl;
																		cout << " Raspuns: ";
																		cin >> raspuns;
																		cout << endl;
=======
																		cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl << " ";
																		cin >> raspuns;
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
																		if (raspuns == 1)
																		{
																			DC.afiseaza();
																		}
																		system("pause");
																		system("cls");
																	}
																}
															}
														}
													}
												}
												else
												{
<<<<<<< HEAD
													cout << " EROARE: Valoarea exista deja." << endl << endl;
=======
													cout << endl << " Eroare: Valoarea exista deja." << endl << endl;
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
													system("pause");
													system("cls");
												}
											}
										}
										else
										{
											cout << " EROARE: Nu ati introdus '='." << endl;
											cout << " Doriti sa consultati instructiunile?" << endl;
<<<<<<< HEAD
											cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl;
											cout << " Raspuns: ";
											cin >> raspuns;
											cout << endl;
=======
											cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl << " ";
											cin >> raspuns;
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
											if (raspuns == 1)
											{
												DC.afiseaza();
											}
											system("pause");
											system("cls");
										}
									}
								}
								else
								{
									cout << " EROARE: Coloana " << verifica << " nu exista." << endl;
									cout << " Doriti sa consultati instructiunile?" << endl;
<<<<<<< HEAD
									cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl;
									cout << " Raspuns: ";
									cin >> raspuns;
									cout << endl;
=======
									cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl << " ";
									cin >> raspuns;
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
									if (raspuns == 1)
									{
										DC.afiseaza();
									}
									cout << endl;
									system("pause");
									system("cls");
								}
							}
						}
						else
						{
							cout << " EROARE: Nu ati introdus cuvantul cheie 'SET'." << endl;
							cout << " Doriti sa consultati instructiunile?" << endl;
<<<<<<< HEAD
							cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl;
							cout << " Raspuns: ";
							cin >> raspuns;
							cout << endl;
=======
							cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl << " ";
							cin >> raspuns;
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
							if (raspuns == 1)
							{
								DC.afiseaza();
							}
							system("pause");
							system("cls");
						}
						for (int i = 0; i < t[aux + 1].numar_date + 1; i++)
							delete[] matrice_update[i];
						delete[] matrice_update;
					}
					else
					{
						cout << " EROARE: Tabela nu exista." << endl;
						cout << " Doriti sa consultati instructiunile?" << endl;
<<<<<<< HEAD
						cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl;
						cout << " Raspuns: ";
						cin >> raspuns;
						cout << endl;
=======
						cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl << " ";
						cin >> raspuns;
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
						if (raspuns == 1)
						{
							DC.afiseaza();
						}
						system("pause");
						system("cls");
					}
				}
			}
			else
			{
				cout << " EROARE: Comanda nu a fost introdusa corect." << endl;
				cout << " Doriti sa consultati instructiunile?" << endl;
<<<<<<< HEAD
				cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl;
				cout << " Raspuns: ";
				cin >> raspuns;
				cout << endl;
=======
				cout << " Apasati 1 pentru a confirma, altfel apasati orice alta tasta numerica." << endl << " ";
				cin >> raspuns;
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
				if (raspuns == 1)
				{
					DG.afiseaza();
					DC.afiseaza();
				}
				cout << endl;
				system("pause");
				system("cls");
			}
		}
		else
		{
			cout << " EROARE: Nu ati introdus nicio comanda." << endl;
			cout << endl;
			system("pause");
			system("cls");
		}
		for (int i = 0; i < X; i++)
			delete[] matrice[i];
		delete[] matrice;
		for (int i = 0; i < X; i++)
			delete[] matrice1[i];
		delete[] matrice1;
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
	friend class gestionare_fisiere;
	friend class chei_primare;
	friend class raport;
	friend class documentatie_gestiuneBD;
	friend class documentatie_CRUD;
	friend class documentatie;
};

ostream& operator<<(ostream& out, identificator_comanda ic)
{
	for (int i = 0; i < ic.nume_tabele.size(); i++)
	{
		out << ic.nume_tabele[i] << " ";
	}
	out << endl;
	out << ic.aux;
	return out;
}

istream& operator>>(istream& in, identificator_comanda& ic)
{
	in >> ic.aux;
	return in;
}

class raport
{
private:
	list<string> comenzi;
	identificator_comanda a;
public:

	void adauga_comanda(string comanda)
	{
		comenzi.push_back(comanda);
	}

	void afiseaza(vector<string> tabele)
	{
<<<<<<< HEAD
		//ofstream fisier("raport1.csv");
=======
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
		int t;
		cout << endl;
		cout << " Apasati 1 pentru a primi un raport cu numele tuturor tabelelor din baza de date." << endl;
		cout << " Apasati 2 pentru a afisa istoricul comenzilor din sesiunea curenta." << endl;
<<<<<<< HEAD
		cout << " Apasati 3 pentru a afisa numarul total de comenzi din sesiunea curenta." << endl;
		cout << " Apasati orice alta tasta pentru a reveni la meniul principal." << endl;
		cout << " Raspuns: ";
		cin >> t;
		if (t == 1)
		{
			if (tabele.size() != 0)
			{
				cout << endl << " Acestea sunt tabelele utilizate: " << endl << endl;
				for (vector<string>::iterator it = tabele.begin(); it != tabele.end(); it++)
				{
					cout << " " << *it << endl;
					/*fisier << *it <<",";
					fisier << "\n";*/
				}
				/*fisier.close();*/
				cout << endl;
				system("pause");
			}
			else
			{
				cout << endl << " Nu exista tabele." << endl << endl;
				system("pause");
			}
=======
		cout << " Apasati 3 pentru a afisa numarul total de comenzi din sesiunea curenta." << endl << " ";
		cin >> t;
		if (t == 1)
		{
			for (vector<string>::iterator it = tabele.begin(); it != tabele.end(); it++)
				cout << *it << endl;
			system("pause");
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
		}
		else if (t == 2)
		{
			cout << endl;
<<<<<<< HEAD
			if (comenzi.size() == 0)
			{
				cout << " Nu ati introdus nicio comanda. " << endl << endl;
				system("pause");
			}
			else
			{
				for (list<string>::iterator it = comenzi.begin(); it != comenzi.end(); it++)
				{
					cout << " " << *it << endl;
				}
				system("pause");
			}
		}
		else if (t == 3)
		{
			if (comenzi.size() != 0)
			{
				cout << endl << " Numar total de comenzi din sesiunea curenta: " << comenzi.size() << endl << endl;
				system("pause");
			}
			else
			{
				cout << endl << " Nu ati introdus nicio comanda. " << endl << endl;
				system("pause");
			}
=======
			for (list<string>::iterator it = comenzi.begin(); it != comenzi.end(); it++)
			{
				cout << " " << *it << endl;
			}
			system("pause");
		}
		else if (t == 3)
		{
			cout << endl << comenzi.size() << endl;
			system("pause");
		}
		else
		{
			cout << " Nu ati introdus...";
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
		}
	}
};

class meniu
{
	char s[200];
	int z;
	int static numar_comanda;
	identificator_comanda a;
	baza_de_date b;
	raport r;
public:

	meniu()
	{
		this->z = 0;
		strcpy(s, " ");
	}

	void verifica()
	{
<<<<<<< HEAD
		b.initializare();
=======
		//b.initializare();
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
		if (b.get_dim() > 0)
		{
			for (int i = 0; i < b.get_dim(); i++)
			{
				a.nume_tabele.push_back(b.v[i]);
			}
		}
		cout << endl;
		cout << " Doriti sa introduceti o comanda? 1" << endl;
		cout << " Doriti sa primiti un raport? 2" << endl;
		cout << " Pentru a inchide apasati orice alta tasta numerica." << endl;
		cout << " Raspuns: ";
		cin >> z;
		system("cls");
		if (z == 1 || z == 2)
		{
			while (z == 1 || z == 2)
			{
				if (z == 1)
				{
					cout << endl;
<<<<<<< HEAD
					cout << " Introduceti comanda:" << endl;
					cout << " ATENTIE! Comanda trebuie scrisa folosind majuscule." << endl << endl << " ";
=======
					cout << " Introduceti comanda:" << endl << endl << " ";
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
					cin.get();
					cin.getline(s, 200);
					cout << endl;
					string copie = s;
					a.identifica_comanda(s);
					numar_comanda++;
					r.adauga_comanda(copie);
					cout << endl;
				}
				else if (z == 2)
				{
					r.afiseaza(a.nume_tabele);
					system("cls");
					cout << endl;
				}
				cout << " Doriti sa introduceti o comanda noua (1) sau sa afisati un raport (2)?" << endl;
				cout << " Pentru a inchide apasati orice alta tasta numerica." << endl;
				cout << " Raspuns: ";
				cin >> z;
				system("cls");
				cout << endl;
			}
		}
		if (b.get_dim() > 0 || numar_tabele > 1)
		{
<<<<<<< HEAD
			validare = 1;
			fstream fisier_inceput("Stocare_date", ios::out);
			fisier_inceput << validare << endl;
=======
			fstream fisier_inceput("Stocare_date", ios::out);
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
			fisier_inceput << nr_display << " ";
			fisier_inceput << nr_select << " ";
			fisier_inceput << endl;
			map<string, int>::iterator it = C.mp.begin();
			map<string, vector<int>>::iterator it2 = CP.mp.begin();
			int ok;
<<<<<<< HEAD
			for (int i = 0; i < a.nume_tabele.size() - 1; i++)
			{
=======
			cout << " a.nume_tabele.size(): " << a.nume_tabele.size() << endl;
			cout << " prima: " << a.nume_tabele[0] << endl;
			cout << " a doua: " << a.nume_tabele[1] << endl;
			for (int i = 0; i < a.nume_tabele.size() - 1; i++)
			{
				cout << " i: " << i << endl;
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
				ok = 0;
				for (map<string, int>::iterator it3 = C.mp.begin(); it3 != C.mp.end(); it3++)
				{
					if (it3->first == a.nume_tabele[i])
					{
<<<<<<< HEAD
=======
						cout << " nume tabela: " << a.nume_tabele[i] << endl;
						cout << " it3: " << it3->first << endl;
						cout << " 1" << endl;
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
						ok = 1;
					}
				}
				if (ok == 1)
				{
<<<<<<< HEAD
=======
					cout << "A bagat cheie simpla." << endl;
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
					fisier_inceput << t[i + 1].get_nume_tabela() << " ";
					fisier_inceput << t[i + 1].get_numar_date() << " ";
					fisier_inceput << t[i + 1].get_numar_coloane() << " ";
					fisier_inceput << it->second << " ";
					fisier_inceput << "-1" << endl;
					it++;
				}
				else
				{
<<<<<<< HEAD
=======
					cout << "A bagat cheie compusa." << endl;
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
					fisier_inceput << t[i + 1].get_nume_tabela() << " ";
					fisier_inceput << t[i + 1].get_numar_date() << " ";
					fisier_inceput << t[i + 1].get_numar_coloane() << " ";
					fisier_inceput << it2->second[0] << " " << it2->second[1] << endl;
					it2++;
				}
			}
			ok = 0;
			for (map<string, int>::iterator it3 = C.mp.begin(); it3 != C.mp.end(); it3++)
			{
<<<<<<< HEAD
				if (it3->first == a.nume_tabele[a.nume_tabele.size() - 1])
				{
=======
				cout << " for final" << endl;
				if (it3->first == a.nume_tabele[a.nume_tabele.size() - 1])
				{
					cout << " nume tabela: " << a.nume_tabele[a.nume_tabele.size() - 1] << endl;
					cout << " it3: " << it3->first << endl;
					cout << " 2" << endl;
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
					ok = 1;
				}
			}
			if (ok == 1)
			{
<<<<<<< HEAD
=======
				cout << "A bagat cheie simpla." << endl;
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
				fisier_inceput << t[a.nume_tabele.size()].get_nume_tabela() << " ";
				fisier_inceput << t[a.nume_tabele.size()].get_numar_date() << " ";
				fisier_inceput << t[a.nume_tabele.size()].get_numar_coloane() << " ";
				fisier_inceput << it->second << " ";
				fisier_inceput << "-1";
				it++;
			}
			else
			{
<<<<<<< HEAD
=======
				cout << "A bagat cheie compusa." << endl;
>>>>>>> 8d4cec55e7d19d5680c51532b303c61dd5a3002e
				fisier_inceput << t[a.nume_tabele.size()].get_nume_tabela() << " ";
				fisier_inceput << t[a.nume_tabele.size()].get_numar_date() << " ";
				fisier_inceput << t[a.nume_tabele.size()].get_numar_coloane() << " ";
				fisier_inceput << it2->second[0] << " " << it2->second[1];
				it2++;
			}
			fisier_inceput.close();
			fisier_inceput.clear();
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
	friend class baza_de_date;
	friend class raport;
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