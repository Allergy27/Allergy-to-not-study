// Copyright 2024 Allergy
// email     Allergy527@gmail.com
// workspace luogu\day3\p2024.cpp
// date      2024/09/24 14:14:43
#include <bits/stdc++.h>
// #define int int64_t

using namespace std;  // NOLINT
using ll = int64_t;
int inf = 0x3f3f3f3f;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

struct UFSet {
    vector<int> fa, rel;
    UFSet(int n) : fa(n + 1), rel(n + 1) {  // NOLINT
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        if (fa[x] == x) return x;
        int temp = find(fa[x]);
        rel[x] = (rel[x] + rel[fa[x]]) % 3;
        return fa[x] = temp;
    }
    void merge(int x, int y, int rootx, int rooty, int f) {
        fa[rootx] = rooty;
        rel[rootx] = (3 - rel[x] + rel[y] + f - 1) % 3;
    }
};

void solve() {
    int n, k, ans = 0;
    cin >> n >> k;
    UFSet qwq(n);
    for (int i = 0; i < k; i++) {
        int f, a, b;
        cin >> f >> a >> b;
        if (a > n || b > n || (f == 2 && a == b)) {
            ++ans;
            continue;
        }
        int rootx = qwq.find(a);
        int rooty = qwq.find(b);
        if (f == 1) {
            if (rootx == rooty && qwq.rel[a] != qwq.rel[b]) {
                ++ans;
                continue;
            } else if (rootx != rooty) {
                qwq.merge(a, b, rootx, rooty, f);
            }
        } else {
            if (rootx == rooty) {
                if ((qwq.rel[a] - qwq.rel[b] + 3) % 3 != 1) {
                    ++ans;
                    continue;
                }
            } else {
                qwq.merge(a, b, rootx, rooty, f);
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
