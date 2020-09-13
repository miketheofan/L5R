#include "DeckBuilder.hpp"

//allocates memory for lists of followers and items of each personality
Personality::Personality(void) 
	: followers(new std::list<Follower *>()), items(new std::list<Item *>()) {}

Personality::~Personality(void){
//deletes lists of followers and items and also deleting pointers to these lists
	this->followers->clear();
	delete this->followers;
	this->items->clear();
	delete this->items;
	
}

void Personality::setAttack(int attack){

	this->attack = attack;
}

int Personality::getAttack(){

	return this->attack;
}

void Personality::setDefence(int defence){

	this->defence = defence;
}

int Personality::getDefence(){

	return this->defence;
}

void Personality::setHonour(int honour){

	this->honour = honour;
}

int Personality::getHonour(){

	return this->honour;
}

void Personality::setisDead(bool isDead){

	this->isDead = isDead;
}

void Personality::tapFollowers(){

	std::list<Follower*>::iterator itF;

	for(itF = this->followers->begin(); itF != this->followers->end(); itF++){
		//check if follower is not dead
		if( !(*itF)->getisDead() )
			(*itF)->setisTapped(true);//tap him

	}

}

void Personality::reduceDurabilities(){

	std::list<Item*>::iterator itI;

	for(itI = this->items->begin(); itI != this->items->end(); itI++){

		(*itI)->setDurability( (*itI)->getDurability()-1 );
		if( !(*itI)->getDurability() )
			this->detach(*itI);//if durability of item drops to 0 , detach it from list
	}
}


void Personality::performSeppuku(){

	std::cout << "Personality with name:" << this->getName() << " performed Seppuku." << std::endl;
}

int Personality::setisDeadwithLimit(bool isDead,int attackLimit){

	std::list<Follower*>::iterator itF;
	itF = this->followers->begin();

	int tmpAttack = 0;
	while( (tmpAttack < attackLimit) && (itF != this->followers->end()) ){
		
		//get attack of each follower of current personality
		tmpAttack += (*itF)->getattackBonus();
		//set current follower as dead
		(*itF)->setisDead(true);
		this->detach(*itF++);
	
	}

	if(tmpAttack < attackLimit){
		
		//if killing all followers didn't reach the desired number
		std::cout << "Number not reached from Followers." << std::endl;
		//get attack from personality as well
		tmpAttack += this->getAttack();
		this->isDead = isDead;
		// //kill personality and detach it from player's list

	}

	return tmpAttack;

}

void Personality::attach(Follower* f) {

	this->followers->push_back(f);

}

void Personality::attach(Item* i) {

	this->items->push_back(i);

}

void Personality::detach(Follower* f){

	std::list<Follower*>::iterator itF;

	for(itF = this->followers->begin(); itF != this->followers->end(); itF++)
		if( f->getName() == (*itF)->getName() ){
			//search for given follower's name and remove it from list
			this->setAttack(this->getAttack() - (*itF)->getattackBonus());
			this->followers->remove(*itF);
			break;
		}
}

void Personality::detach(Item* i){

	std::list<Item*>::iterator itI;

	for(itI = this->items->begin(); itI != this->items->end(); itI++)
		if( i->getName() == (*itI)->getName() ){
			//check for given item's name and remove it from list
			this->setAttack(this->getAttack() - (*itI)->getattackBonus());
			this->items->remove(*itI);
			break;

		}

}

bool Personality::getisDead(){

	return this->isDead;
}

int Personality::getFollowers() {

	return this->followers->size();

}

int Personality::getItems() {

	return this->items->size();

}

int Personality::getFollowersKilled(){
	//returns total amount of dead followers from personality's list
	int tmp = 0;

	std::list<Follower*>::iterator itF;

	for(itF = this->followers->begin(); itF != this->followers->end(); itF++)
		if( !(*itF)->getisDead() )
			tmp++;

	return tmp;
}

int Personality::getTotalBonus(){

	return this->totalBonusPoints;
}

