#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

struct Node {
    int vertex;
    int cost;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<int> left(n + 1);
        vector<int> right(n + 1);

        for (int i = 1; i <= n; ++i) {
            cin >> left[i] >> right[i];
        }

        stack<Node> stk;
        stk.push({1, 0});

        int answer = INT_MAX;

        while (!stk.empty()) {
            Node current = stk.top();
            stk.pop();

            int v = current.vertex;
            int cost = current.cost;

            if (left[v] == 0 && right[v] == 0) {
                answer = min(answer, cost);
                continue;
            }

            if (left[v] != 0) {
                int add = (s[v - 1] == 'L') ? 0 : 1;
                stk.push({left[v], cost + add});
            }

            if (right[v] != 0) {
                int add = (s[v - 1] == 'R') ? 0 : 1;
                stk.push({right[v], cost + add});
            }
        }

        if (answer == INT_MAX) {
            answer = 0;
        }

        cout << answer << '\n';
    }

    return 0;
}

