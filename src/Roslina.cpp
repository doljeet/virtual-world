#include "Roslina.h"
#include "Swiat.h"

Roslina::Roslina(char symbol, int sila, int x, int y): Organizm(symbol, sila, 0, x, y)
{
}

void Roslina::akcja()
{
	if (rand() % 75 == 0) {
		auto dziecko = dynamic_cast<Roslina*>(this->dziecko());
		int move = rand() % 4;
		while (!dziecko->setPozycja(getX() + ruchy[move % 4][0], getY() + ruchy[move % 4][1], true)) {
			move++;
			if (move > 8) {
				swiat->dodajLog(this, "nie ma miejsca na rozsianie");
				dziecko->zniszcz();
				return;
			}
		}
		swiat->dodajLog(this, "rozsiala sie");
	}
}

void Roslina::kolizja(Organizm* drugi)
{
	if(this==drugi)
		return;
	if (getSila() >= drugi->getSila())
	{
		string nazwa = typeid(*drugi).name();
		swiat->dodajLog(this, "zatrula " + nazwa.substr(1, nazwa.length()));
		drugi->zniszcz();
	}
	else if (getSila() < drugi->getSila())
	{
		string nazwa = typeid(*drugi).name();
		swiat->dodajLog(this, "zostala zniszczona przez " + nazwa.substr(1, nazwa.length()));
		zniszcz();
	}
}
