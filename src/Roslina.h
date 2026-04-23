#pragma once
#include "Organizm.h"

/**
 * @brief Base class for all plants.
 *
 * Plants have initiative 0 (act last) and spread to adjacent cells with a 1/75 chance per turn.
 * When an animal walks into a plant, the plant's kolizja() is triggered.
 */
class Roslina : public Organizm
{
public:
	Roslina(char symbol, int sila, int x, int y);
	virtual void akcja() override;
	virtual void kolizja(Organizm* drugi) override;
};
