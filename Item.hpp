#ifndef _ITEM_HPP_
#define _ITEM_HPP_

#include <fstream>

#include "Card.hpp"

class Item : public GreenCard {

protected:
	int durability;

public:
	void setDurability(int);
	int getDurability(void);

};

class Katana : public Item {

public:
	Katana(std::string);

};

class Spear : public Item {

public:
	Spear(std::string);

};

class Bow : public Item {

public:
	Bow(std::string);

};

class Ninjato : public Item {

public:
	Ninjato(std::string);

};

class Wakizashi : public Item {

public:
	Wakizashi(std::string);

};

#endif