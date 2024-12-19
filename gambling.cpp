#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
class Game{
    private:
        int computer;
    public:
        int player;
        int difficulty;
        Game(){
            
        } 
        Game(int d){
            difficulty = d;
        } 
        int computerGuess(){
            srand(time(0));

            int randomNum = rand() % 11;
            if(randomNum !=10){
                randomNum++;
            }
            return randomNum;
        }
        bool playerGuess(int limit){
            bool accept = true;
            limit = NULL;
            cout <<"Enter how many guesses you need: " << endl;
            cin >> limit;
            while (accept == true /*&& limit != 0*/){
                cout<<"Enter Your Guess: "<< endl;
                cin >> player;
                limit--;
                if (player >10 || player <1){
                    cout<<"Invalid Guess."<< endl;
                    continue;
                } else if(limit == 0){
                    cout<<"You are over the limit."<< endl;
                    return false;
                } 
                /*if (player == c || limit !=0){
                    cout<<"You got it right, the answer was: "<<c<<endl;
                } else if ()
                */

                /*else {
                    cout<<"You got it wrong, the answer was: "<<c<<endl;
                }*/
                
                else {
                    return true;
                }
            }
        return false;
        }
        int Player(){
            return player;
        }

};
int main(){
    int score = 0;
    int limit = NULL;
    Game g;
    bool game = true;
    int option;
    while (game == true){
        cout<<R"(
    __   __   _  _  _ ____     ___   __   ____  __  __ _   __  
    _(  ) / _\ ( \/ )(// ___)   / __) / _\ / ___)(  )(  ( \ /  \ 
    / \) \/    \ )  /   \___ \  ( (__ /    \\___ \ )( /    /(  O )
    \____/\_/\_/(__/    (____/   \___)\_/\_/(____/(__)\_)__) \__/ 
    )"<<endl;
    cout<<"1. Play"<<endl;
    cout<<"2. View Score"<<endl;
    cout<<"3. Exit"<<endl;
    cin >> option;
    int c = g.computerGuess();
    switch (option){
            case 1:
                if (g.playerGuess(limit) == c){
                    cout<<"You got it right, the answer was: "<<c<<endl;
                    score++;
                } else {
                    cout<<"You got it wrong, the answer was: "<<c<<endl;
                }
                break;
            case 2:
                cout<<"The score is: "<<score<<" points"<<endl;
                break;
            case 3:
                cout<<"You are exiting with a score of "<<score<<endl;
                return false;
        }
    }
    return 0;
}