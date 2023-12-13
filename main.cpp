#include <iostream>

int main(){
    
    while(true){

    
        // 1 print help
        std::cout << "1: Print help" << std::endl;
        // 2 print exchange stats
        std::cout << "2: Print exchange stats" << std::endl;
        // 3 make an offer
        std::cout << "3: Place an ask" << std::endl;
        // 4 make a bid 
        std::cout << "4: Place a bid" << std::endl;
        // 5 print wallet
        std::cout << "5: Print wallet" << std::endl;
        // 6 continue
        std::cout << "6: Continue" << std::endl;

        std::cout << "========================" << std::endl;
        std::cout << "Type in 1-6" << std::endl;
        
        int userOption;
        std::cin >> userOption;
        std::cout << "You select " << userOption << std::endl;

        if (userOption == 1){
            std::cout << "Help - choose options from the menu" << std::endl;
            std::cout << "and follow the on screen instructions." << std::endl;
        }
        if (userOption == 2){
            std::cout << "Exchange Stats: View statistics related to the exchange." << std::endl;
        }
        if (userOption == 3){
            std::cout << "Place an Ask: Enter details to make an ask on the exchange." << std::endl;
        }
        if (userOption == 4){
            std::cout << "Place a Bid: Enter details to make a bid on the exchange." << std::endl;
        }
        if (userOption == 5){
            std::cout << "Print Wallet: Display information about your wallet." << std::endl;
        }
        if (userOption == 6){
            std::cout << "Continue: Proceed to the next step." << std::endl;
        }
        if (userOption < 1 ||  userOption > 6){
            std::cout << "Invalid Option - Please choose a number between 1-6" << std::endl;
        }
    }

    return 0;
}