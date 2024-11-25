// Copyright 2024 Allergy
/* @author    Allergy
 * @email     Allergy527@gmail.com
 * @workspace cpp\NowCode\round69\e.cpp
 * @date      2024/11/24 19:55:18
 */
#include <bits/stdc++.h>
#define int int64_t
using namespace std;  // NOLINT
const int N = 1e6 + 5;

int t = 1;
int n;
int a[N], sum = 0;
int bi[N];

int lowbit(int x) { return x & -x; }

void update(int x, int v) {
    for (; x <= n; x += lowbit(x))
        bi[x] += v;
}

int query(int x) {
    int res = 0;
    for (; x; x -= lowbit(x))
        res += bi[x];
    return res;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] > 0) update(i, 1);
    }
    if (sum % 3 != 0) {
        cout << 0 << endl;
        return;
    }
    vector<int> q;
    int su = 0;
    int a2 = 0;
    for (int i = 1; i <= n - 1; i++) {
        su += a[i];
        if (su == sum * 2 / 3)
            for (int x : q)
                if (query(i) - query(x) > 0) a2++;
        if (su == sum / 3)
            if (query(i) > 0) q.push_back(i);
    }
    cout << a2 << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    while (t--) {
        solve();
    }
    return 0;
}
