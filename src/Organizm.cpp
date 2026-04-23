#include "Organizm.h"
#include "Swiat.h"

Organizm::Organizm(char symbol, int sila, int inicjatywa, int x, int y) {
	this->swiat = Swiat::getInstance();
	this->symbol = symbol;
	this->sila = sila;
	this->inicjatywa = inicjatywa;
	this->pos_x = x;
	this->pos_y = y;
	this->wiek = 0;
	swiat->dodajOrganizm(this);
}

Organizm::Organizm(const Organizm& a)
{
	this->swiat = a.swiat;
	this->symbol = a.symbol;
	this->sila = a.sila;
	this->inicjatywa = a.inicjatywa;
	this->pos_x = a.pos_x;
	this->pos_y = a.pos_y;
	this->wiek = 0;
	swiat->dodajOrganizm(this);
}



bool Organizm::ucieka()
{
	return false;
}

void Organizm::rysuj()
{
	cout << "\033[" << pos_y + 2 << ";" << pos_x + 2 << "H";
	cout << symbol;
}

int Organizm::getSila()
{
	return sila;
}

int Organizm::getInicjatywa()
{
	return inicjatywa;
}

int Organizm::getWiek()
{
	return wiek;
}

void Organizm::zwiekszWiek(int wartosc)
{
	wiek += wartosc;
}

void Organizm::zniszcz()
{
	pos_x = -1;
	pos_y = -1;
	sila = -1;
	inicjatywa = -1;
}

void Organizm::wzmocnij(int wartosc)
{
	sila += wartosc;
}

int Organizm::getX()
{
	return pos_x;
}

int Organizm::getY()
{
	return pos_y;
}

bool Organizm::setPozycja(int pos_x, int pos_y, bool puste)
{
	if (pos_x < 0 || pos_x >= swiat->getSzerokosc() || pos_y < 0 || pos_y >= swiat->getWysokosc())
		return false;
	if (puste && swiat->getOrganizm(pos_x, pos_y) != nullptr)
		return false;
	prev_pos_x = this->pos_x;
	prev_pos_y = this->pos_y;
	Organizm* drugi = swiat->getOrganizm(pos_x, pos_y);
	this->pos_x = pos_x;
	this->pos_y = pos_y;
	swiat->dodajLog(this, "ruch z (" + to_string(prev_pos_x) + "," + to_string(prev_pos_y) + ") na (" + to_string(pos_x) + "," + to_string(pos_y) + ")");
	if (drugi != nullptr)
	{
		drugi->kolizja(this);
	}
	return true;
}

void Organizm::cofnijRuch()
{
	setPozycja(prev_pos_x, prev_pos_y, false);
}

int Organizm::pierwszenstwo(Organizm* a, Organizm* b)
{
	if(a->inicjatywa > b->inicjatywa) return 1;
	if (a->inicjatywa < b->inicjatywa) return 0;
	if (a->wiek > b->wiek) return 1;
	return 0;
}
