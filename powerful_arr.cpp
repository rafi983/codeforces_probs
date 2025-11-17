#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Query {
    int l;
    int r;
    int idx;
};

static int block_size;

static bool cmp_query(const Query &a, const Query &b) {
    int block_a = a.l / block_size;
    int block_b = b.l / block_size;
    if (block_a != block_b) {
        return block_a < block_b;
    }
    if (block_a & 1) {
        return a.r > b.r;
    }
    return a.r < b.r;
}

int main() {
    int n, t;
    if (!(cin >> n >> t)) {
        return 0;
    }

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        if (!(cin >> arr[i])) {
            return 0;
        }
    }

    vector<Query> queries(t);
    vector<long long> answers(t);

    for (int i = 0; i < t; ++i) {
        int l, r;
        if (!(cin >> l >> r)) {
            return 0;
        }
        --l;
        --r;
        queries[i].l = l;
        queries[i].r = r;
        queries[i].idx = i;
    }

    block_size = 1;
    while ((long long)block_size * block_size < n) {
        ++block_size;
    }

    sort(queries.begin(), queries.end(), cmp_query);

    vector<int> freq(1000001, 0);

    int cur_l = 0;
    int cur_r = -1;
    long long cur_ans = 0;

    for (int qi = 0; qi < t; ++qi) {
        Query q = queries[qi];
        while (cur_l > q.l) {
            --cur_l;
            int x = arr[cur_l];
            long long f = freq[x];
            cur_ans += (2 * f + 1) * (long long)x;
            ++freq[x];
        }
        while (cur_r < q.r) {
            ++cur_r;
            int x = arr[cur_r];
            long long f = freq[x];
            cur_ans += (2 * f + 1) * (long long)x;
            ++freq[x];
        }
        while (cur_l < q.l) {
            int x = arr[cur_l];
            long long f = freq[x];
            cur_ans -= (2 * f - 1) * (long long)x;
            --freq[x];
            ++cur_l;
        }
        while (cur_r > q.r) {
            int x = arr[cur_r];
            long long f = freq[x];
            cur_ans -= (2 * f - 1) * (long long)x;
            --freq[x];
            --cur_r;
        }
        answers[q.idx] = cur_ans;
    }

    for (int i = 0; i < t; ++i) {
        cout << answers[i] << endl;
    }

    return 0;
}

