#pragma once
#include "Zwierze.h"

/**
 * @brief Player-controlled human organism.
 *
 * The human is the only organism directly controlled by the player.
 * Movement direction is set each turn via setKierunek().
 *
 * Special ability: **Alzur's Shield** — when active, pushes away organisms
 * instead of fighting them. Lasts 5 turns, then requires 5 turns to recharge.
 */
class Czlowiek : public Zwierze
{
private:
	int umiejetnosc; ///< Ability counter: <=0 = active shield, 5 = ready to use
	int dir_x;
	int dir_y;
public:
	Czlowiek(int x, int y);
	void akcja() override;
	void kolizja(Organizm* drugi) override;

	/**
	 * @brief Sets the movement direction for the next turn.
	 * @return False if the move would go out of bounds.
	 */
	bool setKierunek(int dir_x, int dir_y);

	/** @brief Activates Alzur's Shield if it is fully charged. */
	void aktywujUmiejetnosc();

	/** @brief Returns true if the shield is currently active. */
	bool getUmiejetnosc();

	Czlowiek* dziecko() override;
};
