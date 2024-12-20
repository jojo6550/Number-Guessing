#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

// Class representing the game
class Game {
    private:
        int computer; // Variable to store the computer's guess
    public:
        int player; // Variable to store the player's guess
        int difficulty;
        // Default constructor
        Game() {
        } 
        // Function to generate a random guess for the computer
        int computerGuess() {
            int upperlimit;
            int difficulty;
            cout<<"Difficulty1 :1-10 "<<endl; 
            cout<<"Difficulty2 :1-20 "<<endl; 
            cout<<"Difficulty3 :1-30 "<<endl;
            cin >> difficulty; 
            switch (difficulty) {
                case 1:
                    upperlimit = 11;
                    break;
                case 2:
                    upperlimit = 21;
                case 3:
                    upperlimit = 31;
                    
            }
            srand(time(0)); // Seed the random number generator with the current time

            int randomNum = rand() % upperlimit; // Generate a random number between 0 and 10
            if (randomNum != 10) {
                randomNum++; // Ensure the number is between 1 and 10
            }
            return randomNum; // Return the computer's guess
        }

        // Function to handle the player's guessing logic
        /*bool playerGuess(int &limit) {
            bool accept = true; // Variable to control the guessing loop
            cout << "Enter how many guesses you need: " << endl;
            cin >> limit; // Get the number of guesses from the player

            // Loop until the player has used all their guesses
            while (limit > 0) {
                cout << "Enter Your Guess: " << endl;
                cin >> player; // Get the player's guess
                limit--; // Decrease the limit of guesses

                // Check if the guess is valid
                if (player > 10 || player < 1) {
                    cout << "Invalid Guess." << endl; // Notify invalid guess
                    limit++; // Does not decrease the limit
                    continue; // Continue to the next iteration
                } else {
                    return true; // Return true indicating a valid guess was made
                }
            }
            cout << "You are over the limit." << endl; 
            return false; // Return false if the loop ends without a valid guess
        }
        */
    bool playerGuess(){
        bool accept = true;
        int limit = 0;
        switch (difficulty) {
                case 1:
                    limit = 4;
                    cout <<"You have " << limit << " guesses." << endl;
                    break;
                case 2:
                    limit = 9;
                    cout <<"You have " << limit << " guesses." << endl;
                case 3:
                    limit = 14;
                    cout <<"You have " << limit << " guesses." << endl;
            }
        while (accept == true){
            cout << "Enter Your Guess: " << endl;
            cin >> player;
            limit --;
            int c = computerGuess();
            if (player > c || player < 1) {
                cout << "Invalid Guess." << endl; // Notify invalid guess
                continue; // Continue to the next iteration
                limit++;
                cout <<"You have " << limit << " guesses." << endl;
            } else if (limit == 0){
                cout << "You are over the limit." << endl;
                accept = false; // End the game loop
            }
    
        }
    return accept;
    }
};

// Main function to run the game
int main() {
    int score = 0; // Variable to keep track of the player's score
    Game g; // Create a Game object
    bool game = true; // Variable to control the game loop
    int option; // Variable to store the player's menu option
    // Main game loop
    while (game) {
        // Display game title and menu options
        cout << R"(
    __   __   _  _  _ ____     ___   __   ____  __  __ _   __  
    _(  ) / _\ ( \/ )(// ___)   / __) / _\ / ___)(  )(  ( \ /  \ 
    / \) \/    \ )  /   \___ \  ( (__ /    \\___ \ )( /    /(  O )
    \____/\_/\_/(__/    (____/   \___)\_/\_/(____/(__)\_)__) \__/ 
    )" << endl;
        cout << "1. Play" << endl; // Option to play the game
        cout << "2. View Score" << endl; // Option to view the score
        cout << "3. Exit" << endl; // Option to exit the game
        cin >> option; // Get the player's choice

        int c = g.computerGuess(); // Get the computer's guess
        switch (option) {
            /*
            case 1: // If the player chooses to play
                if (g.playerGuess(limit)) { // Check if the player made a valid guess
                    if (g.Player() == c) { // Compare the player's guess with the computer's guess
                        cout << "You got it right, the answer was: " << c << endl; // Notify correct guess
                        score++; // Increment the score
                    } else {
                        cout << "You got it wrong, the answer was: " << c << endl; // Notify incorrect guess
                    }
                }
                break; // End of case 
            case 2: // If the player chooses to view the score
                cout << "The score is: " << score << " points" << endl; // Display the score
                break; // End of case 2
            case 3: // If the player chooses to exit
                cout << "You are exiting with a score of " << score << endl; // Notify exit and score
                return false; // Exit the program
            */
        }
        
    }
    return 0; // End of main function
}