#pragma once
#ifndef POPSICLE_H
#define POPSICLE_H

#include "Skater.h"
#include <iostream>
#include <string>
using namespace std;

class Popsicle : public Skater {
private:
    //bool anger = false;

public:
    Popsicle();
    int attack() const;
    int defend() const;

    //int getAnger() { return anger; }
    void printStats() const override{ cout << "POPSICLE" << endl; /*cout << "anger: " << anger << endl;*/ Skater::printStats(); }
    void printFigure() const override;

    void skaterSpecial() override {
        if (special == 1) {
            energy += 3;
            cout << name << " GAINED 3 ENERGY" << endl;
            special--;
        }
        else {
            cout << "NO SPECIAL AVAILABLE! " << "TURN USED." << endl;
        }
    }
};

Popsicle::Popsicle() : Skater() {
    //anger = 0;
    heart += 1;
    speed += 1;
    energy -= 1;
}

int Popsicle::attack() const {
    return 3;
}

int Popsicle::defend() const {
    return 3;
}
void Popsicle::printFigure() const {
    cout << R"(
             @@@             
           @.,(,,.@           
          &,@@@%@%%#,         
             @.%@@//((@(@     
          %@.@///@@@(((@(,    
      @..@,      @////((@     
             @ @((((((,((,    
          @(@@@(((((@@@@(,    
   @ %@(@(((@@ @,((((@        
     @**@      #@((     *.    
          @%*@((((@...**   **.
     ,*..   *..(%*@...  .,*   
**..  ....          @@... . 
)";
}




#endif 