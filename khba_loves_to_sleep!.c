#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef long long ll;

typedef struct { ll l, r; } Interval;

static int cmp_ll(const void *a, const void *b) {
    ll x = *(const ll*)a, y = *(const ll*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

static int cmp_interval(const void *a, const void *b) {
    const Interval *ia = (const Interval*)a;
    const Interval *ib = (const Interval*)b;
    if (ia->l < ib->l) return -1;
    if (ia->l > ib->l) return 1;
    if (ia->r < ib->r) return -1;
    if (ia->r > ib->r) return 1;
    return 0;
}

static int build_forbidden(const ll *arr, int n, ll x, ll d, Interval *out) {
    if (d == 0) {
        return 0;
    }
    int m = 0;
    ll rad = d - 1;
    for (int i = 0; i < n; ++i) {
        ll L = arr[i] - rad;
        ll R = arr[i] + rad;
        if (L < 0) L = 0;
        if (R > x) R = x;
        if (L <= R) {
            out[m].l = L;
            out[m].r = R;
            ++m;
        }
    }
    if (m == 0) return 0;
    qsort(out, m, sizeof(Interval), cmp_interval);
    int k = 0;
    ll curL = out[0].l, curR = out[0].r;
    for (int i = 1; i < m; ++i) {
        if (out[i].l <= curR + 1) {
            if (out[i].r > curR) curR = out[i].r;
        } else {
            out[k].l = curL;
            out[k].r = curR;
            ++k;
            curL = out[i].l;
            curR = out[i].r;
        }
    }
    out[k].l = curL;
    out[k].r = curR;
    ++k;
    return k;
}

static ll count_allowed(const Interval *forb, int m, ll x) {
    ll total = x + 1;
    ll covered = 0;
    for (int i = 0; i < m; ++i) {
        covered += (forb[i].r - forb[i].l + 1);
    }
    if (covered > total) covered = total;
    ll allowed = total - covered;
    if (allowed < 0) allowed = 0;
    return allowed;
}

int main(void) {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        int n, k;
        ll x;
        if (scanf("%d %d %lld", &n, &k, &x) != 3) return 0;
        ll *a = (ll*)malloc((size_t)n * sizeof(ll));
        if (!a) return 0;
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &a[i]);
        }
        qsort(a, n, sizeof(ll), cmp_ll);

        ll lo = 0, hi = x + 1;
        Interval *buf = (Interval*)malloc((size_t)n * sizeof(Interval));
        Interval *merged = buf;
        while (lo + 1 < hi) {
            ll mid = lo + (hi - lo) / 2;
            int m = build_forbidden(a, n, x, mid, buf);
            ll allowed = count_allowed(merged, m, x);
            if (allowed >= k) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        ll best_d = lo;

        int m = build_forbidden(a, n, x, best_d, buf);
        ll *ans = (ll*)malloc((size_t)k * sizeof(ll));
        int cnt = 0;
        ll cur = 0;
        for (int i = 0; i < m && cnt < k; ++i) {
            ll L = buf[i].l, R = buf[i].r;
            for (ll p = cur; p < L && cnt < k; ++p) {
                ans[cnt++] = p;
            }
            if (R + 1 > cur) cur = R + 1;
        }
        for (ll p = cur; p <= x && cnt < k; ++p) {
            ans[cnt++] = p;
        }
        for (int i = 0; i < k; ++i) {
            if (i) putchar(' ');
            printf("%lld", ans[i]);
        }
        putchar('\n');

        free(a);
        free(buf);
        free(ans);
    }
    return 0;
}