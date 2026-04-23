#pragma once
#include "Zwierze.h"

/** @brief Antelope — can move up to 2 cells; 50% chance to escape from combat. */
class Antylopa : public Zwierze
{
public:
    Antylopa(int x, int y);
    void akcja() override;
    bool ucieka() override;
    Antylopa* dziecko() override;
};
