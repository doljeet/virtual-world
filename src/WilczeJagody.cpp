#include "WilczeJagody.h"
#include "Swiat.h"

WilczeJagody::WilczeJagody(int x, int y) : Roslina('j', 99, x, y)
{
}

void WilczeJagody::kolizja(Organizm* drugi)
{
    string nazwa = typeid(*drugi).name();
    swiat->dodajLog(this, "zatruly "+nazwa.substr(1));
    drugi->zniszcz();
    zniszcz();
}

Organizm* WilczeJagody::dziecko()
{
    return new WilczeJagody(*this);
}