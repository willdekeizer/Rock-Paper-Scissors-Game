#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For the time() function
#include <string>

using namespace std;

// Constant variables
const int ROCK = 1;
const int  PAPER = 2;
const int SCISSORS = 3;

// Function Prototypes
void menu();
int computerChoice(int);
int getUserChoice();
int winnerSelection(int, int);



int main()
{
    int computer_choice;
    int user_choice;
    bool play_again;

    do
    {
        computer_choice = computerChoice(computer_choice);
        
        menu();

        user_choice = getUserChoice();

        if(computer_choice == 1){
            cout << "Computer chose Rock." << endl;
        } else if(computer_choice == 2){
            cout << "Computer chose Paper." << endl;
        } else if(computer_choice == 3){
            cout << "Computer chose Scissors." << endl;
        }

        play_again = winnerSelection(computer_choice, user_choice);

    } while (play_again == true);

    return 0;
}

void menu (){
    cout << "Your choices are: Rock, Paper, Scissors. Please enter a choice." << endl;
}


int computerChoice(int computer_choice)
{
    // Get the system time.
    srand(time(0));
    // Random number
    return ((rand() % 3) + 1);
}

int getUserChoice()
{        
    string userx;
    int convertedUserChoice;

    do {
        cin >> userx;

        if(userx.compare("Rock") == 0 || userx.compare("rock") == 0){
            convertedUserChoice = ROCK;
        } else if(userx.compare("Paper") == 0 || userx.compare("paper") == 0){
            convertedUserChoice = PAPER;
        } else if(userx.compare("Scissors") == 0 || userx.compare("scissors") == 0){
            convertedUserChoice = SCISSORS;
        } else {
            convertedUserChoice = -1;
            cout << "incorrect choice, please try again" << endl;
        }
    }
    while (convertedUserChoice == -1);

    return convertedUserChoice;
}


int winnerSelection(int computer_choice, int user_choice)
{
    int play_again = false;

    if(computer_choice == ROCK && user_choice == SCISSORS){
        cout << "Computer WINS. You lose." << endl;
    } else if(computer_choice == PAPER && user_choice == SCISSORS){
        cout << "You WIN." << endl;
    } else if(computer_choice == SCISSORS && user_choice == PAPER){
        cout << "Computer WINS. You lose." << endl;
    } else if(computer_choice == ROCK && user_choice == PAPER){
        cout << "You WIN." << endl;
    } else if(computer_choice == SCISSORS && user_choice == ROCK){
        cout << "You WIN" << endl;
    } else if(computer_choice == PAPER && user_choice == ROCK){
        cout << "Computer WINS. You lose." << endl;
    } else if(computer_choice == user_choice){
        cout << "Tie, try again." << endl;
        play_again = true;
    } 

    return play_again;
}