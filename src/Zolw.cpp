#include "Zolw.h"
#include "Swiat.h"

Zolw::Zolw(int x, int y): Zwierze('Z', 2, 1, x, y)
{
}

void Zolw::akcja()
{
    if (rand() % 100 >= 75)
        Zwierze::akcja();
    else
        zwiekszWiek();
}

void Zolw::kolizja(Organizm* drugi)
{
    if (drugi->getSila() < 5 && typeid(*this) != typeid(*drugi)) {
        string nazwa = typeid(*drugi).name();
        swiat->dodajLog(this, "odparl atak " + nazwa.substr(1, nazwa.length()));
        drugi->cofnijRuch();
    }
    else
        Zwierze::kolizja(drugi);
}

Zolw* Zolw::dziecko()
{
    return new Zolw(*this);
}