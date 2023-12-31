#include "carta.h"
#include <time.h>
#include <conio.h>
#include <stdlib.h>

carta::Carta() {
    srand(time(0));
}

void carta::takeCards(int& playerSum, int& dealerSum) {

    srand(time(0));
    int playerCardNumber = rand() % 11;
    int dealerCardNumber = rand() % 11;
    int playerCardSymbol = rand() % 4;
    int dealerCardSymbol = rand() % 4;

    playerSum = playerSum + playerCardNumber;
    dealerSum = dealerSum + dealerCardNumber;

    //////CARDS///////////
    // if the random number is 0 or 1, the card is a letter card
    if (playerCardNumber == 0 || playerCardNumber == 1) {

        playerSum = playerSum + 10;
        cout << "You: " << letter[playerCardSymbol] << symbol[playerCardSymbol] << " - " << playerSum << " points";
    }

    // Regular numbers
    if (1 < playerCardNumber && playerCardNumber <= 10) {

        cout << "You: " << playerCardNumber << symbol[playerCardSymbol] << " - " << playerSum << " points";
    }

    // Regular numbers
    if (1 < dealerCardNumber && dealerCardNumber <= 10) {

        cout << "\nDealer: " << dealerCardNumber << symbol[dealerCardSymbol] << " - " << dealerSum << " points";
    }

    // if the random number is 0 or 1, the card is a letter card
    if (dealerCardNumber == 0 || dealerCardNumber == 1) {

        dealerSum = dealerSum + 10;
        cout << "\nDealer: " << letter[dealerCardSymbol] << symbol[dealerCardSymbol] << " - " << dealerSum << " points";
    }
}

void carta::showResult(int& playerSum, int& dealerSum, int& money, char& key, bool& isFinished) {

    ////////RESULTS////////
    // 21 points PLAYER
    if (playerSum == 21) {

        cout << "\n\nYou have 21 points,  you win!!";
        playerWins(money, playerSum);
        cout << "\nPress E to continue or X to abandon";
        key = getch();
        isFinished = true;
    }

    // over 21 points PLAYER
    else if (playerSum > 21) {

        cout << "\n\nYou have over 21 points, you lose!!";
        playerLoses(money, playerSum);
        cout << "\nPress E to continue or X to abandon";
        key = getch();
        isFinished = true;
    }

    // 21 points DEALER
    else if (dealerSum == 21) {

        cout << "\n\nThe dealer has 21 points, the dealer wins!!";
        playerLoses(money, playerSum);
        cout << "\nPress E to continue or X to abandon";
        key = getch();
        isFinished = true;
    }

    // over 21 points DEALER
    else if (dealerSum > 21) {

        cout << "\n\nThe dealer has over 21 points, you win!!";
        playerWins(money, playerSum);
        cout << "\nPress E to continue or X to abandon";
        key = getch();
        isFinished = true;
    }

    else if(playerSum == 21 && dealerSum == 21){

        cout << "\n\nIt's a tie!" << endl << "Press E to continue or X to abandon";
        key = getch();
        isFinished = true;
    }

    // After picking up a card
    else {

        cout << "\n\nPress E to play again or X to abandon\n\n";
        key = getch();

        while(key != 'e'){
            if (key == 'x') {
                if (dealerSum > playerSum) {

                    cout << "\nThe dealer has more points, you lose";
                    playerLoses(money, playerSum);
                    cout << "You go away with " << money << "$\n";
                    return;
                }
                else if (dealerSum == playerSum) {

                    cout << "\nTie! you cant abandon" << endl << "Press E to keep playing" << endl;
                    key = getch();
                }
                else {

                    cout << "\nYou have more points than the dealer, you win!" << endl;
                    playerWins(money, playerSum);
                    cout << "You go away with " << money << "$\n";
                    return;
                }
            }
            else {
                    cout << "Please enter a valid key\n\n";
                    key = getch();
            }
        }
    }
}

