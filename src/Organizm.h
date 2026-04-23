#pragma once
#include <string>
#include <iostream>
using namespace std;

class Swiat;

/**
 * @brief Abstract base class for all organisms in the virtual world.
 *
 * Every organism has a position, strength (sila), initiative (inicjatywa),
 * and age (wiek). Derived classes must implement akcja(), kolizja(), and dziecko().
 */
class Organizm
{
	int sila;
	int inicjatywa;
	int wiek;
	char symbol;
	int pos_x;
	int pos_y;
	int prev_pos_x;
	int prev_pos_y;
protected:
	Swiat* swiat;
	/// Relative move offsets: down, right, up, left
	const int ruchy[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
public:
	Organizm(char symbol, int sila, int inicjatywa, int x, int y);
	Organizm(const Organizm& a);

	/** @brief Executed once per turn for this organism. */
	virtual void akcja() = 0;

	/** @brief Called when another organism moves into this organism's cell. */
	virtual void kolizja(Organizm* drugi) = 0;

	/** @brief Creates and returns a new offspring of the same type. */
	virtual Organizm* dziecko() = 0;

	/** @brief Returns true if this organism attempts to flee from combat. */
	virtual bool ucieka();

	/** @brief Renders the organism's symbol at its position in the terminal. */
	void rysuj();

	int getSila();
	int getInicjatywa();
	int getWiek();

	/** @brief Marks the organism as dead (sets position and stats to -1). */
	void zniszcz();

	/** @brief Increases organism's strength by the given value. */
	void wzmocnij(int wartosc);

	void zwiekszWiek(int wartosc = 1);
	int getX();
	int getY();

	/**
	 * @brief Moves the organism to a new position.
	 * @param puste If true, only moves to empty cells.
	 * @return True if the move was successful.
	 */
	bool setPozycja(int pos_x, int pos_y, bool puste);

	/** @brief Reverts the organism to its previous position. */
	void cofnijRuch();

	/**
	 * @brief Comparator for sorting organisms by initiative and age.
	 * @return 1 if a has higher priority than b, 0 otherwise.
	 */
	static int pierwszenstwo(Organizm* a, Organizm* b);
};
