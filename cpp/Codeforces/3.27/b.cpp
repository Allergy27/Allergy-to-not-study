/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace CF\3.27\b.cpp
 *@date      2024/03/27 19:08:23
 */
#include<bits/stdc++.h>
#define ll long long
const ll MOD = 1e9 + 7;
using namespace std;

void solve() {
    ll n, m, i, j = 1, ans, sm = 0;
    cin >> n >> m;
    vector<ll>qwq(n), mx(n);
    for(auto &x : qwq) {
        cin >> x;
        sm += x;
    }
    mx[0] = qwq[0];
    ans = mx[0];
    for(i = 1;i < n;++i) {
        mx[i] = max(mx[i - 1] + qwq[i], qwq[i]);
        ans = max(ans, mx[i]);
    }
    ans = ans % MOD;
    sm = (sm + MOD) % MOD;
    for(i = 0;i < m;++i)j = j * 2 % MOD;
    ans = max(0LL, ans % MOD);
    cout << (sm + ans * j - ans + MOD) % MOD << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}