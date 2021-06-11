#include "Carte.h"
#include "Tabla.h"
#include<iostream>
#include<string>
int main()
{
	std::wcout << "BINE ATI VENIT LA JOCUL TABINET!"<<std::endl;
	_setmode(_fileno(stdout), _O_U16TEXT);
	Tabla tabinet;
	tabinet.citire_pachet();
	tabinet.amestecare_pachet();
	//tabinet.afisare_pachet();
	tabinet.joc();

}