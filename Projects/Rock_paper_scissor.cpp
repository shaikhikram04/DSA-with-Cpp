#include <iostream>
using namespace std;

string getMatch(int input) {
    if (input == 0) 
        return "Rock";

    else if (input == 1)
        return "Paper";

    else
        return "Scessor";
}

int main() {

    cout << "It contain 10 round... who win more time they are the final winner." << endl;

    int Round = 5;
    int playerWinCnt = 0;

    while (Round--) {
        
        cout << endl << "ROUND " << 10-Round << endl;
        //? taking input from user
        cout << "Enter 0 -> Rock, 1 -> paper, 2 -> scessor : ";
        int uInput;
        cin >> uInput;
        cout << endl;
        cout << "your Choice -> " << getMatch(uInput) << endl;
        
        //? assign random number to computer from 1 to 3
        int cInput = rand() % 3;
        cout << "Computer Choice -> " << getMatch(cInput) << endl;

        //* Desiding winner of a round
        if (uInput == (cInput+1)%3) {
            cout << "You are WINNER of the round" << endl;
            playerWinCnt++;
        }
        else if (uInput == cInput)
            cout << "Tie Round" << endl;
        else {
            cout << "Computer is WINNER of the round" << endl;
            playerWinCnt--;
        }

        //* user can't win the game
        if (playerWinCnt + Round < 0) {
            break;
        }
    }
    cout << endl;

    //! Declaring final winner
    if (playerWinCnt >= 0) {
        cout << "You Won the Game." << endl;
    }
    else {
        cout << "Computer Won the Game." << endl;
    }
}