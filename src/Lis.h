#pragma once
#include "Zwierze.h"

/** @brief Fox — avoids stronger opponents; high initiative (strength 3, initiative 7). */
class Lis : public Zwierze
{
public:
    Lis(int x, int y);
    void akcja() override;
    Lis* dziecko() override;
};
