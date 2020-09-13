#include "DeckBuilder.hpp"

#define NO_HAND 6

Player::Player(std::string n) 
	: name(n), stronghold(new Stronghold(n + " Stronghold")), provinces(new std::list<BlackCard *>()), 
	  hand(new std::list<GreenCard *>()), holdings(NULL), army(NULL) , arena(new std::list<Personality *>()) {

	this->decks = new DeckBuilder;

	this->fateDeck = decks->createFateDeck();
	this->dynastyDeck = decks->createDynastyDeck();

	decks->deckShuffler(this->fateDeck);
	decks->deckShuffler(this->dynastyDeck);

	// get 4 provinces
	for(int i = 0 ; i < 4 ; i++)
		this->provinces->splice(this->provinces->begin(), *this->dynastyDeck, this->dynastyDeck->begin());

	// make sure the provinces are not revealed
	std::list<BlackCard *>::iterator itB;

	for (itB = this->provinces->begin(); itB != this->provinces->end(); itB++)
		(*itB)->setisRevealed(false);

	for(int i = 0 ; i < NO_HAND ; i++)
		this->hand->splice(this->hand->begin(), *this->fateDeck, this->fateDeck->begin());

}

Player::~Player(void) {
	//delete pointer to Stronghold
	delete this->stronghold;
	//fully delete fateDeck list
	while(!this->fateDeck->empty()) {

        delete this->fateDeck->back();
        this->fateDeck->pop_back();

    }
    //delete pointer to fateDeck list
    delete this->fateDeck;
    //fully delete dynastyDeck list
	while(!this->dynastyDeck->empty()) {

        delete this->dynastyDeck->back();
        this->dynastyDeck->pop_back();

    }
    //delete pointer to dynastyDeck list
    delete this->dynastyDeck;
    //fully delete provinces list
	while(!this->provinces->empty()) {

        delete this->provinces->back();
        this->provinces->pop_back();

    }
    //delete pointer to provinces list
    delete this->provinces;
    //fully delete hand list
	while(!this->hand->empty()) {

        delete this->hand->back();
        this->hand->pop_back();

    }
    //delete pointer to hand list
    delete this->hand;
    //fully delete holdings list
	while(!this->holdings->empty()) {

        delete this->holdings->back();
        this->holdings->pop_back();

    }
    //delete pointer to holdings list
    delete this->holdings;
    //fully delete army list
	while(!this->army->empty()) {

        delete this->army->back();
        this->army->pop_back();

    }
    //delete pointer to army list
    delete this->army;
    //fully delete arena list
	while(!arena->empty()) {

        delete this->arena->back();
        this->arena->pop_back();

    }
    //delete pointer to arena list
    delete this->arena;
    //delete pointer to DeckBuilder
	delete this->decks;

}

void Player::tap(std::string s) {

	std::list<Holding *>::iterator itH;

	for (itH = this->holdings->begin(); itH != this->holdings->end(); itH++) {

		if((*itH)->getName() == s) {
		//search in holdings list for given Holding and tap it
	    	(*itH)->setisTapped(true);
			break;

		}

	}

}

void Player::startingPhase(void) {

	this->untapEverything();
	this->drawFateCard();
	this->revealProvinces();
	this->printHand();
	this->printProvinces();

}

void Player::untapEverything(void) {

	std::list<BlackCard *>::iterator itB;
	std::list<GreenCard *>::iterator itG;
	std::list<Holding *>::iterator itH;
	std::list<Personality *>::iterator itA;

	this->stronghold->setisTapped(false);

	for (itB = this->provinces->begin(); itB != this->provinces->end(); itB++)
	    (*itB)->setisTapped(false);

	for (itG = this->hand->begin(); itG != this->hand->end(); itG++)
	    (*itG)->setisTapped(false);

	if(this->holdings)
		for (itH = this->holdings->begin(); itH != this->holdings->end(); itH++)
		    (*itH)->setisTapped(false);

	if(this->army)
		for (itA = this->army->begin(); itA != this->army->end(); itA++)
		    (*itA)->setisTapped(false);

}

