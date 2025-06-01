/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace CF\5.20\C.cpp
 *@date      2024/05/20 23:19:23
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n, m;
    cin >> n;
    vector<int>qwq(n);
    map<tuple<int, int, int>, int>qvq;
    cin >> qwq[0] >> qwq[1];
    for(int i = 2;i < n;++i) {
        cin >> qwq[i];
        ++qvq[{ qwq[i - 2], qwq[i - 1], qwq[i] }];
    }
    map<pair<int, int>, int>m0;
    map<pair<int, int>, int>m1;
    map<pair<int, int>, int>m2;
    for(auto [t, k] : qvq) {
        int x = t._M_head, y = t.second(), z = t.third();
        ++m0[{y, z}], ++m1[{x, z}], ++m2[{x, y}];
    }
    ll ans = 0;
    auto C = [](int x) {
        return x * (x - 1) >> 1;
        };
    for(auto [x, y] : m0)ans += C(y);
    for(auto [x, y] : m1)ans += C(y);
    for(auto [x, y] : m2)ans += C(y);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}