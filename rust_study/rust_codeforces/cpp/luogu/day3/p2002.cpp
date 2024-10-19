// Copyright 2024 Allergy
// email     Allergy527@gmail.com
// workspace luogu\day3\p2002.cpp
// date      2024/09/24 22:01:26
#include <bits/stdc++.h>
// #define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    string n;
    int k;
    cin >> n >> k;
    int len = n.size();
    vector<vector<int>> qwq(10, vector<int>(10));
    vector<int> qvq(10);
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        qwq[a][b] = 1;
    }
    for (int i = 1; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            for (int k = 1; k < 10; ++k)
                if (qwq[j][i] && qwq[i][k]) qwq[j][k] = 1;

    for (int i = 0; i < 10; ++i) {
        qwq[i][i] = 1;
        for (int j = 0; j < 10; ++j)
            if (qwq[i][j]) qvq[i]++;
    }
    vector<int> high_int(len + 27);
    high_int[0] = 1;
    int up = 0;
    for (int i = 0; i < len; ++i) {
        int mul = qvq[n[i] ^ 48];             // 乘数
        for (int j = 0; j < len + 27; ++j) {  // 高精乘
            high_int[j] = high_int[j] * mul + up;
            up = high_int[j] / 10;
            high_int[j] %= 10;
        }
    }
    bool f = true;
    for (int i = len + 26; i >= 0; --i) {
        if (f && high_int[i] == 0) continue;
        if (f) f = false;
        cout << high_int[i];
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