void Player::drawFateCard(void) {

	this->hand->splice(this->hand->begin(), *this->fateDeck, this->fateDeck->begin());

}

void Player::revealProvinces(void) {

	std::list<BlackCard *>::iterator itB;

	for (itB = this->provinces->begin(); itB != this->provinces->end(); itB++)
		(*itB)->setisRevealed(true);

}

void Player::printHand(void) {

	std::cout << "Player \"" << this->name << "\" hand is:\n| ";

	std::list<GreenCard *>::iterator itG;

	for (itG = this->hand->begin(); itG != this->hand->end(); itG++)
	    std::cout << (*itG)->getName() << " | ";

	std::cout << std::endl;

}

void Player::printProvinces(void) {

	std::cout << "Provinces of player \"" << this->name << "\" are:\n| ";

	std::list<BlackCard *>::iterator itB;

	for (itB = this->provinces->begin(); itB != this->provinces->end(); itB++)
		if((*itB)->getisRevealed())
		    std::cout << (*itB)->getName() << " | ";

	std::cout << std::endl;

}
///equipPhase
void Player::equipPhase(void) {

	if(!this->army)
		return;

	std::string input;

	do {

		this->printHand();
		this->printArmy();

		std::cout << "Which card do you want to buy (\"none\" for none): " ;
		std::getline(std::cin, input, '\n');

		if(input != "none")
			this->buyCard(input);

	} while(input != "none");

}

void Player::printArmy(void) {

	std::cout << "Player \"" << this->name << "\"army is:\n| ";

	if(this->army) {
		
		std::list<Personality *>::iterator itA;

		for (itA = this->army->begin(); itA != this->army->end(); itA++)
		    std::cout << (*itA)->getName() << " | ";

		std::cout << std::endl;

	} else {

		std::cout << "*none*\n";

	}

}

void Player::buyCard(std::string s) {

	int tempMoney = 0;
	std::list<GreenCard *>::iterator itB;
	// for all cards in player's hand
	for(itB = this->hand->begin() ; itB != this->hand->end() ; itB++) {
		// find the one he wants to buy if it exists and is revealed
		if((*itB)->getName() == s) {

			if(this->availableHarvest() < (*itB)->getCost()) {

				std::cout << "(!) You cannot get enough money to buy this card, on this round.\n";
				return;

			}
			// tap holdings or the stronghold until you get enough money
			while((*itB)->getCost() > tempMoney) {
					
					tempMoney += this->tapHoldings();

					if((*itB)->getCost() > tempMoney)
						std::cout << "(!) Tap more holdings to be allowed to buy this.\n";
				}
			// break, since we have enough money
			break;

		}

	}

	if((itB == this->hand->end()) && (this->hand->back()->getName() !=  s)) {

		std::cout << "(!) The card you entered is not up for sale.\n";
		return;

	}

	std::string input;
	std::cout << "Type the name of the personality that you want to equip with this card: " ;
	std::getline(std::cin, input, '\n');

	std::list<Personality *>::iterator itP;
	// search for the personality in the army
	for(itP = this->army->begin() ; itP != this->army->end() ; itP++) {
		// if the names match
		if((*itP)->getName() == input) {
			// and it is allowed to add more followers or items corespondingly
			if((*itP)->getHonour() > (*itB)->getminimumHonour()) {

				if(Follower *f = dynamic_cast<Follower*>(*itB)) {
					
					if((*itP)->getFollowers() < NO_FOLLOWERS - 1) {
					
						(*itP)->attach(f);
						(*itP)->setAttack((*itP)->getAttack() + f->getattackBonus());
						(*itP)->setDefence((*itP)->getDefence() + f->getdefenceBonus());

						std::cout << "Type \"y\" to buy " << f->geteffectBonus()
								  << "Bonus points, for a cost of" << f->geteffectCost() << ":";
						std::string tempStr;
						std::getline(std::cin, tempStr, '\n');
						std::cout << std::endl;

						if(tempStr == "y") {

							while(f->geteffectCost() > tempMoney) {
					
								tempMoney += this->tapHoldings();

								if(f->geteffectCost() > tempMoney)
									std::cout << "Tap more holdings to be allowed to buy this.\n";

							}

							(*itP)->setAttack((*itP)->getAttack() + f->geteffectBonus());
							(*itP)->setDefence((*itP)->getDefence() + f->geteffectBonus());

						}

					
					} else {

						std::cout << "Cannot equip this Personality with more Items.\n";

						return;

					}

				} else if(Item *i = dynamic_cast<Item*>(*itB)) {

					if((*itP)->getItems() < NO_FOLLOWERS - 1) {

						(*itP)->attach(i);
						(*itP)->setAttack((*itP)->getAttack() + i->getattackBonus());
						(*itP)->setDefence((*itP)->getDefence() + i->getdefenceBonus());

						std::cout << "Type \"y\" to buy " << i->geteffectBonus()
								  << "Bonus points, for a cost of" << i->geteffectCost() << ":";
						std::string tempStr;
						std::getline(std::cin, tempStr, '\n');
						std::cout << std::endl;

						if(tempStr == "y") {

							while(i->geteffectCost() > tempMoney) {
					
								tempMoney += this->tapHoldings();

								if(i->geteffectCost() > tempMoney)
									std::cout << "Tap more holdings to be allowed to buy this.\n";
								
							}

							(*itP)->setAttack((*itP)->getAttack() + i->geteffectBonus());
							(*itP)->setDefence((*itP)->getDefence() + i->geteffectBonus());

						}
					
					} else {

						std::cout << "Cannot equip this Personality with more Items.\n";

						return;
				
					}

				}
				// remove it from the player's hand
				this->hand->erase(itB);
				// and add a new green card in its place
				this->hand->push_back(this->fateDeck->front());
				this->fateDeck->pop_front();

			} else {

				std::cout << "This Personality does not have enough honor.\n";

				return;

			}

			break;
		
		}

	}

}

