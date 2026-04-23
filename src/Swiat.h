#pragma once
#include <list>
#include "Organizm.h"
using namespace std;

/**
 * @brief Singleton class representing the virtual world.
 *
 * Manages all organisms, the game loop, rendering, and the event log.
 * Use Swiat::getInstance() to access the single instance.
 */
class Swiat
{
private:
	list<Organizm*> organizmy;
	int szerokosc;
	int wysokosc;
	Organizm* czlowiek;
	bool narysowany;
	int liczbaLogow;
	int tura;
	void czyscLogi();
	static Swiat* instance;
	Swiat(int szerokosc, int wysokosc);
public:
	/** @brief Returns the existing world instance (must have been created first). */
	static Swiat* getInstance();

	/** @brief Creates and returns the world instance with given dimensions. */
	static Swiat* getInstance(int szerokosc, int wysokosc);

	/** @brief Advances the simulation by one turn. */
	void wykonajTure();

	/** @brief Redraws the entire world in the terminal. */
	void rysujSwiat();

	/** @brief Appends an event message to the turn log. */
	void dodajLog(Organizm* zrodlo, string log);

	int getSzerokosc();
	int getWysokosc();

	/** @brief Populates the world with a default set of organisms at random positions. */
	void generujOrganizmy();

	/** @brief Returns the organism at (pos_x, pos_y), or nullptr if empty. */
	Organizm* getOrganizm(int pos_x, int pos_y);

	/** @brief Registers a new organism in the world's organism list. */
	void dodajOrganizm(Organizm* organizm);

	/** @brief Returns a pointer to the human organism. */
	Organizm* getCzlowiek();
};
