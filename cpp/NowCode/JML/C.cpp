// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace NowCode\JML\C.cpp
 * @date      2024/10/16 14:05:07
 */
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define ln '\n'
#define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;
#define N 1000100

int primes[N], cnt;  // primes[]存储所有素数
bool st[N];          // st[x]存储x是否被筛掉
void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    int l = lower_bound(primes, primes + cnt, n) - primes;
    int r = lower_bound(primes, primes + cnt, m) - primes;
    // for (int i = 0; i < 10; ++i)
    //     cout << primes[i] << " ";
    int len = r - l;
    cout << len + 1 << ln;
}

signed main() {
    get_primes(N - 1);
    int n = 0;
    for (int i = 0; i < N; i++) {
        if (primes[i] == 0) {
            n = i;
            break;
        }
    }
    cout << n << ln;
    for (int i = 0; i < N; ++i) {
        if (primes[i] * primes[i] * primes[i] >= N) break;
        primes[n++] = primes[i] * primes[i] * primes[i];
    }
    for (int i = 0; i < N; i++) {
        if (primes[i] * primes[i] >= N) break;
        for (int j = i; i < N; ++j) {
            if (primes[i] * primes[j] >= N) break;
            primes[n++] = primes[i] * primes[j];
        }
    }
    primes[n] = 1;
    sort(primes, primes + n + 1);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
