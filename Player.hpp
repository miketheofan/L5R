#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include "DeckBuilder.hpp"


class Player {

private:
	std::string name;
	Stronghold *stronghold;
	DeckBuilder *decks;
	std::list<GreenCard*>* fateDeck;
	std::list<BlackCard*>* dynastyDeck;
	std::list<BlackCard*>* provinces;
	std::list<GreenCard*>* hand;
	std::list<Holding*>* holdings;
	std::list<Personality*>* army;
	std::list<Personality*>* arena;
	int armyAdditions = 0;
	int holdingAdditions = 0;

public:
	Player(std::string);
	virtual ~Player(void);
	void tap(std::string);
	void startingPhase(void);
	void untapEverything(void);
	void drawFateCard(void);
	void revealProvinces(void);
	void printHand(void);
	void printProvinces(void);
	void equipPhase(void);
	void printArmy(void);
	void buyCard(std::string);
	void addEquipment(Personality *, GreenCard *);
	void economyPhase(void);
	void buyProvince(std::string);
	int availableHarvest(void);
	void checkForChain(Holding *);
	std::string getName(void);
	void attack(Player*, std::string);
	void initializeDeck(void);
	int getAttack_forPhase(void);
	int getDefence_forPhase(void);
	void clearArena(void);
	void arenaDead(void);
	void arenaDead(int);
	void checkforHonour(void);
	void tap_arena(void);
	int tapHoldings(void);
	bool checkForLoss(void);
	void printHoldings(void);
	void printArena(void);
	double getPersonalitiesKilled(void);
	double getFollowersKilled(void);
	int getTotalBonus(void);
	int getTotalArmy(void);
	int getTotalHoldings(void);
	int getArmyAdditions(void);
	int getHoldingAdditions(void);
	void discardSurplusFateCards(void);
	void discardFromHand(std::string);
	int getHonour(void);
	bool provinceExists(std::string );

};

#endif