#include <iostream>
#include <cstdlib>  // for rand()
#include <ctime>    // for time()
using namespace std;

int main(){
    int n;
    int guess;
    int attempts = 0;  // initialize

    srand(time(0)); // seed random number generator

    n = (rand() % 100) + 1;

    cout << "************ NUMBER GUESSING GAME **************" << endl;

    do {
        cout << "Enter a guess between 1 to 100: ";
        cin >> guess;
        attempts++;

        if(guess > n){
            cout << "Too high" << endl;
        }
        else if(guess < n){
            cout << "Too low" << endl;
        }
        else{
            cout << "CORRECT!! with attempts: " << attempts << endl;
        }

    } while(guess != n);

    cout << "*********** The End ***************" << endl;

    return 0;
}