#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int x, int y, vector<vector<int>>& maze, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1);
}

bool solveMazeUtil(int x, int y, vector<vector<int>>& maze, int n, vector<vector<int>>& sol) {
    if (x == n - 1 && y == n - 1 && maze[x][y] == 1) {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(x, y, maze, n)) {
        if (sol[x][y] == 1) // already visited
            return false;

        sol[x][y] = 1;

        // Move forward in x direction
        if (solveMazeUtil(x + 1, y, maze, n, sol))
            return true;

        // Move down in y direction
        if (solveMazeUtil(x, y + 1, maze, n, sol))
            return true;

        // If none of the above movements work then BACKTRACK:
        sol[x][y] = 0;
        return false;
    }

    return false;
}

void printSolution(vector<vector<int>>& sol, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> maze = {
        {1, 1, 0, 0},
        {0, 1, 1, 1},
        {0, 0, 0, 1},
        {1, 1, 1, 1}
    };

    int n = maze.size();
    vector<vector<int>> sol(n, vector<int>(n, 0));

    if (solveMazeUtil(0, 0, maze, n, sol)) {
        cout << "Path found:" << endl;
        printSolution(sol, n);
    } else {
        cout << "No path found" << endl;
    }

    return 0;
}
