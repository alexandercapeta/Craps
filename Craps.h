/*
 * This program simumlates a craps game
 * @author arivera
 * @version 1.0
 * @since 28/01/2020
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctype.h>
#include <ctime>

using namespace std;

#ifndef CRAPSGAME_H
#define CRAPSGAME_H

bool play(){
    char response;

    cout << "Do you want to load a previous session? (y/n)" << endl;
    cin >> response;

    switch(tolower(response)){
        case 'y':
            return true;
            break;
        case 'n':
            return false;
            break;
    }
} // end of play()


void saveStatus(int &bank){
    ofstream file;
    file.open("./externals/balance.txt");
    file << bank;
    file.close();
} // end of SaveStatus()


void retrieveSatus(int &bank){
    ifstream in("./externals/balance.txt");

    if(!in){
        cout << "Sorry, no saved file exists on this computer." << endl;
		bank = 100;
    }
    else {
       in >> bank;
    }
    in.close();
} // end of retrieveStatus


// roll each dice
void roll(int &value){

    value = rand() % 6 + 1;
} // end of roll()


// Determine if the user loss or won. And adjust the bank accordingly
void winLoss(int finalValue, int &bank, int &bet){
    if(finalValue == 7 || finalValue == 11){
        bank = bank + bet;
        cout << "\tYou WIN!" << endl;
    }
    else if(finalValue == 2 || finalValue == 3 || finalValue == 12){
        bank = bank - bet;
        cout << "\tYou LOSE!" << endl;
    }
} // end of winLoss()


//Checks if there's still money in player's bank.
bool status(int &bank){
    if(bank == 0){
        cout << "\nLooks like you're out of money mate.\nLATER!!" << endl;
        return false;
    }
    else
        return true;
} // end of status()

#endif // CRAPSGAME_H

/*
 *
*/

