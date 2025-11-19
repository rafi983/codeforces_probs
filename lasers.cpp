#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; if(!(cin >> T)) return 0;
    while(T--){
        int n, m; long long x, y;
        cin >> n >> m >> x >> y;
        for(int i=0;i<n;i++){ long long a; cin >> a; }
        for(int j=0;j<m;j++){ long long b; cin >> b; }
        cout << (static_cast<long long>(n) + m);
        if(T) cout << '\n';
    }
    return 0;
}

