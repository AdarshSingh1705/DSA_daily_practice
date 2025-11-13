#include <iostream>
using namespace std;

const int N = 9;

bool isSafe(int board[N][N], int row, int col, int num) {
    // Check row and column
    for (int x = 0; x < N; ++x) {
        if (board[row][x] == num || board[x][col] == num)
            return false;
    }

    // Check 3x3 subboard
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[startRow + i][startCol + j] == num)
                return false;

    return true;
}

bool solveSudoku(int board[N][N]) {
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            // for empty cell or 0
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; ++num) {
                    if (isSafe(board, row, col, num)) { 
                        board[row][col] = num;
                        // Recursivce call to check aage solution is possible or not
                        if (solveSudoku(board))
                            return true;
                        board[row][col] = 0; // backtrack
                    }
                }
                return false; // no valid number found
            }
        }
    }
    return true; // all cells filled
}

void printboard(int board[N][N]) {
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col)
            cout << board[row][col] << ", ";
        cout << endl;
    }
}

int main() {
    int board[N][N] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

 /*   // for dynamic input
    int grid[N][N];

    cout << "Enter the Sudoku grid (use 0 for empty cells):\n";
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> grid[i][j];

*/
    if (solveSudoku(board))
        printboard(board);
    else
        cout << "No solution exists." << endl;

    return 0;
}