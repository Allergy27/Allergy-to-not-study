// Copyright 2024 Allergy
// email     Allergy527@gmail.com
// workspace Atcoder\9.22\a.cpp
// date      2024/09/22 22:05:58
#include <bits/stdc++.h>
// #define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> ans;
    int must_real = 0;
    auto ask = [&](int x, int y) -> int {
        int u;
        cout << "? " << x << ' ' << y << endl;
        cin >> u;
        return u == 0;
    };
    auto work = [&](int l) {
        set<int> fake, real;
        if (l == 981 && ans.empty()) {  // 特判最后一组
            for (int r = 0; r < 19; ++r)
                if (ask(must_real, l + r))
                    real.insert(l + r);
                else
                    fake.insert(l + r);
            if (fake.size() == 9) fake.insert(l + 19);
            for (auto x : fake) ans.emplace_back(x);
            return;
        }
        // 不妨假设第一个就是真币
        real.insert(l);
        for (int i = 1; i < 20; ++i)
            if (ask(l, l + i))
                real.insert(l + i);
            else
                fake.insert(l + i);
        if (fake.size() == real.size()) {  // 第一次相等即为答案
            if (ask(l, l + 20))
                for (auto x : fake) ans.emplace_back(x);
            else
                for (auto x : real) ans.emplace_back(x);
            return;
        }
        if (fake.size() > real.size()) swap(fake, real);
        if (must_real == 0) must_real = *real.begin();
        for (auto x : fake) ans.emplace_back(x);
        if (ans.size() == 10) return;
    };
    for (int i = 1; i <= n; i += 20)
        if (ans.size() < 10) work(i);
    cout << '!';
    for (auto x : ans) cout << ' ' << x;
    cout << endl;
}

signed main() {
    // ios::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
