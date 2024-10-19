/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace luogu\day1\p1111.cpp
 *@date      2024/09/21 21:03:34
 */
#include <bits/stdc++.h>
// #define int long long

using namespace std;  // NOLINT
using ll = int64;
int INT_INF = 0x3f3f3f3f;
ll LL_INF = 0x3f3f3f3f'3f3f3f3f;

struct UFSet {
    vector<int> fa, sz;
    vector<set<pair<int, int>>> s;
    UFSet(int n) : fa(n + 1), sz(n + 1, 1), s(n + 1) {  // NOLINT
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (s[x].size() < s[y].size()) swap(x, y);
        for (auto t : s[y]) s[x].insert(t);
        sz[x] += sz[y];
        fa[y] = x;
        return true;
    }
    int size(int x) {
        return sz[find(x)];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> qwq(m);
    UFSet qaq(n + 1);
    for (auto &[x, y, z] : qwq) {
        cin >> x >> y >> z;
    }
    sort(qwq.begin(), qwq.end(), [](tuple<int, int, int> a, tuple<int, int, int> b) {
        return get<2>(a) < get<2>(b);
    });
    for (int i = 0; i < m; ++i) {
        int x = get<0>(qwq[i]), y = get<1>(qwq[i]);
        qaq.merge(x, y);
        if (qaq.size(1) == n) {
            cout << get<2>(qwq[i]) << '\n';
            return;
        }
    }
    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    cin >> t;
    return 0;
}