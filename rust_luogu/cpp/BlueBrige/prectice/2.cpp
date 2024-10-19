/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace BlueBrige\prectice\2.cpp
 *@date      2024/04/12 15:13:49
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll MOD = 998244353;
const int N = 20000 + 50;

ll div(ll x) {
    ll mul = 1, b = MOD - 2;
    x %= MOD;
    while(b) {
        if(b & 1) mul = mul * x % MOD; //奇数
        x = x * x % MOD;
        b >>= 1;
    }
    return mul;
}

ll C(ll u, ll v) {
    ll ans = 1;
    for(ll i = u; i > u - v; i--)
        ans = ans * (i % MOD) % MOD;
    for(ll i = 0; i < v; i++)
        ans = ans * div(i + 1) % MOD;
    return ans;
}

ll Lucas(ll n, ll m) {
    if(!m) return 1;
    return (C(n % MOD, m % MOD) * Lucas(n / MOD, m / MOD)) % MOD;
}

void solve() {
    ll n, m, ans = 0, a[N], ma[N];
    cin >> n >> m;
    for(ll i = 1; i <= n; i++) cin >> a[i];
    ma[0] = 1;
    for(ll i = 1; i <= n; i++)
        ma[i] = ma[i - 1] * a[i] % MOD;
    ll tmp = m % MOD;
    ll qq = (m % MOD) * (m % MOD) % MOD;
    for(ll i = 1; i < n; i++) {
        ans = (ans + ma[i] * tmp) % MOD;
        tmp = tmp * ((qq + MOD * 54 - i * i) % MOD) % MOD;
        tmp = tmp * (div(4 * i * i + 2 * i)) % MOD;
    }
    ans += Lucas(m + n, 2 * n) % MOD * ma[n] % MOD;
    cout << ans % MOD;
}
int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}