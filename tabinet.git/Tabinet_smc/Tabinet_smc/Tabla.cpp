#include "Tabla.h"
#include<fstream>
#include<string>
#include<algorithm>
#include <random>  
#include <chrono> 
#include"Carte.h"

bool suma_carti(Carte a, std::vector<Carte>vector, Carte& b, Carte& c)
{
	if (vector.size() < 1)
		return false;
	while (vector.size() > 1)
	{
		for (int index = 0; index < vector.size() - 1; index++)
		{
			int suma = vector[index].valoare_carte() + vector.back().valoare_carte();
			if (a.valoare_carte() == suma)
			{
				b = vector[index];
				c = vector.back();
				return true;
			}

		}

		vector.pop_back();
		suma_carti(a, vector, b, c);

	}

}
Tabla::Tabla()
{
}

void Tabla::citire_pachet()
{
	std::wstring auxiliar;

	for (int jdex = 0; jdex < 4; jdex++)
	{
		std::wstring simbol_aux;
		if (jdex == 0)
			simbol_aux = ROSIE;
		else if (jdex == 1)
			simbol_aux = NEAGRA;
		else if (jdex == 2)
			simbol_aux = TREFLA;
		else
			simbol_aux = ROMB;

		for (int index = 1; index <= 13; index++)
		{
			if (index == 1)
			{
				auxiliar = 'A';
			}
			else if (index == 12)
			{
				auxiliar = 'J';
			}
			else if (index == 13)
			{
				auxiliar = 'Q';
			}
			else if (index == 11)
			{
				auxiliar = 'K';
			}
			else
			{

				auxiliar = std::to_wstring(index);
			}
			Carte aux(auxiliar, simbol_aux);

			pachet.push_back(aux);
		}
	}
	
}

void Tabla::amestecare_pachet()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	shuffle(pachet.begin(), pachet.end(), std::default_random_engine(seed));
}

void Tabla::afisare_pachet()
{
	for (auto& element : pachet)
		std::wcout << element;
}

