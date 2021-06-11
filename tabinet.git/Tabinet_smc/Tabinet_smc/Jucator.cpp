#include "Jucator.h"

int Jucator::puncte(std::vector<Carte> puncte)
{
	int total = 0;
	for (int index = 0; index < puncte.size(); index++)
		total += puncte[index].puncte_carte();

	return total;
}

Jucator::Jucator()
{
}

Jucator::Jucator(const char* Nume, std::vector<Carte> Carti_jucator)
{
	nume = Nume;

	for (int index = 0; index < Carti_jucator.size(); index++)
		carti_jucator.push_back(Carti_jucator[index]);
}



const char* Jucator::get_nume()
{
	return nume;;
}

void Jucator::set_carti_jucator(std::vector<Carte> aux)
{
	for (int index = 0; index < aux.size(); index++)
	{
		carti_jucator.push_back(aux[index]);
	}
}



void Jucator::get_carti_jucator()
{
	for (int index = 0; index < carti_jucator.size(); index++)
	{
		std::wcout << carti_jucator[index];
	}
}

void Jucator::ridica_carte(Carte a, std::vector<Carte>& carti_ridicate)
{
	carti_ridicate.push_back(a);
}

