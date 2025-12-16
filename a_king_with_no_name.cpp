#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<string> board(n);
    int startX = -1, startY = -1, targetX = -1, targetY = -1;

    for (int i = 0; i < n; ++i) {
        cin >> board[i];
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 'Q') {
                startX = i;
                startY = j;
            } else if (board[i][j] == 'K') {
                targetX = i;
                targetY = j;
            }
        }
    }

    if (startX == -1 || targetX == -1) {
        // Should not happen based on problem description
        cout << -1 << endl;
        return 0;
    }

    if (startX == targetX && startY == targetY) {
        cout << 0 << endl;
        return 0;
    }


    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, -1, 1};

    vector<vector<int>> dist(n, vector<int>(n, INF));
    queue<pair<int, int>> q;

    dist[startX][startY] = 0;
    q.push({startX, startY});

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == targetX && y == targetY) {
            cout << dist[x][y] << endl;
            return 0;
        }

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            while (nx >= 0 && nx < n && ny >= 0 && ny < n && board[nx][ny] != '#') {
                if (dist[nx][ny] == INF) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                } else if (dist[nx][ny] <= dist[x][y]) {
                    // Optimization: If we reach a cell that was already reached with a smaller or equal distance,
                    // we can stop scanning in this direction.
                    break;
                }

                nx += dx[dir];
                ny += dy[dir];
            }
        }
    }

    cout << -1 << endl;

    return 0;
}

