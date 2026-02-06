#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> compute_pi(const vector<int>& P) {
    int m = P.size();
    vector<int> pi(m);
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && P[i] != P[j])
            j = pi[j - 1];
        if (P[i] == P[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

vector<int> kmp_search(const vector<int>& T, const vector<int>& P) {
    vector<int> pi = compute_pi(P);
    vector<int> matches;
    int n = T.size();
    int m = P.size();
    if (m == 0) return matches;

    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && T[i] != P[j])
            j = pi[j - 1];
        if (T[i] == P[j])
            j++;
        if (j == m) {
            matches.push_back(i - m + 1);
            j = pi[j - 1];
        }
    }
    return matches;
}

vector<int> get_cyclic_shifts(const vector<int>& Base, const vector<int>& Pattern) {
    int k = Base.size();
    if (k == 0) return {};
    vector<int> Text = Base;
    for(int i=0; i<k-1; ++i) Text.push_back(Base[i]);

    return kmp_search(Text, Pattern);
}

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;

    vector<int> a(n);
    int out1 = 0, in1 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i]) out1++; else in1++;
    }

    int m1;
    cin >> m1;
    vector<vector<int>> adj1(n + 1);
    for (int i = 0; i < m1; ++i) {
        int u, v;
        cin >> u >> v;
        adj1[u].push_back(v);
    }

    vector<int> b(n);
    int out2 = 0, in2 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (b[i]) out2++; else in2++;
    }

    int m2;
    cin >> m2;
    vector<vector<int>> adj2(n + 1);
    for (int i = 0; i < m2; ++i) {
        int u, v;
        cin >> u >> v;
        adj2[u].push_back(v);
    }

    if (out1 != in2 || out2 != in1) {
        cout << "NO\n";
        return;
    }

    if (out1 == 0 || out2 == 0) {
        cout << "YES\n";
        return;
    }

    // BFS for layers
    auto get_layers = [&](int size, const vector<vector<int>>& adj) {
        vector<int> layers(size + 1, -1);
        vector<int> q;
        q.push_back(1);
        layers[1] = 0;

        int head = 0;
        while(head < q.size()){
            int u = q[head++];
            for(int v : adj[u]){
                if(layers[v] == -1){
                    layers[v] = (layers[u] + 1) % k;
                    q.push_back(v);
                }
            }
        }
        return layers;
    };

    vector<int> l1 = get_layers(n, adj1);
    vector<int> l2 = get_layers(n, adj2);

    vector<int> A(k, 0), B(k, 0); // Out1, In1 by layer
    for(int i=1; i<=n; ++i){
        if(a[i-1]) A[l1[i]]++;
        else B[l1[i]]++;
    }

    vector<int> C(k, 0), D(k, 0); // Out2, In2 by layer
    for(int i=1; i<=n; ++i){
        if(b[i-1]) C[l2[i]]++;
        else D[l2[i]]++;
    }

    vector<int> shift1 = get_cyclic_shifts(A, D);

    vector<int> shift2 = get_cyclic_shifts(C, B);

    vector<bool> possibleX(k, false);
    for(int s : shift1) {
        int X = (s + 1) % k;
        possibleX[X] = true;
    }

    for(int s : shift2) {
        int X = (-s - 1) % k;
        if(X < 0) X += k;
        if(possibleX[X]) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (cin >> t) {
        while(t--) {
            solve();
        }
    }
    return 0;
}
