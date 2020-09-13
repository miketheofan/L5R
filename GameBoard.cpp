#include "GameBoard.hpp"

GameBoard::GameBoard() {
	//allocating memory for the list that will hold all the players who will play in current game
	this->players = new std::list<Player *>();

	std::cout << "GameBoard created." << std::endl;

}

GameBoard::~GameBoard(void){
	//deleting list
	while(!this->players->empty()) {
        delete this->players->back();
        this->players->pop_back();
    }
    //deleting pointer of list
    delete this->players;
	
}

void GameBoard::initializeGameBoard() {

	int playerCounter= 0;
	std::string inputStr;
	// add same name not allowed
	std::cout << "Insert name of the " << ++playerCounter << "st player:" << std::endl;
	std::getline(std::cin, inputStr, '\n');
	this->addPlayer(inputStr);

	while(inputStr != "end") {

		std::cout << "Insert name of the " << ++playerCounter << "st player (\"end\" to stop adding players):" << std::endl;
		std::getline(std::cin, inputStr, '\n');
		//if user didn't choose option to end input of players , add player to the list 
		if(inputStr != "end")
			this->addPlayer(inputStr);

	}

}

void GameBoard::gameplay(void) {

	std::cout << "\n\n>> Game start << \n\n";
	//run the phases of the game until function that checks if player has won returns true
	do {
		
		this->startingPhase();	
		std::cout << "\n>> End of startingPhase.\n";
		this->equipPhase();
		std::cout << "\n>> End of equipPhase.\n";
		this->battlePhase();
		std::cout << "\n>> End of battlePhase.\n";
		this->economyPhase();
		std::cout << "\n>> End of economyPhase.\n";
		this->endingPhase();

	} while(!this->checkWinningCondition());

}

void GameBoard::addPlayer(std::string s) {

	Player *newPlayer = new Player(s);
	this->players->push_back(newPlayer);

}

bool GameBoard::checkWinningCondition(void) {

	int playersOut = 0;
	std::list<Player*>::iterator playerIterator;
	//checks how many players have lost in current game
	for(playerIterator = this->players->begin() ; playerIterator != this->players->end() ; playerIterator++)
		if((*playerIterator)->checkForLoss())
			playersOut++;
	//if only one player hasn't lost in current game return true , indicating that a player has won
	if(playersOut == (int) this->players->size() - 1)
		return true;
	//otherwise, return false
	return false;

}

void GameBoard::printHand() {

	std::list<Player*>::iterator itP;

	for(itP = this->players->begin(); itP != this->players->end(); itP++)
		(*itP)->printHand();

}

void GameBoard::printProvinces() {

	std::list<Player*>::iterator itP;

	for(itP = this->players->begin(); itP != this->players->end(); itP++)
		(*itP)->printProvinces();

}

void GameBoard::printArena(){

	std::list<Player*>::iterator itP;

	for(itP = this->players->begin(); itP != this->players->end(); itP++)
		(*itP)->printArena();

}

void GameBoard::printHoldings(){

	std::list<Player*>::iterator itP;

	for(itP = this->players->begin(); itP != this->players->end(); itP++)
		(*itP)->printHoldings();

}

void GameBoard::startingPhase(void) {

	std::list<Player*>::iterator itP;
	//call starting phase for every player playing in current game
	for(itP = this->players->begin(); itP != this->players->end(); itP++)
		(*itP)->startingPhase();

}

void GameBoard::equipPhase(void) {

	std::list<Player*>::iterator itP;
	//call equip phase for every player playing in current game
	for(itP = this->players->begin(); itP != this->players->end(); itP++)
		(*itP)->equipPhase();

}

double GameBoard::percentagePersonalitiesKilled(){

	double tmp = 0;

	std::list<Player*>::iterator itP;

	for(itP = this->players->begin(); itP != this->players->end(); itP++)
		tmp += (*itP)->getPersonalitiesKilled();

	return tmp*100;

}

double GameBoard::percentageFollowersKilled(){

	double tmp = 0;

	std:: list<Player*>::iterator itP;

	for(itP = this->players->begin(); itP != this->players->end(); itP++)
		tmp += (*itP)->getFollowersKilled();

	return tmp*100;
}

int GameBoard::getTotalBonus(){

	int tmp = 0;

	std::list<Player*>::iterator itP;

	for(itP = this->players->begin(); itP != this->players->end(); itP++)
		tmp += (*itP)->getTotalBonus();

	return tmp;
}

