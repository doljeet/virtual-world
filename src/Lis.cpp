#include "Lis.h"
#include "Zwierze.h"
#include "Swiat.h"

Lis::Lis(int x, int y) : Zwierze('L', 3, 7, x, y)
{
}

void Lis::akcja()
{
    zwiekszWiek();
    int move = rand()%4;
    int new_pos_x;
    int new_pos_y;
    while (move <= 8) {
        new_pos_x = getX() + ruchy[move%4][0];
        new_pos_y = getY() + ruchy[move%4][1];
        if (swiat->getOrganizm(new_pos_x, new_pos_y) == nullptr) {
            if (setPozycja(new_pos_x, new_pos_y, false))
                break;
        }
        else if(swiat->getOrganizm(new_pos_x, new_pos_y)->getSila() <= getSila())
            if (setPozycja(new_pos_x, new_pos_y, false))
                break;
        move++;
    }
}

Lis* Lis::dziecko()
{
    return new Lis(*this);
}
