#pragma once
#include "Roslina.h"

/** @brief Guarana — boosts the strength of any animal that eats it by 3. */
class Guarana : public Roslina
{
public:
    Guarana(int x, int y);
    void kolizja(Organizm* drugi) override;
    Organizm* dziecko() override;
};
