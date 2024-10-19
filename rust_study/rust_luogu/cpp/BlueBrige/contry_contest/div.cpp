/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace BlueBrige\contry_contest\div.cpp
 *@date      2024/05/31 22:47:36
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll fpm(ll x, ll power, ll mod) {
    x %= mod;
    ll ans = 1;
    for(;power;power >>= 1, (x *= x) %= mod)
        if(power & 1) (ans *= x) %= mod;
    return ans;
}

void solve() {
    int n, m, i, j;
    cin >> n;
    m = (int) 1e9 + 7;
    cout << fpm(n, m - 2, m);
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin >> t;
    return 0;
}