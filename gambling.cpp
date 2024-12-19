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
        int difficulty; // Variable to store the difficulty level

        // Default constructor
        Game() {
        } 

        // Constructor with difficulty parameter
        Game(int d) {
            difficulty = d; // Set the difficulty level
        } 

        // Function to generate a random guess for the computer
        int computerGuess() {
            srand(time(0)); // Seed the random number generator with the current time

            int randomNum = rand() % 11; // Generate a random number between 0 and 10
            if (randomNum != 10) {
                randomNum++; // Ensure the number is between 1 and 10
            }
            return randomNum; // Return the computer's guess
        }

        // Function to handle the player's guessing logic
        bool playerGuess(int limit) {
            bool accept = true; // Variable to control the guessing loop
            limit = NULL; // Initialize limit (this should be an integer, not NULL)
            cout << "Enter how many guesses you need: " << endl;
            cin >> limit; // Get the number of guesses from the player

            // Loop until the player has used all their guesses or decides to stop
            while (accept == true /*&& limit != 0*/) {
                cout << "Enter Your Guess: " << endl;
                cin >> player; // Get the player's guess
                limit--; // Decrease the limit of guesses

                // Check if the guess is valid
                if (player > 10 || player < 1) {
                    cout << "Invalid Guess." << endl; // Notify invalid guess
                    continue; // Continue to the next iteration
                } else if (limit == 0) {
                    cout << "You are over the limit." << endl; // Notify player they exceeded guesses
                    return false; // Return false indicating the game is over
                } 
                
                // Placeholder for checking if the guess is correct
                /*if (player == c || limit != 0) {
                    cout << "You got it right, the answer was: " << c << endl;
                } else if () {
                }*/

                /*else {
                    cout << "You got it wrong, the answer was: " << c << endl;
                }*/
                
                else {
                    return true; // Return true indicating a valid guess was made
                }
            }
            return false; // Return false if the loop ends without a valid guess
        }

        // Function to return the player's guess
        int Player() {
            return player; // Return the player's guess
        }
};

// Main function to run the game
int main() {
    int score = 0; // Variable to keep track of the player's score
    int limit = NULL; // Variable to store the limit of guesses
    Game g; // Create a Game object
    bool game = true; // Variable to control the game loop
    int option; // Variable to store the player's menu option

    // Main game loop
    while (game == true) {
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
            case 1: // If the player chooses to play
                if (g.playerGuess(limit) == c) { // Check if the player's guess matches the computer's guess
                    cout << "You got it right, the answer was: " << c << endl; // Notify correct guess
                    score++; // Increment the score
                } else {
                    cout << "You got it wrong, the answer was: " << c << endl; // Notify incorrect guess
                }
                break; // End of case 1
            case 2: // If the player chooses to view the score
                cout << "The score is: " << score << " points" << endl; // Display the score
                break; // End of case 2
            case 3: // If the player chooses to exit
                cout << "You are exiting with a score of " << score << endl; // Notify exit and score
                return false; // Exit the program
        }
    }
    return 0; // End of main function
}