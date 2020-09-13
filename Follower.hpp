#ifndef _FOLLOWER_HPP_
#define _FOLLOWER_HPP_

#include <iostream>

#include "Card.hpp"


class Follower : public GreenCard {

private:
	bool isDead;

public:
	void setisDead(bool);
	bool getisDead(void);

};

class Footsoldier : public Follower {

public:
	Footsoldier(std::string);

};

class Archer : public Follower {

public:
	Archer(std::string);

};

class Cavalry : public Follower {

public:
	Cavalry(std::string);

};

class Bushido : public Follower {

public:
	Bushido(std::string);

};

class Sieger : public Follower {

public:
	Sieger(std::string);

};

class Atakebune : public Follower {

public:
	Atakebune(std::string);

};

#endif