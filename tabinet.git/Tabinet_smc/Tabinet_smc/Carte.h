#pragma once
#include <io.h>
#include <fcntl.h>
#include <iostream>
#include<fstream>
#define ROSIE L"\u2665"
#define ROMB L"\u2666"
#define NEAGRA L"\u2660"
#define TREFLA L"\u2663"

class Carte
{
private:
	 std::wstring number;
	std::wstring simbol;
public:
	Carte();
	Carte(std::wstring Number, std::wstring Simbol);
	bool operator ==(Carte a);
	friend std::wostream& operator<<(std::wostream& f1, Carte carte);
	int valoare_carte();
	std::wstring get_number();
	int puncte_carte();
};

