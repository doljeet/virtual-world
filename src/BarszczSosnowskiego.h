#pragma once
#include "Roslina.h"

/**
 * @brief Hogweed — poisons all adjacent animals each turn;
 * also kills on contact (and destroys itself).
 */
class BarszczSosnowskiego : public Roslina
{
public:
    BarszczSosnowskiego(int x, int y);
    void akcja() override;
    void kolizja(Organizm* drugi) override;
    Organizm* dziecko() override;
};
