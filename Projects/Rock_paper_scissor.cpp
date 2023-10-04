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

    cout << "It contain 5 round... If you will win more than 2 time then you are winner." << endl;

    int Round = 5;
    int playerWinCnt = 0;

    while (Round--) {
        
        cout << endl << "ROUND " << 5-Round << endl;
        //? taking input from user
        cout << "Enter 0 -> Rock, 1 -> paper, 2 -> scessor : ";
        int uInput;
    takeInputAgain : 
        cin >> uInput;
        if (uInput > 2 || uInput < 0) {
            cout << "Please Enter Valid Number from 0 to 2 : ";
            goto takeInputAgain;
        }
        cout << endl;
        cout << "your Choice -> " << getMatch(uInput) << endl;
        
        //? assign random number to computer from 1 to 3
        int cInput = (rand() % 11) % 3;
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
        if (playerWinCnt + Round < 0 || playerWinCnt > 2) {
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