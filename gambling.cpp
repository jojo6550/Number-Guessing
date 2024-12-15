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
        Game(){
            
        } 
        int computerGuess(){
            srand(time(0));

            int randomNum = rand() % 11;
            if(randomNum !=10){
                randomNum++;
            }
            return randomNum;
        }
        bool playerGuess(){
            bool limit = true;
            while (limit == true){
                cout<<"Enter Your Guess: "<< endl;
                cin >> player;
                if (player >10 || player <1){
                    cout<<"Invalid Guess."<< endl;
                    continue;
                } else {
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
    int p = g.playerGuess();
    switch (option){
            case 1:
                if(p > c && p != c){
                    cout<<"You were too low, you lose."<<endl;
                    cout<<"The answer was: "<<c<<endl;
                } else if (p < c && p != c){
                    cout<<"You were too high, you lose."<<endl;
                    cout<<"The answer was: "<<c<<endl;
                } else if (p == c){
                    cout<<"You got it right, the answer was: "<<c<<endl;
                    score++;
                }
                break;
            case 2:
                cout<<"The score is: "<<score<<" points"<<endl;
                break;
        }
    }
    return 0;
}