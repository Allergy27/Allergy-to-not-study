// COPYRIGHT LUOGU
#include <bits/stdc++.h>

using namespace std;  // NOLINT
#define int int64_t
using ll = int64_t;
const int N = 1e5 + 10;
ll n, k, a[N], f[N], g[N];
ll t[N], L = 1, R, now;
void add(const int &x) { now += t[a[x]]++; }
void del(const int &x) { now -= --t[a[x]]; }
ll c(int l, int r) {
    while (L > l) add(--L);
    while (R < r) add(++R);
    while (L < l) del(L++);
    while (R > r) del(R--);
    return now;
}
void solve(int l, int r, int ql, int qr) {
    if (ql == qr) {
        for (int i = l; i <= r; i++) g[i] = f[ql] + c(ql + 1, i);
    }
    if (ql >= qr || l > r) return;
    int mid = l + r >> 1;
    ll v = 1e18;
    int qmid = -1;
    for (int i = ql; i <= min(qr, mid - 1); i++) {
        ll val = f[i] + c(i + 1, mid);
        if (val < v) v = val, qmid = i;
    }
    g[mid] = v;
    solve(l, mid - 1, ql, qmid);
    solve(mid + 1, r, qmid, qr);
}
signed main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    memset(f, 0x3f, sizeof(f)), f[0] = 0;
    for (int i = 1; i <= k; i++) solve(1, n, 0, n), memcpy(f, g, sizeof f);
    cout << f[n] << endl;
    return 0;
}
