#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
public:
    int RottenOrg(int row, int col, vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        int fresh = 0;

        // Step 1: Count fresh oranges and push rotten ones
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 2) {
                    q.push({i, j});
                } else if (mat[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0) return 0; // no fresh oranges

        int time = 0;
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        // Step 2: BFS
        while (!q.empty()) {
            int size = q.size();
            bool changed = false;

            for (int k = 0; k < size; k++) {
                auto [x, y] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx >= 0 && ny >= 0 && nx < row && ny < col && mat[nx][ny] == 1) {
                        mat[nx][ny] = 2; // rot it
                        q.push({nx, ny});
                        fresh--;
                        changed = true;
                    }
                }
            }

            if (changed) time++;
        }

        return (fresh == 0) ? time : -1; // -1 if impossible
    }
};

int main() {
    int row, col;
    cin >> row >> col;

    vector<vector<int>> mat(row, vector<int>(col));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> mat[i][j];
        }
    }

    Graph g;
    int count = g.RottenOrg(row, col, mat);

    if (count == -1)
        cout << "Impossible to rot all oranges";
    else
        cout << "Time required: " << count;

    return 0;
}