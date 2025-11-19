#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; if(!(cin >> T)) return 0;
    while(T--){
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        vector<int> total(n+1,0);
        for(int x: a) total[x]++;
        bool ok = true;
        for(int v=1; v<=n; ++v){ if(total[v] % k != 0){ ok = false; break; } }
        if(!ok){
            cout << 0;
            if(T) cout << '\n';
            continue;
        }
        vector<int> limit(n+1,0);
        for(int v=1; v<=n; ++v) if(total[v]) limit[v] = total[v]/k; // zero stays zero
        long long ans = 0;
        vector<int> freq(n+1,0);
        int l = 0;
        for(int r=0; r<n; ++r){
            int val = a[r];
            freq[val]++;
            while(freq[val] > limit[val]){ // shrink until valid
                freq[a[l]]--;
                ++l;
            }
            ans += (long long)(r - l + 1);
        }
        cout << ans;
        if(T) cout << '\n';
    }
    return 0;
}

