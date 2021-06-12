#include <iostream>
#include <time.h>
#include <string>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
using namespace std;

int main()
{

    SetConsoleTitle("Blackjack");

    repetir:
    int sum = 0;
    int dealerSum = 0;
    int key;
    int money;
    string character[4] {"A", "J", "Q", "K"};
    string simbol[4] {" diamonds", " hearts", " clover", " spades"};

    cout << "Type the amount of money you will be using"  << endl;
    cin >> money;
    cout << "\n";

    blackjack:

    srand(time(0));
    int number = rand() % 11;
    int dealerNumber = rand() % 11;
    int random = rand() % 4;
    int dealerRandom = rand() % 4;
    sum = sum + number;
    dealerSum = dealerSum + dealerNumber;

    //results
    if(sum == 21) {


        _cputs("21 cards,  Winner!! \n\nPress E to play again or X to leave\n\n");

        key = getch();

        if(key == 'e'){

            cout << "You have "  << money << "$\n" << endl;
            goto repetir;
        }

        else if(key == 'x'){

            cout << "You have "  << money << "$" << endl;
            return 0;
        }
     }

     if(sum > 21){

        sum = 0;
        _cputs("You have over 21 points, loser!\n\nPress E to play again or X to leave\n\n");

        key = getch();

        if(key == 'e'){

            goto repetir;
        }

        else if(key == 'x'){

            money = 0;
            cout << "\nYou lose it all! \nNow you have " << money << "$" << endl;
            return 0;
        }
     }

     if(dealerSum == 21) {

        money = 0;
        cout << "\nYou lose it all! \nNow you have " << money << "$" << endl;
        _cputs("Dealer has 21 points, dealer wins!\nPress E to play again or X to leave\n\n");

        key = getch();

        if(key == 'e'){

            goto repetir;
        }

        else if(key == 'x'){

            cout << "You have "  << money << "$" << endl;
            return 0;
        }
     }

     if(dealerSum > 21){

        sum = 0;
        _cputs("Winner!, dealer has over 21 points\n\nPress E to play again or X to leave\n\n");

        key = getch();

        if(key == 'e'){

            goto repetir;
        }

        else if(key == 'x'){

            money = 0;
            cout << "\nYou lose it all! \nNow you have " << money << "$" << endl;
            return 0;
        }
     }

    //Zero for using characters
    if(number == 0){

      cout << character[random] << simbol[random];

       sum = sum + 10;

       cout << " You: got" << sum << " points";
    }

    //1 means try again
    if (number == 1) {

       goto blackjack;
     }

    if (dealerNumber == 1) {

       goto blackjack;
     }

     //regular numbers
     if(1 < number && number <= 10){

     cout << "You: "<<number << simbol[random];
     cout << " - " << sum << " points";
     }

     if(1 < dealerNumber && dealerNumber <= 10){

     cout << "\nDealer: "<< dealerNumber << simbol[random];
     cout << " - " << dealerSum << " points";
     }

     if(dealerNumber == 0){

      cout << "\nDealer: " << character[dealerRandom] << simbol[dealerRandom];

       dealerSum = dealerSum + 10;

       cout << " - " << dealerSum << " points" << endl;
     }

       _cputs("\nPress E to grab another card or X to leave\n\n");

        key = getch();

        if(key == 'e'){

            goto blackjack;
        }

        if(key == 'x'){

            cout << "Now you have " << money << "$" << endl;
        }
    }
