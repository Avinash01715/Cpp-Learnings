#include <iostream>
using namespace std;

char board[3][3];

// set up the board with numbers 1–9
void setupBoard() {
    char num = '1';
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = num++;
        }
    }
}

// print the board nicely
void showBoard() {
    cout << "\n";
    for(int i = 0; i < 3; i++) {
        cout << " ";
        for(int j = 0; j < 3; j++) {
            cout << board[i][j];
            if(j != 2) cout << " | ";
        }
        cout << "\n";
        if(i != 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

// check if someone has won
bool hasWon() {
    // rows and columns
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;

        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return true;
    }

    // diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;

    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;

    return false;
}

// check if all cells are filled
bool isDraw() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

// take input from player
void playerMove(char player) {
    int choice;
    cout << "Player " << player << ", where do you want to go? (1-9): ";
    cin >> choice;

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    // simple validation
    if(choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Oops! That spot is not available. Try again.\n";
        playerMove(player); // retry
    } else {
        board[row][col] = player;
    }
}

int main() {
    char currentPlayer = 'X';
    char again;

    cout << " Welcome to Tic-Tac-Toe!\n";

    do {
        setupBoard();
        currentPlayer = 'X';

        while(true) {
            showBoard();
            playerMove(currentPlayer);

            if(hasWon()) {
                showBoard();
                cout << " Player " << currentPlayer << " wins! Congrats!\n";
                break;
            }

            if(isDraw()) {
                showBoard();
                cout << " It's a draw! Nobody wins this time.\n";
                break;
            }

            // switch turn
            if(currentPlayer == 'X')
                currentPlayer = 'O';
            else
                currentPlayer = 'X';
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> again;

    } while(again == 'y' || again == 'Y');

    cout << "Thanks for playing! \n";
    return 0;
}