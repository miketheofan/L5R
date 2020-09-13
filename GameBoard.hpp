#ifndef _GAMEBOARD_HPP_
#define _GAMEBOARD_HPP_

#include "Player.hpp"

class GameBoard {

private:
	std::list<Player*>* players;

public:
	GameBoard(void);
	~GameBoard(void);
	void initializeGameBoard(void);
	void printGameStatistics(void);
	void gameplay(void);
	bool checkWinningCondition(void);
	void addPlayer(std::string);
	void printHand(void);
	void printProvinces(void);
	void printArena(void);
	void printHoldings(void);
	void startingPhase(void);
	void equipPhase(void);
	double percentagePersonalitiesKilled(void);
	double percentageFollowersKilled(void);
	int getTotalBonus(void);
	double percentageArmyInc(void);
	double percentageHoldingInc(void);
	void battlePhase(void);
	void economyPhase(void);
	bool comparePlayerHonor( Player *, Player*);
	void endingPhase(void);
	bool playerExists(std::string);

};

#endif
