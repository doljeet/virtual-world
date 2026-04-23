#pragma once
#include "Zwierze.h"

/** @brief Wolf — strong predator (strength 9, initiative 5). */
class Wilk : public Zwierze
{
public:
    Wilk(int x, int y);
    Wilk* dziecko() override;
};
