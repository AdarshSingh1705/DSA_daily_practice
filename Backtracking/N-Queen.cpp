/* N- QUEEN PUZZLE OR PROBLEM
The n queen puzzle is the problem of placing N class queens on an N*N chessboard such that no two queens attack each other.
Given an integer 'N' print all distinct solutions to the N queen puzzle
Two queen on the same chess baord can attack other if any of the below condition satifies:
1. They share a row.
2. they share a column
3. They share a diagonal
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> res;

    // Check if we can place a queen safely at (row, col)
    bool isSafe(int row, int col, 
                unordered_map<int, bool>& colMap,
                unordered_map<int, bool>& leftDiag,
                unordered_map<int, bool>& rightDiag) {

        if (colMap[col] || leftDiag[row + col] || rightDiag[row - col])
            return false;

        return true;
    }

    void solve(int row, int n, vector<string>& board,
               unordered_map<int, bool>& colMap,
               unordered_map<int, bool>& leftDiag,
               unordered_map<int, bool>& rightDiag) {

        // Base case: all queens placed
        if (row == n) {
            res.push_back(board);
            return;
        }

        // Try placing queen in every column
        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, colMap, leftDiag, rightDiag)) {
                board[row][col] = 'Q';

                // Mark as occupied
                colMap[col] = true;
                leftDiag[row + col] = true;
                rightDiag[row - col] = true;

                solve(row + 1, n, board, colMap, leftDiag, rightDiag);

                // Backtrack (unmark)
                board[row][col] = '.';
                colMap[col] = false;
                leftDiag[row + col] = false;
                rightDiag[row - col] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        unordered_map<int, bool> colMap;
        unordered_map<int, bool> leftDiag;
        unordered_map<int, bool> rightDiag;

        solve(0, n, board, colMap, leftDiag, rightDiag);
        return res;
    }
};

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    Solution obj;
    auto ans = obj.solveNQueens(n);

    cout << "\nAll distinct solutions:\n";
    for (auto& sol : ans) {
        for (auto& row : sol)
            cout << row << "\n";
        cout << "\n";
    }

    cout << "Total solutions: " << ans.size() << "\n";
    return 0;
}

//// =============================================================
// ===========More robust and proper oops=====================

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class NQueenSolver {
private:
    int N;
    vector<vector<string>> solutions;
    unordered_map<int, bool> col, diag1, diag2;

    void solve(int row, vector<string>& board) {
        if (row == N) {
            solutions.push_back(board);
            return;
        }

        for (int c = 0; c < N; ++c) {
            if (col[c] || diag1[row - c] || diag2[row + c]) continue;

            board[row][c] = 'Q';
            col[c] = diag1[row - c] = diag2[row + c] = true;

            solve(row + 1, board);

            board[row][c] = '.';
            col[c] = diag1[row - c] = diag2[row + c] = false;
        }
    }

public:
    NQueenSolver(int n) : N(n) {}

    void findSolutions() {
        vector<string> board(N, string(N, '.'));
        solve(0, board);
    }

    void printSolutions() {
        for (const auto& sol : solutions) {
            for (const auto& row : sol)
                cout << row << endl;
            cout << endl;
        }
        cout << "Total solutions: " << solutions.size() << endl;
    }
};

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    NQueenSolver solver(N);
    solver.findSolutions();
    solver.printSolutions();

    return 0;
}
