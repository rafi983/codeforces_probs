#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Clique {
    vector<int> members;
};

bool compareCliques(const Clique& a, const Clique& b) {
    return a.members.size() < b.members.size();
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<Clique> cliques;
    cliques.reserve(n);
    for (int i = 1; i <= n; ++i) {
        cliques.push_back({{i}});
    }


    while (cliques.size() > 1) {
        sort(cliques.begin(), cliques.end(), compareCliques);

        Clique c1 = cliques[0];
        Clique c2 = cliques[1];

        cliques.erase(cliques.begin(), cliques.begin() + 2);

        for (int u : c1.members) {
            for (int v : c2.members) {
                cout << u << " " << v << endl;
                int res;
                cin >> res;
                if (res == -1) exit(0);
                if (res == 1) return;
            }
        }

        Clique newClique;
        newClique.members.reserve(c1.members.size() + c2.members.size());
        newClique.members.insert(newClique.members.end(), c1.members.begin(), c1.members.end());
        newClique.members.insert(newClique.members.end(), c2.members.begin(), c2.members.end());
        cliques.push_back(newClique);
    }
}

int main() {
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}

