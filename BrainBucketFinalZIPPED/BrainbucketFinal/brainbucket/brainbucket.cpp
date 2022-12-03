// brainbucket.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include "Cruiser.h"
#include "LongBoarder.h"
#include "Popsicle.h"
using namespace std;

void selectCharacter(int select, Skater*& mySkater);
void printMenu();

void loadOrNew(Skater*& mySkater);
void newCpuSkater(Skater*& cpuSkater);


//void whosFaster(Skater*& Skater1, Skater*& Skater 2);
void pickAction(Skater*& Skater1, char select, Skater*& Skater2);
char generateCpuSelect();

void intervalStats(Skater*& Skater1) {
    cout << Skater1->getName(); cout << endl;
    Skater1->printFigure();
    Skater1->printStats();
}
void intervalPrint(int interval);
void battleVs();
void hasWon();

int main()
{
    printMenu();
    Skater* mySkater = nullptr; // declare pointer
    loadOrNew(mySkater);
    cout << endl;
    battleVs();
    Skater* cpuSkater = nullptr;
    newCpuSkater(cpuSkater);
    //two loaded players done ---> try game battle simple



    char select;
    int interval = 1;
    //battle start
    while (mySkater->getHeart() > 0 && cpuSkater->getHeart() > 0) {
        intervalPrint(interval);
        if (mySkater->getSpeed() > cpuSkater->getSpeed()) //Character first
        {
            cout << mySkater->getName() << " IS FASTER. " << mySkater->getName() << " GOES FIRST" << endl;
            mySkater->printBattleMenu(); //display options
            cin >> select;
            pickAction(mySkater, select, cpuSkater);


            select = generateCpuSelect();
            pickAction(cpuSkater, select, mySkater);
        }
        else if (mySkater->getSpeed() < cpuSkater->getSpeed()) { //CPU first
            cout << cpuSkater->getName() << " IS FASTER. " << cpuSkater->getName() << " GOES FIRST" << endl;
            select = generateCpuSelect();
            pickAction(cpuSkater, select, mySkater);

            mySkater->printBattleMenu(); //display options
            cin >> select;
            pickAction(mySkater, select, cpuSkater);
        }
        else {
            cout << "SAME SPEED! " << "SKATERS RACE TILL LAST BREATH..." << endl;
            srand(time(NULL)); int ran = (rand() % 2) + 1;
            switch (ran) {
            case 1:
                cout << mySkater->getName() << " IS FASTER. " << mySkater->getName() << " GOES FIRST" << endl;
                mySkater->printBattleMenu(); //display options
                cin >> select;
                pickAction(mySkater, select, cpuSkater);


                select = generateCpuSelect();
                pickAction(cpuSkater, select, mySkater);
                break;
            case 2:
                cout << cpuSkater->getName() << " IS FASTER. " << cpuSkater->getName() << " GOES FIRST" << endl;
                select = generateCpuSelect();
                pickAction(cpuSkater, select, mySkater);

                mySkater->printBattleMenu(); //display options
                cin >> select;
                pickAction(mySkater, select, cpuSkater);
                break;
            }
            
        }
        //display interval stats
        cout << endl;
        intervalStats(mySkater); cout << endl; intervalStats(cpuSkater);
        interval++;
    }
    //battle end

    cout << endl;
    //show winner
    if (mySkater->getHeart() <= 0) {
        cout << cpuSkater->getName() << " "; hasWon();
    }
    else {
        cout << mySkater->getName() << " "; hasWon();
    }

    delete mySkater; delete cpuSkater;

    return 0;
}

