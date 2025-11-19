#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; if(!(cin >> T)) return 0;
    while(T--){
        int n; cin >> n;
        vector<long long> odds; odds.reserve(n);
        long long sumEven = 0;
        for(int i=0;i<n;i++){
            long long x; cin >> x;
            if(x & 1LL) odds.push_back(x); else sumEven += x;
        }
        if(odds.empty()){
            cout << 0;
            if(T) cout << '\n';
            continue;
        }
        sort(odds.begin(), odds.end(), greater<long long>());
        int take = (int)( ( (int)odds.size() + 1 ) / 2 );
        long long sumOdd = 0;
        for(int i=0;i<take;i++) sumOdd += odds[i];
        long long ans = sumEven + sumOdd;
        cout << ans;
        if(T) cout << '\n';
    }
    return 0;
}

