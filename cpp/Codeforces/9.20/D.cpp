/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace CF\9.20\D.cpp
 *@date      2024/09/21 10:58:56
 */
#include<bits/stdc++.h>
//#define int long long

using namespace std;
using ll = long long;
ll ll_inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    ll n, s = 0, mn = ll_inf, mx = 0;
    cin >> n;
    vector<ll>qwq(n);
    for(auto &x : qwq)cin >> x;
    for(int i = 0;i < n;++i) {
        s += qwq[i];
        mn = min(mn, s / (i + 1));
    }
    s = 0;
    for(int i = n - 1;i >= 0;--i) {
        s += qwq[i];
        mx = max(mx, (s + n - i - 1) / (n - i));
    }
    // for(int i = 0;i < n;++i) {
    //     s += qwq[i];
    //     mx = max(mx, (s + i) / (i + 1));
    // }
    cout << mx - mn << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}