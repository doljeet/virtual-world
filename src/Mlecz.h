#pragma once
#include "Roslina.h"

/** @brief Dandelion — spreads 3x faster than regular plants. */
class Mlecz : public Roslina
{
public:
    Mlecz(int x, int y);
    void akcja() override;
    Organizm* dziecko() override;
};
