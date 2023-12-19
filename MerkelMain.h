class MerkelMain
{
    public:
        MerkelMain();
        void init();
        void printMenu();
        int getuserOption();
        void printHelp();
        void printMarketStats();
        void enterAsk();
        void processUserOption(int userOption);
        void enterBid();
        void printWallet();
        void goToNextWallet();
};