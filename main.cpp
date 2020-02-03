/*
 * This program simumlates a craps game
 * @author arivera
 * @version 1.0
 * @since 28/01/2020
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void roll(int&);
void winLoss(int, int&, int&);
bool status(int&);


int main()
{
    int roll3, roll4, finalRollValue;
    int bank = 100;
    int bet = 0;
    bool active = true;
    char choice;

    cout << "Welcome to the CRAPS game.\n" << endl;

    while(active){
        cout << "\nYou have $" << bank <<".\tDo you want to roll (y/n)?" << endl;
        cin >> choice;

        if(choice == 'y'){
            cout << "How much do you want to bet?" << endl;
            cin >> bet;
            if(bet > bank){
                cout << "\nYour bet can't exceed the amount in your bank.\n" << endl;
            }
            else{
                roll(roll3);
                roll(roll4);

                finalRollValue = roll3 + roll4;

                cout << "You rolled a " << roll3 << " and a " << roll4;
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
        else {
            cout << "Input not recognized." << endl;
        }
    }
    return 0;
}

// roll each dice
void roll(int &value){
    srand((unsigned)time(0));
    value = rand() % 6 + 1;
}

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
}

//Checks if there's still money in player's bank.
bool status(int &bank){
    if(bank == 0){
        cout << "\nLooks like you're out of money mate.\nLATER!!" << endl;
        return false;
    }
}

/*
 *This program works as intended.
*/
