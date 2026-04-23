#include "BarszczSosnowskiego.h"
#include "Swiat.h"
#include "Zwierze.h"

BarszczSosnowskiego::BarszczSosnowskiego(int x, int y) : Roslina('b', 10, x, y)
{
}

void BarszczSosnowskiego::akcja()
{
    for (int i = 0; i < 4; i++) {
        auto drugi = swiat->getOrganizm(getX() + ruchy[i][0], getY() + ruchy[i][1]);
        if (drugi != nullptr) {
            if (dynamic_cast<Zwierze*>(drugi)) {
                string nazwa = typeid(*drugi).name();
                swiat->dodajLog(this, "zatrul " + nazwa.substr(1));
                drugi->zniszcz();
            }
        }
    }
}

void BarszczSosnowskiego::kolizja(Organizm* drugi)
{
    string nazwa = typeid(*drugi).name();
    swiat->dodajLog(this, "zatrul " + nazwa.substr(1));
    drugi->zniszcz();
    zniszcz();
}

Organizm* BarszczSosnowskiego::dziecko()
{
    return new BarszczSosnowskiego(*this);
}