#pragma once
#ifndef CRUISER_H
#define CRUISER_H

#include "Skater.h"

class Cruiser : public Skater {
private:
    //bool happiness = false; 

public:
    Cruiser();
    int attack() const;
    int defend() const;

    //bool getHappiness() { return happiness; }
    void printStats() const override{ cout << "CRUISER" << endl; /*cout << "happiness: " << happiness << endl;*/ Skater::printStats(); }
    void printFigure() const override;

    void skaterSpecial() override {
        if (special == 1) {
            heart += 3;
            cout << name << " GAINED 3 HEART" << endl;
            special--;
        }
        else {
            cout << "NO SPECIAL AVAILABLE! " << "TURN USED." << endl;
        }
    }
};

Cruiser::Cruiser() : Skater() {
    energy += 1;
    heart -= 1;
    speed += 1;
    //happiness = 0;
}

int Cruiser::attack() const {
    return 3;
}
int Cruiser::defend() const {
    return 3;
}

void Cruiser::printFigure() const {
    cout << R"(
                 @@                
                    @/##             
                    @*@              
                  @(((#@             
                  @#((#@             
                @,,,.#((((/(@        
             @,,,,,,,**@####@*,//#   
          *,,,*/@/,,,*/@       @##   
        &,,@...##.@**@               
       @@&#,.....,,@*                
      @@@@,###&@,,#**                
    @*(((@&(**@%@@,,@                
     @,//@@(((((/(((#**@@@@          
      @@       @@#((@//@             
                 /@@@                
)";
}


#endif
