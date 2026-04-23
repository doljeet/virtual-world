#include "Swiat.h"
#include "Organizm.h"
#include "Czlowiek.h"
#include "Wilk.h"
#include "Owca.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"
#include <iostream>
Organizm* Swiat::getOrganizm(int pos_x, int pos_y)
{
    if(pos_x < 0 || pos_x >= szerokosc || pos_y < 0 || pos_y >= wysokosc)
	    return nullptr;
    for (Organizm* organizm : organizmy)
    {
        if (organizm->getX() == pos_x && organizm->getY() == pos_y)
        {
			return organizm;
		}
	}
	return nullptr;
}

void Swiat::dodajLog(Organizm* organizm, string log)
{
    string nazwa = typeid(*organizm).name();
    nazwa = nazwa.substr(nazwa.length() > 9 ? 2 : 1, nazwa.length());
    liczbaLogow++;
	cout << "\033[" << wysokosc + 5 + liczbaLogow << ";0H";
    cout <<  nazwa <<"[S:" << to_string(organizm->getSila()) << "] " << log;
}

void Swiat::czyscLogi()
{
    cout << "\x1B[2J";
	liczbaLogow = 0;
}

Organizm* Swiat::getCzlowiek()
{
    return czlowiek;
}

int Swiat::getSzerokosc()
{
    return szerokosc;
}

int Swiat::getWysokosc()
{
    return wysokosc;
}

void Swiat::dodajOrganizm(Organizm* organizm)
{
    organizmy.push_back(organizm);
}

Swiat::Swiat(int szerokosc, int wysokosc)
{
    this->szerokosc = szerokosc;
    this->wysokosc = wysokosc;
    narysowany = false;
    liczbaLogow = 0;
    tura = 0;
    czlowiek = nullptr;
}

Swiat* Swiat::instance = nullptr;
Swiat* Swiat::getInstance() {
    return instance;
}

Swiat* Swiat::getInstance(int szerokosc, int wysokosc) {
    if (instance == nullptr) {
        instance = new Swiat(szerokosc, wysokosc);
    }
    return instance;
}

void Swiat::generujOrganizmy() {
    czlowiek = new Czlowiek(rand() % szerokosc, rand() % wysokosc);
    new Wilk(rand() % szerokosc, rand() % wysokosc);
    new Owca(rand() % szerokosc, rand() % wysokosc);
    new Wilk(rand() % szerokosc, rand() % wysokosc);
    new Owca(rand() % szerokosc, rand() % wysokosc);
    new Lis(rand() % szerokosc, rand() % wysokosc);
    new Lis(rand() % szerokosc, rand() % wysokosc);
    new Zolw(rand() % szerokosc, rand() % wysokosc);
    new Zolw(rand() % szerokosc, rand() % wysokosc);
    new Antylopa(rand() % szerokosc, rand() % wysokosc);
    new Antylopa(rand() % szerokosc, rand() % wysokosc);
    new Trawa(rand() % szerokosc, rand() % wysokosc);
    new Mlecz(rand() % szerokosc, rand() % wysokosc);
    new Guarana(rand() % szerokosc, rand() % wysokosc);
    new WilczeJagody(rand() % szerokosc, rand() % wysokosc);
    new BarszczSosnowskiego(rand() % szerokosc, rand() % wysokosc);
}

void Swiat::wykonajTure()
{
    czyscLogi();
    tura++;
    organizmy.sort(Organizm::pierwszenstwo);
    for (Organizm* organizm : organizmy)
    {
        if (organizm->getSila() > -1)
            organizm->akcja();
        else
            break;
	}
}

void Swiat::rysujSwiat()
{
    cout << "\033[0;0H";
    for (int i = 0; i < szerokosc + 2; i++)
    {
        cout << "\xDB";
    }
    cout << endl;
    for (int i = 0; i < wysokosc; i++) {
        cout << "\xDB";
        for (int j = 0; j < szerokosc; j++)
        {
            cout << " ";
        }
        cout << "\xDB\n";
    }
    for (int i = 0; i < szerokosc + 2; i++)
    {
        cout << "\xDB";
    }
    cout << endl;
    for (Organizm* organizm : organizmy)
    {
        if(organizm->getSila()>-1)
		    organizm->rysuj();
    }
    cout << "\033["<<wysokosc+3<<";0H";
    cout << "Bartlomiej Chociaj 203683";
    cout << "\033["<<wysokosc+4<<";0H";
    for (int i = 0; i < szerokosc + 2; i++)
    {
        cout << "\xDB";
    }
    cout << "\033["<<wysokosc+5<<";0H";
    cout << "TURA " << tura;
}


