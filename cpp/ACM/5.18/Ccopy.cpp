/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace ACM\5.18\C.cpp
 *@date      2024/05/18 20:19:31
 */
#include<bits/stdc++.h>
#define ll long long
const int MOD = 1000000007, ln = 20000007;
using namespace std;


ll dp[1000005], f[20000009];
void solve() {
    f[2] = 1, f[1] = 1;
    string s;
    cin >> s;
    ll ans = 0;
    ll n = s.size();
    for(ll i = 3;i <=ln;++i)
        f[i] = (f[i - 1] + f[i - 2]) % MOD;
    ll k = 0;
    for(ll i = 0;i < n;++i)
        if(s[i] == '1')ans = (ans + (f[(n - i - 1) * 2 + k]) % MOD) % MOD, k++;
    cout << (ans + f[k]) % MOD << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}