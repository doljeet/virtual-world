#pragma once
#include "Zwierze.h"

/** @brief Turtle — slow (25% move chance), repels attackers weaker than strength 5. */
class Zolw : public Zwierze
{
public:
    Zolw(int x, int y);
    void akcja() override;
    void kolizja(Organizm* drugi) override;
    Zolw* dziecko() override;
};
