#pragma once
#include<iostream>
#include"Carte.h"
#include"Jucator.h"
#include<vector>
#include<fstream>

class Tabla
{
private:
	std::vector<Carte> pachet;
	std::vector<Carte> carti_pe_masa;
	int nr_jucatori;
public:
	std::vector<Jucator>aux;
	Tabla();
	void citire_pachet();
	void amestecare_pachet();
	void afisare_pachet();
	void joc();
	void set_nr_jucatori();
};

