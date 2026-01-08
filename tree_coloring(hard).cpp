#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve_zaman() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> depth(n + 1);
    vector<int> parent(n + 1, 0);
    vector<vector<int>> levels(n + 1);
    int max_depth = 0;

    vector<int> q;
    q.reserve(n);
    q.push_back(1);
    depth[1] = 0;
    levels[0].push_back(1);

    int head = 0;
    while(head < q.size()){
        int u = q[head++];
        max_depth = max(max_depth, depth[u]);
        for(int v : adj[u]){
            if(v != parent[u]){
                depth[v] = depth[u] + 1;
                parent[v] = u;
                levels[depth[v]].push_back(v);
                q.push_back(v);
            }
        }
    }

    int k = 0;
    for(int d=0; d<=max_depth; ++d){
        int size = (int)levels[d].size();
        int req = size;
        set<int> parents;
        for(int u : levels[d]){
            if(parent[u] != 0) parents.insert(parent[u]);
        }
        if(parents.size() == 1 && d > 0) {
            req++;
        }
        k = max(k, req);
    }


    vector<int> color(n + 1, 0);
    color[1] = 1;

    for (int d = 1; d <= max_depth; ++d) {
        int m = (int)levels[d].size();
        map<int, vector<int>> groups;
        for(int u : levels[d]) groups[color[parent[u]]].push_back(u);

        set<int> bad_colors;
        for(auto const& [pc, nodes] : groups) bad_colors.insert(pc);

        int star_color = -1;
        for(auto const& [pc, nodes] : groups){
            if(nodes.size() == m) star_color = pc;
        }

        vector<int> chosen_colors;
        int count = 0;
        for(int c=1; c<=k; ++c){
            if(c == star_color) continue;
            chosen_colors.push_back(c);
            count++;
            if(count == m) break;
        }

        vector<int> s_bad, s_free;
        for(int c : chosen_colors){
            if(bad_colors.count(c)) s_bad.push_back(c);
            else s_free.push_back(c);
        }

        sort(s_bad.begin(), s_bad.end(), [&](int a, int b){
            return groups[a].size() > groups[b].size();
        });

        priority_queue<pair<int, int>> pq;
        for(auto const& [pc, nodes] : groups){
            pq.push({(int)nodes.size(), pc});
        }

        auto assign_color = [&](int c) {
            pair<int, int> best = pq.top(); pq.pop();

            // Conflict resolution
            if(best.second == c) {
                pair<int, int> second = pq.top(); pq.pop();
                pq.push(best);
                best = second;
            }

            int target_pc = best.second;
            int u = groups[target_pc].back();
            groups[target_pc].pop_back();
            color[u] = c;

            if(best.first > 1) pq.push({best.first - 1, target_pc});
        };

        for(int c : s_bad) assign_color(c);
        for(int c : s_free) assign_color(c);
    }

    cout << k << "\n";
    vector<vector<int>> ops(k + 1);
    for(int i=1; i<=n; ++i) ops[color[i]].push_back(i);
    for(int i=1; i<=k; ++i){
        cout << ops[i].size();
        for(int u : ops[i]) cout << " " << u;
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve_zaman();
    }
    return 0;
}
