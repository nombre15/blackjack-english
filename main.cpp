#include <iostream>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include "carta.h"
using namespace std;

void playerWins(int& money, int& playerSum);
void playerLoses(int& money, int& playerSum);
int enterKey(char key, int money);

int main(){


    char key;
    //Game starts
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

        //Take cards
        do{

            system("cls");

            if(!isFinished){

                blackjack.takeCards(playerSum, dealerSum);
                blackjack.showResult(playerSum, dealerSum, money, key, isFinished);
            }

            else{

                cout << "Your balance is $" << money << endl;
                cout << "\nPress E to play again or X to abandon the game\n\n";

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

void playerWins(int& money, int& playerSum) {

    money = money + (money * 0.5);
    cout << "\nNow you have " << money << "$\n" << endl;
    playerSum = 0;
}

void playerLoses(int& money, int& playerSum) {

    cout << "\nYou lose it all!" << endl;
    money = 0;
    playerSum = 0;
}

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
}
