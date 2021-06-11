#include "Carte.h"
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include<string>
#include<vector>


Carte::Carte()
{
}

Carte::Carte(std::wstring Number, std::wstring Simbol)
{

	number = Number;
	simbol = Simbol;
}

bool Carte::operator==(Carte a)
{
	if ((number == a.number) && (simbol == a.simbol))return true;
	return false;
}

int Carte::valoare_carte()
{
	char buf[] = "J";
	std::wstring ws(&buf[0], &buf[1]);
	if (number == ws)return 12;
	char buf1[] = "Q";
	std::wstring ws1(&buf1[0], &buf1[1]);
	if (number == ws1)return 13;
	char buf2[] = "K";
	std::wstring ws2(&buf2[0], &buf2[1]);
	if (number == ws2)return 14;
	char buf3[] = "A";
	std::wstring ws3(&buf3[0], &buf3[1]);
	if (number == ws3)return 1;
	for (int index = 2; index <= 10; index++)
	{
		if (number == std::to_wstring(index))
			return index;
	}
}

std::wstring Carte::get_number()
{
	return number;
}

int Carte::puncte_carte()
{
	int puncte = 0;
	char buf[] = "J";
	std::wstring ws(&buf[0], &buf[1]);
	if (number == ws)puncte++;
	char buf1[] = "Q";
	std::wstring ws1(&buf1[0], &buf1[1]);
	if (number == ws1)puncte++;
	char buf2[] = "K";
	std::wstring ws2(&buf2[0], &buf2[1]);
	if (number == ws2)puncte++;
	char buf3[] = "A";
	std::wstring ws3(&buf3[0], &buf3[1]);
	if (number == ws3)puncte++;
	if (number == std::to_wstring(10))puncte++;
	if ((number == std::to_wstring(10)) && (simbol == ROMB))puncte++;
	if (simbol == TREFLA)puncte++;
	if ((simbol == TREFLA) && (number == std::to_wstring(2)))puncte++;
	return puncte;
}



std::wostream& operator<<(std::wostream& f1, Carte carte)
{




	if (carte.number == std::to_wstring(10))
	{
		f1 << std::endl << L"╔" << L"═" << L"═" << L"═" << L"╗" << std::endl;
		f1 << L"║" << carte.number << carte.simbol << L"║" << std::endl;
		f1 << L"╚" << L"═" << L"═" << L"═" << L"╝";
		return f1;
	}
	else
	{
		f1 << std::endl << L"╔" << L"═" << L"═" << L"╗" << std::endl;
		f1 << L"║" << carte.number << carte.simbol << L"║" << std::endl;
		f1 << L"╚" << L"═" L"═" << L"╝";
		return f1;
	}



}