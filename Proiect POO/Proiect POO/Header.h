#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;

class CREATE_TABLE
{
public:
	int nr_coloane;
	string tip;
	int dim_tip;
	string nume_tabel;
	char* nume_coloane = nullptr;
};
 
