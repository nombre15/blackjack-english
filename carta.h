#ifndef CARTA_H
#define CARTA_H
#include <iostream>
using namespace std;

class carta
{
    public:
        Carta();
        void takeCards(int& playerSum, int& dealerSum);
        void showResult(int playerSum, int dealerSum, int& money, char& key, bool &isFinished);

    private:
        string letter[4] {"A", "J", "Q", "K"};
        string symbol[4] {" of diamonds", " of hearts", " of clubs", " of spades"};
};

//Methods from main that will be used in carta.cpp
void playerWins(int& money);
void playerLoses(int& money);

#endif // CARTA_H
