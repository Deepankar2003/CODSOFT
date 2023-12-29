#include <iostream>
#include <vector>
using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    char currentPlayer;

public:
    TicTacToe() : board(3, vector<char>(3, ' ')), currentPlayer('X') {}

    void displayBoard() const {
        cout << "  1 2 3\n";
        for (int i = 0; i < 3; ++i) {
            cout << i + 1 << " ";
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }

    void getPlayerMove() {
        int row, col;
        do {
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;
        } while (!isValidMove(row - 1, col - 1));

        board[row - 1][col - 1] = currentPlayer;
    }

    bool isValidMove(int row, int col) const {
        return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
    }

    bool checkForWin() const {
       
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
                return true; 
            }
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
                return true; 
            }
        }

        
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
            return true; 
        }
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
            return true; 
        }

        return false;
    }

    bool checkForDraw() const {
        for (const auto& row : board) {
            for (char cell : row) {
                if (cell == ' ') {
                    return false; 
                }
            }
        }
        return true; 
    }


    void switchPlayers() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }


    void displayResult() const {
        if (checkForWin()) {
            cout << "Player " << currentPlayer << " wins!\n";
        } else {
            cout << "The game is a draw!\n";
        }
    }

    void playGame() {
        do {
            displayBoard();
            getPlayerMove();
            if (checkForWin() || checkForDraw()) {
                displayBoard();
                displayResult();
                break;
            }
            switchPlayers();
        } while (true);
    }
};

int main() {
    TicTacToe game;
    game.playGame();

    return 0;
}
