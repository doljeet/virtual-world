#include "Czlowiek.h"
#include "Swiat.h"

Czlowiek::Czlowiek(int x, int y) : Zwierze('C', 5, 4, x, y)
{
	umiejetnosc = 5;
	dir_x = 0;
	dir_y = 0;
}

void Czlowiek::akcja()
{
	zwiekszWiek();
	int predkosc = 1;
	if (umiejetnosc < 5) {
		umiejetnosc++;
	}
	if (umiejetnosc == 0) {
		swiat->dodajLog(this, " koniec Tarczy");
	}
	setPozycja(getX()+dir_x * predkosc,getY()+dir_y * predkosc, false);
	dir_x = 0;
	dir_y = 0;
}

void Czlowiek::kolizja(Organizm *drugi)
{
	if(this==drugi) return;
	if (ucieka() || drugi->ucieka()) return;
	if (getUmiejetnosc()) {
		int move = rand() % 4;
		while (!drugi->setPozycja(drugi->getX()+ruchy[move%4][0], drugi->getY()+ruchy[move%4][1],true)) {
			move++;
			if (move > 8) {
				drugi->zniszcz();
				return;
			}
		}
		string nazwa = typeid(*drugi).name();
		swiat->dodajLog(this, "odsunal "+ nazwa.substr(1, nazwa.length()) + " przy pomocy Tarczy");
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

bool Czlowiek::setKierunek(int dir_x, int dir_y)
{
	if((getX()+dir_x)<0 || (getX()+dir_x)>=swiat->getSzerokosc() || (getY()+dir_y)<0 || (getY()+dir_y)>=swiat->getWysokosc())
		return false;
	this->dir_x = dir_x;
	this->dir_y = dir_y;
	return true;
}

void Czlowiek::aktywujUmiejetnosc()
{
	if (umiejetnosc == 5)
	{
		swiat->dodajLog(this, "Aktywowano Tarcze Alzura");
		umiejetnosc = -5;
	}
}

bool Czlowiek::getUmiejetnosc() {
	return umiejetnosc <= 0;
}


Czlowiek* Czlowiek::dziecko()
{
	return nullptr;
}
