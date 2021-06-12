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
    int random = rand() % 4;
    int dealerRandom = rand() % 4;
    int dealerNumber = 0;

    dealerSum = dealerSum + dealerNumber;
    sum = sum + number;

    //results
    if(sum == 21) {


        _cputs("21 cards,  Winner!! \n\nPress E to play again or X to leave\n\n");

        key = getch();

        if(key == 'e'){

            goto blackjack;
        }

        else if(key == 'x'){

            cout << "You have "  << money << "$" << endl;
            return 0;
        }
     }

     if(sum > 21){

        sum = 0;
        _cputs("You have over 21, loser!\n\nPress E to play again or X to leave\n\n");

        key = getch();

        if(key == 'e'){

            goto blackjack;
        }

        else if(key == 'x'){

            money = 0;
            cout << "\nYou lose it all! \nNow you have " << money << "$" << endl;
            return 0;
        }
     }

    //Zero for using characters
    if(number == 0){

      cout << "You got " << character[random] << simbol[random];
      cout << "  ------------  " << "Dealer got " << character[dealerRandom] << simbol[dealerRandom];

       sum = sum + 10;
       dealerSum = dealerSum + 10;

       cout << "\nYou got " << sum << " points";
       cout << "  ------------  " << " Dealer got " << dealerSum << " points" << endl;
       _cputs("\nPress E to grab another card or X to leave\n\n");

        key = getch();

        if(key == 'e'){

            goto blackjack;
        }

        if(key == 'x'){

            cout << "Now you have " << money << "$" << endl;
        }
    }

    //1 means try again
    else if (number == 1) {

       goto blackjack;
     }

     //regular numbers
     else{

     cout << number << simbol[random] << endl;
     cout << "You got " << sum << " points" << endl;
     _cputs("\nPress E to grab another card or X to leave\n\n");

        key = getch();

        if(key == 'e'){

            money = money + (money * 0.5);
            goto blackjack;
        }

        if(key == 'x'){

            cout << "You have " << money << "$" << endl;
        }
    }
}