double GameBoard::percentageArmyInc(){

	double tmp = 0;

	std::list<Player*>::iterator itP;

	for(itP = this->players->begin(); itP != this->players->end(); itP++)
		tmp += ((*itP)->getTotalArmy() - ( (*itP)->getTotalArmy() - (*itP)->getArmyAdditions() )) / ((*itP)->getTotalArmy() - (*itP)->getArmyAdditions());  

	return tmp*100;

}

double GameBoard::percentageHoldingInc(){

	double tmp = 0;

	std::list<Player*>::iterator itP;

	for(itP = this->players->begin(); itP != this->players->end(); itP++)
		tmp += ((*itP)->getTotalHoldings() - ( (*itP)->getTotalHoldings() - (*itP)->getHoldingAdditions() )) / ((*itP)->getTotalHoldings() - (*itP)->getHoldingAdditions());  

	return tmp*100;
}

void GameBoard::battlePhase(){

	std::string playerOpponents[this->players->size()];
	std::string provinceAttack[this->players->size()];

	std::list<BlackCard *>::iterator itB;

	std::list<Player*>::iterator itP1;
	std::list<Player*>::iterator itP2;
	std::string input;
	int tmp = 0;

	for(itP1 = this->players->begin(); itP1 != this->players->end(); itP1++){
	//for every player initialize his deck that he can use to battle
		(*itP1)->initializeDeck();

		do {
			//get input for which player to attack
			do {

				std::cout << "\nPlayer " <<  (*itP1)->getName() << ", type player's name to attack: ";
			
				std::getline(std::cin, input, '\n');
				//he can't attack himself
				if(input == (*itP1)->getName())
					std::cout << "You cannot attack yourself.\n";

			} while(input == (*itP1)->getName());
			//check if player exists in the list
			if(!this->playerExists(input))
				std::cout << "This player does not exist.\n";	

		} while(!this->playerExists(input));

		playerOpponents[tmp] = input;

		for(itP2 = this->players->begin(); itP2 != this->players->end(); itP2++){
		
			if((*itP2)->getName() == input) {
			
				do {

					std::cout << std::endl;
					//print provinces of defender
					(*itP2)->printProvinces();

					std::cout << "Player " <<  (*itP1)->getName() << ", type province name to attack: ";
					std::getline(std::cin, input, '\n');

					provinceAttack[tmp] = input;
					//check if province exists
					if(!(*itP2)->provinceExists(input))
						std::cout << "This province does not exist.\n";

				} while(!(*itP2)->provinceExists(input));

				break;

			}


		}

		tmp++;

	}

	tmp = 0;

	for(itP1 = this->players->begin(); itP1 != this->players->end(); itP1++) {

		for(itP2 = this->players->begin(); itP2 != this->players->end(); itP2++) {

			if((*itP2)->getName() == playerOpponents[tmp]) {
				//attack chosen player , chosen province
				(*itP1)->attack(*itP2, provinceAttack[tmp]);
				tmp++;
				//after the attack check if defender lost and if he did erase him from the list
				if((*itP2)->checkForLoss())
					this->players->erase(itP2);

				break;

			}

		}

	}

}

void GameBoard::economyPhase(void) {

	std::list<Player*>::iterator itP;
	//call economy phase for every player playing in current game
	for(itP = this->players->begin(); itP != this->players->end(); itP++)
		(*itP)->economyPhase();

}

void GameBoard::printGameStatistics(){
	//prints game statistics for current finished game
	std::cout << ">> Game Statistics:\n";
	std::cout << "Percentage of Personalities killed from army:" << this->percentagePersonalitiesKilled() << std::endl
	<< "Percentage of Followers killed from army:" << this->percentageFollowersKilled() << std::endl
	<< "Total bonus points gained from Green card is:" << this->getTotalBonus() << std::endl
	<< "The percentage of army's increacement is:" << this->percentageArmyInc() << std::endl
	<< "The percentage of holding's increacement is:" << this->percentageHoldingInc() << std::endl;

}

bool GameBoard::comparePlayerHonor( Player* p1, Player* p2) {

	return (p1->getHonour() < p2->getHonour());

} 

void GameBoard::endingPhase(void) {

	std::list<Player*>::iterator itP;

	for(itP = this->players->begin(); itP != this->players->end(); itP++) {
		//for every player discard additonal cards
		(*itP)->discardSurplusFateCards();
		//also print hand , privinces , arena cards and holdings
		(*itP)->printHand();
		(*itP)->printProvinces();
		(*itP)->printArena();
		(*itP)->printHoldings();	
	
	}

}

bool GameBoard::playerExists(std::string s) {
	//checks if player exists in list of players currrently playing
	std::list<Player*>::iterator itP;

	for(itP = this->players->begin(); itP != this->players->end(); itP++)
		if((*itP)->getName() == s)
			return true;

	return false;

}
