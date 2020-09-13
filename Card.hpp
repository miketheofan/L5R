#ifndef _CARD_HPP_
#define _CARD_HPP_

#include <iostream>


class Card {
	
protected:
	std::string name;
	int cost;
	bool isTapped;

public:

	virtual ~Card(void);
	virtual void setName(std::string);
	std::string getName();
	void setCost(int);
	int getCost();
	void setisTapped(bool);
	bool getisTapped();

};

class BlackCard : public Card {

protected:
	bool isRevealed;

public:

	void setisRevealed(bool);
	bool getisRevealed();

};

class GreenCard : public Card {

protected:
	int attackBonus;
	int defenceBonus;
	int minimumHonour;
	std::string cardText;
	int effectBonus;
	int effectCost;

public:
	void setattackBonus(int);
	int getattackBonus();
	void setdefenceBonus(int);
	int getdefenceBonus();
	void setminimumHonour(int);
	int getminimumHonour();
	void setcardText(std::string);
	std::string getcardText();
	void seteffectBonus(int);
	int geteffectBonus();
	void seteffectCost(int);
	int geteffectCost();

};

#endif