//economyPhase
void Player::economyPhase(void) {

	this->revealProvinces();

	std::string input;

	do {

		this->printProvinces();

		std::cout << "Which province do you want to buy (\"none\" for none): " ;
		std::getline(std::cin, input, '\n');

		if(input != "none")
			this->buyProvince(input);

	} while(input != "none");

}

void Player::buyProvince(std::string s) {

	int tempMoney = 0;
	BlackCard *tmp = NULL;
	std::list<BlackCard *>::iterator itB;
	// for all of player's provinces
	for(itB = this->provinces->begin() ; itB != this->provinces->end() ; itB++) {
			// find the one he wants to buy if it exists and is revealed
			if(((*itB)->getName() == s) && ((*itB)->getisRevealed())) {

				int provinceCost = (*itB)->getCost();
				
				if(this->availableHarvest() < provinceCost) {

					std::cout << "(!) You cannot get enough money to buy this province, on this round.\n";
					
					return;

				}

				while(provinceCost > tempMoney) {

					tempMoney += this->tapHoldings();

					if(provinceCost > tempMoney)
						std::cout << "(!) Tap more holdings to be allowed to buy this.\n";

				}
				// hold on to the province's address, if we have enough money
				tmp = *itB;
				break;

			}

	}

	if((itB == this->provinces->end()) && (this->provinces->back()->getName() !=  s)) {

		std::cout << "(!) The province you entered is not available for sale.\n";

	}

	if(tmp) {
		// then push it in army or holdings -- depending on what it is
		if(Holding *h = dynamic_cast<Holding*>(tmp)) {

			if(!this->holdings) 
				this->holdings = new std::list<Holding *>();

			this->holdings->push_back(h);
			this->checkForChain(h);
			// delete h;

		} else if(Personality *p = dynamic_cast<Personality*>(tmp)) {

			if(!this->army)
				this->army = new std::list<Personality *>();

			this->army->push_back(p);
			// delete p;

		}
		// erase it from the provinces list
		this->provinces->erase(itB);
		// delete tmp;
		// and add a new non-revealed province in its place
		this->provinces->push_back(this->dynastyDeck->front());
		this->provinces->back()->setisRevealed(false);
		this->dynastyDeck->pop_front();

	}

}

