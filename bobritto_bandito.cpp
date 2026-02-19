#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    int k = n - m;
    int cur_l = l;
    int cur_r = r;
    int ans_l = max(l, -m);
    int ans_r = ans_l + m;
    cout << ans_l << " " << ans_r << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

