#include "DeckBuilder.hpp"

DeckBuilder::DeckBuilder(){
//create both decks
	black = new std::list<BlackCard *>();
	green = new std::list<GreenCard *>();

}

DeckBuilder::~DeckBuilder(){
//fully delete both lists of the class
	while(!black->empty()) {

        delete black->back();
        black->pop_back();

    }

   while(!green->empty()) {

        delete green->back();
        green->pop_back();

    }
//deleting the pointers to the lists
    delete black;
    delete green;
    
}

std::list<GreenCard *> *DeckBuilder::createFateDeck(){

	int i;
	//Create Followers
	//NO_FOOTSOLDIER
	for (i = 0; i < NO_FOOTSOLDIER; i++)
		green->push_back(new Footsoldier("Peasants"));
	//NO_ARCHER
	for (i = 0; i < NO_ARCHER; i++)
		green->push_back(new Archer("Elite Troops"));
	//NO_SIEGER
	for (i = 0; i < NO_SIEGER; i++)
		green->push_back(new Sieger("Immortal Bushi"));
	//NO_CAVALRY
	for (i = 0; i < NO_CAVALRY; i++)
		green->push_back(new Cavalry("Unicorn Horses"));
	//NO_NAVAL
	for (i = 0; i < NO_NAVAL; i++)
		green->push_back(new Atakebune("Yomi Ships"));
	//NO_BUSHIDO
	for (i = 0; i < NO_BUSHIDO; i++)
		green->push_back(new Bushido("7 Samurai"));

	//NO_KATANA
	for (i = 0; i < NO_KATANA; i++)
		green->push_back(new Katana("Daijtso"));
	//NO_BOW
	for (i = 0; i < NO_BOW; i++)
		green->push_back(new Bow("Yumi"));
	//NO_SPEAR	
	for (i = 0; i < NO_SPEAR; i++)
		green->push_back(new Spear("Kama"));
	//NO_NINJATO	
	for (i = 0; i < NO_NINJATO; i++)
		green->push_back(new Ninjato("Butterfly Dagger"));
	//NO_WAKIZASHI	
	for (i = 0; i < NO_WAKIZASHI; i++)
		green->push_back(new Wakizashi("Kusanagi"));

	return green;
}

std::list<BlackCard *> *DeckBuilder::createDynastyDeck(){

	int i;
	//Create Personalities
	//NO_DEFENSIVE 10
	for (i = 0; i < NO_DEFENSIVE; i++)
		black->push_back(new Defender("Footsoldiers"));
	//NO_ATTACKING 10
	for (i = 0; i < NO_ATTACKING; i++)
		black->push_back(new Attacker("Steadfast bushi"));
	//NO_SHOGUN	2
	black->push_back(new Shogun("Akodo Kaneka"));
	black->push_back(new Shogun("Isawa Shi en"));
	//NO_CHANCELLOR 2
	black->push_back(new Chancellor("Hida Shozen"));
	black->push_back(new Chancellor("Mirimuto Enishi"));
	//NO_CHAMPION 1
	black->push_back(new Champion("Hida Kisada"));
	//Create holdings
	for (i = 0; i < NO_PLAIN; i++)
		black->push_back(new Plain("Rice Fields"));
	for (i = 0; i < NO_FARMS; i++)
		black->push_back(new Farmland("Fish Farms"));
	for (i = 0; i < NO_MINE; i++)
		black->push_back(new Mine("Ashio Copper Mine"));
	for (i = 0; i < NO_GOLD_MINE; i++)
		black->push_back(new GoldMine("Konomai Gold Mine"));
	for (i = 0; i < NO_CRYSTAL_MINE; i++)
		black->push_back(new CrystalMine("Ichinokawa Crystal Mine"));
	for (i = 0; i < NO_SOLO; i++)
		black->push_back(new GiftsandFavour("Gifts and Favors"));
  
	return black;
}

void DeckBuilder::deckShuffler(std::list<BlackCard *> *black){
//Shuffles list of Black Cards given
	std::vector<BlackCard *> vect;
	std::list<BlackCard *>::iterator it;
	for (it = black->begin(); it != black->end(); it++)
		vect.push_back((*it));

	random_shuffle(vect.begin(), vect.end());

	black->clear();

	std::vector<BlackCard *>::iterator it2;
	for (it2 = vect.begin(); it2 != vect.end(); it2++)
		black->push_back((*it2));
}

void DeckBuilder::deckShuffler(std::list<GreenCard *> *green){
//Shuffles list of Green Cards given	
	std::vector<GreenCard *> vect;
	std::list<GreenCard *>::iterator it;
	for (it = green->begin(); it != green->end(); it++)
		vect.push_back((*it));

	random_shuffle(vect.begin(), vect.end());

	green->clear();

	std::vector<GreenCard *>::iterator it2;
	for (it2 = vect.begin(); it2 != vect.end(); it2++)
		green->push_back((*it2));
}