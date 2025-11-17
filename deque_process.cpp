#include <iostream>
#include <vector>
#include <string>
using namespace std;

inline bool is_strict_inc4(const vector<int>& q, int m) {
    return q[m-4] < q[m-3] && q[m-3] < q[m-2] && q[m-2] < q[m-1];
}

inline bool is_strict_dec4(const vector<int>& q, int m) {
    return q[m-4] > q[m-3] && q[m-3] > q[m-2] && q[m-2] > q[m-1];
}

inline bool safe_append(const vector<int>& q, int m, int x) {
    if (m < 4) return true;
    if (is_strict_inc4(q, m) && x > q[m-1]) return false;
    if (is_strict_dec4(q, m) && x < q[m-1]) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }

        vector<int> q(n);
        int m = 0;
        string ans;
        ans.reserve(n);
        int l = 0, r = n - 1;

        while (l <= r) {
            int left = p[l];
            int right = p[r];
            bool safeL = safe_append(q, m, left);
            bool safeR = safe_append(q, m, right);

            if (safeL && !safeR) {
                ans += 'L';
                q[m++] = left;
                ++l;
            } else if (safeR && !safeL) {
                ans += 'R';
                q[m++] = right;
                --r;
            } else if (safeL && safeR) {
                bool chooseLeft = (left <= right);
                if (m >= 3) {
                    int a = q[m-3], b = q[m-2], c = q[m-1];
                    bool riskL = false, riskR = false;
                    {
                        int x = left;
                        int nl = l + 1, nr = r;
                        if (a < b && b < c && c < x) {
                            int nleft = (nl <= nr) ? p[nl] : -1000000007;
                            int nright = (nl <= nr) ? p[nr] : -1000000007;
                            if (nleft > x && nright > x) riskL = true;
                        } else if (a > b && b > c && c > x) {
                            int nleft = (nl <= nr) ? p[nl] : 1000000007;
                            int nright = (nl <= nr) ? p[nr] : 1000000007;
                            if (nleft < x && nright < x) riskL = true;
                        }
                    }
                    {
                        int x = right;
                        int nl = l, nr = r - 1;
                        if (a < b && b < c && c < x) {
                            int nleft = (nl <= nr) ? p[nl] : -1000000007;
                            int nright = (nl <= nr) ? p[nr] : -1000000007;
                            if (nleft > x && nright > x) riskR = true;
                        } else if (a > b && b > c && c > x) {
                            int nleft = (nl <= nr) ? p[nl] : 1000000007;
                            int nright = (nl <= nr) ? p[nr] : 1000000007;
                            if (nleft < x && nright < x) riskR = true;
                        }
                    }
                    if (riskL && !riskR) chooseLeft = false;
                    else if (riskR && !riskL) chooseLeft = true;
                }
                if (chooseLeft) {
                    ans += 'L';
                    q[m++] = left;
                    ++l;
                } else {
                    ans += 'R';
                    q[m++] = right;
                    --r;
                }
            } else {
                ans += 'L';
                q[m++] = left;
                ++l;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}