Attacker::Attacker(std::string name) {

	this->name = name;
	//file to read from
	std::ifstream fp("Personalities_and_Holdings.txt");
	//check if file can't be opened
  	if(!fp) {

    	std::cout << "Unable to open file";
      	exit(1); // terminate with error

 	 }

 	std::string fileInput, key = "ATTACKER:";

 	do {	// cycle through lines until you find the key word

 		std::getline(fp, fileInput);

 	} while(fileInput != key);
 	// we have reached the correct item spot
 	std::getline(fp, fileInput);
 	this->cost = fileInput.back();
 	std::getline(fp, fileInput);
 	this->attack = fileInput.back();
 	std::getline(fp, fileInput);
 	this->defence = fileInput.back();
 	std::getline(fp, fileInput);
 	this->honour = fileInput.back();

}

Defender::Defender(std::string name) {

	this->name = name;
	//file to read from
	std::ifstream fp("Personalities_and_Holdings.txt");
	//check if file can't be opened
  	if(!fp) {

    	std::cout << "Unable to open file";
      	exit(1); // terminate with error

 	 }

 	std::string fileInput, key = "DEFENDER:";

 	do {	// cycle through lines until you find the key word

 		std::getline(fp, fileInput);

 	} while(fileInput != key);
 	// we have reached the correct item spot
 	std::getline(fp, fileInput);
 	this->cost = fileInput.back();
 	std::getline(fp, fileInput);
 	this->attack = fileInput.back();
 	std::getline(fp, fileInput);
 	this->defence = fileInput.back();
 	std::getline(fp, fileInput);
 	this->honour = fileInput.back();

}

Champion::Champion(std::string name) {

	this->name = name;
	//file to read from
	std::ifstream fp("Personalities_and_Holdings.txt");
	//check if file can't be opened
  	if(!fp) {

    	std::cout << "Unable to open file";
      	exit(1); // terminate with error

 	 }

 	std::string fileInput, key = "CHAMPION:";

 	do {	// cycle through lines until you find the key word

 		std::getline(fp, fileInput);

 	} while(fileInput != key);
 	// we have reached the correct item spot
 	std::getline(fp, fileInput);
 	this->cost = fileInput.back();
 	std::getline(fp, fileInput);
 	this->attack = fileInput.back();
 	std::getline(fp, fileInput);
 	this->defence = fileInput.back();
 	std::getline(fp, fileInput);
 	this->honour = fileInput.back();

}

Chancellor::Chancellor(std::string name) {

	this->name = name;
	//file to read from
	std::ifstream fp("Personalities_and_Holdings.txt");
	//check if file can't be opened
  	if(!fp) {

    	std::cout << "Unable to open file";
      	exit(1); // terminate with error

 	 }

 	std::string fileInput, key = "CHANCELLOR:";

 	do {	// cycle through lines until you find the key word

 		std::getline(fp, fileInput);

 	} while(fileInput != key);
 	// we have reached the correct item spot
 	std::getline(fp, fileInput);
 	this->cost = fileInput.back();
 	std::getline(fp, fileInput);
 	this->attack = fileInput.back();
 	std::getline(fp, fileInput);
 	this->defence = fileInput.back();
 	std::getline(fp, fileInput);
 	this->honour = fileInput.back();

}

Shogun::Shogun(std::string name) {

	this->name = name;
	//file to read from
	std::ifstream fp("Personalities_and_Holdings.txt");
	//check if file can't be opened
  	if(!fp) {

    	std::cout << "Unable to open file";
      	exit(1); // terminate with error

 	 }

 	std::string fileInput, key = "SHOGUN:";

 	do {	// cycle through lines until you find the key word

 		std::getline(fp, fileInput);

 	} while(fileInput != key);
 	// we have reached the correct item spot
 	std::getline(fp, fileInput);
 	this->cost = fileInput.back();
 	std::getline(fp, fileInput);
 	this->attack = fileInput.back();
 	std::getline(fp, fileInput);
 	this->defence = fileInput.back();
 	std::getline(fp, fileInput);
 	this->honour = fileInput.back();

}