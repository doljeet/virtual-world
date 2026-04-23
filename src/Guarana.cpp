#include "Guarana.h"
#include "Swiat.h"

Guarana::Guarana(int x, int y) : Roslina('g', 0, x, y)
{
}

void Guarana::kolizja(Organizm* drugi)
{
    string nazwa = typeid(*drugi).name();
    swiat->dodajLog(this, "wzmocnila " + nazwa.substr(1));
    drugi->wzmocnij(3);
    zniszcz();
}

Organizm* Guarana::dziecko()
{
    return new Guarana(*this);
}
