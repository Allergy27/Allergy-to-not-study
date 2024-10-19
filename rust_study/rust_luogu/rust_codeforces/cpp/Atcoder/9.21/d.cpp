/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Atcoder\9.21\d.cpp
 *@date      2024/09/21 22:06:04
 */
#include <bits/stdc++.h>
// #define int long long

using namespace std;
using ll = long long;
int inf = 0x3f3f3f3f;

void solve() {
    int n, m, i, j;
    cin >> n;
    vector<int> qwq(n);
    set<int> ans;
    for (auto &x : qwq) cin >> x;
    for (int i = n - 2; i >= 0; --i) {
        ans.insert(qwq[i]);
    }
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