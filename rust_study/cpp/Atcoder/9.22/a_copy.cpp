/*Copyright [year]
 *@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Atcoder\9.22\a.cpp
 *@date      2024/09/22 20:00:05
 */
#include <bits/stdc++.h>
// #define int int64_t

using namespace std;  // NOLINT;
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m, q;
    vector<set<int>> fake(51), real(51);
    cin >> n >> m >> q;
    vector<int> ans;
    int must_real = -1;
    auto ask = [&](int x, int y) -> int {
        int u;
        cout << "? " << x << ' ' << y << endl;
        cin >> u;
        return u == 0;
    };
    for (int i = 1; i < 50; i++) {
        int p = 20 * (i - 1) + 1;
        real[i].insert(p);
        for (int j = p + 1; j <= p + 19; j++) {
            if (ask(p, j)) {
                real[i].insert(j);
            } else {
                fake[i].insert(j);
            }
        }  // 跑完轮次
        if (fake[i].size() != real[i].size()) {
            if (fake[i].size() > real[i].size()) swap(fake[i], real[i]);
            for (auto x : fake[i]) ans.emplace_back(x);
        }
        if (ans.size() == 10) {
            cout << "!";
            for (auto x : ans) cout << x << ' ';
            cout << '\n';
            return;
        }
        if (must_real == -1 && real[i].size() > fake[i].size())
            must_real = p;
        if (fake[i].size() == real[i].size()) {
            int temp = p + 20;
            if (ask(p, temp)) {
                cout << '!';
                for (auto x : fake[i]) cout << ' ' << x;
            } else {
                cout << '!';
                for (auto x : real[i]) cout << ' ' << x;
            }
            cout << endl;
            return;
        }
    }
    for (int i = 20 * 49 + 1; i < 1000; ++i) {
        if (ask(must_real, i))
            real[50].insert(i);
        else
            fake[50].insert(i);
        if (fake[50].size() == 10) {
            cout << '!';
            for (auto x : fake[50]) cout << ' ' << x;
            cout << endl;
            return;
        }
    }
    cout << '!';
    fake[50].insert(1000);
    for (auto &x : fake[50]) cout << ' ' << x;
    cout << endl;
}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
