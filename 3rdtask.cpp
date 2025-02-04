#include <iostream>

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char currentPlayer = 'X';

void displayBoard() {
    std::cout << "\n";
    std::cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    std::cout << "---|---|---\n";
    std::cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    std::cout << "---|---|---\n";
    std::cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
    std::cout << "\n";
}

bool isWin() {
    
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    
    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool makeMove(int position) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;
    
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
        return true;
    } else {
        std::cout << "Invalid move! Try again.\n";
        return false;
    }
}

void resetBoard() {
    char start = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = start++;
}

int main() {
    char playAgain;
    
    do {
        resetBoard();
        currentPlayer = 'X';
        bool gameOver = false;

        std::cout << "Welcome to Tic-Tac-Toe!\n";
        displayBoard();

        while (!gameOver) {
            int move;
            std::cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            std::cin >> move;

            if (move < 1 || move > 9 || !makeMove(move)) continue;

            displayBoard();

            if (isWin()) {
                std::cout << "Congratulations! Player " << currentPlayer << " wins!\n";
                gameOver = true;
            } else if (isDraw()) {
                std::cout << "It's a draw!\n";
                gameOver = true;
            } else {
                switchPlayer();
            }
        }

        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;
        
    } while (playAgain == 'y' || playAgain == 'Y');

    std::cout << "Thanks for playing!\n";
    return 0;
}
