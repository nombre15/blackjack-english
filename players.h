class players
{
    public:
        players();
        int play();
        void playerWins(int& money);
        void playerLoses(int& money);
        void validateMoney(int& money);
        int enterKey(char key, int money);

    private:
        int playerSum = 0;
        int dealerSum = 0;
        int money = 0;
        bool isFinished = false;
};
