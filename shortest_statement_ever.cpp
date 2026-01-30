#include <iostream>
#include <cstring>

using namespace std;

const long long INF = 5e18;

class ZamanSolver {
    long long dp[32][3][3];
    short parent_state[32][3][3];
    char chosen_bits[32][3][3];
    int tx, ty;

public:
    void zaman_execute() {
        if (!(cin >> tx >> ty)) return;

        for (int i = 0; i < 32; ++i)
            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 3; ++k)
                    dp[i][j][k] = INF;

        dp[31][0][0] = 0;

        for (int i = 30; i >= 0; --i) {
            int bx = (tx >> i) & 1;
            int by = (ty >> i) & 1;
            long long bit_val = (1LL << i);

            for (int cp = 0; cp < 3; ++cp) {
                for (int cq = 0; cq < 3; ++cq) {
                    if (dp[i + 1][cp][cq] == INF) continue;
                    long long prev_cost = dp[i + 1][cp][cq];

                    int pairs[3][2] = {{0,0}, {0,1}, {1,0}};

                    for (auto& p : pairs) {
                        int bp = p[0];
                        int bq = p[1];

                        long long current_add = 0;
                        int ncp = cp;
                        int ncq = cq;

                        if (cp == 0) {
                            if (bp < bx) { ncp = 1; current_add += bit_val; }
                            else if (bp > bx) { ncp = 2; current_add += bit_val; }
                        } else if (cp == 1) {
                             if (bx == 1 && bp == 0) current_add += bit_val;
                             else if (bx == 0 && bp == 1) current_add -= bit_val;
                        } else {
                             if (bp == 1 && bx == 0) current_add += bit_val;
                             else if (bp == 0 && bx == 1) current_add -= bit_val;
                        }

                         if (cq == 0) {
                            if (bq < by) { ncq = 1; current_add += bit_val; }
                            else if (bq > by) { ncq = 2; current_add += bit_val; }
                        } else if (cq == 1) {
                             if (by == 1 && bq == 0) current_add += bit_val;
                             else if (by == 0 && bq == 1) current_add -= bit_val;
                        } else {
                             if (bq == 1 && by == 0) current_add += bit_val;
                             else if (bq == 0 && by == 1) current_add -= bit_val;
                        }

                        if (prev_cost + current_add < dp[i][ncp][ncq]) {
                            dp[i][ncp][ncq] = prev_cost + current_add;
                            parent_state[i][ncp][ncq] = (short)(cp * 3 + cq);
                            chosen_bits[i][ncp][ncq] = (char)(bp * 2 + bq);
                        }
                    }
                }
            }
        }

        long long final_min = INF;
        int best_cp = 0, best_cq = 0;

        for(int j=0; j<3; ++j) {
            for(int k=0; k<3; ++k) {
                if(dp[0][j][k] < final_min) {
                    final_min = dp[0][j][k];
                    best_cp = j;
                    best_cq = k;
                }
            }
        }

        int cur_cp = best_cp;
        int cur_cq = best_cq;
        int res_p = 0;
        int res_q = 0;

        for (int i = 0; i <= 30; ++i) {
            int bits = chosen_bits[i][cur_cp][cur_cq];
            int bp = (bits >> 1) & 1;
            int bq = bits & 1;

            if (bp) res_p |= (1 << i);
            if (bq) res_q |= (1 << i);

            int p_state = parent_state[i][cur_cp][cur_cq];
            cur_cp = p_state / 3;
            cur_cq = p_state % 3;
        }

        cout << res_p << " " << res_q << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            ZamanSolver solver;
            solver.zaman_execute();
        }
    }
    return 0;
}
