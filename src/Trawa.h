#pragma once
#include "Roslina.h"

/** @brief Grass — basic plant that spreads to adjacent cells (1/75 chance/turn). */
class Trawa : public Roslina
{
public:
    Trawa(int x, int y);
    Organizm* dziecko() override;
};
