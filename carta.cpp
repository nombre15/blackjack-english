#include "carta.h"
#include <time.h>
#include <conio.h>
#include <stdlib.h>

carta::Carta() {
}

/**
 * @brief Function to take a card in a turn.
 *
 * This function generates random numbers to simulate a real card with its symbol and numerical value or letter.
 * It generates one card for the player and another one for the dealer.
 *
 * @param playerSum Total points of the player based on the cards taken, it updates on every call of this function.
 * @param dealerSum Total points of the dealer based on the cards taken, it updates on every call of this function.
*/
void carta::takeCards(int& playerSum, int& dealerSum) {

    srand(time(0)); // Generates a new seed of random numbers for every iteration of the loop
    int playerNum = rand() % 11; // Random number between 0 and 10
    int dealerNum = rand() % 11;
    int playerSymbol = rand() % 4; // Random number between 0 and 3
    int dealerSymbol = rand() % 4;

    //////CARDS///////////

    // "letter[dealerSymbol]" and "symbol[playerSymbol]" are different so the letter and the symbol wont always be the same as a couple //

    // if the number is 0 or 1, then the card will be a letter card (A, Q, K, J)
    if (playerNum == 0 || playerNum == 1) {

        playerSum = playerSum + 10; // The amount of points of a letter is 10, it is added to the sum
        cout << "You: " << letter[dealerSymbol] << symbol[playerSymbol] << " - " << playerSum << " points";
    }

    // Regular numbers, else if is used since only one of them can be true at a time
    else if (1 < playerNum && playerNum <= 10) {

        playerSum = playerSum + playerNum;
        cout << "You: " << playerNum << symbol[playerSymbol] << " - " << playerSum << " points";
    }

    // if the number is 0 or 1, then the card will be a letter card (A, Q, K, J)
    if (dealerNum == 0 || dealerNum == 1) {

        dealerSum = dealerSum + 10; // The amount of points of a letter is 10, it is added to the sum
        cout << "\nDealer: " << letter[playerSymbol] << symbol[dealerSymbol] << " - " << dealerSum << " points";
    }

    // Regular numbers, else if is used since only one of them can be true at a time
    else if (1 < dealerNum && dealerNum <= 10) {

        dealerSum = dealerSum + dealerNum;
        cout << "\nDealer: " << dealerNum << symbol[dealerSymbol] << " - " << dealerSum << " points";
    }
}

/** @brief Shows the result after each turn
 *
 * Shows the final result of the game if it has finished
 * If the game has not finished, it shows the result of the turn
 *
 * @param playerSum Total points of the player based of the taken cards
 * @param dealerSum Total points of the dealer based of the taken cards
 * @param money Amount of money in play
 * @param key Pressed key to repeat or abandon the game
 * @param isFinished Bool used to know if the game has finished
*/

void carta::showResult(int playerSum, int dealerSum, int& money, char& key, bool& isFinished) {

    ////////RESULTS////////

    // 21 points PLAYER
    if (playerSum == 21) {

        cout << "\n\nYou have 21 points,  Winner!!";
        playerWins(money);
        cout << "\nPress E to continue or X to abandon";
        key = getch();
        isFinished = true;
    }

    // over 21 points PLAYER
    else if (playerSum > 21) {

        cout << "\n\nYou have over 21 points, you lose!";
        playerLoses(money);
        cout << "\nPress E to continue or X to abandon";
        key = getch();
        isFinished = true;
    }

    // 21 points DEALER
    else if (dealerSum == 21) {

        cout << "\n\nThe dealer has 21 points, the dealer wins!";
        playerLoses(money);
        cout << "\nPress E to continue or X to abandon";
        key = getch();
        isFinished = true;
    }

    // over 21 points DEALER
    else if (dealerSum > 21) {

        cout << "\n\nThe dealer has over 21 points, you win!";
        playerWins(money);
        cout << "\nPress E to continue or X to abandon";
        key = getch();
        isFinished = true;
    }

    // End of a turn
    else {

        cout << "\n\nPress E to play again or X to abandon\n\n";
        key = getch();

        while(key != 'e'){
            if (key == 'x') {
                if (dealerSum > playerSum) {

                    cout << "\nThe dealer has more points, you lose";
                    playerLoses(money);
                    cout << "You go away with" << money << "$\n";
                    return;
                }
                else if (dealerSum == playerSum) {

                    cout << "\nTie!, you cant abandon" << endl << "Press E to keep playing" << endl;
                    key = getch();
                }
                else {

                    cout << "\nYou have more points than the dealer, you win!" << endl;
                    playerWins(money);
                    return;
                }
            }
            else {
                    cout << "Press enter a valid key\n\n";
                    key = getch();
            }
        }
    }
}

