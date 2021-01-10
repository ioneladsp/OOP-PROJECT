#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <ctype.h>
using namespace std;

int nr_display = 0;
int nr_select = 0;

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
		cout << " numar_coloane: " << numar_coloane << endl;
		cout << " nume_tabela: " << nume_tabela << endl;
		int numar_spatii;
		int numar_liniute;
		int l = 1;
		numar_liniute = (20 * numar_coloane - strlen(nume_tabela)) / 2;
		cout << " numar_liniute: " << numar_liniute << endl;
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
	void display(tabela t)
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
		lungime_nume = (54 - strlen(t.get_nume_tabela())) / 2;
		for (int i = 0; i < lungime_nume; i++)
		{
			f << "-";
		}
		f << " ";
		f << t.get_nume_tabela();
		f << " ";
		for (int i = 0; i < lungime_nume; i++)
		{
			f << "-";
		}
		f << endl;
		for (int i = 0; i < t.get_numar_coloane(); i++)
		{
			f << " | " << t.coloane[i].get_nume_coloana();
			lungime_coloana = 13 - strlen(t.coloane[i].get_nume_coloana());
			for (j = 0; j < lungime_coloana; j++)
				f << " ";
			f << "|   ";
			f << t.coloane[i].get_tip_coloana();
			lungime_coloana = 11 - strlen(t.coloane[i].get_tip_coloana());
			for (j = 0; j < lungime_coloana; j++)
				f << " ";
			f << "|  ";
			f << t.coloane[i].get_dim_tip_coloana();
			lungime_coloana = 5 - strlen(t.coloane[i].get_dim_tip_coloana());
			for (j = 0; j < lungime_coloana; j++)
				f << " ";
			f << "|  ";
			f << t.coloane[i].get_valoare_implicita();
			lungime_coloana = 14 - strlen(t.coloane[i].get_valoare_implicita());
			for (j = 0; j < lungime_coloana; j++)
				f << " ";
			f << "|" << endl;
		}
		f << " ";
		int lungime_bara_jos;
		if (strlen(t.nume_tabela) % 2 == 1)
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
	void select_all(tabela t)
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
		numar_liniute = (20 * t.numar_coloane - strlen(t.nume_tabela)) / 2;
		f << " ";
		for (int i = 0; i < numar_liniute; i++)
			f << "-";
		f << t.nume_tabela;
		for (int i = 0; i < numar_liniute; i++)
			f << "-";
		f << endl;
		for (int i = 0; i <= t.numar_date; i++)
		{
			for (int j = 1; j <= t.numar_coloane; j++)
			{
				if (i == 1 && j == 1)
				{
					f << " ";
					while (l <= t.numar_coloane)
					{
						f << "--------------------"; //20
						l++;
					}
					f << endl;
				}
				f << " |  " << t.d[i][j].get_date_introduse();
				numar_spatii = 16 - strlen(t.d[i][j].get_date_introduse());
				for (int k = 0; k < numar_spatii; k++)
				{
					f << " ";
				}
			}
			f << "|" << endl;
		}
		f << " ";
		for (int i = 1; i <= t.numar_coloane; i++)
		{
			f << "--------------------";
		}
		f.close();
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
	void create_binar(char* nume_fisier, string* vector, int dim)
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
		for (int i = 0; i < dim; i++)
		{
			g << vector[i] << " ";
		}
		g.close();
	}
	//void insert_binar(char nume_fisier[10], int dim, string* vector, date m[10][10], int nr_linii)
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
		/*for (int i = 0; i < nr_linii; i++)
		{
			for (int j = 1; j <= dim; j++)
			{
				g << m[i][j] << " ";
			}
			g << endl;
		}*/
		g.close();
	}
	void update_binar(char nume_fisier[10], int nr_linii, int nr_coloane, string** matrice)
	{
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
		strcat(nume_fisier, ".bin");
		remove(nume_fisier);
	}
	void delete_binar(char nume_fisier[10], int nr_linii, int nr_coloane, string** matrice)
	{
		cout << " nr linii:" << nr_linii << endl;
		cout << " nr_coloane:" << nr_coloane << endl;
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

class baza_de_date
{
	string* v;
	int dim = 0;
	int* nr_linii;
	int* nr_coloane;
	tabela* tb;
public:

	void initializare(tabela* tb)
	{
		tb = new tabela[10];
		cout << " A intrat in initializare!" << endl;
		v = new string[10];
		nr_linii = new int[10];
		nr_coloane = new int[10];
		char* nume_tabela;
		fstream fisier_date("Stocare_date.txt", ios::in | ios::out);
		fisier_date >> nr_display;
		cout << " nr_display: " << nr_display << endl;
		fisier_date >> nr_select;
		cout << " nr_select: " << nr_select << endl;
		int i = 0;
		while (!fisier_date.eof())
		{
			cout << " A intrat in while!" << endl;
			fisier_date >> v[i];
			cout << " v[i]: " << v[i] << endl;
			tb[i + 1].set_nume_tabela(v[i].c_str());
			fisier_date >> nr_linii[i];
			cout << " nr_linii[i]: " << nr_linii[i] << endl;
			tb[i + 1].set_numar_date(nr_linii[i]);
			fisier_date >> nr_coloane[i];
			cout << " nr_coloane[i]: " << nr_coloane[i] << endl;
			tb[i + 1].set_numar_coloane(nr_coloane[i]);
			char* s = new char[4];
			nume_tabela = new char[v[i].length() + 1];
			strcpy(nume_tabela, v[i].c_str());
			cout << " nume_tabela: " << nume_tabela;
			fstream f;
			f.open(nume_tabela, ios::in);
			for (int j = 0; j < nr_linii[i]; j++)
			{
				cout << " for2:" << endl;
				for (int k = 1; k <= nr_coloane[i]; k++)
				{
					cout << " for3: " << endl;
					f >> s;
					cout << " s: " << s << endl;
					tb[i + 1].d[j][k].set_date_introduse(s);
					cout << " t[i].d[j][k].get_date_introduse(): " << tb[i + 1].d[j][k].get_date_introduse();
				}
			}
			i++;
			numar_tabele++;
		}
		cout << " i: " << i << endl;
		dim = i;
		cout << " dim: " << dim << endl;
	}

	void set_tabela(tabela* tb)
	{
		this->tb = tb;
	}

	tabela* get_tabela()
	{
		return tb;
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

class identificator_comanda
{
	vector<string> nume_tabele;
	//tabela t[10];
	int aux;
public:

	identificator_comanda()
	{
	}

	identificator_comanda(int aux)
	{
		this->aux = aux;
	}

	/*identificator_comanda(int aux, tabela t[10])
	{
		this->aux = aux;
		for (int i = 0; i < 10; i++)
		{
			this->t[10] = t[10];
		}
	}*/

	void identifica_comanda(char s[], tabela* t)
	{
		char separator[5] = " ,()";
		char comanda[20];
		char nume_tabela[20];
		int numar_coloane;
		gestionare_fisiere G;
		gestionare_fisiere_binare F;
		baza_de_date B;
		string** matrice = new string * [10];
		for (int i = 0; i < 10; i++)
			matrice[i] = new string[10];
		string** matrice1 = new string * [10];
		for (int i = 0; i < 10; i++)
			matrice1[i] = new string[10];
		int X = 0, Y = 0;
		int nr_id = 0;
		char* verifica = strtok(s, separator);
		// comanda
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
						cout << " EROARE: Tabela exista deja. Incercati sa introduceti alt nume." << endl;
						cout << endl;
						system("pause");
						system("cls");
					}
					else
					{
						t[numar_tabele].set_nume_tabela(verifica);
						nume_tabele.push_back(verifica);
						char* nume_t = new char[strlen(verifica) + 1];
						strcpy(nume_t, verifica);
						verifica = strtok(NULL, separator);
						int k = 0;
						while (verifica)
						{
							t[numar_tabele].coloane[numar_coloane].set_nume_coloana(verifica);
							vector_create[k++] = verifica;
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
						F.create_binar(nume_t, vector_create, k);
						cout << " Tabela a fost creata." << endl;
						cout << endl;
						system("pause");
						system("cls");
						t[numar_tabele].set_id_tabela(numar_tabele);
						t[numar_tabele].set_numar_coloane(numar_coloane);
						numar_tabele++; // acest numar tabele nu creste dupa ce am creat primul tabel
					}
				}
				else
				{
					cout << " EROARE: Introduceti numele tabelei." << endl;
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
					/*for (int h = 0; h < B.get_dim(); h++)
						{
							if (B.v[h] == verifica)
								ok = 1;
						}*/
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
								G.display(t[i]);
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
					string* insert = new string[100];
					int y = 0;
					char* nume_tabela_binar = new char[strlen(verifica) + 1];
					strcpy(nume_tabela_binar, verifica);
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
									insert[y++] = t[aux + 1].d[t[aux + 1].numar_date + 1][m].get_date_introduse();
									verifica = strtok(NULL, separator);
									m++;
								}
								cout << " Inregistrare inserata." << endl;
								//F.insert_binar(nume_tabela_binar, t[aux + 1].numar_coloane, insert, t[aux+1].d, t[aux+1].get_numar_date()+1);
								F.insert_binar(nume_tabela_binar, t[aux + 1].numar_coloane, insert);
								cout << endl;
								system("pause");
								system("cls");
								t[aux + 1].numar_date++; //numar insert
								t[aux + 1].set_numar_date(t[aux + 1].numar_date);
							}
							else
							{
								cout << " EROARE: Nu ati introdus cuvantul cheie VALUES." << endl;
								cout << endl;
								system("pause");
								system("cls");
							}
						}
					}
					else
					{
						cout << " EROARE: Tabela nu exista sau a fost stearsa." << endl;
						cout << endl;
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
											int lungime_nume = (54 - copie_nume_tabela.length()) / 2;
											for (int i = 0; i < lungime_nume; i++)
											{
												cout << "-";
											}
											cout << copie_nume_tabela;
											for (int i = 0; i < lungime_nume; i++)
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
													for (g = 0; g < t[aux + 1].numar_date + 1; g++) //parcurgere pe linii
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
																for (int Q = 1; Q <= t[aux + 1].numar_coloane; Q++)
																{
																	cout << "------------------";
																}
																cout << endl;
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
											system("pause");
											system("cls");
										}
									}
								}
								else
								{
									cout << " EROARE: Nu ati introdus cuvantul cheie WHERE." << endl;
									cout << endl;
									system("pause");
									system("cls");
								}
							}
							else
							{
								//int i = 1;
								cout << " numar_tabele: " << numar_tabele << endl;
								cout << " copie_nume_tabela: " << copie_nume_tabela << endl;
								for (int i = 0; i < nume_tabele.size(); i++)
								{
									cout << " for copie" << endl;
									if (nume_tabele[i] == copie_nume_tabela)
									{
										cout << " tabela " << i << ":" << endl;
										t[i + 1].afiseaza_date(t[i + 1].numar_coloane);
										cout << endl;
										nr_select++;
										G.set_nr_select(nr_select);
										G.select_all(t[i]);
									}
								}
								/*while (i <= numar_tabele && t[i].nume_tabela != copie_nume_tabela)
								{
									cout << " t[i].nume_tabela: " << t[i].nume_tabela << endl;
									i++;
								}
								cout << " tabela " << i << ":" << endl;
								t[i].afiseaza_date(t[i].numar_coloane);
								cout << endl;
								nr_select++;
								G.set_nr_select(nr_select);
								G.select_all(t[i]);*/
								system("pause");
								system("cls");
							}
						}
						else
						{
							cout << " EROARE: Tabela nu exista sau a fost stearsa." << endl;
							cout << endl;
							system("pause");
							system("cls");
						}
					}
				}
				else
				{
					cout << " EROARE: Nu ati introdus cuvantul cheie FROM." << endl;
					cout << endl;
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
													F.delete_binar(nume_temporar, t[aux + 1].numar_date + 1, t[aux + 1].numar_coloane, matrice_delete);
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
												}
											}
										}
									}
								}
								else
								{
									cout << " EROARE: Coloana " << verifica << " nu exista." << endl;
									cout << endl;
									system("pause");
									system("cls");
								}
							}
						}
						else
						{
							cout << " EROARE: Nu ati introdus cuvantul cheie WHERE." << endl;
							cout << endl;
							system("pause");
							system("cls");
						}
					}
					else
					{
						cout << " EROARE: Tabela nu exista sau a fost stearsa." << endl;
						cout << endl;
						system("pause");
						system("cls");
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
													X = 0;
													for (int g = 0; g < t[aux + 1].numar_date + 1; g++) //parcurgere pe linii
													{
														Y = 0;
														if (strcmp(t[aux + 1].d[g][i].get_date_introduse(), verifica) == 0 || strcmp(t[aux + 1].d[g][i].get_date_introduse(), nume_coloana_conditie) == 0)
														{
															for (int j = 1; j <= t[aux + 1].numar_coloane; j++)
															{
																for (int k = 0; k < coloana.size(); k++)
																	if (coloana[k] == t[aux + 1].d[0][j].get_date_introduse())
																	{
																		cout << t[aux + 1].d[g][j].get_date_introduse() << " ";
																		matrice1[X][Y++] = t[aux + 1].d[g][j].get_date_introduse();
																	}
															}
															cout << endl;
															X++;
														}
													}
													cout << endl;
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
						}
						else
						{
							X = 0;
							for (int l = 0; l < t[aux + 1].numar_date + 1; l++)
							{
								Y = 0;
								for (int j = 0; j < t[aux + 1].numar_date; j++)
								{
									for (int k = 0; k < coloana.size(); k++)
										if (coloana[k] == t[aux + 1].d[0][j + 1].get_date_introduse())
										{
											cout << t[aux + 1].d[l][j + 1].get_date_introduse() << " ";
											matrice1[X][Y++] = t[aux + 1].d[l][j + 1].get_date_introduse();
										}
								}
								cout << endl;
								X++;
							}
							cout << endl;
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
					vector<string>::iterator it = find(nume_tabele.begin(), nume_tabele.end(), verifica);
					if (it != nume_tabele.end()) //daca se gaseste in vector
					{
						aux = distance(nume_tabele.begin(), it);
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
																		int w = 0;
																		while (w < t[aux + 1].numar_coloane && strcmp(verifica, t[aux + 1].d[0][w + 1].get_date_introduse()) != 0)
																		{
																			w++;
																		}
																		if (w < t[aux + 1].numar_coloane)
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
																						for (int U = 0; U < t[aux + 1].numar_date + 1; U++)
																						{
																							for (int P = 0; P < t[aux + 1].numar_coloane; P++)
																							{
																								matrice_update[U][P] = t[aux + 1].d[U][P + 1].get_date_introduse();
																							}
																						}
																						F.update_binar(t[aux + 1].get_nume_tabela(), t[aux + 1].numar_date + 1, t[aux + 1].numar_coloane, matrice_update);
																						cout << " A fost modificata o inregistrare." << endl;
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
																						F.update_binar(t[aux + 1].get_nume_tabela(), t[aux + 1].numar_date + 1, t[aux + 1].numar_coloane, matrice_update);
																						cout << " Au fost modificate " << nr << " inregistrari." << endl;
																						system("pause");
																						system("cls");
																					}
																				}
																			}
																			else
																			{
																				cout << " EROARE: Nu ati introdus '='." << endl;
																				system("pause");
																				system("cls");
																			}
																		}
																		else
																		{
																			cout << " EROARE: Coloana " << verifica << " nu exista." << endl;
																			cout << endl;
																			system("pause");
																			system("cls");
																		}
																	}
																}
																else
																{
																	cout << " EROARE: Nu ati introdus cuvantul cheie WHERE." << endl;
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
											cout << " EROARE: Nu ati introdus '='." << endl;
											system("pause");
											system("cls");
										}
									}
								}
								else
								{
									cout << " EROARE: Coloana " << verifica << " nu exista." << endl;
									cout << endl;
									system("pause");
									system("cls");
								}
							}
						}
						else
						{
							cout << " EROARE: Nu ati introdus cuvantul cheie 'SET'." << endl;
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

	/*tabela& operator[](int index)
	{
		if (index >= 0 && index < this->aux)
		{
			return t[index];
		}
		throw exception("index invalid");
	}*/

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
};

