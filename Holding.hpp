#ifndef _HOLDING_HPP_
#define _HOLDING_HPP_

#include <fstream>

#include "Card.hpp"

class Holding : public BlackCard {

protected:
	int harvest;
	bool upperHolding;
	bool subHolding;

public:
	void setHarvest(int);
	int getHarvest();
	bool check_for_chain();
	virtual void add_upperHolding(Holding*);
	virtual void add_subHolding(Holding*);

};

class Plain : public Holding {

public:
	Plain(std::string);

};

class Mine : public Holding {

public:
	Mine(std::string);
	void add_upperHolding(Holding*);

};

class GoldMine : public Holding {

public:
	GoldMine(std::string);
	void add_upperHolding(Holding*);
	void add_subHolding(Holding*);

};

class CrystalMine : public Holding {

public:
	CrystalMine(std::string);
	void add_subHolding(Holding*);

};

class Farmland : public Holding {

public:
	Farmland(std::string);

};

class GiftsandFavour : public Holding {

public:
	GiftsandFavour(std::string);

};

class Stronghold : public Holding {

private:
	int startingHonour;
	int initialDefense;

public:
	Stronghold(std::string);
	int getStartingHonour(void);
	int getInitialDefense(void);

};

#endif