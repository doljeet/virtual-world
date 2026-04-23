#include <iostream>
#include <conio.h>
#include "Swiat.h"
#include "Czlowiek.h"
using namespace std;

enum keys { gora = 72, dol = 80, lewo = 75, prawo = 77, umiejetnosc = ' ', enter = 13, esc = 27};

int main()
{
    srand(time(NULL));
    int szerokosc, wysokosc;
    char key;
    cout<<"Szerokosc planszy: ";
    cin>>szerokosc;
    cout<<"Wysokosc planszy: ";
    cin>>wysokosc;

    Swiat* swiat = Swiat::getInstance(szerokosc, wysokosc);
    swiat->generujOrganizmy();
    swiat->rysujSwiat();

    while (true) {
        Czlowiek* czlowiek = dynamic_cast<Czlowiek*>(swiat->getCzlowiek());
        key = _getch();
        if (czlowiek != nullptr)
            switch (key) {
            case gora:
                if (!czlowiek->setKierunek(0, -1))
                    continue;
                break;
            case dol:
                if (!czlowiek->setKierunek(0, 1))
                    continue;
                break;
            case lewo:
                if (!czlowiek->setKierunek(-1, 0))
                    continue;
                break;
            case prawo:
                if (!czlowiek->setKierunek(1, 0))
                    continue;
                break;
            case umiejetnosc:
                czlowiek->aktywujUmiejetnosc();
                continue;
            case enter:
                break;
            case esc:
                    return 0;
            default:
                continue;
            }
        if(key != enter)
            continue;
        swiat->wykonajTure();
        swiat->rysujSwiat();
    }
}