int Player::availableHarvest(void) {

	int tmp = 0;
	std::list<Holding *>::iterator itH;
	// cycle through holdings
	if(this->holdings) {
		//for every Holding in holdings list if it is not tapped get it's harvest value
		for(itH = this->holdings->begin() ; itH != this->holdings->end() ; itH++)
			if(!(*itH)->getisTapped())
				tmp += (*itH)->getHarvest();

	}
	//get stronghold's harvest value
	if(!this->stronghold->getisTapped())
		tmp += this->stronghold->getHarvest();

	return tmp;

}

void Player::checkForChain(Holding *h) {

	std::list<Holding *>::iterator itH;
	// cycle through holdings
	for(itH = this->holdings->begin() ; itH != this->holdings->end() ; itH++) {
		//checks for conditions mentioned in exercise
		if(Mine *m = dynamic_cast<Mine*>(*itH)) {

			m->add_upperHolding(h);
			delete m;

		} else if(GoldMine *gm = dynamic_cast<GoldMine*>(*itH)) {

			gm->add_upperHolding(h);
			gm->add_subHolding(h);
			delete gm;

		} else if(CrystalMine *cm = dynamic_cast<CrystalMine*>(*itH)) {

			cm->add_subHolding(h);
			delete cm;

		}

	}

}

std::string Player::getName(){

	return this->name;
}

void Player::attack(Player * p,std::string s) {

	BlackCard * tmp;

	std::list<BlackCard *>::iterator itB;

	for(itB = p->provinces->begin(); itB != p->provinces->end(); itB++) {
			//search for province's name given in player's provinces list
			if((*itB)->getName() == s) {

				tmp = *itB;
				break;
			
			}

	}
	//get total attack and defensive points of personalities in arena deck
	int ap = this->getAttack_forPhase();
	int dp = p->getDefence_forPhase();

	if(Personality * pp = dynamic_cast<Personality*>(tmp)) {

		if(ap > (pp->getDefence() + p->stronghold->getInitialDefense() + dp)) {

			std::cout << "Province with name:" << tmp->getName() << " desroyed succesfully." << std::endl;
			p->provinces->remove(tmp);//remove defeated province from list
			p->arenaDead();//kill all arena cards of defeated defender
			p->clearArena();//clear arena deck of defeated defender
		//	p->provinces = NULL;

		}else if(ap > dp){

			p->arenaDead();//kill all arena cards of defeated defender
			this->arenaDead(ap-dp);//kill personalites from arena deck up to a limit
			this->checkforHonour();//reduce by 1 all arena cards that lost , but did not die
			p->checkforHonour();//reduce by 1 all arena cards of opponent that lost , but did not die
			this->tap_arena();//tap all arena cards 

		}else if(ap == dp){

			p->arenaDead();//kill all arena cards of defeated defender
			this->arenaDead();//kill all arena cards 
			this->checkforHonour();//reduce by 1 all arena cards that lost , but did not die
			p->checkforHonour();//reduce by 1 all arena cards of opponent that lost , but did not die

		}else if(ap < dp){

			this->arenaDead();//kill all arena cards 
			p->arenaDead(dp-ap);//kill personalites from arena deck of opponent up to a limit
			this->checkforHonour();//reduce by 1 all arena cards that lost , but did not die
			p->checkforHonour();//reduce by 1 all arena cards of opponent that lost , but did not die
		}

	} else if(dynamic_cast<Holding*>(tmp)) {
		//same thing if province is type Holding , but without taking into consideration card's defense
		if(ap > (p->stronghold->getInitialDefense() + dp)) {

			std::cout << "Province with name:" << tmp->getName() << " desroyed succesfully." << std::endl;
			p->provinces->remove(tmp);
			p->arenaDead();
			p->clearArena();
		//	p->provinces = NULL;

		}else if(ap > dp){

			p->arenaDead();
			this->arenaDead(ap-dp);
			p->checkforHonour();

		}else if(ap == dp){

			p->arenaDead();
			this->arenaDead();

		}else if(ap < dp){

			this->arenaDead();
			p->arenaDead(dp-ap);
			this->checkforHonour();
		}

	}

}

