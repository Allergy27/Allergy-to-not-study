// Copyright 2024 Allergy
// email     Allergy527@gmail.com
// workspace luogu\day3\p9853.cpp
// date      2024/09/25 00:04:29
#include <bits/stdc++.h>
// #define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    auto trans = [](string str) -> int {
        int ne = str[0] == '-', ans = 0, len = str.size();
        for (int i = 0; i < len; ++i)
            if ('0' <= str[i] && str[i] <= '9') ans = ans * 10 + str[i] - '0';
        return (ne ? -1 : 1) * ans;
    };
    auto check = [&](string str) -> int {
        int temp = 0, a = 0, b = 2, c = str.size();
        for (int i = 0; i < c; ++i) {
            if (str[i] == 'x') a = i;
            if (str[i] == '=') {
                b = i;
                break;
            }
        }
        c = trans(str.substr(b + 1, c - b));
        b = trans(str.substr(a + 1, b - a));
        a = trans(str.substr(0, a));
        // cout << a << ' ' << b << ' ' << c << '\n';
        return (c - b) / a;
    };
    string qaq;
    set<int> ans;
    for (int i = 0; i < n; ++i) {
        cin >> qaq;
        ans.insert(check(qaq));
    }
    int len = ans.size(), res = 0;
    vector<int> qwq;
    vector<int> qvq(1);
    for (auto x : ans) {
        qwq.emplace_back(x);
        qvq.emplace_back(++res);
    }
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        int l_f = lower_bound(qwq.begin(), qwq.end(), l) - qwq.begin();
        int r_f = upper_bound(qwq.begin(), qwq.end(), r) - qwq.begin();
        cout << qvq[r_f] - qvq[l_f] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
