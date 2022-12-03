#pragma once
#ifndef LONGBOARDER_H
#define LONGBOARDER_H

#include "Skater.h"

class LongBoarder : public Skater {
private:
    //bool sadness = false;

public:
    LongBoarder();
    int attack() const;
    int defend() const;

    //bool getSadness() { return sadness; }
    void printStats() const override{ cout << "LONGBOARDER" << endl; /*cout << "sadness: " << sadness << endl;*/ Skater::printStats(); }
    void printFigure() const override;

    void skaterSpecial() override {
        if (special == 1) {
            speed += 3;
            cout << name << " GAINED 3 SPEED" << endl;
            special--;
        }
        else {
            cout << "NO SPECIAL AVAILABLE! " << "TURN USED." << endl;
        }
    }
};

LongBoarder::LongBoarder() : Skater() {
    //sadness = 0;
    heart += 1;
    energy += 1;
    speed -= 1;
}

int LongBoarder::attack() const {
    return 3;
}
int LongBoarder::defend() const {
    return 3;
}

void LongBoarder::printFigure() const {
    cout << R"(
                ##&&&&&#                          
               &&&,,/,,/    ,                     
                ,,,,,,,,    &,,                   
               &&&#&&#&#%&###&                    
             &#&########%&                        
           &##&#&&#####&.                         
          ,,      &#####%& %%%%.,*#               
                  ####&%%%%%%%**,*#               
                    %%%                           
                    %%%                           
                   %%%                            
                  **.                             
               @&@@@@@@@&@@@@@**. 
)";
}

#endif