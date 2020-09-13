//#include "Holding.hpp"
#include "DeckBuilder.hpp"

void Holding::setHarvest(int harvest){

	this->harvest = harvest;
}

int Holding::getHarvest(){

	return this->harvest;
}

bool Holding::check_for_chain(){
	//checks if current Holding has upper holding and sub holding already
	if( this->upperHolding != false && this->subHolding != false)
		return true;
	return false;
}

void Holding::add_upperHolding(Holding*) {}
void Holding::add_subHolding(Holding*) {}

Plain::Plain(std::string name) {

	this->name = name;
	//file to read from
	std::ifstream fp("Personalities_and_Holdings.txt");
	//check if file can't be opened
  	if(!fp) {

    	std::cout << "Unable to open file";
      	exit(1); // terminate with error

 	 }

 	std::string fileInput, key = "PLAIN:";

 	do {	// cycle through lines until you find the key word

 		std::getline(fp, fileInput);

 	} while(fileInput != key);
 	// we have reached the correct item spot
 	std::getline(fp, fileInput);
 	this->cost = fileInput.back();
 	std::getline(fp, fileInput);
 	this->harvest = fileInput.back();

}

Mine::Mine(std::string name){

	this->name = name;
	this->upperHolding = false;
	this->subHolding = false;
	//file to read from
	std::ifstream fp("Personalities_and_Holdings.txt");
	//check if file can't be opened
  	if(!fp) {

    	std::cout << "Unable to open file";
      	exit(1); // terminate with error

 	 }

 	std::string fileInput, key = "MINE:";

 	do {	// cycle through lines until you find the key word

 		std::getline(fp, fileInput);

 	} while(fileInput != key);
 	// we have reached the correct item spot
 	std::getline(fp, fileInput);
 	this->cost = fileInput.back();
 	std::getline(fp, fileInput);
 	this->harvest = fileInput.back();

}

void Mine::add_upperHolding(Holding* h){
	//if there it doesn't have upper holding already
	if( this->upperHolding )
		//if it is the correct type , add it as upper holding
		if( dynamic_cast<GoldMine*>(h) ){
			this->upperHolding = true;
			this->setHarvest(this->getHarvest()+2);//update harvest value
			//this->setHarvest(this);
			h->add_subHolding(this);//add current holding as sub holding of the other
		}

}

GoldMine::GoldMine(std::string name){

	this->name = name;
	this->upperHolding = false;
	this->subHolding = false;
	//file to read from
	std::ifstream fp("Personalities_and_Holdings.txt");
	//check if file can't be opened
  	if(!fp) {

    	std::cout << "Unable to open file";
      	exit(1); // terminate with error

 	 }

 	std::string fileInput, key = "GOLD_MINE:";

 	do {	// cycle through lines until you find the key word

 		std::getline(fp, fileInput);

 	} while(fileInput != key);
 	// we have reached the correct item spot
 	std::getline(fp, fileInput);
 	this->cost = fileInput.back();
 	std::getline(fp, fileInput);
 	this->harvest = fileInput.back();

}

void GoldMine::add_upperHolding(Holding* h){

	if( this->upperHolding )
		if( dynamic_cast<CrystalMine*>(h) ){
			this->upperHolding = true;
			this->setHarvest(this->getHarvest()+5);
			h->add_subHolding(this);
			if( this->check_for_chain() )
				this->setHarvest(this->getHarvest()+this->getHarvest()*2);
		}
}

void GoldMine::add_subHolding(Holding* h){
	//if there it doesn't have sub holding already
	if( this->subHolding )
		//if it is the correct type , add it as sub holding
		if( dynamic_cast<Mine*>(h) ){
			this->subHolding = true;
			this->setHarvest(this->getHarvest()+4);//update harvest value
			h->add_upperHolding(this);//add current holding as upper holding of the other
			if( this->check_for_chain() )//check if we have a complete chain for current holding
				this->setHarvest(this->getHarvest()+this->getHarvest()*2);//update harvest value if yes
		}
}

CrystalMine::CrystalMine(std::string name){

	this->upperHolding = false;
	this->subHolding = false;
	this->name = name;
	//file to read from
	std::ifstream fp("Personalities_and_Holdings.txt");
	//check if file can't be opened
  	if(!fp) {

    	std::cout << "Unable to open file";
      	exit(1); // terminate with error

 	 }

 	std::string fileInput, key = "CRYSTAL_MINE:";

 	do {	// cycle through lines until you find the key word

 		std::getline(fp, fileInput);

 	} while(fileInput != key);
 	// we have reached the correct item spot
 	std::getline(fp, fileInput);
 	this->cost = fileInput.back();
 	std::getline(fp, fileInput);
 	this->harvest = fileInput.back();

}

void CrystalMine::add_subHolding(Holding* h){

	if( this->subHolding )
		if( dynamic_cast<GoldMine*>(h) ){
			this->subHolding = true;
			this->setHarvest(this->getHarvest()*2);
			h->add_upperHolding(this);
			if( h->check_for_chain() )
				this->setHarvest(this->getHarvest()+this->getHarvest()*3);
		}
}

Farmland::Farmland(std::string name) {

	this->name = name;
	//file to read from
	std::ifstream fp("Personalities_and_Holdings.txt");
	//check if file can't be opened
  	if(!fp) {

    	std::cout << "Unable to open file";
      	exit(1); // terminate with error

 	 }

 	std::string fileInput, key = "FARMS:";

 	do {	// cycle through lines until you find the key word

 		std::getline(fp, fileInput);

 	} while(fileInput != key);
 	// we have reached the correct item spot
 	std::getline(fp, fileInput);
 	this->cost = fileInput.back();
 	std::getline(fp, fileInput);
 	this->harvest = fileInput.back();

}

GiftsandFavour::GiftsandFavour(std::string name) {

	this->name = name;
	//file to read from
	std::ifstream fp("Personalities_and_Holdings.txt");
	//check if file can't be opened
  	if(!fp) {

    	std::cout << "Unable to open file";
      	exit(1); // terminate with error

 	 }

 	std::string fileInput, key = "SOLO:";

 	do {	// cycle through lines until you find the key word

 		std::getline(fp, fileInput);

 	} while(fileInput != key);
 	// we have reached the correct item spot
 	std::getline(fp, fileInput);
 	this->cost = fileInput.back();
 	std::getline(fp, fileInput);
 	this->harvest = fileInput.back();

}

Stronghold::Stronghold(std::string n) {

	this->name = n;
	//file to read from
	std::ifstream fp("Personalities_and_Holdings.txt");
	//check if file can't be opened
  	if(!fp) {

    	std::cout << "Unable to open file";
      	exit(1); // terminate with error

 	 }

 	std::string fileInput, key = "STRONGHOLD:";

 	do {	// cycle through lines until you find the key word

 		std::getline(fp, fileInput);

 	} while(fileInput != key);
 	// we have reached the correct item spot
 	std::getline(fp, fileInput);
 	this->startingHonour = fileInput.back() + rand() % 1001;
 	std::getline(fp,fileInput);
 	this->initialDefense = fileInput.back();
 	std::getline(fp,fileInput);
 	this->harvest = fileInput.back();

}

int Stronghold::getStartingHonour(){

	return this->startingHonour;

}

int Stronghold::getInitialDefense(){

	return this->initialDefense;

}
