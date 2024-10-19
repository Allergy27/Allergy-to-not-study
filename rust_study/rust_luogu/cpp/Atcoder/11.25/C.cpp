/*@author    Allergy
 *@email     Allergy527@gmail.com
 *@workspace Atcoder\11.25\C.cpp
 *@data      2023/11/25 20:08:18
 */
#include<bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    ll n;
    cin >> n;
    ll a = (ll) sqrt(n) + 1, b = 0;
    ll ans = abs(n - a * a - b * b);
    for(ll i = 0;i < (ll) sqrt(n);++i) {
        a -= a > 1 ? 1 : 0;
        b = (ll) sqrt(n - a * a);
        if(abs(n - a * a - b * b) < ans)ans = abs(n - a * a - b * b);
        if(abs(n - a * a - (b + 1) * (b + 1)) < ans)ans = abs(n - a * a - (b + 1) * (b + 1));
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    cin>>t;
    return 0;
}