#include "DeckBuilder.hpp"

void Item::setDurability(int i){

  this->durability = i;
}

int Item::getDurability(void){

  return this->durability;
}

Katana::Katana(std::string name) {

	this->name = name;
  //file to read from
	std::ifstream fp("Followers_and_Weapons.txt");
    //check if file can't be opened
  	if(!fp) {

    	std::cout << "Unable to open file";
      	exit(1); // terminate with error

 	 }

 	std::string fileInput, key = "KATANA:";

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
 	std::getline(fp, fileInput);
 	this->durability = fileInput.back();

}

Spear::Spear(std::string name) {

	this->name = name;
  //file to read from
	std::ifstream fp("Followers_and_Weapons.txt");
    //check if file can't be opened
  	if(!fp) {

    	std::cout << "Unable to open file";
      	exit(1); // terminate with error

 	 }

 	std::string fileInput, key = "SPEAR:";

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
 	std::getline(fp, fileInput);
 	this->durability = fileInput.back();

}

Bow::Bow(std::string name) {

	this->name = name;
	//file to read from
	std::ifstream fp("Followers_and_Weapons.txt");
    //check if file can't be opened
  	if(!fp) {

    	std::cout << "Unable to open file";
      	exit(1); // terminate with error

 	 }

 	std::string fileInput, key = "BOW:";

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
 	std::getline(fp, fileInput);
 	this->durability = fileInput.back();

}

Ninjato::Ninjato(std::string name) {

	this->name = name;
	//file to read from
	std::ifstream fp("Followers_and_Weapons.txt");
    //check if file can't be opened
  	if(!fp) {

    	std::cout << "Unable to open file";
      	exit(1); // terminate with error

 	 }

 	std::string fileInput, key = "NINJATO:";

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
 	std::getline(fp, fileInput);
 	this->durability = fileInput.back();

}

Wakizashi::Wakizashi(std::string name) {

	this->name = name;
	//file to read from
	std::ifstream fp("Followers_and_Weapons.txt");
    //check if file can't be opened
  	if(!fp) {

    	std::cout << "Unable to open file";
      	exit(1); // terminate with error

 	 }

 	std::string fileInput, key = "WAKIZASHI:";

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
 	std::getline(fp, fileInput);
 	this->durability = fileInput.back();

}
