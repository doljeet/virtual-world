#include "Antylopa.h"
#include "Swiat.h"

Antylopa::Antylopa(int x, int y): Zwierze('A', 4, 4, x, y)
{
}

void Antylopa::akcja()
{
    zwiekszWiek();
    int move = rand() % 8;
    while (!setPozycja(getX() + ruchy[move][0], getY() + ruchy[move][1], false)) {
        move++;
        move %= 8;
    }
}

bool Antylopa::ucieka()
{
    if (rand() % 2) {
        int move = 0;
        while (!setPozycja(getX() + ruchy[move][0], getY() + ruchy[move][1], true)) {
            move++;
            if (move == 8) {
                swiat->dodajLog(this,"nie udalo sie uciec");
                return false;
            }
        }
        swiat->dodajLog(this, "udalo sie uciec");
        return true;
    }
    return false;
}

Antylopa* Antylopa::dziecko()
{
    return new Antylopa(*this);
}
