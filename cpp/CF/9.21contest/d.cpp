/*Copyright [year]
 *@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace CF\9.21contest\d.cpp
 *@date      2024/09/22 00:15:26
 */
#include <bits/stdc++.h>
// #define int long long

using namespace std;  // NOLINT
using ll = __int64;
int inf = 0x3f3f3f3f;

void solve() {
    int n, d, k, l, r;
    cin >> n >> d >> k;
    vector<int> qwq(n + 1);
    map<int, vector<int>> in, out;
    for (int i = 0; i < k; ++i) {
        cin >> l >> r;
        in[l].emplace_back(i);
        out[r].emplace_back(i);
    }
    set<int> qvq;
    int mx = 1, mn = 1, mx_s = 0, mn_s = inf;
    for (int r = 1; r <= n; ++r) {
        l = r - d + 1;
        for (auto x : in[r]) qvq.insert(x);
        if (r >= d) {
            int ans = qvq.size();
            if (ans < mn_s) {
                mn_s = ans;
                mn = l;
            }
            if (ans > mx_s) {
                mx_s = ans;
                mx = l;
            }
        }
        for (auto x : out[l]) qvq.erase(x);
    }
    cout << mx << ' ' << mn << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while (t--) solve();
    cin >> t;
    return 0;
}
