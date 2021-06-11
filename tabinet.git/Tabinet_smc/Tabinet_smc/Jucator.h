#pragma once
#include "Carte.h"
#include<iostream>
#include<vector>

class Jucator
{
private:
	const char* nume;

public:
	std::vector<Carte> carti_jucator;
	std::vector<Carte> carti_ridicate;
	int puncte(std::vector<Carte>puncte);
	Jucator();
	Jucator(const char* Nume, std::vector<Carte> Carti_jucator);
	const char* get_nume();
	void set_carti_jucator(std::vector<Carte>);
	void get_carti_jucator();
	void ridica_carte(Carte a, std::vector<Carte>& carti_ridicate);

};

