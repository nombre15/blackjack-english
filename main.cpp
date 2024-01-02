#include <iostream>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include "carta.h"
using namespace std;

void playerWins(int& money);
void playerLoses(int& money);
int enterKey(char key, int money);

int main(){

    char key;
    SetConsoleTitle("Blackjack");

    // Beginning of the game
    do{

        system("cls");
        int playerSum = 0;
        int dealerSum = 0;
        int money = 0;
        bool isFinished = false;
        carta blackjack;

        cout << "Enter the amount of money you will bet"  << endl;
        cin >> money;

        while(cin.fail()) {

            cout << "Enter a valid number" << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cin >> money;
        }

        cout << "\n";

        // Take cards every round
        do{

            system("cls");

            // If its not finished yet, play a round
            if(!isFinished){

                blackjack.takeCards(playerSum, dealerSum);
                blackjack.showResult(playerSum, dealerSum, money, key, isFinished);
            }

            // If the game has finished
            else{

                cout << "Your balance is $" << money << endl;
                cout << "\nPress E to play again or X to abandon\n\n";

                key = getch();
                enterKey(key, money);
                break;
            }

            if(key == 'x'){

                system("cls");
                cout << "You go away with $" << money << endl << endl;
                return 0;
            }

            while(key != 'e'){

                cout << "\n\nPlease enter a valid key\n\n";
                key = getch();
            }
        }while(key == 'e');
    }while(key == 'e');
}

/** The player has won the game
 *
 * @param money Amount of money that will be increased
*/
void playerWins(int& money) {

    money = money + (money * 0.5);
    cout << "\nNow you have " << money << "$\n" << endl;
}

/** The player has lost the game
 *
 * @param money Amount of money that will be changed to 0, poor player :(
*/
void playerLoses(int& money) {

    cout << "\nYou lose it all!" << endl;
    money = 0;
}

/** Function to enter a key
 *
 * @param key Value of the entered key
 * @param money Amount of money that will be output if the player abandons
*/
int enterKey(char key, int money){

    while(key != 'e'){
        if(key == 'x'){

            system("cls");
            cout << "You go away with $" << money << "\n";
            return 0;
        }

        else{

            cout << "\nPlease enter a valid key\n\n";
            key = getch();
        }
    }

    // Intentional no return, as the function should never get here and there is no real value to return anyway
}
