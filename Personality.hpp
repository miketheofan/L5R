#ifndef _PERSONALITY_HPP_
#define _PERSONALITY_HPP_

#include <list>
#include <fstream>

#include "Card.hpp"
#include "Follower.hpp"
#include "Item.hpp"

#define maxFollowers 10
#define maxItems 10

class Personality : public BlackCard {

protected:
	int attack;
	int defence;
	int honour;
	bool isDead;
	std::list <Follower *>* followers;
	std::list <Item *>* items;
	int totalBonusPoints = 0;

public:
	Personality(void);
	~Personality(void);
	void setAttack(int);
	int getAttack();
	void setDefence(int);
	int getDefence();
	void setHonour(int);
	int getHonour();
	void setisDead(bool);
	int setisDeadwithLimit(bool,int);
	bool getisDead();
	void attach(Follower*);
	void attach(Item*);
	void detach(Follower*);
	void detach(Item*);
	void tapFollowers(void);
	void reduceDurabilities(void);
	void performSeppuku(void);
	int getFollowers(void);
	int getItems(void);
	int getFollowersKilled(void);
	int getTotalBonus(void);

};

class Attacker : public Personality {

public:
	Attacker(std::string);

};

class Defender : public Personality {

public:
	Defender(std::string);

};

class Champion : public Personality {

public:
	Champion(std::string);

};

class Chancellor : public Personality {

public:
	Chancellor(std::string);

};

class Shogun : public Personality {

public:
	Shogun(std::string);

};

#endif