ostream& operator<<(ostream& out, identificator_comanda ic)
{
	for (int i = 0; i < ic.nume_tabele.size(); i++)
	{
		out << ic.nume_tabele[i] << " ";
	}
	out << endl;
	out << ic.aux;
	/*for (int i = 0; i < numar_tabele; i++)
	{
		out << ic.t[i] << endl;
	}*/
	return out;
}

istream& operator>>(istream& in, identificator_comanda& ic)
{
	in >> ic.aux;
	/*for (int i = 0; i < numar_tabele; i++)
	{
		in >> ic.t[i];
	}*/
	return in;
}

class meniu
{
	char s[200];
	int z;
	int static numar_comanda;
	identificator_comanda a;
	baza_de_date b;
	tabela* t = new tabela[10];
public:
	meniu()
	{
		this->z = 0;
		strcpy(s, " ");
	}

	void verifica()
	{
		b.initializare(t);
		if (b.get_dim() > 0)
		{
			for (int i = 0; i < b.get_dim(); i++)
			{
				cout << " for push back " << endl;
				a.nume_tabele.push_back(b.v[i]);
			}
		}
		cout << " meniu/nume_tabela: " << t[1].get_nume_tabela() << endl;;
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
				a.identifica_comanda(s, t);
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
		fstream fisier_inceput("Stocare_date.txt", ios::in | ios::out | ios::trunc);
		fisier_inceput << nr_display << " ";
		cout << " nr_display: " << nr_display << endl;
		fisier_inceput << nr_select << " ";
		cout << " nr_select: " << nr_select << endl;
		fisier_inceput << endl;
		for (int i = 1; i <= a.nume_tabele.size(); i++)
		{
			cout << " for1" << endl;
			cout << " nume_tabela:" << t[i].get_nume_tabela() << endl;
			fisier_inceput << t[i].get_nume_tabela() << " ";
			fisier_inceput << t[i].get_numar_date() + 1 << " ";
			fisier_inceput << t[i].get_numar_coloane();
		}
		fisier_inceput.close();
		fisier_inceput.clear();
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