#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve(){
    string p, s;
    cin >> p >> s;


    int n = p.length();
    int m = s.length();

    int i = 0;
    int j = 0;

    while(i < n && j < m){
        char char_p = p[i];
        char char_s = s[j];

        if(char_p != char_s){
            cout << "NO" << endl;
            return;
        }

        int count_p = 0;
        while(i < n && p[i] == char_p){
            count_p++;
            i++;
        }

        int count_s = 0;
        while(j < m && s[j] == char_s){
            count_s++;
            j++;
        }

        if(count_s < count_p || count_s > 2 * count_p){
            cout << "NO" << endl;
            return;
        }
    }

    if(i < n || j < m){
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
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

