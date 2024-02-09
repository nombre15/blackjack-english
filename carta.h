#include <iostream>
using namespace std;

class carta{

    public:
        carta();
        void takeCards(int& playerSum, int& dealerSum);
        void showResult(int playerSum, int dealerSum, int& money, char& key, bool &isFinished);

    private:
        string letter[4] {"A", "J", "Q", "K"};
        string symbol[4] {" of diamonds", " of hearts", " of clubs", " of spades"};
};

