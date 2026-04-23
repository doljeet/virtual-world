#pragma once
#include "Organizm.h"

/**
 * @brief Base class for all animals.
 *
 * Provides default random movement (akcja) and combat/reproduction logic (kolizja).
 * Animals of the same species reproduce when they collide (if both are old enough).
 */
class Zwierze : public Organizm
{
public:
	Zwierze(char symbol, int sila, int inicjatywa, int x, int y);
	virtual void akcja() override;
	virtual void kolizja(Organizm* drugi) override;
};
