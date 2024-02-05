#include "players.h"
#include "carta.h"
#include <conio.h>
#include <windows.h>

players::players(){

    SetConsoleTitle("Blackjack");
}

int players::play(){

    char key;

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

        validateMoney(money);

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

void players::playerWins(int& money){

    money = money + (money * 0.5);
    cout << "\nNow you have " << money << "$\n" << endl;
}

void players::playerLoses(int& money) {

    cout << "\nYou lose it all!" << endl;
    money = 0;
}

void validateMoney(int& money){

    system("cls");
    cout << "Enter a valid amount of money\n" << endl;
    cin.clear();
    cin.ignore(256,'\n');
    cout << "$";
    cin >> money;
}

int players::enterKey(char key, int money){

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

