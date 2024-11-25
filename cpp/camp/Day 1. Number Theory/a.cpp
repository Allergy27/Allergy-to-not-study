// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\camp\Day 1. Number Theory\a.cpp
 * @date      2024/11/18 15:59:31
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

vector<int> sieve(int l, int r) {
    if (l < 2) l = 2;
    int n = ceil(sqrt(r));

    // Step 1. 筛
    vector<bool> nt_prime(n + 1);
    vector<int> prime;
    for (int i = 2; i <= n; ++i) {
        if (!nt_prime[i]) prime.emplace_back(i);
        for (auto x : prime) {
            if (i * x > n) break;
            nt_prime[i * x] = true;
            if (!(i % x)) break;
        }
    }

    // Step 2. 扩展到 [l,r]
    vector<bool> ntp(r - l + 1);
    for (auto p : prime) {
        int start = max(((l + p - 1) / p) * p, 2 * p);
        for (int x = start; x <= r; x += p) ntp[x - l] = true;
    }
    vector<int> ans;
    for (int i = l; i <= r; ++i)
        if (!ntp[i - l]) ans.emplace_back(i);
    return ans;
}

void solve() {
    int n;
    cin >> n;
    int l = n * n, r = n * n + n;
    vector<int> ans = sieve(l, r);
    for (auto x : ans) cout << x << ' ';
    cout << ln;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
