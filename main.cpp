/*
 * This program simumlates a craps game
 * @author arivera
 * @version 1.0
 * @since 28/01/2020
*/
#include <iostream>
#include "Craps.h"

using namespace std;

int main()
{
    srand((unsigned)time(0));

    int roll1, roll2, finalRollValue;
    int bank;
    int bet = 0;
    bool active = true;
    char choice;

    cout << "Welcome to the CRAPS game.\n" << endl;

    if(play() == true){
        retrieveSatus(bank);
    }
    else {
        bank = 100;
    }

    while(active){

        cout << "\nYou have $" << bank <<".\tDo you want to roll (y/n/s)?" << endl;
        cin >> choice;

        if(choice == 'y'){
            cout << "How much do you want to bet?" << endl;
            cin >> bet;
            if(bet > bank){
                cout << "\nYour bet can't exceed the amount in your bank.\n" << endl;
            }
            else{
                roll(roll1);
                roll(roll2);

                finalRollValue = roll1 + roll2;

                cout << "You rolled a " << roll1 << " and a " << roll2;
                cout << "\tYour total is " << finalRollValue << ".";

                // Check if the user won or loss and adjust their bank balance accordingly
                winLoss(finalRollValue, bank, bet);

                // If the player runs out of funds then the game ends.
                active = status(bank);
            }
        }
        else if(choice == 'n'){
            cout << "\nThank you for playing." << endl;
            exit(0);
        }
        else if(choice == 's'){
            saveStatus(bank);
        }
        else {
            cout << "Input not recognized." << endl;
        }
    }
    return 0;
}
/*
 *This program works as intended.
*/
