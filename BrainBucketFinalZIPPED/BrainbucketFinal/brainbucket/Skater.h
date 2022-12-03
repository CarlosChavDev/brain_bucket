#pragma once
#ifndef SKATER_H
#define SKATER_H

#include <iostream>
using namespace std;

class Skater {
protected:
	string name; //name
	int heart; //stats
	int energy;
	int speed;
	int special = 1; //one special stat boosts
	bool choseDefend = false; //bool for negation of attack

public:
	Skater();
	//Skater(string name) { this->name = name; }//not really being used
	virtual int attack() const = 0;
	virtual int defend() const = 0;

	int getHeart() { return heart; }
	int getEnergy() { return energy; }
	int getSpeed() { return speed; }
	string getName() { return name; }
	void setName(string name) { this->name = name; }

	void ChoseDefend() { choseDefend = true; }
	void recieveAttack(int attack);

	
	void pickItem();
	void printBattleMenu() const;


	virtual void printStats() const;
	virtual void printFigure() const = 0;
	virtual void skaterSpecial() = 0; //special for boosting stats

};

Skater::Skater() {   // not being used
	name = "unknown";
	heart = 5; energy = 5; speed = 5;
}

void Skater::printStats() const {
	cout << "heart: " << heart << endl;
	cout << "energy: " << energy << endl;
	cout << "speed: " << speed << endl;
	cout << "attack: " << attack() << endl;
	cout << "defense: " << defend() << endl;
}

void Skater::printBattleMenu() const{
	cout << R"(
	A: ATTACK	I: ITEM
	D: DEFEND	S: SPECIAL
)";
	cout << "YOU HAVE " << special << " SPECIAL(S) LEFT |||" << " YOU HAVE " << energy << " ENERGY FOR ITEMS LEFT" << endl;
}

void Skater::recieveAttack(int attack) {
	if (choseDefend == true) {
		if ((attack - defend()) < 0)
		{
			cout << name << " LOST NO HEART " << endl;
			return;
		}
		attack -= defend();
	}
	heart -= attack;
	cout << name << " LOST " << attack << " HEART" << endl;
	choseDefend = false; //reset defense choice
};

void Skater::pickItem() {
	if (energy >= 2) {
		cout << "1: KICKFLIP: +3 HEART -3 ENERGY" << endl;
		cout << "2: OLLIE: +2 SPEED -2 ENERGY" << endl;
		int pick;
		if (name == "~DAN") { //CPU SKATER
			srand(time(NULL)); pick = (rand() % 2) + 1; //if bot--> pick random item
		}
		else {
			cin >> pick;
		}
		switch (pick) {
		case 1:
			cout << name << " KICKFLIPPED! " << endl;
			heart += 3; energy -= 3;
			break;
		case 2:
			cout << name << " DID AN OLLIE! " << endl;
			speed += 2; energy -= 2;
			break;
		default:
			cout << name << " 1 OR 2 NOT PICKED! NO ENERGY SPENT. TURN USED! " << endl;
		}
	}
	else {
		cout << "NOT ENOUGH ENERGY. TURN USED!" << endl;
	}
}

#endif
