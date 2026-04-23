#pragma once
#include "Zwierze.h"

/** @brief Sheep — basic herbivore (strength 4, initiative 4). */
class Owca : public Zwierze
{
public:
    Owca(int x, int y);
    Owca* dziecko() override;
};