void Player::tap_arena() {

	std::list<Personality*>::iterator it1;
	std::list<Personality*>::iterator it2;

	for(it1 = this->arena->begin(); it1 != this->arena->end(); it1++){
		for(it2 = this->army->begin(); it2 != this->army->end(); it2++)

			if( ( (*it2)->getName() == (*it1)->getName() ) && ( !(*it2)->getisDead() ) ){
				//tap card's followers , card and reduce durability of its' items by 1
				(*it2)->setisTapped(true);
				(*it2)->tapFollowers();
				(*it2)->reduceDurabilities();

			}
	}
}

void Player::checkforHonour() {

	std::list<Personality*>::iterator it1;
	std::list<Personality*>::iterator it2;

	for(it1 = this->arena->begin(); it1 != this->arena->end(); it1++)
		for( it2 = this->army->begin(); it2 != this->army->end(); it2++)
			if( (*it1)->getName() == (*it2)->getName() )
				if( !(*it1)->getisDead() ){

					(*it1)->setHonour( (*it1)->getHonour() - 1 );
					if( !(*it1)->getHonour() )
						(*it1)->performSeppuku();

				}

}

void Player::arenaDead(int i) {
	//killing arena's cards up to a limit given
	std::list<Personality*>::iterator it1;
	std::list<Personality*>::iterator it2;
	int tmp = 0;

	for(it1 = this->arena->begin(); it1 != this->arena->end(); it1++)
		for( it2 = this->army->begin(); it2 != this->army->end(); it2++)
			if( (*it1)->getName() == (*it2)->getName() ){

				if(tmp < i){
				//while limit isn't reached
					tmp += (*it2)->setisDeadwithLimit(true,i - tmp);//update variable 
					break;

				}

			}
}

void Player::arenaDead() {

	std::list<Personality*>::iterator it1;
	std::list<Personality*>::iterator it2;

	for(it1 = this->arena->begin(); it1 != this->arena->end(); it1++)
		for( it2 = this->army->begin(); it2 != this->army->end(); it2++)
			if( (*it1)->getName() == (*it2)->getName() ){

				(*it2)->setisDead(true);
				break;

			}


}

void Player::clearArena() {

	this->arena->clear();

}

int Player::getAttack_forPhase() {

	std::list<Personality *>::iterator itP;

	int tmp = 0;

	for(itP = this->arena->begin(); itP != this->arena->end(); itP++)
		tmp += (*itP)->getAttack();

	return tmp;
}

int Player::getDefence_forPhase() {

	std::list<Personality *>::iterator itP;

	int tmp = 0;

	for(itP = this->arena->begin(); itP != this->arena->end(); itP++){

		tmp += (*itP)->getDefence();
	}

	return tmp + stronghold->getInitialDefense();
}

void Player::initializeDeck() {

	if(!this->army)
		return;

	std::list<Personality *>::iterator itP;

	for( itP = this->army->begin(); itP != this->army->end(); itP++) {

		if(!(*itP)->getisTapped()) {
		//if card from army deck is not tapped , ask user if he wants to add it to arena deck 
			std::cout << "Card's name is:" << (*itP)->getName() << std::endl;
			std::cout << "Type \"y\" to use this for fighting:";
			std::string input;
			std::getline(std::cin, input, '\n');
			//if answer is yes add it to arena list
			if(input == "y")			
				arena->push_back(*itP);

		}
	}
}

int Player::tapHoldings(void) {
	
	int moneyGathered = 0;
	std::string tmpStr;
	// check stronghold for tapping
	if(!this->stronghold->getisTapped()) {
		//ask user if he wants to tap stronghold
		std::cout << "Enter \"tap\" to tap [" << this->stronghold->getName() << "]: ";
		std::getline(std::cin, tmpStr, '\n');
		std::cout << std::endl;

		if(tmpStr == "tap") {
			//if answer is "tap" , taps it and gets it's harvest value 
			this->stronghold->setisTapped(true);
			moneyGathered += this->stronghold->getHarvest();

		}

	}

	if(this->holdings) {

		std::list<Holding *>::iterator itH;
		// cycle through holdings to select which ones to tap
		for(itH = this->holdings->begin() ; itH != this->holdings->end() ; itH++) {
			// print tap message for the non tapped ones
			if(!(*itH)->getisTapped()) {

				std::cout << "Enter \"tap\" to tap [" << (*itH)->getName() << "]: ";
				std::getline(std::cin, tmpStr, '\n');
				std::cout << std::endl;

				if(tmpStr == "tap") {

					(*itH)->setisTapped(true);
					moneyGathered += (*itH)->getHarvest();

				}

			}

		}

	}

	return moneyGathered;

}

