#include "DeckBuilder.hpp"

void Follower::setisDead(bool isDead){

	this->isDead = isDead;
}

bool Follower::getisDead(){

	return this->isDead;
}

Footsoldier::Footsoldier(std::string name) {

	this->name = name;
  //file to read from
	std::ifstream fp("Followers_and_Weapons.txt");
  //check if file can't be opened
  	if(!fp) {

    	std::cout << "Unable to open file";
      	exit(1); // terminate with error

 	 }

 	std::string fileInput, key = "FOOTSOLDIER:";

 	do {	// cycle through lines until you find the key word

 		std::getline(fp, fileInput);

 	} while(fileInput != key);
 	// we have reached the correct item spot
 	std::getline(fp, fileInput);
 	this->cost = fileInput.back();
 	std::getline(fp, fileInput);
 	this->attackBonus = fileInput.back();
 	std::getline(fp, fileInput);
 	this->defenceBonus = fileInput.back();
 	std::getline(fp, fileInput);
 	this->minimumHonour = fileInput.back();
 	std::getline(fp, fileInput);
 	this->effectBonus = fileInput.back();
 	std::getline(fp, fileInput);
 	this->effectCost = fileInput.back();

}

Archer::Archer(std::string name) {

	this->name = name;
  //file to read from
	std::ifstream fp("Followers_and_Weapons.txt");
  //check if file can't be opened
  	if(!fp) {

    	std::cout << "Unable to open file";
      	exit(1); // terminate with error

 	 }

 	std::string fileInput, key = "ARCHER:";

 	do {	// cycle through lines until you find the key word

 		std::getline(fp, fileInput);

 	} while(fileInput != key);
 	// we have reached the correct item spot
 	std::getline(fp, fileInput);
 	this->cost = fileInput.back();
 	std::getline(fp, fileInput);
 	this->attackBonus = fileInput.back();
 	std::getline(fp, fileInput);
 	this->defenceBonus = fileInput.back();
 	std::getline(fp, fileInput);
 	this->minimumHonour = fileInput.back();
 	std::getline(fp, fileInput);
 	this->effectBonus = fileInput.back();
 	std::getline(fp, fileInput);
 	this->effectCost = fileInput.back();

}

Cavalry::Cavalry(std::string name) {

	this->name = name;
  //file to read from
	std::ifstream fp("Followers_and_Weapons.txt");
  //check if file can't be opened
  	if(!fp) {

    	std::cout << "Unable to open file";
      	exit(1); // terminate with error

 	 }

 	std::string fileInput, key = "SIEGER:";

 	do {	// cycle through lines until you find the key word

 		std::getline(fp, fileInput);

 	} while(fileInput != key);
 	// we have reached the correct item spot
 	std::getline(fp, fileInput);
 	this->cost = fileInput.back();
 	std::getline(fp, fileInput);
 	this->attackBonus = fileInput.back();
 	std::getline(fp, fileInput);
 	this->defenceBonus = fileInput.back();
 	std::getline(fp, fileInput);
 	this->minimumHonour = fileInput.back();
 	std::getline(fp, fileInput);
 	this->effectBonus = fileInput.back();
 	std::getline(fp, fileInput);
 	this->effectCost = fileInput.back();
 	
}

Bushido::Bushido(std::string name) {

	this->name = name;
  //file to read from
	std::ifstream fp("Followers_and_Weapons.txt");
  //check if file can't be opened
  	if(!fp) {

    	std::cout << "Unable to open file";
      	exit(1); // terminate with error

 	 }

 	std::string fileInput, key = "CAVALRY:";

 	do {	// cycle through lines until you find the key word

 		std::getline(fp, fileInput);

 	} while(fileInput != key);
 	// we have reached the correct item spot
 	std::getline(fp, fileInput);
 	this->cost = fileInput.back();
 	std::getline(fp, fileInput);
 	this->attackBonus = fileInput.back();
 	std::getline(fp, fileInput);
 	this->defenceBonus = fileInput.back();
 	std::getline(fp, fileInput);
 	this->minimumHonour = fileInput.back();
 	std::getline(fp, fileInput);
 	this->effectBonus = fileInput.back();
 	std::getline(fp, fileInput);
 	this->effectCost = fileInput.back();
 	
}

Sieger::Sieger(std::string name) {

	this->name = name;
  //file to read from
	std::ifstream fp("Followers_and_Weapons.txt");
  //check if file can't be opened
  	if(!fp) {

    	std::cout << "Unable to open file";
      	exit(1); // terminate with error

 	 }

 	std::string fileInput, key = "NAVAL:";

 	do {	// cycle through lines until you find the key word

 		std::getline(fp, fileInput);

 	} while(fileInput != key);
 	// we have reached the correct item spot
 	std::getline(fp, fileInput);
 	this->cost = fileInput.back();
 	std::getline(fp, fileInput);
 	this->attackBonus = fileInput.back();
 	std::getline(fp, fileInput);
 	this->defenceBonus = fileInput.back();
 	std::getline(fp, fileInput);
 	this->minimumHonour = fileInput.back();
 	std::getline(fp, fileInput);
 	this->effectBonus = fileInput.back();
 	std::getline(fp, fileInput);
 	this->effectCost = fileInput.back();
 	
}

Atakebune::Atakebune(std::string name) {

	this->name = name;
  //file to read from
	std::ifstream fp("Followers_and_Weapons.txt");
  //check if file can't be opened
  	if(!fp) {

    	std::cout << "Unable to open file";
      	exit(1); // terminate with error

 	 }

 	std::string fileInput, key = "BUSHIDO:";

 	do {	// cycle through lines until you find the key word

 		std::getline(fp, fileInput);

 	} while(fileInput != key);
 	// we have reached the correct item spot
 	std::getline(fp, fileInput);
 	this->cost = fileInput.back();
 	std::getline(fp, fileInput);
 	this->attackBonus = fileInput.back();
 	std::getline(fp, fileInput);
 	this->defenceBonus = fileInput.back();
 	std::getline(fp, fileInput);
 	this->minimumHonour = fileInput.back();
 	std::getline(fp, fileInput);
 	this->effectBonus = fileInput.back();
 	std::getline(fp, fileInput);
 	this->effectCost = fileInput.back();
 	
}
