#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
int main(){
    srand(static_cast<unsigned int>(time(0)));
    int secretNumber = rand() % 100 + 1;
    int userGuess = 0;
    int limit;
    int turns = 1;
    cout<<"Enter your limit: "<<endl;
    cin >> limit;
    while (userGuess != secretNumber){
        cout<<"Choose a number between 1 and 100..."<<endl;
        cin >> userGuess;
        if (userGuess > secretNumber && turns != limit){
            cout<<"Guess is two high"<<endl;
            turns ++;
        } else if(userGuess < secretNumber && turns!= limit){
            cout<<"Guess is two low"<<endl;
            turns ++;
        } else if(userGuess != secretNumber && turns == limit){
            cout<<"You ran out of turns"<<endl;
            break;
        }else {
            cout<<"You win!"<<endl;
        }
    }

    return 0;
}