#ifndef CARTA_H
#define CARTA_H
#include <iostream>
using namespace std;

class carta
{
    public:
        Carta();
        void takeCards(int& sum, int& dealerSum);
        void showResult(int& sum, int& dealerSum, int& money, char& key, bool &isFinished);

    private:
        string letter[4] {"A", "J", "Q", "K"};
        string symbol[4] {" of diamonds", " of hearts", " of clubs", " of spades"}};
};

void playerWins(int& money, int& sum);
void playerLoses(int& money, int& sum);
int enterKey(char key, int money);

#endif // CARTA_H
