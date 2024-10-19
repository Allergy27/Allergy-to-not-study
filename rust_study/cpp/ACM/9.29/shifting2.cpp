// Copyright 2024 Allergy
// email     Allergy527@gmail.com
// workspace ACM\9.29\shifting2.cpp
// date      2024/09/29 19:05:50
#include <bits/stdc++.h>
#define lowbit(x) ((x) & (-(x)))
#define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;
int flag, ans;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    if (n == 2 && s[0] == s[1]) {
        cout << "1\n";
        return;
    }
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            flag++;
        } else {
            if (flag > ans)
                ans = flag;
            flag = 0;
        }
    }
    if (flag % 2 == 0) {
        int op = 0;
        for (int i = 0; i < n; ++i)
            if (s[i] == s[(i + 1) % n]) ++i, ++op;
        if (op != 0)
            cout << op - 1 << '\n';
        else
            cout << "0\n";
    } else {
        int op = 0;
        for (int i = 0; i < n; ++i)
            if (s[i] == s[(i + 1) % n]) ++i, ++op;
        if (op != 0)
            cout << op << '\n';
        else
            cout << "0\n";
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