void printMenu() {
    cout << R"(
 ______     ______     ______     __     __   __        ______     __  __     ______     __  __     ______     ______  
/\  == \   /\  == \   /\  __ \   /\ \   /\ "-.\ \      /\  == \   /\ \/\ \   /\  ___\   /\ \/ /    /\  ___\   /\__  _\ 
\ \  __<   \ \  __<   \ \  __ \  \ \ \  \ \ \-.  \     \ \  __<   \ \ \_\ \  \ \ \____  \ \  _"-.  \ \  __\   \/_/\ \/ 
 \ \_____\  \ \_\ \_\  \ \_\ \_\  \ \_\  \ \_\\"\_\     \ \_____\  \ \_____\  \ \_____\  \ \_\ \_\  \ \_____\    \ \_\ 
  \/_____/   \/_/ /_/   \/_/\/_/   \/_/   \/_/ \/_/      \/_____/   \/_____/   \/_____/   \/_/\/_/   \/_____/     \/_/                                                         
                                  .%///////////                                 
                            *%%%%%%/////////////////                            
                         %%%%%%%%%/////////////////////                         
                       %%%%%%%%%%////////////////%(///%//                       
                      %%%%%%%%//////////////////%%%(//////                      
                     //////////////////////////////////////                     
                     ///////////////////////////////////////                    
                     //////////////////////////%%%%%%%%%##                      
                     /////////////////(#%%%%%%%%    ((                          
                      //////##%%%####%%%%%%%%##     ((                          
                       ////###%%#(((  .######((    ,(.                          
                        //####    ((           ((((((                           
                          ##((    ((                 /                          
                              (((((((              ((.                          
                                   *((             (((                          
                                    *((            (((                          
                                      ((           .((     
 ______  __  __  ______  ______  ______  ______  ______ ______  ______     
/\  ___\/\ \_\ \/\  __ \/\  == \/\  __ \/\  ___\/\__  _/\  ___\/\  == \    
\ \ \___\ \  __ \ \  __ \ \  __<\ \  __ \ \ \___\/_/\ \\ \  __\\ \  __<    
 \ \_____\ \_\ \_\ \_\ \_\ \_\ \_\ \_\ \_\ \_____\ \ \_\\ \_____\ \_\ \_\  
  \/_____/\/_/\/_/\/_/\/_/\/_/ /_/\/_/\/_/\/_____/  \/_/ \/_____/\/_/ /_/  
                                                                           
   __      ______  ______  _____      
  /\ \    /\  __ \/\  __ \/\  __-.    
  \ \ \___\ \ \/\ \ \  __ \ \ \/\ \   
   \ \_____\ \_____\ \_\ \_\ \____-   
    \/_____/\/_____/\/_/\/_/\/____/   
                                                                           
     __   __  ______  __     __        
    /\ "-.\ \/\  ___\/\ \  _ \ \       
    \ \ \-.  \ \  __\\ \ \/ ".\ \      
     \ \_\\"\_\ \_____\ \__/".~\_\     
      \/_/ \/_/\/_____/\/_/   \/_/                                                                                                                                         
	)" << '\n';
}

void intervalPrint(int interval) {
    cout << R"(
                     __  __   __  ______  ______  ______  __   ________  __        
                    /\ \/\ "-.\ \/\__  _\/\  ___\/\  == \/\ \ / /\  __ \/\ \       
                    \ \ \ \ \-.  \/_/\ \/\ \  __\\ \  __<\ \ \'/\ \  __ \ \ \____  
                     \ \_\ \_\\"\_\ \ \_\ \ \_____\ \_\ \_\ \__| \ \_\ \_\ \_____\ 
                      \/_/\/_/ \/_/  \/_/  \/_____/\/_/ /_/\/_/   \/_/\/_/\/_____/ 
                                                               
)"; cout << interval << endl;
}
void battleVs() {
    cout << R"(
 ______  __   __  ______  ______  ______  __  __   __  ______       ______  ______  ______  ______  __      ______       __   ________    
/\  ___\/\ "-.\ \/\__  _\/\  ___\/\  == \/\ \/\ "-.\ \/\  ___\     /\  == \/\  __ \/\__  _\/\__  _\/\ \    /\  ___\     /\ \ / /\  ___\   
\ \  __\\ \ \-.  \/_/\ \/\ \  __\\ \  __<\ \ \ \ \-.  \ \ \__ \    \ \  __<\ \  __ \/_/\ \/\/_/\ \/\ \ \___\ \  __\     \ \ \'/\ \___  \  
 \ \_____\ \_\\"\_\ \ \_\ \ \_____\ \_\ \_\ \_\ \_\\"\_\ \_____\    \ \_____\ \_\ \_\ \ \_\   \ \_\ \ \_____\ \_____\    \ \__| \/\_____\ 
  \/_____/\/_/ \/_/  \/_/  \/_____/\/_/ /_/\/_/\/_/ \/_/\/_____/     \/_____/\/_/\/_/  \/_/    \/_/  \/_____/\/_____/     \/_/   \/_____/ 
                                                                                                                                          

)";
}
void hasWon() {
    cout << R"(
 __  __  ______  ______       __     __  ______  __   __    
/\ \_\ \/\  __ \/\  ___\     /\ \  _ \ \/\  __ \/\ "-.\ \   
\ \  __ \ \  __ \ \___  \    \ \ \/ ".\ \ \ \/\ \ \ \-.  \  
 \ \_\ \_\ \_\ \_\/\_____\    \ \__/".~\_\ \_____\ \_\\"\_\ 
  \/_/\/_/\/_/\/_/\/_____/     \/_/   \/_/\/_____/\/_/ \/_/ 
)";
}


void selectCharacter(int select, Skater*& mySkater) {
    switch (select) {
    case 1: {
        mySkater = new Cruiser;
        break;}
    case 2: {
        mySkater = new Popsicle;
        break;}
    case 3: {
        mySkater = new LongBoarder;
        break;}
    default: {
        cout << "Uh oh. Incorrect input. Exiting game." << endl;
        exit(0);
    }
    }

}

void loadOrNew(Skater*& mySkater) {
    //create or load character start
    string fileName, key, characterName;
    const int SIZE = 3;
    int select;
    cin >> key;

    //load character
    if (key == "load" || key == "LOAD")
    {
        fileName = "Player.txt";
        ifstream fin(fileName);
        if (!fin.is_open()) { //Check if file exists... always does
            cout << "FILE NOT FOUND: EXITING" << endl;
            exit;
        }
        else { //load character
            getline(fin, characterName);
            fin >> select; selectCharacter(select, mySkater); mySkater->setName(characterName);
            cout << "Character Name: " << mySkater->getName() << endl;
            mySkater->printFigure();
            mySkater->printStats();
        }
    }

    //new character
    else if (key == "NEW" || key == "new") {
        ofstream fout("Player.txt");//ofstream to Player
        cout << "ENTER CHARACTER NAME" << endl; cin >> characterName;

        //display skaters
        cout << endl; cout << "ENTER " << characterName << "'s SKATER TYPE" << endl;
        Skater* mySkaters[SIZE];
        mySkaters[0] = new Cruiser; mySkaters[1] = new Popsicle; mySkaters[2] = new LongBoarder;
        for (int i = 0;i < SIZE; i++) {
            cout << i + 1 << ": ";
            mySkaters[i]->printStats();
            delete mySkaters[i];
            cout << endl;
        }

        //select skater
        cin >> select; selectCharacter(select, mySkater); mySkater->setName(characterName);
        cout << "Character Name: " << mySkater->getName() << endl;
        mySkater->printFigure();
        mySkater->printStats();
        //save variables into file
        fout << characterName; fout << endl; fout << select;
    }
    else {
        cout << "LOAD OR NEW not found. EXITING GAME"; exit(0);
    }
}

void newCpuSkater(Skater*& cpuSkater) {
    int select;
    srand(time(NULL)); //set random based on time
    select = (rand() % 3) + 1; // 1-3
    selectCharacter(select, cpuSkater);

    //save bot
    ofstream fout("CPU.txt");
    fout << "~DAN"; fout << endl; fout << select;
    cpuSkater->setName("~DAN");

    //display bot
    cout << "Character Name: " << cpuSkater->getName(); cout << endl;
    cpuSkater->printFigure();
    cpuSkater->printStats();
}


// whosFaster(Skater*& Skater1, Skater*& Skater 2) {

//}
void pickAction(Skater*& Skater1, char select, Skater*& Skater2)
{
    switch (select) {
    case 'A':
        cout << Skater1->getName() << " CHOSE ATTACK!" << endl;
        Skater2->recieveAttack(Skater1->attack());
        break;
    case 'D':
        cout << Skater1->getName() << " CHOSE DEFEND." << endl;
        Skater1->ChoseDefend();
        break;
    case 'S':
        cout << Skater1->getName() << " CHOOSES SPECIAL ABILITY!" << endl;
        Skater1->skaterSpecial();
        break;
    case 'I':
        cout << Skater1->getName() << " CHOOSES ITEM..." << endl;
        Skater1->pickItem();
        break;
    default:
        cout << "exiting from battle menu" << endl;
        exit(0);
    }

}

char generateCpuSelect() {
    srand(time(NULL)); //set random based on time
    int ranArray[3] = { 'A','D','S' }; /*A or D*/
    return ranArray[(rand() % 3)];  //A-D-S //predefined char 
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