bool Player::checkForLoss() {	// to be used on GameBoard
	//if there are no provinces left return true
	if(this->provinces->empty())
		return true;

	return false;

}

void Player::printHoldings(void) {

	std::cout << "Player \"" << this->name << "\"holdings are:\n";


	if(this->holdings) {
		
		std::list<Holding *>::iterator itH;

		for (itH = this->holdings->begin(); itH != this->holdings->end(); itH++)
		    std::cout << (*itH)->getName() << " ";

		std::cout << std::endl;

	} else {

		std::cout << "*none*\n";

	}

}

void Player::printArena(void) {

	std::cout << "Player \"" << this->name << "\"arena is:\n";

	std::list<Personality *>::iterator itP;

	for (itP = this->arena->begin(); itP != this->arena->end(); itP++)
	    std::cout << (*itP)->getName() << " ";

	std::cout << std::endl;

}

double Player::getPersonalitiesKilled() {

	int deadCounter = 0;

	std::list<Personality*>::iterator itP;

	for(itP = this->army->begin(); itP != this->army->end(); itP++ )
		if( !(*itP)->getisDead() )
			deadCounter++;

	return deadCounter / this->army->size();

}

double Player::getFollowersKilled() {

	int totalFollowersKilled = 0, totalFollowers = 0;

	std::list<Personality*>::iterator itP;

	if(this->army)
		for(itP = this->army->begin(); itP != this->army->end(); itP++){
			
			totalFollowersKilled += (*itP)->getFollowersKilled();
			totalFollowers += (*itP)->getFollowers();
		
		}
	if(totalFollowersKilled)
		return totalFollowersKilled / totalFollowers;
	return 0;

}

int Player::getTotalBonus() {

	int totalPersonalityBonus = 0;

	std::list<Personality*>::iterator itP;
	
	if(this->army)
		for(itP = this->army->begin(); itP != this->army->end(); itP++)
			totalPersonalityBonus += (*itP)->getTotalBonus();

	return totalPersonalityBonus;

}

int Player::getTotalArmy(){

	if(this->army)
		return this->army->size();
	return 0;
}

int Player::getTotalHoldings(){

	if(this->holdings)
		return this->holdings->size();
	return 0;
}

int Player::getArmyAdditions(){

	return this->armyAdditions;
}

int Player::getHoldingAdditions(){

	return this->holdingAdditions;
}

void Player::discardSurplusFateCards(){

	std::string input;
	std::list<GreenCard*>::iterator itG;

	while(this->hand->size() > NO_HAND) {
		//while hand's size is more than we want keep asking user which card of list to discard
		this->printHand();

		std::cout << "Type the name of the card you want to discard:" << std::endl;
		std::string input;
		std::getline(std::cin, input, '\n');
		std::cout << std::endl;
		//discard certain card
		this->discardFromHand(input);

	}

}

void Player::discardFromHand(std::string s){

	std::list<GreenCard*>::iterator itG;

	for(itG = this->hand->begin(); itG != this->hand->end(); itG++)
		if((*itG)->getName() == s) {

			this->hand->remove(*itG);
			break;

		}

}

int Player::getHonour() {

	if(this->stronghold)
		return this->stronghold->getStartingHonour();
	return 0;

}

bool Player::provinceExists(std::string s) {

	std::list<BlackCard*>::iterator itB;

	for(itB = this->provinces->begin(); itB != this->provinces->end(); itB++)
		if((*itB)->getName() == s)
			return true;


	return false;

}