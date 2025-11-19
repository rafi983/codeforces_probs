#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; if(!(cin >> T)) return 0;
    while(T--){
        int n; long long m;
        cin >> n >> m;
        vector<pair<long long,int>> req; req.reserve(n);
        for(int i=0;i<n;i++){ long long a; int b; cin >> a >> b; req.emplace_back(a,b); }
        long long ans = 0;
        long long prev_t = 0; int prev_side = 0;
        for(auto &r: req){
            long long t = r.first; int side = r.second;
            long long L = t - prev_t;
            int parity_needed = prev_side ^ side;
            long long seg_flips = (L % 2 == parity_needed) ? L : (L - 1);
            ans += seg_flips;
            prev_t = t; prev_side = side;
        }
        if(prev_t < m){
            ans += (m - prev_t);
        }
        cout << ans;
        if(T) cout << '\n';
    }
    return 0;
}

