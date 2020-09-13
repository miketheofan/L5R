#include "DeckBuilder.hpp"

Card::~Card(void) {}

void Card::setName(std::string n){

	this->name = n;

}

std::string Card::getName(){

	return this->name;

}

void Card::setCost(int c){

	this->cost = c;
}

int Card::getCost(){

	return this->cost;

}

void Card::setisTapped(bool cond){

	this->isTapped = cond;

}

bool Card::getisTapped(){

	return this->isTapped;

}

void BlackCard::setisRevealed(bool cond){

	this->isRevealed = cond;

}

bool BlackCard::getisRevealed(){

	return this->isRevealed;

}

void GreenCard::setattackBonus(int points){

	this->attackBonus = points;

}

int GreenCard::getattackBonus(){

	return this->attackBonus;

}

void GreenCard::setdefenceBonus(int points){

	this->defenceBonus = points;

}

int GreenCard::getdefenceBonus(){

	return this->defenceBonus;

}

void GreenCard::setminimumHonour(int points){

	this->minimumHonour = points;

}

int GreenCard::getminimumHonour(){

	return this->minimumHonour;

}

void GreenCard::setcardText(std::string txt){

	this->cardText = txt;

}

std::string GreenCard::getcardText(){

	return this->cardText;

}

void GreenCard::seteffectBonus(int points){

	this->effectBonus = points;

}

int GreenCard::geteffectBonus(){

	return this->effectBonus;

}

void GreenCard::seteffectCost(int cost){

	this->effectCost = cost;

}

int GreenCard::geteffectCost(){

	return this->effectCost;

}
