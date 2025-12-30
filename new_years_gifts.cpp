#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Friend {
    int id;
    int x, y, z;
    long long cost;
};

void solve_zaman() {
    int n, m;
    long long k;
    if (!(cin >> n >> m >> k)) return;

    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());

    vector<Friend> friends(n);
    long long sum_y = 0;
    for (int i = 0; i < n; ++i) {
        friends[i].id = i;
        cin >> friends[i].x >> friends[i].y >> friends[i].z;
        friends[i].cost = friends[i].z - friends[i].y;
        sum_y += friends[i].y;
    }

    long long budget = k - sum_y;

    sort(friends.begin(), friends.end(), [](const Friend& a, const Friend& b) {
        return a.x > b.x;
    });

    priority_queue<long long, vector<long long>, greater<long long>> boxed_pq;

    vector<long long> paid_costs;

    int box_idx = 0;
    int available_boxes = 0;

    for (int i = 0; i < n; ++i) {
        int req_x = friends[i].x;

        while (box_idx < m && a[box_idx] >= req_x) {
            available_boxes++;
            box_idx++;
        }

        if (available_boxes > 0) {
            available_boxes--;
            boxed_pq.push(friends[i].cost);
        } else {

            if (!boxed_pq.empty() && boxed_pq.top() < friends[i].cost) {
                long long min_boxed_cost = boxed_pq.top();
                boxed_pq.pop();

                boxed_pq.push(friends[i].cost);

                paid_costs.push_back(min_boxed_cost);
            } else {
                paid_costs.push_back(friends[i].cost);
            }
        }
    }

    sort(paid_costs.begin(), paid_costs.end());

    long long spent = 0;
    int paid_kept = 0;
    for (long long c : paid_costs) {
        if (spent + c <= budget) {
            spent += c;
            paid_kept++;
        } else {
            break;
        }
    }

    cout << boxed_pq.size() + paid_kept << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve_zaman();
        }
    }
    return 0;
}
