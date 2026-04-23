#include "Zwierze.h"
#include "Swiat.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>

#include "Czlowiek.h"
using namespace std;

Zwierze::Zwierze(char symbol, int sila, int inicjatywa, int x, int y) : Organizm(symbol, sila, inicjatywa, x, y)
{

}

void Zwierze::akcja()
{
	zwiekszWiek();
	int move = rand() % 4;
	while (!setPozycja(getX()+ruchy[move][0], getY()+ruchy[move][1], false)) {
		move++;
		move %= 4;
	}
}

void Zwierze::kolizja(Organizm *drugi)
{
	if(this==drugi)
		return;
	if (typeid(*this) == typeid(*drugi)) {
		if(getWiek() < 2 || drugi->getWiek() < 2)
			return;
		swiat->dodajLog(this,"rozmnazanie");
		auto dziecko = dynamic_cast<Zwierze*>(this->dziecko());
		int move = rand() % 4;
		while (!dziecko->setPozycja(getX()+ruchy[move%4][0], getY()+ruchy[move%4][1],true)) {
			move++;
			if (move > 8) {
				swiat->dodajLog(this, "brak miejsca na rozmnozenie");
				dziecko->zniszcz();
				return;
			}
		}
	}
	else if (ucieka() || drugi->ucieka())
	{
		return;
	}
	else if (dynamic_cast<Czlowiek*>(drugi) != nullptr  && dynamic_cast<Czlowiek*>(drugi)->getUmiejetnosc()) {
		int move = rand() % 4;
		while (!this->setPozycja(drugi->getX()+ruchy[move%4][0], this->getY()+ruchy[move%4][1],true)) {
			move++;
			if (move > 8) {
				this->zniszcz();
			}
		}
		string nazwa = typeid(*drugi).name();
		swiat->dodajLog(this, "odsuniety przy pomocy Tarczy");
	}
	else if (getSila() >= drugi->getSila())
	{
		string nazwa = typeid(*drugi).name();
		swiat->dodajLog(this, "zabil "+ nazwa.substr(1, nazwa.length()));
		drugi->zniszcz();
	}
	else if (getSila() < drugi->getSila())
	{
		string nazwa = typeid(*drugi).name();
		swiat->dodajLog(this, "zabity przez " + nazwa.substr(1, nazwa.length()));
		zniszcz();
	}
}