void Tabla::joc()
{
	std::vector<Carte> Carti_jucator;

	std::vector<Jucator> jucatori;

	set_nr_jucatori();

	for (int jdex = 0; jdex < nr_jucatori; jdex++)
	{


		Carti_jucator.clear();

		if (jdex == 0)
		{
			for (int index = 0; index < 4; index++)
			{
				Carti_jucator.push_back(pachet[index]);

			}

			pachet.erase(pachet.begin(), pachet.begin() + 4);

			for (int index = 0; index < 4; index++)
				std::wcout << Carti_jucator[index] << std::endl;

			std::wcout << "doresti sa pastrezi aceste carti?" << std::endl;

			std::string decizie;

			std::cin >> decizie;


			if (decizie == "da")
			{
				for (int index = 0; index < 2; index++)
				{
					Carti_jucator.push_back(pachet[index]);

				}
				pachet.erase(pachet.begin(), pachet.begin() + 2);
			}
			else
			{
				for (int index = 0; index < Carti_jucator.size(); index++)
					carti_pe_masa.push_back(Carti_jucator[index]);

				Carti_jucator.clear();

				for (int index = 0; index < 6; index++)
				{
					Carti_jucator.push_back(pachet[index]);

				}
				pachet.erase(pachet.begin(), pachet.begin() + 6);
			}

			Jucator Andrei("Andrei", Carti_jucator);

			jucatori.push_back(Andrei);
		}
		else
		{
			for (int index = 0; index < 6; index++)
			{
				Carti_jucator.push_back(pachet[index]);

			}

			pachet.erase(pachet.begin(), pachet.begin() + 6);

		}
		if (jdex == 1)
		{
			Jucator Ana("Ana", Carti_jucator);

			jucatori.push_back(Ana);
		}
		else if (jdex == 2)
		{
			Jucator Dragos("Dragos", Carti_jucator);

			jucatori.push_back(Dragos);
		}
		else if (jdex == 3)
		{
			Jucator Denisa("Denisa", Carti_jucator);

			jucatori.push_back(Denisa);
		}





	}

	if (carti_pe_masa.size() == 0)
	{

		for (int index = 0; index < 4; index++)
			carti_pe_masa.push_back(pachet[index]);

		pachet.erase(pachet.begin(), pachet.begin() + 4);
	}






	int one_more = 2;
	while (one_more!=0)
	{
		for (int index = 0; index < jucatori.size(); index++)
		{
			std::wcout << std::endl << "Cartile lui ";

			std::wcout << jucatori[index].get_nume();

			std::wcout << " sunt:" << std::endl;

			jucatori[index].get_carti_jucator();

			std::wcout << std::endl;
		}
		std::wcout << "carti pe masa:";

		for (auto& element : carti_pe_masa)
			std::wcout << element;

		std::wcout << "MARIMEA DECK ULUI ESTE: " << pachet.size();

		Carte a(L"3", ROSIE), b(L"3", ROSIE);

		for (int index = 0; index < jucatori.size(); index++)
		{
			int ok = 0;
			for (int index2 = 0; index2 < jucatori[index].carti_jucator.size(); index2++)
			{
				if (suma_carti(jucatori[index].carti_jucator[index2], carti_pe_masa, a, b) == true)
				{
					jucatori[index].ridica_carte(a, jucatori[index].carti_ridicate);
					jucatori[index].ridica_carte(b, jucatori[index].carti_ridicate);
					jucatori[index].ridica_carte(jucatori[index].carti_jucator[index2], jucatori[index].carti_ridicate);
					for (int i = 0; i < carti_pe_masa.size(); i++)
						if ((carti_pe_masa[i] == a) || (carti_pe_masa[i] == b))
						{
							carti_pe_masa.erase(carti_pe_masa.begin() + i);
							i--;
						}
					jucatori[index].carti_jucator.erase(jucatori[index].carti_jucator.begin() + index2);
					ok = 1;
					break;
				}

			}
			if (ok == 0)
			{
				carti_pe_masa.push_back(jucatori[index].carti_jucator[0]);
				jucatori[index].carti_jucator.erase(jucatori[index].carti_jucator.begin() + 0);
			}
		}
		int nr = 0;
		for (int index = 0; index < jucatori.size(); index++)
			if (jucatori[index].carti_jucator.size() == 0)
			{
				nr++;
			}
		if (nr == jucatori.size())
		{

			if (pachet.size() >= 6 * jucatori.size())

			{
				for (int index = 0; index < jucatori.size(); index++)

				{
					for (int index2 = 0; index2 < 6; index2++)
					{
						jucatori[index].carti_jucator.push_back(pachet[index2]);

					}
					pachet.erase(pachet.begin(), pachet.begin() + 6);
				}
			}

			else
			{
				int carti_distribuite = pachet.size() / jucatori.size();
				for (int index = 0; index < jucatori.size(); index++)
				{
					for (int index2 = 0; index2 < carti_distribuite; index2++)
					{
						jucatori[index].carti_jucator.push_back(pachet[index2]);

					}
					pachet.erase(pachet.begin(), pachet.begin() + carti_distribuite);
				}
			
			}
			
		}
		

		if (pachet.size() == 0)
			one_more--;
	}
	for (int index = 0; index < jucatori.size(); index++)
	{
		std::wcout << std::endl << " carti ridicate de: ";

		std::wcout << jucatori[index].get_nume();

		std::wcout << " sunt:" << std::endl;

		for (int index2 = 0; index2 < jucatori[index].carti_ridicate.size(); index2++)
			std::wcout << jucatori[index].carti_ridicate[index2];
	
		
	}
	std::wcout << "carti pe masa:";

	for (auto& element : carti_pe_masa)
		std::wcout << element;

	std::wcout << "punctaj final"<<std::endl;

	for (int index = 0; index < jucatori.size(); index++)
	{
		std::wcout << jucatori[index].get_nume() << jucatori[index].puncte(jucatori[index].carti_ridicate) << std::endl;
	}
	
}

void Tabla::set_nr_jucatori()
{
	std::wcout << "Cati jucatori doriti sa joace?";
	std::wcin >> nr_jucatori;
}
