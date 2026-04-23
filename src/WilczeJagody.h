#pragma once
#include "Roslina.h"

/** @brief Deadly nightshade — kills any animal that steps on it; destroyed afterward. */
class WilczeJagody : public Roslina
{
public:
    WilczeJagody(int x, int y);
    void kolizja(Organizm* drugi) override;
    Organizm* dziecko() override;
};
